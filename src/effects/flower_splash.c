#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000E08_32DCC8[];

void flower_splash_init(EffectInstance* effect);
void flower_splash_update(EffectInstance* effect);
void flower_splash_render(EffectInstance* effect);
void flower_splash_appendGfx(void* effect);

void func_E0010000(FlowerFXData* effect) {
    Matrix4f sp18;
    Matrix4f sp58;

    shim_guRotateF(sp18, effect->unk_24, 1.0f, 0.0f, 0.0f);
    shim_guRotateF(sp58, effect->unk_2C, 0.0f, 0.0f, 1.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guRotateF(sp58, effect->unk_28, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp18, sp58, sp18);
    shim_guScaleF(sp58, effect->unk_18, effect->unk_1C, effect->unk_20);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guTranslateF(sp58, effect->unk_0C, effect->unk_10, effect->unk_14);
    shim_guMtxCatF(sp18, sp58, sp18);
    shim_guMtxF2L(sp18, &effect->unk_30);
}

void func_E0010104(FlowerFXData* effect) {
    effect->unk_70 *= 0.85;
    effect->unk_0C += effect->unk_70 * effect->unk_90;
    effect->unk_88 += effect->unk_8C;
    effect->unk_84 += effect->unk_88;
    effect->unk_80 += effect->unk_84;
    effect->unk_10 += effect->unk_80;
    effect->unk_14 += effect->unk_70 * effect->unk_94;

    if (effect->unk_80 < 0.0f) {
        effect->unk_88 = 0.004f;
    }

    effect->unk_24 -= 1.0f;
    if (effect->unk_24 < -100.0f) {
        effect->unk_24 = -100.0f;
    }
}

void flower_splash_main(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    EffectBlueprint bp;
    EffectInstance* effect;
    FlowerFXData* data;
    s32 numParts = 5;
    f32 angle;
    s32 i;

    bp.init = flower_splash_init;
    bp.update = flower_splash_update;
    bp.renderWorld = flower_splash_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_FLOWER_SPLASH;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;

    data = shim_general_heap_malloc(numParts * sizeof(*data));
    effect->data = data;
    ASSERT(effect->data != NULL);

    shim_mem_clear(data, numParts * sizeof(*data));

    for (i = 0; i < numParts; i++, data++) {
        data->unk_00 = 1;
        data->unk_28 = arg3 + (i * 72);
        data->unk_74 = 0.29999998f;
        data->unk_78 = 0.0f;
        data->unk_7C = 0.0f;
        data->unk_0C = arg0;
        data->unk_10 = arg1;
        data->unk_14 = arg2;
        data->unk_18 = 1.0f;
        data->unk_1C = 1.0f;
        data->unk_20 = 1.0f;
        data->primAlpha = 255;
        data->unk_06 = 60;
        data->unk_24 = 0.0f;
        data->unk_2C = 0.0f;
        data->unk_80 = 1.75f;
        data->unk_84 = -0.08f;
        data->unk_70 = -3.9f;
        data->unk_88 = 0;
        data->unk_8C = 0;
        angle = shim_clamp_angle(data->unk_28);
        data->unk_90 = shim_sin_deg(angle);
        data->unk_94 = shim_cos_deg(angle);
    }
}

void flower_splash_init(EffectInstance* effect) {
}

void flower_splash_update(EffectInstance* effect) {
    FlowerFXData* data = (FlowerFXData*)effect->data;
    s32 cond = FALSE;
    s32 i;

    for (i = 0; i < effect->numParts; i++, data++) {
        if (data->unk_00 != 0) {
            data->unk_06--;
            if (data->unk_06 <= 0) {
                data->unk_00 = 0;
            } else {
                cond = TRUE;
                func_E0010104(data);
                func_E0010000(data);
            }
        }
    }

    if (!cond) {
        shim_remove_effect(effect);
    }
}

void flower_splash_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = flower_splash_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00104F4(EffectInstance* effect) {
    shim_remove_effect(effect);
}

void flower_splash_appendGfx(void* effect) {
    EffectInstance* effectTemp = effect;
    FlowerFXData* data = effectTemp->data;
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->graphics->data));

    for (i = 0; i < effectTemp->numParts; i++, data++) {
        if (data->unk_00 != 0) {
            Gfx* dlist = D_09000E08_32DCC8;

            gDisplayContext->matrixStack[gMatrixListPos] = data->unk_30;

            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 112, 96, 24, data->primAlpha);
            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                        G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMasterGfxPos++, dlist);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        }
    }
    gDPPipeSync(gMasterGfxPos++);
}
