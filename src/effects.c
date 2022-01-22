#include "common.h"
#include "effects.h"
#include "effects_internal.h"
#include "ld_addrs.h"

typedef s32 TlbEntry[0x1000 / 4];
typedef TlbEntry TlbMappablePage[15];

extern TlbMappablePage D_80197000;

#define EFFECT_LOADED 1

extern EffectGraphics gEffectGraphicsData[15];
extern EffectInstance* gEffectInstances[96];
extern s32 D_801A6000;


#define FX_ENTRY(name, gfx_name) { \
    name##_main, name##_ROM_START, name##_ROM_END, name##_VRAM, gfx_name##_ROM_START, gfx_name##_ROM_END \
}

// TODO remove once everyone is named
#define FX_ENTRY_NUMBERED(name, gfx_name) { \
    fx_##name##_main, effect_##name##_ROM_START, effect_##name##_ROM_END, effect_##name##_VRAM, gfx_name##_ROM_START, \
    gfx_name##_ROM_END \
} \

EffectTableEntry gEffectTable[] = {
    /* 0x00 */ {},
    /* 0x01 */ FX_ENTRY(big_smoke_puff, _326410),
    /* 0x02 */ {},
    /* 0x03 */ {},
    /* 0x04 */ {},
    /* 0x05 */ {},
    /* 0x06 */ FX_ENTRY(landing_dust, _328EA0),
    /* 0x07 */ FX_ENTRY(walking_dust, _328EA0),
    /* 0x08 */ FX_ENTRY(flower_splash, _32CEC0),
    /* 0x09 */ FX_ENTRY(flower_trail, _32CEC0),
    /* 0x0A */ FX_ENTRY(cloud_puff, _32EC50),
    /* 0x0B */ FX_ENTRY(cloud_trail, _32EC50),
    /* 0x0C */ FX_ENTRY(footprint, _32FB50),
    /* 0x0D */ FX_ENTRY(floating_flower, _330460),
    /* 0x0E */ FX_ENTRY(snowflake, _330F00),
    /* 0x0F */ FX_ENTRY(star, _3326A0),
    /* 0x10 */ FX_ENTRY(emote, _334C70),
    /* 0x11 */ FX_ENTRY(sparkles, _337FC0),
    /* 0x12 */ FX_ENTRY(shape_spell, _339F60),
    /* 0x13 */ FX_ENTRY(gather_energy_pink, _33BBD0),
    /* 0x14 */ FX_ENTRY(drop_leaves, _33D610),
    /* 0x15 */ FX_ENTRY(dust, _33F000),
    /* 0x16 */ FX_ENTRY(shattering_stones, _340880),
    /* 0x17 */ FX_ENTRY(smoke_ring, _328EA0),
    /* 0x18 */ FX_ENTRY(damage_stars, _343040),
    /* 0x19 */ FX_ENTRY(explosion, _343F70),
    /* 0x1A */ FX_ENTRY(lens_flare, _3451E0),
    /* 0x1B */ FX_ENTRY(got_item_outline, _345B40),
    /* 0x1C */ FX_ENTRY(spiky_white_aura, _34E770),
    /* 0x1D */ FX_ENTRY(smoke_impact, _328EA0),
    /* 0x1E */ FX_ENTRY(damage_indicator, _350220),
    /* 0x1F */ FX_ENTRY(purple_ring, _352CE0),
    /* 0x20 */ FX_ENTRY(flame, _353BB0),
    /* 0x21 */ FX_ENTRY(stars_burst, _343040),
    /* 0x22 */ FX_ENTRY(stars_shimmer, _337FC0),
    /* 0x23 */ FX_ENTRY(rising_bubble, _356530),
    /* 0x24 */ FX_ENTRY(ring_blast, _3573A0),
    /* 0x25 */ FX_ENTRY(shockwave, _3593B0),
    /* 0x26 */ FX_ENTRY(music_note, _35A5E0),
    /* 0x27 */ FX_ENTRY(smoke_burst, _328EA0),
    /* 0x28 */ FX_ENTRY(sweat, _35C550),
    /* 0x29 */ FX_ENTRY(sleep_bubble, _35D510),
    /* 0x2A */ {},
    /* 0x2B */ FX_ENTRY(windy_leaves, _33D610),
    /* 0x2C */ FX_ENTRY(falling_leaves, _35F0E0),
    /* 0x2D */ FX_ENTRY(stars_spread, _360A30),
    /* 0x2E */ FX_ENTRY(steam_burst, _361670),
    /* 0x2F */ FX_ENTRY(stars_orbiting, _362C50),
    /* 0x30 */ FX_ENTRY(big_snowflakes, _3638C0),
    /* 0x31 */ FX_ENTRY(debuff, _364C00),
    /* 0x32 */ FX_ENTRY(green_impact, _3659B0),
    /* 0x33 */ FX_ENTRY(radial_shimmer, _366D60),
    /* 0x34 */ FX_ENTRY(ending_decals, _36AEE0),
    /* 0x35 */ FX_ENTRY(light_rays, _36DF90),
    /* 0x36 */ FX_ENTRY(lightning, _36ED60),
    /* 0x37 */ FX_ENTRY(fire_breath, _3733E0),
    /* 0x38 */ FX_ENTRY(shimmer_burst, _337FC0),
    /* 0x39 */ FX_ENTRY(energy_shockwave, _375510),
    /* 0x3A */ FX_ENTRY(shimmer_wave, _337FC0),
    /* 0x3B */ FX_ENTRY(aura, _377F80),
    /* 0x3C */ FX_ENTRY_NUMBERED(60, _37ADD0),
    /* 0x3D */ FX_ENTRY_NUMBERED(61, _37D180),
    /* 0x3E */ FX_ENTRY(blast, _37D9D0),
    /* 0x3F */ FX_ENTRY(fire_flower_attacking, _3803A0),
    /* 0x40 */ FX_ENTRY_NUMBERED(64, _381E00),
    /* 0x41 */ FX_ENTRY_NUMBERED(65, _3863B0),
    /* 0x42 */ FX_ENTRY_NUMBERED(66, _37D9D0),
    /* 0x43 */ FX_ENTRY_NUMBERED(67, _38A350),
    /* 0x44 */ FX_ENTRY_NUMBERED(68, _38BBA0),
    /* 0x45 */ FX_ENTRY_NUMBERED(69, _38D070),
    /* 0x46 */ FX_ENTRY_NUMBERED(70, _38E990),
    /* 0x47 */ FX_ENTRY_NUMBERED(71, _38F710),
    /* 0x48 */ FX_ENTRY_NUMBERED(72, _3903D0),
    /* 0x49 */ FX_ENTRY_NUMBERED(73, _392440),
    /* 0x4A */ FX_ENTRY_NUMBERED(74, _3930A0),
    /* 0x4B */ FX_ENTRY_NUMBERED(75, _394670),
    /* 0x4C */ FX_ENTRY_NUMBERED(76, _3960F0),
    /* 0x4D */ FX_ENTRY_NUMBERED(77, _397040),
    /* 0x4E */ FX_ENTRY_NUMBERED(78, _398BC0),
    /* 0x4F */ FX_ENTRY_NUMBERED(79, _3A0D60),
    /* 0x50 */ FX_ENTRY_NUMBERED(80, _3A2440),
    /* 0x51 */ FX_ENTRY_NUMBERED(81, _3A33D0),
    /* 0x52 */ FX_ENTRY_NUMBERED(82, _3A4320),
    /* 0x53 */ FX_ENTRY_NUMBERED(83, _3A5BE0),
    /* 0x54 */ FX_ENTRY_NUMBERED(84, _3A77A0),
    /* 0x55 */ FX_ENTRY_NUMBERED(85, _3AB030),
    /* 0x56 */ FX_ENTRY_NUMBERED(86, _3AF700),
    /* 0x57 */ FX_ENTRY_NUMBERED(87, _3B2D90),
    /* 0x58 */ FX_ENTRY_NUMBERED(88, _3B46A0),
    /* 0x59 */ FX_ENTRY_NUMBERED(89, _3B5340),
    /* 0x5A */ FX_ENTRY_NUMBERED(90, _3B6BF0),
    /* 0x5B */ FX_ENTRY_NUMBERED(91, _3B78D0),
    /* 0x5C */ FX_ENTRY_NUMBERED(92, _3B8860),
    /* 0x5D */ FX_ENTRY_NUMBERED(93, _3B9A70),
    /* 0x5E */ FX_ENTRY_NUMBERED(94, _3BAEA0),
    /* 0x5F */ FX_ENTRY_NUMBERED(95, _3BCA90),
    /* 0x60 */ FX_ENTRY_NUMBERED(96, _3BD9A0),
    /* 0x61 */ FX_ENTRY_NUMBERED(97, _3C1BA0),
    /* 0x62 */ FX_ENTRY_NUMBERED(98, _3CB890),
    /* 0x63 */ FX_ENTRY_NUMBERED(99, _3CD6E0),
    /* 0x64 */ FX_ENTRY_NUMBERED(100, _3CFAF0),
    /* 0x65 */ FX_ENTRY_NUMBERED(101, _3D11E0),
    /* 0x66 */ FX_ENTRY_NUMBERED(102, _3D2580),
    /* 0x67 */ FX_ENTRY_NUMBERED(103, _3D3930),
    /* 0x68 */ FX_ENTRY_NUMBERED(104, _3593B0),
    /* 0x69 */ FX_ENTRY_NUMBERED(105, _3D4E90),
    /* 0x6A */ {},
    /* 0x6B */ FX_ENTRY_NUMBERED(107, _3D5F30),
    /* 0x6C */ FX_ENTRY_NUMBERED(108, _3D7040),
    /* 0x6D */ FX_ENTRY_NUMBERED(109, _3D7770),
    /* 0x6E */ FX_ENTRY_NUMBERED(110, _3D80C0),
    /* 0x6F */ FX_ENTRY_NUMBERED(111, _3D9100),
    /* 0x70 */ FX_ENTRY_NUMBERED(112, _3DBF40),
    /* 0x71 */ FX_ENTRY_NUMBERED(113, _3DCD50),
    /* 0x72 */ FX_ENTRY_NUMBERED(114, _3DEE60),
    /* 0x73 */ FX_ENTRY_NUMBERED(115, _3E12D0),
    /* 0x74 */ FX_ENTRY_NUMBERED(116, _3E1CD0),
    /* 0x75 */ FX_ENTRY_NUMBERED(117, _3E2960),
    /* 0x76 */ {},
    /* 0x77 */ FX_ENTRY_NUMBERED(119, _3E5350),
    /* 0x78 */ FX_ENTRY_NUMBERED(120, _3E5F30),
    /* 0x79 */ FX_ENTRY_NUMBERED(121, _3EBE60),
    /* 0x7A */ FX_ENTRY_NUMBERED(122, _3F8CC0),
    /* 0x7B */ FX_ENTRY_NUMBERED(123, _3FA4B0),
    /* 0x7C */ FX_ENTRY_NUMBERED(124, _3FF250),
    /* 0x7D */ FX_ENTRY_NUMBERED(125, _3FA4B0),
    /* 0x7E */ FX_ENTRY_NUMBERED(126, _403BF0),
    /* 0x7F */ FX_ENTRY_NUMBERED(127, _404F40),
    /* 0x80 */ FX_ENTRY_NUMBERED(128, _407080),
    /* 0x81 */ FX_ENTRY_NUMBERED(129, _40A1C0),
    /* 0x82 */ FX_ENTRY_NUMBERED(130, _40BBA0),
    /* 0x83 */ FX_ENTRY_NUMBERED(131, _40D290),
    /* 0x84 */ FX_ENTRY_NUMBERED(132, _337FC0),
    /* 0x85 */ FX_ENTRY_NUMBERED(133, _413FA0),
    /* 0x86 */ FX_ENTRY_NUMBERED(134, _415060),
};

s32 D_8007FEB8[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000008, 0x00000005, 0x00000003, 0x00000004,
    0x0000000D, 0x0000003C, 0x00000000, 0x00000200, 0x00000000, 0x00000000,
    0x00000003, 0x00000000,
};

/// Used for unbound function points in effect structs.
void stub_effect_delegate(EffectInstance* effectInst) {
}

void set_effect_pos_offset(EffectGraphics* effect, f32 x, f32 y, f32 z) {
    EffectInstanceData* instanceData = effect->freeDelay;

    instanceData->pos.x = x;
    instanceData->pos.y = y;
    instanceData->pos.z = z;
}

void clear_effect_data(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
        gEffectGraphicsData[i].flags = 0;
    }

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        gEffectInstances[i] = 0;
    }

    osUnmapTLBAll();
    osMapTLB(0x10, NULL, _325AD0_VRAM, (s32)&D_801A6000 & 0xFFFFFF, -1, -1);
    dma_copy(_325AD0_ROM_START, _325AD0_ROM_END, _325AD0_VRAM);
}

void func_80059D48(void) {
}

void update_effects(void) {
    if (!(gOverrideFlags & 0xC00)) {
        EffectGraphics* effectGraphics;
        s32 i;

        for (i = 0, effectGraphics = gEffectGraphicsData; i < ARRAY_COUNT(gEffectGraphicsData); i++, effectGraphics++) {
            if (effectGraphics->flags & FX_GRAPHICS_ENABLED) {
                if (!(effectGraphics->flags & FX_GRAPHICS_FLAGS_2)) {
                    effectGraphics->flags |= FX_GRAPHICS_FLAGS_2;
                    effectGraphics->freeDelay = 3;
                }
            }
        }

        for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
            EffectInstance* effectInstance = gEffectInstances[i];

            if (effectInstance != NULL && (effectInstance->flags & EFFECT_INSTANCE_FLAGS_1)) {
                effectInstance->graphics->flags &= ~FX_GRAPHICS_FLAGS_2;

                if (gGameStatusPtr->isBattle) {
                    if (effectInstance->flags & EFFECT_INSTANCE_FLAGS_4) {
                        effectInstance->graphics->update(effectInstance);
                        effectInstance->flags |= EFFECT_INSTANCE_FLAGS_8;
                    }
                } else {
                    if (!(effectInstance->flags & EFFECT_INSTANCE_FLAGS_4)) {
                        effectInstance->graphics->update(effectInstance);
                        effectInstance->flags |= EFFECT_INSTANCE_FLAGS_8;
                    }
                }
            }
        }

        for (i = 0, effectGraphics = gEffectGraphicsData; i < ARRAY_COUNT(gEffectGraphicsData); i++, effectGraphics++) {
            if (effectGraphics->flags & FX_GRAPHICS_ENABLED) {
                if (effectGraphics->flags & FX_GRAPHICS_FLAGS_2) {
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
        if (gEffectInstances[i] != NULL && gEffectInstances[i]->flags & 1 && gEffectInstances[i]->flags & 8) {
            if (gGameStatusPtr->isBattle) {
                if (gEffectInstances[i]->flags & 4) {
                    gEffectInstances[i]->graphics->renderWorld(gEffectInstances[i]);
                }
            } else {
                if (!(gEffectInstances[i]->flags & 4)) {
                    gEffectInstances[i]->graphics->renderWorld(gEffectInstances[i]);
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
            if (effectInstance->flags & EFFECT_INSTANCE_FLAGS_1) {
                if (effectInstance->flags & EFFECT_INSTANCE_FLAGS_8) {
                    void (*renderUI)(EffectInstance* effect);

                    if (gGameStatusPtr->isBattle && !(effectInstance->flags & EFFECT_INSTANCE_FLAGS_4)) {
                        continue;
                    }

                    if (!gGameStatusPtr->isBattle && effectInstance->flags & EFFECT_INSTANCE_FLAGS_4) {
                        continue;
                    }

                    renderUI = effectInstance->graphics->renderUI;
                    if (renderUI != stub_effect_delegate) {
                        if (cond) {
                            Camera* camera = &gCameras[gCurrentCameraID];

                            gDPPipeSync(gMasterGfxPos++);
                            gSPViewport(gMasterGfxPos++, &camera->vp);
                            gSPClearGeometryMode(gMasterGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG |
                                                G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD |
                                                G_SHADING_SMOOTH | G_CLIPPING | 0x40F9FA);
                            gSPSetGeometryMode(gMasterGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
                            gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE,
                                              camera->viewportStartX,
                                              camera->viewportStartY,
                                              camera->viewportStartX + camera->viewportW,
                                              camera->viewportStartY + camera->viewportH);
                            gSPClipRatio(gMasterGfxPos++, FRUSTRATIO_2);

                            cond = FALSE;
                            if (!(camera->flags & 0x10)) {
                                gSPPerspNormalize(gMasterGfxPos++, camera->perspNorm);
                                gSPMatrix(gMasterGfxPos++, &gDisplayContext->camPerspMatrix[gCurrentCameraID],
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
    EffectGraphics* curEffect;
    s32 i;

    // Search for an unused instance
    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        if (gEffectInstances[i] == NULL) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(gEffectInstances));

    // Allocate space for the new instance
    gEffectInstances[i] = newEffectInst = general_heap_malloc(sizeof(EffectInstance));
    ASSERT(newEffectInst != NULL);

    curEffect = &gEffectGraphicsData[0];
    newEffectInst->effectIndex = effectBp->effectID;
    newEffectInst->flags = 1;

    // Look for a loaded effect of the proper index
    for (i = 0; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
        if ((curEffect->flags & EFFECT_LOADED) && (curEffect->effectIndex == effectBp->effectID)) {
            break;
        }
        curEffect++;
    }

    ASSERT(i < ARRAY_COUNT(gEffectGraphicsData));

    // If this is the first new instance of the effect, initialize the function pointers
    if (curEffect->instanceCounter == 0) {
        curEffect->update = effectBp->update;
        if (curEffect->update == NULL) {
            curEffect->renderWorld = stub_effect_delegate;
        }

        curEffect->renderWorld = effectBp->renderWorld;
        if (curEffect->renderUI == NULL) {
            curEffect->renderUI = stub_effect_delegate;
        }

        curEffect->renderUI = effectBp->unk_14;
        if (curEffect->renderUI == NULL) {
            curEffect->renderUI = stub_effect_delegate;
        }
    }

    curEffect->instanceCounter++;
    newEffectInst->graphics = curEffect;

    if (effectBp->init != NULL) {
        effectBp->init(newEffectInst);
    }

    if (gGameStatusPtr->isBattle) {
        newEffectInst->flags |= 4;
    }
    return newEffectInst;
}

void remove_effect(EffectInstance* effectInstsance) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        if (gEffectInstances[i] == effectInstsance) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(gEffectInstances));

    if (effectInstsance->data == NULL) {
        general_heap_free(effectInstsance);
        gEffectInstances[i] = NULL;
    } else {
        general_heap_free(effectInstsance->data);
        general_heap_free(effectInstsance);
        gEffectInstances[i] = NULL;
    }
}

void remove_all_effects(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        EffectInstance* effect = gEffectInstances[i];

        if (effect != NULL && effect->flags & 4) {
            if (effect->data != NULL) {
                general_heap_free(effect->data);
            }
            general_heap_free(effect);
            gEffectInstances[i] = NULL;
        }
    }
}

s32 load_effect(s32 effectIndex) {
    EffectTableEntry* effectEntry = &gEffectTable[effectIndex];
    EffectGraphics* curEffect;
    TlbMappablePage* tlbMappablePages;
    s32 i;

    // Look for a loaded effect matching the desired index
    for (i = 0, curEffect = &gEffectGraphicsData[0]; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
        if (curEffect->flags & EFFECT_LOADED && curEffect->effectIndex == effectIndex) {
            break;
        }
        curEffect++;
    }

    // If an effect was found within the table, initialize it and return
    if (i < ARRAY_COUNT(gEffectGraphicsData)) {
        curEffect->effectIndex = effectIndex;
        curEffect->instanceCounter = 0;
        curEffect->flags = EFFECT_LOADED;
        return 1;
    }

    // If a loaded effect wasn't found, look for the first empty space
    for (i = 0, curEffect = &gEffectGraphicsData[0]; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
        if (!(curEffect->flags & EFFECT_LOADED)) {
            break;
        }
        curEffect++;
    }

    // If no empty space was found, panic
    ASSERT(i < ARRAY_COUNT(gEffectGraphicsData));

    // Map space for the effect
    tlbMappablePages = &D_80197000;
    osMapTLB(i, 0, effectEntry->dmaDest, (s32)((*tlbMappablePages)[i]) & 0xFFFFFF, -1, -1);

    // Copy the effect into the newly mapped space
    dma_copy(effectEntry->dmaStart, effectEntry->dmaEnd, effectEntry->dmaDest);

    // If there's extra data the effect normally loads, allocate space and copy into the new space
    if (effectEntry->graphicsDmaStart != NULL) {
        void* effectDataBuf = general_heap_malloc(effectEntry->graphicsDmaEnd - effectEntry->graphicsDmaStart);
        curEffect->data = effectDataBuf;
        ASSERT(effectDataBuf != NULL);
        dma_copy(effectEntry->graphicsDmaStart, effectEntry->graphicsDmaEnd, curEffect->data);
    }

    // Initialize the newly loaded effect data
    curEffect->effectIndex = effectIndex;
    curEffect->instanceCounter = 0;
    curEffect->flags = EFFECT_LOADED;
    return 1;
}
