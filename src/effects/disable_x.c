#include "common.h"
#include "effects_internal.h"

extern Gfx D_09002100_3884B0[];
extern Gfx D_09002198_388548[];
extern Gfx D_09002230_3885E0[];
extern Gfx D_09002250_388600[];
extern Gfx D_09002270_388620[];
extern Gfx D_09002290_388640[];
extern Gfx D_090022B0_388660[];
extern Gfx D_09002320_3886D0[];
extern Gfx D_09002360_388710[];
extern Gfx D_090023A0_388750[];
extern Gfx D_090023E0_388790[];
extern Gfx D_09002420_3887D0[];
extern Gfx D_09002460_388810[];
extern Gfx D_090024A0_388850[];
extern Gfx D_090024E0_388890[];
extern Gfx D_09002520_3888D0[];
extern Gfx D_09002560_388910[];
extern Gfx D_090025A0_388950[];
extern Gfx D_090025E0_388990[];

Gfx* D_E0082D00[] = {
    D_09002320_3886D0, D_09002360_388710, D_090023A0_388750, D_090023E0_388790, D_09002420_3887D0, D_09002460_388810,
    D_090024A0_388850, D_090024E0_388890, D_09002520_3888D0, D_09002560_388910, D_090025A0_388950, D_090025E0_388990
};

void disable_x_init(EffectInstance* effect);
void disable_x_update(EffectInstance* effect);
void disable_x_render(EffectInstance* effect);
void func_E0082528(EffectInstance* effect);
void func_E00828B4(EffectInstance* effect);
void func_E0082A84(EffectInstance* effect);

EffectInstance* disable_x_main(s32 type, f32 x, f32 y, f32 z, s32 arg4) {
    EffectBlueprint bp;
    EffectInstance* effect;
    DisableXFXData* data;
    s32 numParts = 2;
    s32 i;

    bp.unk_00 = 0;
    bp.init = disable_x_init;
    bp.update = disable_x_update;
    bp.renderWorld = disable_x_render;
    bp.renderUI = func_E0082528;
    bp.effectID = EFFECT_DISABLE_X;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = general_heap_malloc(numParts * sizeof(*data));
    effect->data.disableX = data;
    ASSERT(effect->data.disableX != NULL);

    data->type = type;
    data->scale = 1.0f;
    if (type == 1) {
        data->unk_38 = type;
        data->koDuration = 0;
    } else {
        data->unk_38 = 0;
        data->koDuration = arg4;
    }

    data->pos.x = x;
    data->pos.y = y;
    data->pos.z = z;

    switch (type) {
        case 0:
            data->unk_28 = 100;
            break;
        case 1:
            data->unk_28 = 100;
            break;
        case 10:
            data->unk_28 = 21;
            break;
    }

    data->unk_2C = 0;
    data->unk_44 = 0;
    data->unk_04 = 1;

    data++;
    for (i = 1; i < numParts; i++, data++) {
        data->pos.x = data->pos.y = data->pos.z = 0.0f;
        data->unk_18 = data->unk_1C = data->unk_20 = 0.0f;
        data->unk_14 = 0.0f;
        data->unk_40 = 0.0f;
        data->unk_28 = 0;
        data->alpha = 255;
    }

    return effect;
}

void disable_x_init(EffectInstance* effect) {
}

void disable_x_update(EffectInstance* effect) {
    static const f32 D_E0082D30[12] = { 5.0f, 4.0f, 4.0f, 3.0f, 2.0f, 1.0f, 0.7f, 1.2f, 1.0f, 0.0f, 0.0f, 0.0f };

    DisableXFXData* data = effect->data.disableX;
    s32 unk_28;
    s32 unk_2C;
    f32 unk_34;
    s32 unk_3C;
    s32 unk_38;
    u32 type;
    s32 i;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->unk_28 = 21;
    }

    if (data->unk_28 < 100) {
        data->unk_28--;
    }

    if (data->unk_28 < 0) {
        remove_effect(effect);
        return;
    }

    data->unk_2C++;
    if (data->unk_2C > 324000) {
        data->unk_2C = 256;
    }

    type = data->type;
    unk_28 = data->unk_28;
    unk_2C = data->unk_2C;
    unk_38 = data->unk_38;
    unk_34 = data->scale;
    unk_3C = data->koDuration;

    if (type == 0) {
        if (data->unk_44 > 0) {
            data->unk_44--;
        } else {
            if (data->koDuration != unk_38) {
                if (data->koDuration < 0) {
                    unk_3C = 0;
                }
                if (unk_38 < unk_3C) {
                    data->unk_28 = 100;
                    data->unk_2C = 1;
                    data[1].unk_28 = 0;
                    data->unk_38++;
                    if (data->pos.y > -500.0f) {
                        sfx_play_sound_at_position(SOUND_2107, SOUND_SPACE_MODE_0, data->pos.x, data->pos.y, data->pos.z);
                    }
                } else if (unk_3C < unk_38) {
                    load_effect(EFFECT_DISABLE_X);
                    disable_x_main(10, data->pos.x, data->pos.y + data[1].unk_20, data->pos.z, 0);
                    data->unk_38--;
                }
                data->unk_44 = 8;
            }
        }
    }

    data++;
    for (i = 1; i < effect->numParts; i++, data++) {
        if (data->unk_28 < 9 && type != 10) {
            data->unk_30 = D_E0082D30[data->unk_28];
        } else {
            data->unk_30 = 1.0f;
        }

        data->unk_30 *= unk_34;
        if (type < 2) {
            data->unk_20 = cos_deg(unk_2C * 12) * 4.0f;
        } else {
            data->unk_20 = 0.0f;
        }

        data->pos.x += data->unk_14;
        data->pos.y += data->unk_18;
        data->pos.z += data->unk_1C;

        if (unk_28 == 20) {
            data->unk_18 = 4.0f;
            data->unk_14 = -2.0f;
        }
        if (unk_28 < 20) {
            data->unk_18 += -0.5;
            data->unk_40 += 10.0f;
            data->unk_20 *= (f32) unk_28 * 0.05;
        }
        if (unk_28 < 10) {
            data->alpha = unk_28 * 25;
        }
        data->unk_28 += 1;
    }
}

void disable_x_render(EffectInstance* effect) {
}

void func_E0082528(EffectInstance* effect) {
    DisableXFXData* data = effect->data.disableX;

    if (data->unk_04 != 0) {
        func_E00828B4(effect);
        if (data->type != 1) {
            func_E0082A84(effect);
        }
    }
}

void func_E0082580(DisableXFXData* data) {
    Matrix4f sp18, sp58;

    guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    guScaleF(sp58, data->scale, data->scale, 1.0f);
    guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
}

void func_E00826C4(DisableXFXData* data) {
    Matrix4f sp18, sp58;

    guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    guScaleF(sp58, data->unk_30, data->unk_30, 1.0f);
    guMtxCatF(sp58, sp18, sp18);
    guRotateF(sp58, data->unk_40, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp58, sp18, sp18);
    guTranslateF(sp58, 0.0f, data->unk_20, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, data->alpha);

    if (data->alpha == 255) {
        gDPSetRenderMode(gMainGfxPos++, AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA |
                         GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM),
                         AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA |
                         GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM));
        gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIDECALA, G_CC_MODULATEIDECALA);
    } else {
        gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        gDPSetCombineLERP(gMainGfxPos++, TEXEL0, 0, SHADE, 0, PRIMITIVE, 0, TEXEL0, 0, TEXEL0, 0, SHADE, 0, PRIMITIVE, 0, TEXEL0, 0);
    }
}

void func_E00828B4(EffectInstance* effect) {
    DisableXFXData* data = effect->data.disableX;
    s32 type;
    s32 unk_38;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effect->graphics->data));
    func_E0082580(data);
    unk_38 = data->unk_38;
    type = data->type;

    data++;
    for (i = 1; i < effect->numParts; i++, data++) {
        if (unk_38 > 0 || type == 10) {
            if (type == 1) {
                gSPDisplayList(gMainGfxPos++, D_09002198_388548);
            } else {
                gSPDisplayList(gMainGfxPos++, D_09002100_3884B0);
            }
            func_E00826C4(data);
            gSPDisplayList(gMainGfxPos++, D_09002230_3885E0);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}

void func_E0082A84(EffectInstance* effect) {
    DisableXFXData* data = effect->data.disableX;
    s32 unk_38;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effect->graphics->data));
    func_E0082580(data);
    unk_38 = data->unk_38;

    data++;
    for (i = 1; i < effect->numParts; i++, data++) {
        func_E00826C4(data);
        if (unk_38 > 0) {
            gSPDisplayList(gMainGfxPos++, D_090022B0_388660);
            if (unk_38 < 10) {
                gSPDisplayList(gMainGfxPos++, D_E0082D00[unk_38]);
                gSPDisplayList(gMainGfxPos++, D_09002250_388600);
            } else {
                s32 ones = unk_38 % 10;
                s32 tens = unk_38 / 10;

                gSPDisplayList(gMainGfxPos++, D_E0082D00[ones]);
                gSPDisplayList(gMainGfxPos++, D_E0082D00[tens]);
                gSPDisplayList(gMainGfxPos++, D_09002290_388640);
                gSPDisplayList(gMainGfxPos++, D_E0082D00[tens]);
                gSPDisplayList(gMainGfxPos++, D_09002270_388620);
            }
        }
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
