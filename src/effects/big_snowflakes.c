#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000900_3641C0[];
extern Gfx D_090009E8_3642A8[];
extern Gfx D_09000A10_3642D0[];

Gfx* D_E0060730[] = { D_090009E8_3642A8, D_09000A10_3642D0 };
Gfx* D_E0060738[] = { D_09000900_3641C0, D_09000900_3641C0 };

void big_snowflakes_init(EffectInstance* effect);
void big_snowflakes_update(EffectInstance* effect);
void big_snowflakes_render(EffectInstance* effect);
void big_snowflakes_appendGfx(void* effect);

void big_snowflakes_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    EffectBlueprint bp;
    EffectInstance* effect;
    BigSnowflakesFXData* data;
    s32 numParts = 9;
    s32 i;

    bp.unk_00 = 0;
    bp.init = big_snowflakes_init;
    bp.update = big_snowflakes_update;
    bp.renderWorld = big_snowflakes_render;
    bp.unk_14 = 0;
    bp.effectID = EFFECT_BIG_SNOWFLAKES;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;

    data = shim_general_heap_malloc(effect->numParts * sizeof(*data));
    effect->data.bigSnowflakes = data;

    ASSERT(data != NULL);

    shim_mem_clear(data, numParts * sizeof(*data));
    data->unk_00 = arg0;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_28 = 30;
    data->unk_2C = 0;
    data->unk_24 = 0;

    data++;
    for (i = 1; i < numParts; i++, data++) {
        data->unk_04 = func_E0200000(10) - 5;
        data->unk_08 = func_E0200000(10) + 5;
        data->unk_0C = 10.0f;
        data->unk_18 = func_E0200000(360);
        data->unk_20 = func_E0200000(360);
        data->unk_1C = func_E0200000(100) / 10;
        data->unk_10 = 0;
        data->unk_14 = 2.0f;
    }
}

void big_snowflakes_init(EffectInstance* effect) {
}

void big_snowflakes_update(EffectInstance* effect) {
    BigSnowflakesFXData* data = effect->data.bigSnowflakes;
    s32 unk_28;
    s32 i;

    data->unk_28--;
    data->unk_2C++;
    if (data->unk_28 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_28 = data->unk_28;
    if (data->unk_2C < 10) {
        data->unk_24 += (255 - data->unk_24) * 0.3;
    }
    if (unk_28 < 10) {
        data->unk_24 *= 0.8;
    }

    data++;
    for (i = 1; i < effect->numParts; i++, data++) {
        data->unk_10 += (f32) (shim_sin_deg(2.0f * data->unk_18) * 0.2);
        data->unk_14 += -0.05f;
        data->unk_10 *= 0.92;
        data->unk_14 += -0.05f;
        data->unk_1C += func_E0200044(50, unk_28 + (i * 20)) - 25;
        data->unk_18 += shim_sin_deg(data->unk_1C) * 10.0f;
        data->unk_20 += shim_cos_deg(data->unk_1C * 0.5f) * 10.0f;
        data->unk_04 += data->unk_10;
        data->unk_08 += data->unk_14;
    }
}

void big_snowflakes_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = big_snowflakes_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void big_snowflakes_appendGfx(void* effect) {
    BigSnowflakesFXData* data = ((EffectInstance*)effect)->data.bigSnowflakes;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    Gfx* dlist = D_E0060738[0];
    s32 i;

    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, dlist);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 20, 100, 20, data->unk_24);

    shim_guTranslateF(sp18, data->unk_04, data->unk_08, data->unk_0C);
    shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp58, sp18, sp98);

    data++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, data++) {
        Gfx* dlist2 = D_E0060730[i & 1]; // should be able to be i % 2 (ARRAY_COUNT(D_E0060730))

        shim_guTranslateF(sp58, data->unk_04, data->unk_08, data->unk_0C);
        shim_guMtxCatF(sp58, sp98, sp18);

        if (!(i & 1)) {
            shim_guRotateF(sp58, data->unk_18, 0.0f, 0.0f, 1.0f);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guRotateF(sp58, data->unk_20, 0.0f, 1.0f, 0.0f);
            shim_guMtxCatF(sp58, sp18, sp18);
        }
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, dlist2);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }
}
