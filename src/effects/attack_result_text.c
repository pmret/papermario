#include "common.h"
#include "effects_internal.h"

extern Gfx D_09001500[];
extern Gfx D_090015A8[];
extern Gfx D_09001610[];
extern Gfx D_09001658[];
extern Gfx D_090016A0[];
extern Gfx D_090016E8[];
extern Gfx D_09001730[];
extern Gfx D_090018B8[];
extern Gfx D_090018D8[];
extern Gfx D_090018F8[];
extern Gfx D_09001918[];
extern Gfx D_09001938[];

Gfx* D_E0090A40[5] = { D_09001658, D_09001610, D_090016A0, D_090016E8, D_09001730 };
Gfx* D_E0090A54[5] = { D_090018D8, D_090018B8, D_090018F8, D_09001918, D_09001938 };

u8 D_E0090A68[8] = { 10, 40, 80, 120, 125, 100, 90, 100 };
u8 D_E0090A70[8] = { 60, 80, 100, 110, 112, 95, 100, 0 };

s8 D_E0090A78[5][6] = {
    { 255, 255, 255, 254, 159, 15 },
    { 215, 86, 0, 254, 207, 15 },
    { 254, 159, 15, 229, 21, 0 },
    { 0, 107, 42, 255, 217, 69 },
    { 0, 0, 215, 151, 255, 255 },
};

void attack_result_text_init(EffectInstance* effect);
void attack_result_text_update(EffectInstance* effect);
void attack_result_text_render(EffectInstance* effect);
void func_E0090428(EffectInstance* effect);
void func_E0090444(EffectInstance* effect);

EffectInstance* attack_result_text_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    AttackResultTextFXData* data;
    s32 numParts = 1;

    bp.unk_00 = 0;
    bp.init = attack_result_text_init;
    bp.update = attack_result_text_update;
    bp.renderWorld = attack_result_text_render;
    bp.unk_14 = func_E0090428;
    bp.effectID = EFFECT_ATTACK_RESULT_TEXT;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;

    data = effect->data = shim_general_heap_malloc(effect->numParts * sizeof(*data));

    ASSERT(data != NULL);

    data->unk_24 = 1;
    data->unk_20 = 0;
    data->unk_00 = arg0;
    data->unk_1C = 0;
    data->unk_04 = arg0 % 5;

    if (arg5 <= 0) {
        data->unk_18 = 100;
    } else {
        data->unk_18 = arg5;
    }

    data->unk_14 = 0xFF;

    if (arg0 < 5) {
        data->unk_08 = arg1;
        data->unk_0C = arg2;
        data->unk_10 = arg3;
        data->unk_30 = 2.0f * (-shim_sin_deg(30.0f) * arg4);
        data->unk_34 = 2.0f * (shim_cos_deg(30.0f) * arg4);
    } else {
        data->unk_08 = -100.0f;
        data->unk_0C = 40.0f;
        data->unk_10 = 0.0f;
        data->unk_30 = 115.0f;
        data->unk_34 = 0.0f;
    }

    return effect;
}

void attack_result_text_init(EffectInstance* effect) {
}

void attack_result_text_update(EffectInstance* effect) {
    AttackResultTextFXData* data = effect->data;
    s32 unk_00 = data->unk_00;
    s32 old_unk_1C;
    s32 unk_1C;
    s32 unk_18;
    u32 temp1C;

    if (data->unk_18 < 100) {
        data->unk_18--;
    }

    old_unk_1C = data->unk_1C;
    data->unk_1C++;
    unk_1C = data->unk_1C;

    if (data->unk_18 < 0) {
        data->unk_24 = 0;
        data->unk_18 = -1;
        shim_remove_effect(effect);
        return;
    }

    unk_18 = data->unk_18;

    if (unk_00 < 5) {
        if (data->unk_1C < 9) {
            data->unk_28 = (f32) D_E0090A68[old_unk_1C] * 0.01;
        }

        temp1C = old_unk_1C - 100;
        if (unk_1C == 10) {
            data->unk_1C = 9;
        }

        if (temp1C < 7) {
            data->unk_28 = (f32) D_E0090A70[temp1C] * 0.01;
        }

        if (unk_1C == 109) {
            data->unk_1C = 108;
        }
        if (unk_1C > 1000) {
            data->unk_1C = 1000;
        }
        if (unk_18 >= 6) {
            data->unk_30 *= 0.75;
            data->unk_34 *= 0.75;
        }
        if (unk_18 < 5) {
            data->unk_30 *= 0.7;
            data->unk_34 *= 0.7;
        }
    } else {
        if (unk_18 >= 6) {
            data->unk_30 *= 0.7;
            data->unk_34 *= 0.7;
        }
        if (unk_18 < 5) {
            data->unk_30 *= 0.6;
            data->unk_34 *= 0.6;
        }
    }

    data->unk_08 += data->unk_30;
    data->unk_0C += data->unk_34;
    if (data->unk_20 != 0) {
        data->unk_20 = 0;
        data->unk_1C = 100;
        data->unk_04++;
        if (data->unk_04 > 2) {
            data->unk_04 = 2;
        }
    }
}

void attack_result_text_render(EffectInstance* effect) {
}

void func_E0090428(EffectInstance* effect) {
    func_E0090444(effect);
}

// gSPTextureRectangle needs a lot of work
#ifdef NON_EQUIVALENT
void func_E0090444(EffectInstance* effect) {
    Matrix4f sp18;
    Matrix4f sp58;
    AttackResultTextFXData* data;
    s32 unk_00;
    s32 unk_1C;
    s32 temp_a2;
    s8* temp_a0_3;
    f32 scale;
    // f32 temp_f2;
    // s32 temp_f4;
    // s32 temp_f4_2;
    // s32 temp_f4_3;
    // s32 temp_f4_4;
    // s32 temp_f4_5;
    // s32 temp_v0_3;
    // s32 temp_v1_4;
    // u32 phi_v1;
    // u32 phi_a0;
    // u32 phi_v1_2;
    // u32 phi_v0;
    // u32 phi_v0_2;
    // s32 phi_a0_2;
    // s32 phi_v1_3;
    // s32 phi_v0_3;

    data = effect->data;
    unk_00 = data->unk_00;
    unk_1C = data->unk_1C;

    if (data->unk_24 != 0) {
        scale = data->unk_28;
        gDPPipeSync(gMasterGfxPos++);
        gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effect->graphics->data));
        gDPSetDepthSource(gMasterGfxPos++, G_ZS_PRIM);
        temp_a2 = 200 - unk_1C;
        if (temp_a2 < 0) {
            temp_a2 = 0;
        }
        gDPSetPrimDepth(gMasterGfxPos++, temp_a2, 0);

        if (unk_00 < 5) {
            shim_guTranslateF(sp18, data->unk_08, data->unk_0C, data->unk_10);
            shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guScaleF(sp58, scale, scale, 1.0f);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);
            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                      G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, data->unk_14);
            gSPDisplayList(gMasterGfxPos++, D_090015A8);
            gSPDisplayList(gMasterGfxPos++, D_E0090A40[data->unk_04]);
            gSPDisplayList(gMasterGfxPos++, D_E0090A54[data->unk_04]);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        } else {
            unk_00 -= 5;
            temp_a0_3 = D_E0090A78[unk_00];
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, temp_a0_3[0], temp_a0_3[1], temp_a0_3[2], data->unk_14);
            gDPSetEnvColor(gMasterGfxPos++, temp_a0_3[3], temp_a0_3[4], temp_a0_3[5], 0);
            gSPDisplayList(gMasterGfxPos++, D_09001500);
            gSPDisplayList(gMasterGfxPos++, D_E0090A40[data->unk_04]);

            // temp_f4 = (s32) ((data->unk_08 + 128.0f) * 4.0f);
            // if ((s32) (s16) temp_f4 > 0) {
            //     phi_v0 = (((s16) temp_f4 & 0xFFF) << 0xC) | 0xE4000000;
            // } else {
            //     phi_v0 = 0xE4000000U;
            // }
            // temp_f4_2 = (s32) ((data->unk_0C + 64.0f) * 4.0f);
            // phi_v1 = phi_v0;
            // if ((s32) (s16) temp_f4_2 > 0) {
            //     phi_v1 = phi_v0 | ((s16) temp_f4_2 & 0xFFF);
            // }
            // temp_f4_3 = (s32) (data->unk_08 * 4.0f);
            // if ((s32) (s16) temp_f4_3 > 0) {
            //     phi_v0_2 = ((s16) temp_f4_3 & 0xFFF) << 0xC;
            // } else {
            //     phi_v0_2 = 0U;
            // }
            // temp_f4_4 = (s32) (data->unk_0C * 4.0f);
            // phi_a0 = phi_v0_2;
            // if ((s32) (s16) temp_f4_4 > 0) {
            //     phi_a0 = phi_v0_2 | ((s16) temp_f4_4 & 0xFFF);
            // }

            // temp_f4_5 = (s32) (data->unk_08 * 4.0f);
            // if ((s32) (s16) temp_f4_5 < 0) {
            //     temp_v0_3 = (s16) temp_f4_5 * 4;
            //     phi_v0_3 = temp_v0_3;
            //     if (temp_v0_3 > 0) {
            //         phi_v0_3 = 0;
            //     }
            //     phi_a0_2 = phi_v0_3 * -0x10000;
            // } else {
            //     phi_a0_2 = 0;
            // }
            // temp_f2 = data->unk_0C * 4.0f;
            // phi_v1_2 = phi_a0_2 | 0x400;
            // if (temp_f2 < 0.0f) {
            //     temp_v1_4 = (s32) -(s32) ((s32) ((s32) temp_f2 << 0x10) >> 7) >> 7;
            //     phi_v1_3 = temp_v1_4;
            //     if (temp_v1_4 < 0) {
            //         phi_v1_3 = 0;
            //     }
            //     phi_v1_2 = phi_a0_2 | ((0x400 - phi_v1_3) & 0xFFFF);
            // }

            // temp_v1_2->words.w0 = E400000000000000 // data->unk_08, data->unk_0C
            // temp_v1_3->words.w0 = E100000012341234 // phi_v1_2
            // temp_v1_5->words.w0 = F10000000200FE00
            gSPTextureRectangle(gMasterGfxPos++, 0, 0, 0, 0, G_TX_RENDERTILE, data->unk_08, data->unk_0C, 0x0200, -0x0200);
        }
        gDPPipeSync(gMasterGfxPos++);
        gDPSetDepthSource(gMasterGfxPos++, G_ZS_PIXEL);
        gDPPipeSync(gMasterGfxPos++);
    }
}
#else
INCLUDE_ASM(s32, "effects/attack_result_text", func_E0090444);
#endif
