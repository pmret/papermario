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

s32 D_E0122BA8[] = {
    0x006400FF, 0x00C800FF, 0x012C00FF, 0x019000FF, 0x01F400F5, 0x025800EB,
    0x02BC00E1, 0x032000D7, 0x038400CD, 0x03E800C3, 0x044C00B9, 0x04B000AF,
    0x051400A5, 0x0578009B, 0x05DC0091, 0x06400087, 0x06A4007D, 0x07080073,
    0x076C0069, 0x07D0005F, 0x08340055, 0x0898004B, 0x08FC0041, 0x09600037,
    0x09C4002D, 0x0A28001E, 0x0A8C0014, 0x0AF0000A, 0x0B540005, 0x0BB80000
};

s32 D_E0122C20[] = {
    0x0BB80000, 0x0B540005, 0x0AF0000A, 0x0A8C0014, 0x0A28001E, 0x09C4002D, 0x09600037, 0x08FC0041,
    0x0898004B, 0x08340055, 0x07D0005F, 0x076C0069, 0x07080073, 0x06A4007D, 0x06400087, 0x05DC0091,
    0x0578009B, 0x051400A5, 0x04B000AF, 0x044C00B9, 0x03E800C3, 0x038400CD, 0x032000D7, 0x02BC00E1,
    0x025800EB, 0x01F400F5, 0x019000FF, 0x012C00FF, 0x00C800FF, 0x006400FF, 0x00000000, 0x00000000
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
    bp.renderWorld = star_spirits_energy_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_STAR_SPIRITS_ENERGY;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.starSpiritsEnergy = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.starSpiritsEnergy != NULL);

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

INCLUDE_ASM(s32, "effects/star_spirits_energy", star_spirits_energy_update);

void star_spirits_energy_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = star_spirits_energy_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void star_spirits_energy_appendGfx(void* effect) {
    StarSpiritsEnergyFXData* data = ((EffectInstance*)effect)->data.starSpiritsEnergy;
    s32 unk_04 = data->unk_04;
    s32 alpha;
    Matrix4f sp20;
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].currentYaw, 0.0f, data->unk_3C, data->unk_08, data->unk_0C, data->unk_10);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, D_E0122BA4[0]);
    gDPSetEnvColor(gMasterGfxPos++, data->unk_2C, data->unk_30, data->unk_34, data->unk_38);

    for (i = 0; i < 4; i++) {
        if (unk_04 != 1 || i != 2) {
            if (data->unk_40[i] != 0.0f && data->unk_50[i] != 0) {
                shim_guPositionF(sp20, 0.0f, 0.0f, 0.0f, data->unk_40[i], 0.0f, 0.0f, 0.0f);
                shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

                gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                gDPSetPrimColor(gMasterGfxPos++, 0, 0, data->unk_1C, data->unk_20, data->unk_24, data->unk_50[i]);
                gSPDisplayList(gMasterGfxPos++, D_E0122B90[i]);
                gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
            }
        }
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);

    if (unk_04 == 2 || unk_04 == 3) {
        alpha = 0;

        if (data->unk_70 == 1 || data->unk_70 == 100) {
            if (data->unk_74 > 2) {
                if (data->unk_74 < 11) {
                    alpha = 255 - (data->unk_74 - 2) * 30;
                }
            }
        }

        if (data->unk_70 == 5) {
            if (data->unk_74 > 0) {
                if (data->unk_74 < 9) {
                    alpha = 255 - data->unk_74 * 30;
                }
            }
        }

        if (alpha > 0) {
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 208, 208, 208, alpha);
            gSPDisplayList(gMasterGfxPos++, D_E0122BA0[0]);
        }
    }

    gDPPipeSync(gMasterGfxPos++);
}
