#include "common.h"
#include "effects_internal.h"

extern Gfx D_090002C0_392700[];
extern Gfx D_09000330_392770[];
extern Gfx D_09000370_3927B0[];
extern Gfx D_090003B0_3927F0[];
extern Gfx D_090003F0_392830[];
extern Gfx D_09000430_392870[];
extern Gfx D_09000470_3928B0[];

static Gfx* sDlists[] = { D_09000430_392870, D_090003F0_392830, D_090003B0_3927F0, D_09000370_3927B0, D_09000330_392770 };

static s32 sPartParams[4 * 5] = {
    1, 0, 0, 0, 100,
    2, 4, -2, 0, 100,
    3, -2, 2, 0, 70,
    4, 2, 4, 0, 40,
};

void small_gold_sparkle_init(EffectInstance* effect);
void small_gold_sparkle_update(EffectInstance* effect);
void small_gold_sparkle_render(EffectInstance* effect);
void small_gold_sparkle_appendGfx(void* effect);

EffectInstance* small_gold_sparkle_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    EffectBlueprint bp;
    EffectInstance* effect;
    SmallGoldSparkleFXData* data;
    SmallGoldSparkleFXData* part;
    s32 numParts = 5;
    s32 i;

    bp.init = small_gold_sparkle_init;
    bp.update = small_gold_sparkle_update;
    bp.renderScene = small_gold_sparkle_render;
    bp.unk_00 = 0;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_SMALL_GOLD_SPARKLE;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;

    data = general_heap_malloc(numParts * sizeof(*data));
    effect->data.smallGoldSparkle = data;
    part = data;

    ASSERT(data != nullptr);

    part->unk_00 = arg0;
    part->unk_18 = 0;
    part->unk_14 = 14;
    part->unk_08 = arg1;
    part->unk_0C = arg2;
    part->unk_10 = arg3;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        part->unk_08 = sPartParams[1 + (i - 1) * 5];
        part->unk_0C = sPartParams[2 + (i - 1) * 5];
        part->unk_10 = sPartParams[3 + (i - 1) * 5];
        part->unk_04 = -1;
        part->unk_20 = sPartParams[0 + (i - 1) * 5];
        part->unk_1C = (arg4 * sPartParams[4 + (i - 1) * 5]) * 0.01;
    }
    return effect;
}

void small_gold_sparkle_init(EffectInstance* effect) {
}

void small_gold_sparkle_update(EffectInstance* effect) {
    SmallGoldSparkleFXData* part = effect->data.smallGoldSparkle;
    s32 i;

    part->unk_14--;
    part->unk_18++;

    if (part->unk_14 < 0) {
        remove_effect(effect);
        return;
    }

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        if (part->unk_20 > 0) {
            part->unk_20--;
        }

        if (part->unk_20 <= 0) {
            part->unk_04++;
            if (part->unk_04 >= 10) {
                part->unk_20 = -1;
            }
        }
    }
}

void small_gold_sparkle_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = small_gold_sparkle_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void small_gold_sparkle_appendGfx(void* effect) {
    SmallGoldSparkleFXData* part = ((EffectInstance*)effect)->data.smallGoldSparkle;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    Mtx* spD8;
    s32 i;

    guRotateF(sp98, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxF2L(sp98, &gDisplayContext->matrixStack[gMatrixListPos]);
    spD8 = &gDisplayContext->matrixStack[gMatrixListPos++];
    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));
    guTranslateF(sp18, part->unk_08, part->unk_0C, part->unk_10);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, D_090002C0_392700);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 15, 255);

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        if (part->unk_20 == 0) {
            f32 temp_f20 = part->unk_1C;

            guTranslateF(sp18, part->unk_08, part->unk_0C, part->unk_10);
            if (temp_f20 != 1.0f) {
                guScaleF(sp58, temp_f20, temp_f20, 1.0f);
                guMtxCatF(sp58, sp18, sp18);
            }
            guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);
            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                      G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPMatrix(gMainGfxPos++, spD8, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, sDlists[part->unk_04 >> 1]);
            gSPDisplayList(gMainGfxPos++, D_09000470_3928B0);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
