#include "common.h"
#include "effects_internal.h"

extern Gfx D_09001000_3A5320[];
extern Gfx D_090010A8_3A53C8[];
extern Gfx D_090011D0_3A54F0[];
extern Gfx D_090011F0_3A5510[];
extern Gfx D_09001210_3A5530[];

void energy_orb_wave_init(EffectInstance* effect);
void energy_orb_wave_update(EffectInstance* effect);
void energy_orb_wave_render(EffectInstance* effect);
void energy_orb_wave_appendGfx(void* effect);

EffectInstance* energy_orb_wave_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    EnergyOrbWaveFXData* data;
    s32 numParts = 1;

    bp.init = energy_orb_wave_init;
    bp.update = energy_orb_wave_update;
    bp.renderScene = energy_orb_wave_render;
    bp.unk_00 = 0;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_ENERGY_ORB_WAVE;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.energyOrbWave = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.energyOrbWave != nullptr);

    data->unk_00 = arg0;
    data->unk_14 = 0;
    if (arg5 <= 0) {
        data->unk_10 = 100;
    } else {
        data->unk_10 = arg5;
    }
    data->unk_2C = 0;
    data->pos.x = arg1;
    data->pos.y = arg2;
    data->pos.z = arg3;
    data->scale = arg4;
    data->unk_18 = 0;

    switch (arg0) {
        case 0:
            data->unk_1C = 0;
            break;
        case 1:
            data->unk_1C = 2;
            break;
        case 2:
            data->unk_1C = 4;
            break;
        case 3:
            data->unk_1C = 6;
            break;
        case 4:
            data->unk_1C = 7;
            break;
        case 5:
            data->unk_1C = 8;
            break;
        case 6:
            data->unk_1C = 9;
            break;
        default:
            data->unk_1C = 10;
            data->unk_34 = -(arg4 - 0.1) / arg5;
            break;
    }

    return effect;
}

void energy_orb_wave_init(EffectInstance* effect) {
}

void energy_orb_wave_update(EffectInstance* effect) {
    EnergyOrbWaveFXData* data = effect->data.energyOrbWave;
    f32 var_float;
    s32 unk_14;
    s32 var_2;
    s32 var_1;
    s32 unk_1C;
    u16 var_4;
    s32 var_3;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->unk_10 = 30;
    }

    if (data->unk_10 < 100) {
        data->unk_10--;
    }
    data->unk_14++;

    if (data->unk_10 < 0) {
        remove_effect(effect);
        return;
    }

    unk_14 = data->unk_14;
    unk_1C = data->unk_1C;
    var_1 = 0xFF;
    var_2 = 0xFF;

    if (unk_14 < 16) {
        var_1 = (unk_14 * 16) - 1;
    }
    if (data->unk_10 < 16) {
        var_1 = var_1 * data->unk_10 / 16;
        var_2 = data->unk_10 * 16;
    }

    switch (unk_1C) {
        case 0:
            data->unk_20 = 70;
            data->unk_24 = 180;
            data->unk_28 = 120;
            var_float = sin_deg(unk_14 * 2) * 10.0f + 190.0f;
            data->unk_2C = ((s32) var_float * var_1) / 255;
            break;
        case 1:
            var_3 = 255;
            data->unk_20 = 70;
            data->unk_24 = 255;
            data->unk_28 = 230;
            data->unk_2C = (var_1 * var_3) / 255;
            break;
        case 2:
            data->unk_20 = 170;
            data->unk_24 = 40;
            data->unk_28 = 110;
            var_float = sin_deg(unk_14 * 2) * 10.0f + 190.0f;
            data->unk_2C = ((s32) var_float * var_1) / 255;
            break;
        case 3:
            var_4 = 255;
            data->unk_20 = 220;
            data->unk_24 = 40;
            data->unk_28 = 170;
            data->unk_2C = (var_1 * var_4) / 255;
            break;
        case 4:
            data->unk_20 = 235;
            data->unk_24 = 235;
            data->unk_28 = 200;
            var_float = sin_deg(unk_14 * 2) * 15.0f + 215.0f;
            data->unk_2C = ((s32) var_float * var_1) / 255;
            break;
        case 5:
            var_4 = 255;
            data->unk_20 = 235;
            data->unk_24 = 235;
            data->unk_28 = 200;
            data->unk_2C = (var_1 * var_4) / 255;
            break;
        case 6:
            var_4 = 127;
            data->unk_20 = 70;
            data->unk_24 = 180;
            data->unk_28 = 120;
            data->unk_2C = (var_2 * var_4) / 255;
            data->scale *= 1.1;
            break;
        case 7:
            var_4 = 160;
            data->unk_20 = 162;
            data->unk_24 = 189;
            data->unk_28 = 174;
            data->unk_2C = (var_2 * var_4) / 255;
            data->scale *= 1.1;
            break;
        case 8:
            var_4 = 127;
            data->unk_20 = 170;
            data->unk_24 = 40;
            data->unk_28 = 110;
            data->unk_2C = (var_2 * var_4) / 255;
            data->scale *= 1.1;
            break;
        case 9:
            var_4 = 160;
            data->unk_20 = 180;
            data->unk_24 = 178;
            data->unk_28 = 174;
            data->unk_2C = (var_2 * var_4) / 255;
            data->scale *= 1.1;
            break;
        default:
            var_4 = 160;
            data->unk_20 = 50;
            data->unk_24 = 50;
            data->unk_28 = 255;
            data->unk_2C = (var_2 * var_4) / 255;
            data->scale += data->unk_34;
            break;
    }
}

void energy_orb_wave_render(EffectInstance* effect) {
    EnergyOrbWaveFXData* effect82 = effect->data.energyOrbWave;
    RenderTask renderTask;
    RenderTask* retTask;
    RenderTask* renderTaskPointer = &renderTask;

    renderTask.appendGfx = energy_orb_wave_appendGfx;
    renderTask.dist = 10;
    renderTask.appendGfxArg = effect;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;
    if (effect82->unk_00 >= 3) {
        queue_render_task(renderTaskPointer);
        return;
    }

    retTask = queue_render_task(renderTaskPointer);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00A4648(void) {
}

void energy_orb_wave_appendGfx(void* effect) {
    EnergyOrbWaveFXData* data = ((EffectInstance*)effect)->data.energyOrbWave;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 unk_14 = data->unk_14;
    s32 unk_2C = data->unk_2C;
    s32 unk_00 = data->unk_00;
    Matrix4f sp18;
    Matrix4f sp58;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

    guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    guScaleF(sp58, data->scale, data->scale, data->scale);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMainGfxPos++, camera->mtxBillboard, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->unk_20, data->unk_24, data->unk_28, unk_2C);
    gDPSetColorDither(gMainGfxPos++, G_CD_BAYER);
    gDPSetAlphaDither(gMainGfxPos++, G_AD_PATTERN);

    if (unk_00 < 3) {
        gSPDisplayList(gMainGfxPos++, D_09001000_3A5320);

        guRotateF(sp18, unk_14, 0.0f, 0.0f, 1.0f);
        guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_090011D0_3A54F0);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        gDPSetColorDither(gMainGfxPos++, G_CD_MAGICSQ);

        guRotateF(sp18, -unk_14 * 8, 0.0f, 0.0f, 1.0f);
        guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_090011F0_3A5510);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    } else {
        gSPDisplayList(gMainGfxPos++, D_090010A8_3A53C8);
        gSPDisplayList(gMainGfxPos++, D_09001210_3A5530);
    }

    gDPSetColorDither(gMainGfxPos++, G_CD_DISABLE);
    gDPSetAlphaDither(gMainGfxPos++, G_AD_DISABLE);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
