#include "common.h"
#include "effects_internal.h"

extern Gfx D_09002A38_32B8D8[];
extern Gfx D_09002B60_32BA00[];
extern Gfx D_09002B80_32BA20[];

Gfx* D_E003A800[] = {
    D_09002B60_32BA00, D_09002B80_32BA20, D_09002B60_32BA00
};

Gfx* D_E003A80C[] = {
    D_09002A38_32B8D8, D_09002A38_32B8D8, D_09002A38_32B8D8
};

void smoke_impact_init(EffectInstance* effect);
void smoke_impact_update(EffectInstance* effect);
void smoke_impact_render(EffectInstance* effect);
void smoke_impact_appendGfx(void* effect);

void smoke_impact_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    s32 arg5,
    f32 arg6,
    s32 arg7
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    SmokeImpactFXData* part;
    s32 i;

    arg5++;

    bp.init = smoke_impact_init;
    bp.update = smoke_impact_update;
    bp.renderWorld = smoke_impact_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_SMOKE_IMPACT;

    effect = create_effect_instance(&bp);
    effect->numParts = arg5;
    part = effect->data.smokeImpact = general_heap_malloc(arg5 * sizeof(*part));
    ASSERT(effect->data.smokeImpact != NULL);

    mem_clear(part, arg5 * sizeof(*part));

    part->unk_24 = arg7;
    part->unk_28 = 0;
    part->unk_2C = arg7;
    part->unk_30 = 0;
    part->unk_00 = arg0;
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_20 = arg4;
    part->unk_1C = 10.0f;

    part++;
    for (i = 1; i < arg5; i++, part++) {
        f32 angle = arg6 + (i - 1) * 360 / (arg5 - 1);

        part->unk_04 = 0;
        part->unk_08 = 0;
        part->unk_0C = 0;
        part->unk_10 = sin_deg(angle);
        part->unk_14 = 0;
        part->unk_18 = cos_deg(angle);
    }
}

void smoke_impact_init(EffectInstance* effect) {
}

void smoke_impact_update(EffectInstance* effect) {
    SmokeImpactFXData* part = effect->data.smokeImpact;
    f32 unk_1C;
    s32 i;

    part->unk_30 = part->unk_28 * 8.0f / part->unk_2C;
    part->unk_28++;
    part->unk_24--;

    if (part->unk_24 < 0) {
        remove_effect(effect);
        return;
    }

    part->unk_1C += (part->unk_20 - part->unk_1C) * 0.1;
    unk_1C = part->unk_1C;

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        part->unk_14 += 0.04;
        part->unk_14 *= 0.9;
        part->unk_04 = unk_1C * part->unk_10;
        part->unk_08 += part->unk_14;
        part->unk_0C = unk_1C * part->unk_18;
    }
}

void smoke_impact_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = smoke_impact_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_PASS_THROUGH;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void smoke_impact_appendGfx(void* effect) {
    SmokeImpactFXData* part = ((EffectInstance*)effect)->data.smokeImpact;
    s32 unk_00 = part->unk_00;
    f32 unk_30 = part->unk_30;
    s32 unk_30_s32 = unk_30;
    s32 envAlpha = (unk_30 - unk_30_s32) * 256.0f;
    Gfx* dlist = D_E003A800[unk_00];
    Gfx* dlist2 = D_E003A80C[unk_00];
    s32 cond = (unk_30_s32 == 7);
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, dlist2);

    guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
    guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp98);
    guMtxF2L(sp98, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    if (unk_00 < 2) {
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 230, 222, 222, 130);
    } else {
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 40, 10, 160);
        gDPSetAlphaCompare(gMainGfxPos++, G_AC_DITHER);
    }

    gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, envAlpha);
    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE,
        (unk_30_s32 * 32     ) * 4, 0,
        (unk_30_s32 * 32 + 32) * 4, 32 * 4);

    if (cond) {
        gDPSetTileSize(gMainGfxPos++, 1,
            (unk_30_s32 * 32 + 32) * 4, 32 * 4,
            (unk_30_s32 * 32 + 64) * 4, 64 * 4);
    } else {
        gDPSetTileSize(gMainGfxPos++, 1,
            (unk_30_s32 * 32 + 32) * 4, 0,
            (unk_30_s32 * 32 + 64) * 4, 32 * 4);
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

    if (unk_00 == 2) {
        gDPSetAlphaCompare(gMainGfxPos++, G_AC_NONE);
    }

    gDPPipeSync(gMainGfxPos++);
}
