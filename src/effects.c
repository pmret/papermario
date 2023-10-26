#include "common.h"
#include "effects.h"
#include "ld_addrs.h"

typedef s32 TlbEntry[0x1000 / 4];
typedef TlbEntry TlbMappablePage[15];

SHIFT_BSS EffectGraphics gEffectGraphicsData[15];
SHIFT_BSS EffectInstance* gEffectInstances[96];

extern TlbMappablePage D_80197000;
extern Addr D_801A6000;

#define FX_ENTRY(name, gfx_name) { \
    name##_main, effect_##name##_ROM_START, effect_##name##_ROM_END, effect_##name##_VRAM, gfx_name##_ROM_START, \
    gfx_name##_ROM_END \
}

#include "effects/effect_table.c"

s32 D_8007FEB8[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 5, 3, 4, 13, 60, 0, 512, 0, 0, 3, 0 };

/// Used for unbound function points in effect structs.
void stub_effect_delegate(EffectInstance* effect) {
}

void set_effect_pos_offset(EffectInstance* effect, f32 x, f32 y, f32 z) {
    s32* data = effect->data.any;

    ((f32*)data)[1] = x;
    ((f32*)data)[2] = y;
    ((f32*)data)[3] = z;
}

void clear_effect_data(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
        gEffectGraphicsData[i].flags = 0;
    }

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        gEffectInstances[i] = NULL;
    }

    osUnmapTLBAll();
    osMapTLB(0x10, NULL, _325AD0_VRAM, (s32)&D_801A6000 & 0xFFFFFF, -1, -1);
    DMA_COPY_SEGMENT(_325AD0);
}

void func_80059D48(void) {
}

void update_effects(void) {
    if (!(gOverrideFlags & (GLOBAL_OVERRIDES_800 | GLOBAL_OVERRIDES_400))) {
        EffectGraphics* effectGraphics;
        s32 i;

        // reset free delay for each EffectGraphics touched in previous update
        for (i = 0, effectGraphics = gEffectGraphicsData; i < ARRAY_COUNT(gEffectGraphicsData); i++, effectGraphics++) {
            if (effectGraphics->flags & FX_GRAPHICS_LOADED) {
                if (!(effectGraphics->flags & FX_GRAPHICS_CAN_FREE)) {
                    effectGraphics->flags |= FX_GRAPHICS_CAN_FREE;
                    effectGraphics->freeDelay = 3;
                }
            }
        }

        // update each EffectInstances
        for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
            EffectInstance* effectInstance = gEffectInstances[i];

            if (effectInstance != NULL && (effectInstance->flags & FX_INSTANCE_FLAG_ENABLED)) {
                effectInstance->graphics->flags &= ~FX_GRAPHICS_CAN_FREE;

                if (gGameStatusPtr->isBattle) {
                    if (effectInstance->flags & FX_INSTANCE_FLAG_BATTLE) {
                        effectInstance->graphics->update(effectInstance);
                        effectInstance->flags |= FX_INSTANCE_FLAG_HAS_UPDATED;
                    }
                } else {
                    if (!(effectInstance->flags & FX_INSTANCE_FLAG_BATTLE)) {
                        effectInstance->graphics->update(effectInstance);
                        effectInstance->flags |= FX_INSTANCE_FLAG_HAS_UPDATED;
                    }
                }
            }
        }

        // free any EffectGraphics which haven't been used recently
        for (i = 0, effectGraphics = gEffectGraphicsData; i < ARRAY_COUNT(gEffectGraphicsData); i++, effectGraphics++) {
            if (effectGraphics->flags & FX_GRAPHICS_LOADED) {
                if (effectGraphics->flags & FX_GRAPHICS_CAN_FREE) {
                    if (effectGraphics->freeDelay != 0) {
                        effectGraphics->freeDelay--;
                    } else {
                        if (effectGraphics->data != NULL) {
                            general_heap_free(effectGraphics->data);
                            effectGraphics->data = NULL;
                        }
                        effectGraphics->flags = FX_GRAPHICS_DISABLED;
                        osUnmapTLB(i);
                    }
                }
            }
        }
    }
}

void render_effects_world(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        EffectInstance* effectInstance = gEffectInstances[i];

        if (effectInstance != NULL) {
            if (effectInstance->flags & FX_INSTANCE_FLAG_ENABLED) {
                if (effectInstance->flags & FX_INSTANCE_FLAG_HAS_UPDATED) {
                    if (gGameStatusPtr->isBattle) {
                        if (effectInstance->flags & FX_INSTANCE_FLAG_BATTLE) {
                            effectInstance->graphics->renderWorld(effectInstance);
                        }
                    } else {
                        if (!(effectInstance->flags & FX_INSTANCE_FLAG_BATTLE)) {
                            effectInstance->graphics->renderWorld(effectInstance);
                        }
                    }
                }
            }
        }
    }
}

void render_effects_UI(void) {
    s32 cond = TRUE;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        EffectInstance* effectInstance = gEffectInstances[i];

        if (effectInstance != NULL) {
            if (effectInstance->flags & FX_INSTANCE_FLAG_ENABLED) {
                if (effectInstance->flags & FX_INSTANCE_FLAG_HAS_UPDATED) {
                    void (*renderUI)(EffectInstance* effect);

                    if (gGameStatusPtr->isBattle && !(effectInstance->flags & FX_INSTANCE_FLAG_BATTLE)) {
                        continue;
                    }

                    if (!gGameStatusPtr->isBattle && effectInstance->flags & FX_INSTANCE_FLAG_BATTLE) {
                        continue;
                    }

                    renderUI = effectInstance->graphics->renderUI;
                    if (renderUI != stub_effect_delegate) {
                        if (cond) {
                            Camera* camera = &gCameras[gCurrentCameraID];

                            gDPPipeSync(gMainGfxPos++);
                            gSPViewport(gMainGfxPos++, &camera->vp);
                            gSPClearGeometryMode(gMainGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG |
                                                G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD |
                                                G_SHADING_SMOOTH | G_CLIPPING | 0x40F9FA);
                            gSPSetGeometryMode(gMainGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
                            gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE,
                                              camera->viewportStartX,
                                              camera->viewportStartY,
                                              camera->viewportStartX + camera->viewportW,
                                              camera->viewportStartY + camera->viewportH);
                            gSPClipRatio(gMainGfxPos++, FRUSTRATIO_2);

                            cond = FALSE;
                            if (!(camera->flags & CAMERA_FLAG_ORTHO)) {
                                gSPPerspNormalize(gMainGfxPos++, camera->perspNorm);
                                gSPMatrix(gMainGfxPos++, &gDisplayContext->camPerspMatrix[gCurrentCameraID],
                                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
                            }
                        }

                        renderUI(effectInstance);
                    }
                }
            }
        }
    }
}

EffectInstance* create_effect_instance(EffectBlueprint* effectBp) {
    EffectInstance* newEffectInst;
    EffectGraphics* effectGraphics;
    s32 i;

    // Search for an unused instance
    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        if (gEffectInstances[i] == NULL) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(gEffectInstances));

    // Allocate space for the new instance
    gEffectInstances[i] = newEffectInst = general_heap_malloc(sizeof(*newEffectInst));
    ASSERT(newEffectInst != NULL);

    effectGraphics = &gEffectGraphicsData[0];
    newEffectInst->effectIndex = effectBp->effectID;
    newEffectInst->flags = FX_INSTANCE_FLAG_ENABLED;

    // Look for a loaded effect of the proper index
    for (i = 0; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
        if ((effectGraphics->flags & FX_GRAPHICS_LOADED) && (effectGraphics->effectIndex == effectBp->effectID)) {
            break;
        }
        effectGraphics++;
    }

    ASSERT(i < ARRAY_COUNT(gEffectGraphicsData));

    // If this is the first new instance of the effect, initialize the function pointers
    if (effectGraphics->instanceCounter == 0) {
        effectGraphics->update = effectBp->update;
        if (effectGraphics->update == NULL) {
            effectGraphics->renderWorld = stub_effect_delegate;
        }

        effectGraphics->renderWorld = effectBp->renderWorld;
        // @bug? null check for renderUI instead of renderWorld
        if (effectGraphics->renderUI == NULL) {
            effectGraphics->renderUI = stub_effect_delegate;
        }

        effectGraphics->renderUI = effectBp->renderUI;
        if (effectGraphics->renderUI == NULL) {
            effectGraphics->renderUI = stub_effect_delegate;
        }
    }

    effectGraphics->instanceCounter++;
    newEffectInst->graphics = effectGraphics;

    if (effectBp->init != NULL) {
        effectBp->init(newEffectInst);
    }

    if (gGameStatusPtr->isBattle) {
        newEffectInst->flags |= FX_INSTANCE_FLAG_BATTLE;
    }
    return newEffectInst;
}

void remove_effect(EffectInstance* effectInstance) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        if (gEffectInstances[i] == effectInstance) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(gEffectInstances));

    if (effectInstance->data.any == NULL) {
        general_heap_free(effectInstance);
        gEffectInstances[i] = NULL;
    } else {
        general_heap_free(effectInstance->data.any);
        general_heap_free(effectInstance);
        gEffectInstances[i] = NULL;
    }
}

void remove_all_effects(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        EffectInstance* effect = gEffectInstances[i];

        if (effect != NULL && effect->flags & FX_INSTANCE_FLAG_BATTLE) {
            if (effect->data.any != NULL) {
                general_heap_free(effect->data.any);
            }
            general_heap_free(effect);
            gEffectInstances[i] = NULL;
        }
    }
}

s32 load_effect(s32 effectIndex) {
    EffectTableEntry* effectEntry = &gEffectTable[effectIndex];
    EffectGraphics* effectGraphics;
    TlbMappablePage* tlbMappablePages;
    s32 i;

    // Look for a loaded effect matching the desired index
    for (i = 0, effectGraphics = &gEffectGraphicsData[0]; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
        if (effectGraphics->flags & FX_GRAPHICS_LOADED && effectGraphics->effectIndex == effectIndex) {
            break;
        }
        effectGraphics++;
    }

    // If an effect was found within the table, initialize it and return
    if (i < ARRAY_COUNT(gEffectGraphicsData)) {
        effectGraphics->effectIndex = effectIndex;
        effectGraphics->instanceCounter = 0;
        effectGraphics->flags = FX_GRAPHICS_LOADED;
        return 1;
    }

    // If a loaded effect wasn't found, look for the first empty space
    for (i = 0, effectGraphics = &gEffectGraphicsData[0]; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
        if (!(effectGraphics->flags & FX_GRAPHICS_LOADED)) {
            break;
        }
        effectGraphics++;
    }

    // If no empty space was found, panic
    ASSERT(i < ARRAY_COUNT(gEffectGraphicsData));

    // Map space for the effect
    tlbMappablePages = &D_80197000;
    osMapTLB(i, 0, effectEntry->dmaDest, (s32)((*tlbMappablePages)[i]) & 0xFFFFFF, -1, -1);

    // Copy the effect into the newly mapped space
    dma_copy(effectEntry->dmaStart, effectEntry->dmaEnd, effectEntry->dmaDest);

    // If there's graphics data for the effect, allocate space and copy into the new space
    if (effectEntry->graphicsDmaStart != NULL) {
        void* effectDataBuf = general_heap_malloc(effectEntry->graphicsDmaEnd - effectEntry->graphicsDmaStart);
        effectGraphics->data = effectDataBuf;
        ASSERT(effectDataBuf != NULL);
        dma_copy(effectEntry->graphicsDmaStart, effectEntry->graphicsDmaEnd, effectGraphics->data);
    }

    // Initialize the newly loaded effect data
    effectGraphics->effectIndex = effectIndex;
    effectGraphics->instanceCounter = 0;
    effectGraphics->flags = FX_GRAPHICS_LOADED;
    return 1;
}
