#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000C00_341480[];
extern Gfx D_09001068_3418E8[];
extern Gfx D_09001080_341900[];
extern Gfx D_09001098_341918[];
extern Gfx D_090010B8_341938[];
extern Gfx D_090010D0_341950[];
extern Gfx D_090010E8_341968[];
extern Gfx D_09001108_341988[];
extern Gfx D_09001120_3419A0[];
extern Gfx D_09001138_3419B8[];

Gfx* D_E002C940[] = {
    D_09001138_3419B8, D_09001120_3419A0, D_09001108_341988,
    D_090010E8_341968, D_090010D0_341950, D_090010B8_341938,
    D_09001098_341918, D_09001080_341900, D_09001068_3418E8
};

f32 D_E002C964[] = {
    -1.0f, -0.5f, 0.5f, 1.0f, -1.0f, -0.5f, 0.5f, 1.0f
};

f32 D_E002C984[][2] = {
    { -5.0f, -4.0f },
    { -3.0f, -2.0f },
    {  2.0f, -3.0f },
    {  5.0f, -4.0f },
    { -4.0f,  2.0f },
    { -1.0f,  4.0f },
    {  3.0f,  2.0f },
    {  5.0f,  4.0f }
};

void shattering_stones_init(EffectInstance* effect);
void shattering_stones_update(EffectInstance* effect);
void shattering_stones_render(EffectInstance* effect);
void shattering_stones_appendGfx(void* effect);

void shattering_stones_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    EffectBlueprint bp;
    EffectInstance* effect;
    ShatteringStonesFXData* part;
    s32 numParts = 9;
    s32 i;

    bp.init = shattering_stones_init;
    bp.update = shattering_stones_update;
    bp.renderWorld = shattering_stones_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_SHATTERING_STONES;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    part = effect->data.shatteringStones = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.shatteringStones != NULL);

    part->unk_24 = 0;
    part->unk_00 = arg1;
    part->unk_04 = arg2;
    part->unk_0C = arg4;
    part->unk_08 = arg3;
    part->unk_2C = 0;
    part->unk_30 = 0;
    part->unk_14 = -2.0f;
    part->unk_34 = rand_int(60) - 30;
    part->unk_28 = 255;
    part->unk_38 = rand_int(60) - 30;
    part->unk_3C = part->unk_38 * 0.25;
    part->unk_20 = 20;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        part->unk_18 = D_E002C984[i - 1][0];
        part->unk_1C = D_E002C984[i - 1][1];
        part->unk_00 = 0;
        part->unk_04 = 0;
        part->unk_08 = 0;
        part->unk_10 = D_E002C964[i - 1] * 2.0f;
        part->unk_14 = (f32) rand_int(10) * 0.1 * 2.0 + 1.0;
        part->unk_2C = 0;
        part->unk_34 = 0;
    }
}

void shattering_stones_init(EffectInstance* effect) {
}

void shattering_stones_update(EffectInstance* effect) {
    ShatteringStonesFXData* part = effect->data.shatteringStones;
    s32 i;

    if (part->unk_24 == 0) {
        part->unk_14 += -0.1;
        part->unk_04 += part->unk_14;
        part->unk_2C += part->unk_38;
        part->unk_30 += part->unk_3C;
        if (part->unk_04 <= part->unk_0C) {
            part->unk_24 = 1;
        }
    }

    if (part->unk_24 == 1) {
        part->unk_20--;
        if (part->unk_20 < 0) {
            remove_effect(effect);
            return;
        }

        if (part->unk_20 < 10) {
            part->unk_28 *= 0.8;
        }

        part++;
        for (i = 1; i < effect->numParts; i++, part++) {
            part->unk_14 += -0.2;
            part->unk_10 *= 0.9;
            part->unk_00 += part->unk_10;
            part->unk_04 += part->unk_14;
            part->unk_2C += 10.0f;
            part->unk_34 += 20.0f;
        }
    }
}

void shattering_stones_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = shattering_stones_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void shattering_stones_appendGfx(void* effect) {
    ShatteringStonesFXData* part = ((EffectInstance*)effect)->data.shatteringStones;
    Matrix4f sp20;
    Matrix4f sp60;
    Matrix4f spA0;
    Matrix4f spE0;
    s32 i;

    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_09000C00_341480);

    if (part->unk_24 == 0) {
        guTranslateF(sp20, part->unk_00, part->unk_04, part->unk_08);
        guScaleF(sp60, 1.5f, 1.5f, 1.5f);
        guMtxCatF(sp60, sp20, spA0);
        guRotateF(sp60, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp60, spA0, spA0);
        guRotateF(sp60, part->unk_34, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp60, spA0, spA0);
        guRotateF(sp60, part->unk_2C, 1.0f, 0.0f, 0.0f);
        guMtxCatF(sp60, spA0, spA0);
        guRotateF(sp60, part->unk_30, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp60, spA0, spA0);
        guMtxF2L(spA0, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 102, 109, 123, part->unk_28);
        gSPDisplayList(gMainGfxPos++, D_E002C940[0]);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    } else {
        s32 unk_28 = part->unk_28;

        guTranslateF(sp20, part->unk_00, part->unk_04, part->unk_08);
        guScaleF(sp60, 1.5f, 1.5f, 1.5f);
        guMtxCatF(sp60, sp20, spA0);
        guRotateF(sp60, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp60, spA0, spA0);
        guRotateF(spE0, part->unk_2C, 1.0f, 0.0f, 0.0f);

        part++;
        for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
            Gfx* dlist = D_E002C940[i];

            guTranslateF(sp60, part->unk_00, part->unk_04, part->unk_08);
            guMtxCatF(sp60, spA0, sp20);
            guMtxCatF(spE0, sp20, sp20);
            guPositionF(sp60, part->unk_2C, 0.0f, part->unk_34, 1.0f, part->unk_18, part->unk_1C, 0.0f);
            guMtxCatF(sp60, sp20, sp20);
            guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 150, 150, 200, unk_28);
            gSPDisplayList(gMainGfxPos++, dlist);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }
}
