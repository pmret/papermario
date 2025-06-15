#include "common.h"
#include "effects_internal.h"

extern Gfx D_09004E00_412090[];
extern Gfx D_09005168_4123F8[];
extern Gfx D_090051C8_412458[];
extern Gfx D_09005370_412600[];
extern Gfx D_090053D0_412660[];
extern Gfx D_09005440_4126D0[];

Gfx* D_E0122B90[] = {
    D_09005168_4123F8, D_090051C8_412458, D_09005370_412600, D_090053D0_412660
};

Gfx* D_E0122BA0[] = { D_09005440_4126D0 };
Gfx* D_E0122BA4[] = { D_09004E00_412090 };

typedef struct UnkStarSpiritsEnergy {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk_02;
    /* 0x03 */ u8 unk_03;
} UnkStarSpiritsEnergy; // size = 0x4

UnkStarSpiritsEnergy D_E0122BA8[] = {
    { 100, 0, 255 },
    { 200, 0, 255 },
    { 300, 0, 255 },
    { 400, 0, 255 },
    { 500, 0, 245 },
    { 600, 0, 235 },
    { 700, 0, 225 },
    { 800, 0, 215 },
    { 900, 0, 205 },
    { 1000, 0, 195 },
    { 1100, 0, 185 },
    { 1200, 0, 175 },
    { 1300, 0, 165 },
    { 1400, 0, 155 },
    { 1500, 0, 145 },
    { 1600, 0, 135 },
    { 1700, 0, 125 },
    { 1800, 0, 115 },
    { 1900, 0, 105 },
    { 2000, 0, 95 },
    { 2100, 0, 85 },
    { 2200, 0, 75 },
    { 2300, 0, 65 },
    { 2400, 0, 55 },
    { 2500, 0, 45 },
    { 2600, 0, 30 },
    { 2700, 0, 20 },
    { 2800, 0, 10 },
    { 2900, 0, 5 },
    { 3000, 0, 0 },
};

UnkStarSpiritsEnergy D_E0122C20[] = {
    { 3000, 0, 0 },
    { 2900, 0, 5 },
    { 2800, 0, 10 },
    { 2700, 0, 20 },
    { 2600, 0, 30 },
    { 2500, 0, 45 },
    { 2400, 0, 55 },
    { 2300, 0, 65 },
    { 2200, 0, 75 },
    { 2100, 0, 85 },
    { 2000, 0, 95 },
    { 1900, 0, 105 },
    { 1800, 0, 115 },
    { 1700, 0, 125 },
    { 1600, 0, 135 },
    { 1500, 0, 145 },
    { 1400, 0, 155 },
    { 1300, 0, 165 },
    { 1200, 0, 175 },
    { 1100, 0, 185 },
    { 1000, 0, 195 },
    { 900, 0, 205 },
    { 800, 0, 215 },
    { 700, 0, 225 },
    { 600, 0, 235 },
    { 500, 0, 245 },
    { 400, 0, 255 },
    { 300, 0, 255 },
    { 200, 0, 255 },
    { 100, 0, 255 },
};

void star_spirits_energy_init(EffectInstance* effect);
void star_spirits_energy_update(EffectInstance* effect);
void star_spirits_energy_render(EffectInstance* effect);
void star_spirits_energy_appendGfx(void* effect);

EffectInstance* star_spirits_energy_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    StarSpiritsEnergyFXData* data;
    s32 numParts = 1;

    bp.init = star_spirits_energy_init;
    bp.update = star_spirits_energy_update;
    bp.renderScene = star_spirits_energy_render;
    bp.unk_00 = 0;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_STAR_SPIRITS_ENERGY;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.starSpiritsEnergy = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.starSpiritsEnergy != nullptr);

    data->unk_00 = arg0 & 0xFF00;
    arg0 &= 0xFF;
    data->unk_04 = arg0;
    data->unk_18 = 0;
    if (arg5 <= 0) {
        data->unk_14 = 1000;
    } else {
        data->unk_14 = arg5;
    }
    data->unk_28 = 255;
    data->unk_08 = arg1;
    data->unk_0C = arg2;
    data->unk_10 = arg3;
    data->unk_3C = arg4;
    data->unk_1C = 255;
    data->unk_20 = 255;
    data->unk_24 = 255;
    data->unk_2C = 255;
    data->unk_30 = 255;
    data->unk_34 = 255;
    data->unk_38 = 255;
    data->unk_60 = 0;
    data->unk_64 = 0;
    data->unk_68 = 0;
    data->unk_6C = 0;
    data->unk_40[0] = 1.0f;
    data->unk_40[1] = 0;
    data->unk_40[2] = 0;
    data->unk_40[3] = 0;
    data->unk_50[0] = 255;
    data->unk_50[1] = 0;
    data->unk_50[2] = 0;
    data->unk_50[3] = 0;
    if (arg0 == 3) {
        data->unk_70 = 1;
    } else {
        data->unk_70 = 0;
    }
    data->unk_74 = 0;

    return effect;
}

void star_spirits_energy_init(EffectInstance* effect) {
}

void star_spirits_energy_update(EffectInstance* effect) {
    StarSpiritsEnergyFXData* data = effect->data.starSpiritsEnergy;
    s32 unk_04 = data->unk_04;
    s32 unk_18;
    s32 i;
    f32 var_float_1;
    f32 var_float_2;
    f32 var_float_3;
    u8 var_int_1;
    u8 var_int_2;
    u8 var_int_3;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->unk_14 = 16;
    }

    if (data->unk_14 < 1000) {
        data->unk_14--;
    }

    data->unk_18++;

    if (data->unk_14 < 0) {
        remove_effect(effect);
        return;
    }

    unk_18 = data->unk_18;

    if (data->unk_14 < 16) {
        data->unk_28 = data->unk_14 * 16;
    }

    switch (data->unk_70) {
        case 0:
            data->unk_50[0] = (unk_18 & 3) * 30 + 200;
            data->unk_74++;
            data->unk_40[0] = sin_deg(unk_18 * 20) * 0.04 + 0.5;
            if (data->unk_00 != 0) {
                data->unk_08 += sin_deg(unk_18);
                data->unk_0C += cos_deg(unk_18 * 1.235631);
                if (data->unk_74 > 50) {
                    data->unk_74 = 0;
                    if (unk_04 == 3) {
                        data->unk_70 = 100;
                    } else {
                        data->unk_70 = 1;
                    }
                }
            }
            break;
        case 100:
            switch (data->unk_74) {
                case 0:
                    data->unk_40[3] = 4.0f;
                    data->unk_50[3] = 255;
                    break;
                case 1:
                    data->unk_40[3] = 8.0f;
                    data->unk_50[3] = 255;
                    break;
                default:
                    data->unk_40[3] = 0.0f;
                    data->unk_50[3] = 0;
                    break;
            }
            if (data->unk_74 < 30) {
                var_float_1 = (f32) D_E0122BA8[data->unk_74].unk_00 * 0.01 + data->unk_74 * 0.3;
                var_int_1 = D_E0122BA8[data->unk_74].unk_03;
            } else {
                var_float_1 = (f32) D_E0122BA8[29].unk_00 * 0.01 + data->unk_74 * 0.3;
                var_int_1 = D_E0122BA8[29].unk_03;
            }
            data->unk_40[0] = data->unk_50[0] = 0;
            data->unk_50[1] = var_int_1;
            data->unk_50[2] = var_int_1;
            data->unk_40[1] = var_float_1;
            data->unk_40[2] = var_float_1 + 0.6;
            data->unk_74++;
            break;
        case 1:
            switch (data->unk_74) {
                case 0:
                    data->unk_40[3] = 4.0f;
                    data->unk_50[3] = 255;
                    break;
                case 1:
                    data->unk_40[3] = 8.0f;
                    data->unk_50[3] = 255;
                    break;
                default:
                    data->unk_40[3] = 0.0f;
                    data->unk_50[3] = 0;
                    break;
            }
            var_float_2 = (f32) D_E0122BA8[data->unk_74].unk_00 * 0.01;
            var_int_2 = D_E0122BA8[data->unk_74].unk_03;

            data->unk_40[0] = data->unk_50[0] = 0;
            data->unk_50[1] = var_int_2;
            data->unk_50[2] = var_int_2;
            data->unk_40[1] = var_float_2;
            data->unk_40[2] = var_float_2 * 1.2 + 4.0;
            data->unk_74++;
            if (data->unk_74 >= 30) {
                data->unk_74 = 0;
                data->unk_70 = 4;
            }
            break;
        case 4:
            switch (29 - data->unk_74) {
                case 0:
                    data->unk_40[3] = 4.0f;
                    data->unk_50[3] = 255;
                    break;
                case 1:
                    data->unk_40[3] = 8.0f;
                    data->unk_50[3] = 255;
                    break;
                default:
                    data->unk_40[3] = 0;
                    data->unk_50[3] = 0;
                    break;
            }
            var_float_3 = (f32) D_E0122C20[data->unk_74].unk_00 * 0.01;
            var_int_3 = D_E0122C20[data->unk_74].unk_03;
            data->unk_40[0] = data->unk_50[0] = 0;
            data->unk_50[1] = var_int_3;
            data->unk_50[2] = 0;
            data->unk_40[1] = var_float_3;
            data->unk_40[2] = 0.0f;
            data->unk_74++;
            if (data->unk_74 >= 30) {
                data->unk_74 = 0;
                data->unk_70 = 5;
            }
            break;
        case 5:
        default:
            data->unk_40[0] = 0.0f;
            data->unk_40[1] = 0.0f;
            data->unk_40[2] = 0.0f;
            data->unk_50[0] = 0;
            data->unk_50[1] = 0;
            data->unk_50[2] = 0;
            data->unk_40[3] = 0;
            data->unk_50[3] = 0;
            data->unk_40[3] = 0;
            data->unk_74++;
            break;
    }

    for (i = 0; i < 4; i++) {
        if (data->unk_50[i] > 255) {
            data->unk_50[i] = 255;
        }
        if (data->unk_50[i] < 0) {
            data->unk_50[i] = 0;
        }
        if (data->unk_40[i] < 0.0f) {
            data->unk_40[i] = 0.0f;
        }
    }
}

void star_spirits_energy_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = star_spirits_energy_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void star_spirits_energy_appendGfx(void* effect) {
    StarSpiritsEnergyFXData* data = ((EffectInstance*)effect)->data.starSpiritsEnergy;
    s32 unk_04 = data->unk_04;
    s32 alpha;
    Matrix4f sp20;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

    guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f,
                     data->unk_3C, data->unk_08, data->unk_0C, data->unk_10);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, D_E0122BA4[0]);
    gDPSetEnvColor(gMainGfxPos++, data->unk_2C, data->unk_30, data->unk_34, data->unk_38);

    for (i = 0; i < 4; i++) {
        if (unk_04 != 1 || i != 2) {
            if (data->unk_40[i] != 0.0f && data->unk_50[i] != 0) {
                guPositionF(sp20, 0.0f, 0.0f, 0.0f, data->unk_40[i], 0.0f, 0.0f, 0.0f);
                guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

                gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                          G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                gDPSetPrimColor(gMainGfxPos++, 0, 0, data->unk_1C, data->unk_20, data->unk_24, data->unk_50[i]);
                gSPDisplayList(gMainGfxPos++, D_E0122B90[i]);
                gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
            }
        }
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);

    if (unk_04 == 2 || unk_04 == 3) {
        alpha = 0;

        if ((data->unk_70 == 1 || data->unk_70 == 100) && data->unk_74 > 2 && data->unk_74 < 11) {
            alpha = 255 - (data->unk_74 - 2) * 30;
        }

        if (data->unk_70 == 5 && data->unk_74 > 0 && data->unk_74 < 9) {
            alpha = 255 - data->unk_74 * 30;
        }

        if (alpha > 0) {
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 208, 208, 208, alpha);
            gSPDisplayList(gMainGfxPos++, D_E0122BA0[0]);
        }
    }

    gDPPipeSync(gMainGfxPos++);
}
