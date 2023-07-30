#include "common.h"
#include "effects_internal.h"

extern Gfx D_09003200_385000[];
extern Gfx D_09003298_385098[];
extern Gfx D_09003330_385130[];
extern Gfx D_090033D0_3851D0[];
extern Gfx D_090033F0_3851F0[];
extern Gfx D_09003410_385210[];
extern Gfx D_09003430_385230[];
extern Gfx D_09003450_385250[];
extern Gfx D_09003470_385270[];
extern Gfx D_09003490_385290[];
extern Gfx D_090034B0_3852B0[];
extern Gfx D_090034D0_3852D0[];
extern Gfx D_09003540_385340[];
extern Gfx D_09003580_385380[];
extern Gfx D_090035C0_3853C0[];
extern Gfx D_09003600_385400[];
extern Gfx D_09003640_385440[];
extern Gfx D_09003680_385480[];
extern Gfx D_090036C0_3854C0[];
extern Gfx D_09003700_385500[];
extern Gfx D_09003740_385540[];
extern Gfx D_09003780_385580[];
extern Gfx D_090037C0_3855C0[];
extern Gfx D_09003800_385600[];

Gfx* D_E0080AC0[] = { D_09003540_385340, D_09003580_385380, D_090035C0_3853C0,
                      D_09003600_385400, D_09003640_385440, D_09003680_385480,
                      D_090036C0_3854C0, D_09003700_385500, D_09003740_385540,
                      D_09003780_385580, D_090037C0_3855C0, D_09003800_385600 };

f32 D_E0080AF0[] = { 0.25f, 0.5f, 0.75f, 1.0f, 0.9f, 1.1f, 1.0f };

f32 D_E0080B0C[] = { 0.25f, 0.5f, 0.75f, 1.0f, 1.2f, 0.9f, 1.0f };

void recover_init(EffectInstance* effect);
void recover_update(EffectInstance* effect);
void recover_render(EffectInstance* effect);
void func_E008042C(EffectInstance* effect);
void func_E0080448(EffectInstance* effect);

EffectInstance* recover_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    EffectBlueprint bp;
    EffectInstance* effect;
    RecoverFXData* part;
    s32 numParts = 2;
    s32 i;

    bp.init = recover_init;
    bp.update = recover_update;
    bp.renderWorld = recover_render;
    bp.renderUI = func_E008042C;
    bp.unk_00 = 0;
    bp.effectID = EFFECT_RECOVER;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    part = effect->data.recover = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.recover != NULL);

    part->unk_00 = arg0;
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_2C = 46;
    part->unk_30 = 0;
    if (arg4 < 0) {
        part->unk_44 = 1;
        arg4 = -arg4;
    } else {
        part->unk_44 = 0;
    }
    part->unk_40 = arg4;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        part->unk_04 = 0.0f;
        part->unk_08 = 0;
        part->unk_0C = 0;
        part->unk_24 = 0;
        part->unk_10 = 0;
        part->unk_18 = 0;
        part->unk_20 = 0;
        part->unk_1C = 0;
        if (i == 1) {
            part->unk_04 = 0.0f;
            part->unk_34 = 0;
            part->unk_38 = 0;
            part->unk_3C = 0;
            part->unk_14 = 1.4f;
        } else {
            part->unk_14 = 1.4f;
            part->unk_34 = i + 10;
            part->unk_38 = 0;
            part->unk_3C = 0;
            part->unk_04 = ((i & 1) * 2 - 1) * ((i - 1) >> 1) * 4;
        }
        part->unk_2C = 0;
        part->unk_28 = 255;
    }

    return effect;
}

void recover_init(EffectInstance* effect) {
}

void recover_update(EffectInstance* effect) {
    RecoverFXData* part = effect->data.recover;
    s32 unk_2C;
    s32 i;

    part->unk_2C--;
    part->unk_30++;

    if (part->unk_2C < 0) {
        remove_effect(effect);
        return;
    }

    unk_2C = part->unk_2C;

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        s32 unk_2C_2 = part->unk_2C;

        if (part->unk_34 <= 0 || --part->unk_34 <= 0) {
            if (unk_2C_2 >= 7) {
                part->unk_3C = 1.0f;
                part->unk_38 = 1.0f;
            } else {
                part->unk_38 = D_E0080AF0[unk_2C_2];
                part->unk_3C = D_E0080B0C[unk_2C_2];
            }

            part->unk_04 += part->unk_10;
            part->unk_08 += part->unk_14;
            part->unk_0C += part->unk_18;
            part->unk_1C = sin_deg(i * 38 + unk_2C * 12) * -30.0f;
            part->unk_24 = cos_deg(i * 38 + unk_2C * 12) * 8.0f;

            if (unk_2C < 20) {
                part->unk_24 *= (f32) unk_2C * 0.05;
                part->unk_1C *= (f32) unk_2C * 0.05;
            }

            if (unk_2C < 10) {
                part->unk_28 = unk_2C * 25;
                part->unk_14 *= 0.9;
            }

            part->unk_2C++;
        }
    }
}

void recover_render(EffectInstance* effect) {
}

void func_E008042C(EffectInstance* effect) {
    func_E0080448(effect);
}

void func_E0080448(EffectInstance* effect) {
    RecoverFXData* part = ((EffectInstance*)effect)->data.recover;
    s32 i;
    s32 unk_00;
    s32 unk_40;
    s32 unk_44 = part->unk_44;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guTranslateF(sp18, part->unk_04, part->unk_08, part->unk_0C);
    guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp98);
    guMtxF2L(sp98, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    unk_00 = part->unk_00;
    unk_40 = part->unk_40;

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        if (part->unk_34 <= 0) {
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, part->unk_28);

            if (part->unk_28 == 255) {
                gDPSetRenderMode(gMainGfxPos++, AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM), AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM));
                gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIDECALA, G_CC_MODULATEIDECALA);
            } else {
                gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
                gDPSetCombineLERP(gMainGfxPos++, TEXEL0, 0, SHADE, 0, PRIMITIVE, 0, TEXEL0, 0, TEXEL0, 0, SHADE, 0, PRIMITIVE, 0, TEXEL0, 0);
            }

            gSPDisplayList(gMainGfxPos++, (unk_00 == 0 || unk_00 == 2) ?
                (unk_44 == 0 ? D_09003200_385000 : D_09003298_385098) :
                D_09003330_385130);

            guTranslateF(sp18, part->unk_04 + part->unk_24, part->unk_08, part->unk_0C);
            guScaleF(sp58, part->unk_38, part->unk_3C, 1.0f);
            guMtxCatF(sp58, sp18, sp18);
            guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            guRotateF(sp18, part->unk_1C, 0.0f, 0.0f, 1.0f);
            guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            if (i == 1 && unk_00 != 2) {
                gSPDisplayList(gMainGfxPos++, D_090033D0_3851D0);
                gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
                gSPDisplayList(gMainGfxPos++, D_090034D0_3852D0);

                if (unk_40 < 0xA && unk_44 == 0) {
                    gSPDisplayList(gMainGfxPos++, D_E0080AC0[unk_40]);
                    gSPDisplayList(gMainGfxPos++, unk_00 == 0 ? D_09003410_385210 : D_09003470_385270);
                } else {
                    s32 ones = unk_40 % 10;
                    s32 tens = unk_44 == 0 ? (unk_40 / 10) : 10;

                    gSPDisplayList(gMainGfxPos++, D_E0080AC0[ones]);
                    gSPDisplayList(gMainGfxPos++, unk_00 == 0 ? D_09003450_385250 : D_090034B0_3852B0);
                    gSPDisplayList(gMainGfxPos++, D_E0080AC0[tens]);
                    gSPDisplayList(gMainGfxPos++, unk_00 == 0 ? D_09003430_385230 : D_09003490_385290);
                }
            } else {
                gSPDisplayList(gMainGfxPos++, D_090033F0_3851F0);
                gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
            }

            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
