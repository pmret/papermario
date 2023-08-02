#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000DC0_3762D0[];
extern Gfx D_09000E60_376370[];

void energy_shockwave_init(EffectInstance* effect);
void energy_shockwave_update(EffectInstance* effect);
void energy_shockwave_render(EffectInstance* effect);
void energy_shockwave_appendGfx(void* effect);

void energy_shockwave_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    s32 arg5
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    EnergyShockwaveFXData* data;
    s32 numParts = 31;

    bp.init = energy_shockwave_init;
    bp.update = energy_shockwave_update;
    bp.renderWorld = energy_shockwave_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_ENERGY_SHOCKWAVE;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.energyShockwave = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.energyShockwave != NULL);

    data->unk_00 = arg0;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_20 = arg4 * 0.1;
    data->unk_24 = 255;
    data->unk_28 = arg5;
    data->unk_2C = 0;
    data->unk_30 = 0;
    data->unk_34 = 0;
    data->unk_38 = 0;
    data->unk_3C = 0;
    data->unk_40 = -1.1f;
    data->unk_44 = 0;
    data->unk_48 = 0.4f;
    data->unk_4C = 1.0f;
    data->unk_1C = 0;
    data->unk_50 = 255;
    data->unk_51 = 255;
    data->unk_52 = 64;
}

void energy_shockwave_init(EffectInstance* effect) {
}

EFFECT_DEF_SHIMMER_WAVE(shimmer_wave_main);

void energy_shockwave_update(EffectInstance* effect) {
    EnergyShockwaveFXData* data = effect->data.energyShockwave;
    s32 unk_28;
    s32 unk_2C;
    f32 angle;

    data->unk_28--;
    data->unk_2C++;

    unk_28 = data->unk_28;
    unk_2C = data->unk_2C;

    if (unk_28 < 0) {
        remove_effect(effect);
        return;
    }

    if (unk_2C % 2) {
        angle = func_E0200044(360, unk_2C);
        sin_deg(angle);
        cos_deg(angle);
        load_effect(EFFECT_SHIMMER_WAVE);
        shimmer_wave_main(0, data->unk_04, data->unk_08, data->unk_0C, unk_2C * 8, 10.0f, 10, 20);
    }

    data->unk_1C += data->unk_20;

    if (unk_28 < 10) {
        data->unk_24 = unk_28 * 25;
    }

    data->unk_30 += data->unk_40;
    data->unk_34 += data->unk_44;
    data->unk_38 += data->unk_48;
    data->unk_3C += data->unk_4C;

    if (data->unk_30 > 128.0f) {
        data->unk_30 -= 128.0f;
    }
    if (data->unk_34 > 128.0f) {
        data->unk_34 -= 128.0f;
    }
    if (data->unk_38 > 128.0f) {
        data->unk_38 -= 128.0f;
    }
    if (data->unk_3C > 128.0f) {
        data->unk_3C -= 128.0f;
    }

    if (data->unk_30 < 0.0f) {
        data->unk_30 += 128.0f;
    }
    if (data->unk_34 < 0.0f) {
        data->unk_34 += 128.0f;
    }
    if (data->unk_38 < 0.0f) {
        data->unk_38 += 128.0f;
    }
    if (data->unk_3C < 0.0f) {
        data->unk_3C += 128.0f;
    }
}

void energy_shockwave_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = energy_shockwave_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void energy_shockwave_appendGfx(void* effect) {
    EnergyShockwaveFXData* data = ((EffectInstance*)effect)->data.energyShockwave;
    Matrix4f sp10;
    Matrix4f sp50;
    s32 uls;
    s32 ult;
    s32 uls2;
    s32 ult2;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_09000E60_376370);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 179, 30, data->unk_24);
    gDPSetEnvColor(gMainGfxPos++, data->unk_50, data->unk_51, data->unk_52, 128);

    uls = data->unk_30 * 4;
    ult = data->unk_34 * 4;
    uls2 = data->unk_38 * 4;
    ult2 = data->unk_3C * 4;

    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, uls, ult, uls + 252, ult + 252);
    gDPSetTileSize(gMainGfxPos++, 1, uls2, ult2, uls2 + 124, ult2 + 124);

    guTranslateF(sp10, data->unk_04, data->unk_08, data->unk_0C);
    guScaleF(sp50, data->unk_1C, data->unk_1C, data->unk_1C);
    guMtxCatF(sp50, sp10, sp10);
    guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, D_09000DC0_3762D0);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
