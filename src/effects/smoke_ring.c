#include "common.h"
#include "effects_internal.h"

extern Gfx D_09002950_32B7F0[];
extern Gfx D_09002B40_32B9E0[];
extern Gfx D_09002B60_32BA00[];

s8 D_E002E740[] = {
    0,  1, 2, 26,  3, 27,  4,  28,
    5, 29, 6, 22, 38, 71, 87, 103, -1
};

s8* D_E002E754[] = { D_E002E740 };

void smoke_ring_init(EffectInstance* effect);
void smoke_ring_update(EffectInstance* effect);
void smoke_ring_render(EffectInstance* effect);
void smoke_ring_appendGfx(void* effect);

void smoke_ring_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    SmokeRingFXData* part;
    s32 numParts;
    f32 factor;
    s32 i;

    switch (arg0) {
        case 0:
            numParts = 7;
            factor = 14.0f;
            break;
        case 1:
            numParts = 9;
            factor = 28.0f;
            break;
        default:
            numParts = 11;
            factor = 42.0f;
            break;
    }

    bpPtr->init = smoke_ring_init;
    bpPtr->update = smoke_ring_update;
    bpPtr->renderWorld = smoke_ring_render;
    bpPtr->unk_00 = 0;
    bpPtr->renderUI = NULL;
    bpPtr->effectID = EFFECT_SMOKE_RING;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    part = effect->data.smokeRing = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.smokeRing != NULL);

    mem_clear(part, numParts * sizeof(*part));

    part->unk_38 = 0;
    part->unk_3C = 0;
    part->unk_00 = arg0;
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        f32 angle = (i - 1) * 360 / (numParts - 1);

        part->unk_10 = -3.0f;
        part->unk_14 = 0.19999999f;
        part->unk_18 = 0;
        part->unk_1C = 0;
        part->unk_20 = 1.75f;
        part->unk_24 = -0.16f;
        part->unk_28 = 0;
        part->unk_2C = 0;
        part->unk_04 = -sin_deg(angle) * factor;
        part->unk_08 = -cos_deg(angle) * factor;
        part->unk_0C = 0;
        part->unk_30 = sin_deg(angle);
        part->unk_34 = cos_deg(angle);
    }
}

void smoke_ring_init(EffectInstance* effect) {
}

void smoke_ring_update(EffectInstance* effect) {
    SmokeRingFXData* part = effect->data.smokeRing;
    s32 i;

    part->unk_40 = D_E002E754[part->unk_38][part->unk_3C++];

    if (part->unk_40 < 0) {
        remove_effect(effect);
        return;
    }

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        part->unk_18 += part->unk_1C;
        part->unk_14 += part->unk_18;
        part->unk_10 += part->unk_14;
        part->unk_04 += part->unk_10 * part->unk_30;
        part->unk_08 += part->unk_10 * part->unk_34;
    }
}

void smoke_ring_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = smoke_ring_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = queue_render_task(&renderTask);
}

void smoke_ring_appendGfx(void* effect) {
    SmokeRingFXData* part = ((EffectInstance*)effect)->data.smokeRing;
    s32 temp_s5 = part->unk_40 & 7;
    s32 envAlpha = (part->unk_40 & 0x38) * 4;
    s32 spD8 = part->unk_40 & 0x40;
    s32 temp_a3;
    Gfx* dlist;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    s32 i;

    if (part->unk_00 != 0) {
        dlist = D_09002B60_32BA00;
    } else {
        dlist = D_09002B40_32B9E0;
    }

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_09002950_32B7F0);

    guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
    guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp98);
    guMtxF2L(sp98, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 238, 220, 215, 160);
    gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, envAlpha);
    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE,
        (temp_s5 * 32       ) * 4, 0,
        (temp_s5 * 32 + 0x1F) * 4, 31 * 4);

    temp_a3 = temp_s5 * 32 + 32;

    if (spD8 != 0) {
        gDPSetTileSize(gMainGfxPos++, 1,
            (temp_a3     ) * 4, 32 * 4,
            (temp_a3 + 31) * 4, 63 * 4);
    } else {
        gDPSetTileSize(gMainGfxPos++, 1,
            (temp_a3     ) * 4, 0,
            (temp_a3 + 31) * 4, 31 * 4);
    }

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
        guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, dlist);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
