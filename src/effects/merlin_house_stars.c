#include "common.h"
#include "effects_internal.h"

extern Gfx D_09001000_3A6BE0[];
extern Gfx D_09001418_3A6FF8[];

void merlin_house_stars_init(EffectInstance* effect);
void merlin_house_stars_update(EffectInstance* effect);
void merlin_house_stars_render(EffectInstance* effect);
void merlin_house_stars_appendGfx(void* effect);

EffectInstance* merlin_house_stars_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    EffectBlueprint bp;
    EffectInstance* effect;
    MerlinHouseStarsFXData* data;
    s32 numParts = 1;

    bp.init = merlin_house_stars_init;
    bp.update = merlin_house_stars_update;
    bp.renderScene = merlin_house_stars_render;
    bp.unk_00 = 0;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_MERLIN_HOUSE_STARS;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.merlinHouseStars = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.merlinHouseStars != nullptr);

    data->unk_04 = 100;
    data->unk_00 = arg0;
    data->alpha = 255;
    data->unk_0C = arg1;
    data->unk_10 = arg2;
    data->unk_14 = arg3;
    data->unk_08 = 0;
    data->unk_1C = data->unk_20 = 0.0f;
    data->unk_24 = data->unk_28 = 0.0f;
    data->unk_2C = 1.2f;
    data->unk_30 = 0.4f;
    data->unk_34 = -1.0f;
    data->unk_38 = 0.4f;

    return effect;
}

void merlin_house_stars_init(EffectInstance* effect) {
}

void merlin_house_stars_update(EffectInstance* effect) {
    MerlinHouseStarsFXData* data = effect->data.merlinHouseStars;
    s32 unk_04;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->unk_04 = 30;
    }

    if (data->unk_04 < 100) {
        data->unk_04--;
    }

    data->unk_08++;

    if (data->unk_04 < 0) {
        remove_effect(effect);
        return;
    }

    data->unk_1C += data->unk_2C;
    data->unk_20 += data->unk_30;
    data->unk_24 += data->unk_34;
    data->unk_28 += data->unk_38;

    unk_04 = data->unk_04;

    if (data->unk_08 < 17) {
        data->alpha = data->unk_08 * 16 - 1;
    }

    if (unk_04 < 16) {
        data->alpha = unk_04 * 16;
    }

    if (data->unk_1C < 0.0f) {
        data->unk_1C += 128.0f;
    } else if (data->unk_1C > 128.0f) {
        data->unk_1C -= 128.0f;
    }

    data->unk_20 += data->unk_30;
    if (data->unk_20 < 0.0f) {
        data->unk_20 += 128.0f;
    } else if (data->unk_20 > 128.0f) {
        data->unk_20 -= 128.0f;
    }

    data->unk_24 += data->unk_34;
    if (data->unk_24 < 0.0f) {
        data->unk_24 += 128.0f;
    } else if (data->unk_24 > 128.0f) {
        data->unk_24 -= 128.0f;
    }

    data->unk_28 += data->unk_38;
    if (data->unk_28 < 0.0f) {
        data->unk_28 += 128.0f;
    } else if (data->unk_28 > 128.0f) {
        data->unk_28 -= 128.0f;
    }
}

void merlin_house_stars_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = merlin_house_stars_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00A639C(void) {
}

#define PM_CC1_MERLIN_STARS     0, 0, 0, 1, TEXEL1, 0, PRIMITIVE, TEXEL0
#define PM_CC2_MERLIN_STARS     0, 0, 0, COMBINED, COMBINED, 0, ENVIRONMENT, 0

void merlin_house_stars_appendGfx(void* effect) {
    MerlinHouseStarsFXData* data = ((EffectInstance*)effect)->data.merlinHouseStars;
    s32 envAlpha = data->alpha;
    Matrix4f sp10;
    Matrix4f sp50;
    s32 uls;
    s32 ult;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

    guTranslateF(sp10, data->unk_0C, data->unk_10, data->unk_14);
    guScaleF(sp50, 0.96f, 0.96f, 0.96f);
    guMtxCatF(sp50, sp10, sp10);
    guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, 127);
    gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, envAlpha);
    gDPSetCombineMode(gMainGfxPos++, PM_CC1_MERLIN_STARS, PM_CC2_MERLIN_STARS);
    gSPDisplayList(gMainGfxPos++, D_09001000_3A6BE0);

    uls = data->unk_1C * 4.0f;
    ult = data->unk_20 * 4.0f;
    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, uls, ult, uls + 252, ult + 252);

    uls = data->unk_24 * 4.0f;
    ult = data->unk_28 * 4.0f;
    gDPSetTileSize(gMainGfxPos++, 1, uls, ult, uls + 252, ult + 252);

    gSPDisplayList(gMainGfxPos++, D_09001418_3A6FF8);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
