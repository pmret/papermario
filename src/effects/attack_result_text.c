#include "common.h"
#include "effects_internal.h"

extern Gfx D_09001500_3918D0[];
extern Gfx D_090015A8_391978[];
extern Gfx D_09001610_3919E0[];
extern Gfx D_09001658_391A28[];
extern Gfx D_090016A0_391A70[];
extern Gfx D_090016E8_391AB8[];
extern Gfx D_09001730_391B00[];
extern Gfx D_090018B8_391C88[];
extern Gfx D_090018D8_391CA8[];
extern Gfx D_090018F8_391CC8[];
extern Gfx D_09001918_391CE8[];
extern Gfx D_09001938_391D08[];

Gfx* D_E0090A40[5] = { D_09001658_391A28, D_09001610_3919E0, D_090016A0_391A70, D_090016E8_391AB8, D_09001730_391B00 };
Gfx* D_E0090A54[5] = { D_090018D8_391CA8, D_090018B8_391C88, D_090018F8_391CC8, D_09001918_391CE8, D_09001938_391D08 };

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

    data = effect->data.attackResultText = shim_general_heap_malloc(effect->numParts * sizeof(*data));

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
    AttackResultTextFXData* data = effect->data.attackResultText;
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

void func_E0090444(EffectInstance* effect) {
    AttackResultTextFXData* data = effect->data.attackResultText;
    s32 unk_00 = data->unk_00;
    s32 unk_1C = data->unk_1C;
    Matrix4f sp18;
    Matrix4f sp58;
    s32 z;
    f32 scale;

    if (data->unk_24 != 0) {
        scale = data->unk_28;
        gDPPipeSync(gMainGfxPos++);
        gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effect->graphics->data));
        gDPSetDepthSource(gMainGfxPos++, G_ZS_PRIM);
        z = 200 - unk_1C;
        if (z < 0) {
            z = 0;
        }
        gDPSetPrimDepth(gMainGfxPos++, z, 0);

        if (unk_00 < 5) {
            shim_guTranslateF(sp18, data->unk_08, data->unk_0C, data->unk_10);
            shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guScaleF(sp58, scale, scale, 1.0f);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);
            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                      G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, data->unk_14);
            gSPDisplayList(gMainGfxPos++, D_090015A8_391978);
            gSPDisplayList(gMainGfxPos++, D_E0090A40[data->unk_04]);
            gSPDisplayList(gMainGfxPos++, D_E0090A54[data->unk_04]);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        } else {
            unk_00 -= 5;
            gDPSetPrimColor(gMainGfxPos++, 0, 0, D_E0090A78[unk_00][0], D_E0090A78[unk_00][1], D_E0090A78[unk_00][2], data->unk_14);
            gDPSetEnvColor(gMainGfxPos++, D_E0090A78[unk_00][3], D_E0090A78[unk_00][4], D_E0090A78[unk_00][5], 0);
            gSPDisplayList(gMainGfxPos++, D_09001500_3918D0);
            gSPDisplayList(gMainGfxPos++, D_E0090A40[data->unk_04]);

            gSPScisTextureRectangle(gMainGfxPos++,
                data->unk_08 * 4.0f,
                data->unk_0C * 4.0f,
                (data->unk_08 + 128.0f) * 4.0f,
                (data->unk_0C + 64.0f) * 4.0f,
                G_TX_RENDERTILE, 0, 1024, 512, 65024);
        }
        gDPPipeSync(gMainGfxPos++);
        gDPSetDepthSource(gMainGfxPos++, G_ZS_PIXEL);
        gDPPipeSync(gMainGfxPos++);
    }
}
