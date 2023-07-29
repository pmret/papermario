#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000440_360E70[];
extern Gfx D_090004F0_360F20[];

void stars_spread_init(EffectInstance* effect);
void stars_spread_update(EffectInstance* effect);
void stars_spread_render(EffectInstance* effect);
void stars_spread_appendGfx(void* effect);

void stars_spread_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    s32 arg4,
    s32 arg5
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    StarsSpreadFXData* part;
    s32 i;

    arg4++;

    bp.init = stars_spread_init;
    bp.update = stars_spread_update;
    bp.renderWorld = stars_spread_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_STARS_SPREAD;

    effect = create_effect_instance(&bp);
    effect->numParts = arg4;
    part = effect->data.starsSpread = general_heap_malloc(arg4 * sizeof(*part));
    ASSERT(effect->data.starsSpread != NULL);

    mem_clear(part, arg4 * sizeof(*part));

    part->unk_24 = arg5;
    part->unk_28 = 0;
    part->unk_2C = arg5;
    part->unk_00 = arg0;
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;

    part++;
    for (i = 1; i < arg4; i++, part++) {
        part->unk_04 = 0;
        part->unk_08 = 0;
        part->unk_0C = 0;
        part->unk_10 = sin_deg((i - 1) * 360 / (arg4 - 1)) * 8.0;
        part->unk_14 = cos_deg((i - 1) * 360 / (arg4 - 1)) * 8.0;
        part->unk_18 = 0;
        part->unk_1C = 0;
        part->unk_20 = 20.0f;
        part->unk_30 = 1.0f;
    }
}

void stars_spread_init(EffectInstance* effect) {
}

void stars_spread_update(EffectInstance* effect) {
    StarsSpreadFXData* part = effect->data.starsSpread;
    s32 unk_24;
    s32 unk_2C;
    s32 i;

    part->unk_28++;
    part->unk_24--;

    if (part->unk_24 < 0) {
        remove_effect(effect);
        return;
    }

    unk_24 = part->unk_24;
    unk_2C = part->unk_2C;

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        if (unk_24 >= 6) {
            part->unk_10 *= 0.8;
            part->unk_14 *= 0.8;
            part->unk_18 *= 0.8;
        }

        if (unk_24 < 5) {
            part->unk_20 *= 0.8;
            part->unk_10 *= 0.7;
            part->unk_14 *= 0.7;
            part->unk_18 *= 0.7;
        }

        if (unk_24 * 2 < unk_2C) {
            part->unk_30 += -part->unk_30 * 0.2;
        }

        part->unk_04 += part->unk_10;
        part->unk_08 += part->unk_14;
        part->unk_0C = 0;
        part->unk_1C += part->unk_20;
    }
}

void stars_spread_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = stars_spread_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void stars_spread_appendGfx(void* effect) {
    StarsSpreadFXData* part = ((EffectInstance*)effect)->data.starsSpread;
    Gfx* dlist = D_090004F0_360F20;
    Matrix4f sp18;
    Matrix4f sp58;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_09000440_360E70);

    guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
    guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 220, 220, 40, 230);

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
        guRotateF(sp58, part->unk_1C, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp58, sp18, sp18);
        guScaleF(sp58, part->unk_30, part->unk_30, 1.0f);
        guMtxCatF(sp58, sp18, sp18);
        guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, dlist);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
