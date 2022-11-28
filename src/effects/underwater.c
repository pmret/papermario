#include "common.h"
#include "effects_internal.h"
#include "nu/nusys.h"

void underwater_init(EffectInstance* effect);
void underwater_update(EffectInstance* effect);
void underwater_render(EffectInstance* effect);
void underwater_appendGfx(void* effect);

EffectInstance* underwater_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    UnderwaterFXData* data;
    s32 numParts = 1;
    s32 i;
    s32 j;

    bp.init = underwater_init;
    bp.update = underwater_update;
    bp.renderWorld = underwater_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_UNDERWATER;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.underwater = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.underwater != NULL);

    data->unk_00 = arg0;
    data->unk_14 = 0;
    if (arg5 <= 0) {
        data->unk_10 = 1000;
    } else {
        data->unk_10 = arg5;
    }
    data->unk_1F = 0;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_18 = arg4;
    data->unk_1C = 10;
    data->unk_1D = 110;
    data->unk_1E = 255;
    data->unk_20 = 190;
    data->unk_21 = 220;
    data->unk_22 = 255;

    for (i = 0; i < ARRAY_COUNT(data->unk_23); i++) {
        for (j = 0; j < ARRAY_COUNT(data->unk_23[0]); j++) {
            data->unk_23[i][j] = 0;
            data->unk_11A[i][j] = 0;
        }
    }

    return effect;
}

void underwater_init(EffectInstance* effect) {
}

void underwater_update(EffectInstance* effect) {
    UnderwaterFXData* data = effect->data.underwater;
    s32 unk_10;
    s32 unk_14;
    s32 var_a0;
    f32 factor;
    s32 i;
    s32 j;

    if (effect->flags & EFFECT_INSTANCE_FLAGS_10) {
        effect->flags &= ~EFFECT_INSTANCE_FLAGS_10;
        data->unk_10 = 32;
    }

    if (data->unk_10 < 1000) {
        data->unk_10--;
    }

    data->unk_14++;

    if (data->unk_10 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_10 = data->unk_10;
    unk_14 = data->unk_14;

    var_a0 = 255;
    if (unk_10 < 32) {
        var_a0 = unk_10 * 8;
    }
    if (unk_14 < 16) {
        var_a0 = unk_14 * 16 + 15;
    }

    data->unk_1F = (f32) var_a0;
    factor = (f32) var_a0 / 255.0f;

    for (i = 1; i < ARRAY_COUNT(data->unk_23) - 1; i++) {
        data->unk_23[i][6] = shim_sin_deg(-((unk_14 - i) * 20)) * -64.0f * factor;
    }

    for (i = 1; i < ARRAY_COUNT(data->unk_23) - 1; i++) {
        for (j = 1; j < ARRAY_COUNT(data->unk_23[0]) - 1; j++) {
            f32 m11 = data->unk_23[i][j] * 4.0f;
            f32 m21 = data->unk_23[i + 1][j];
            f32 m01 = data->unk_23[i - 1][j];
            f32 m12 = data->unk_23[i][j + 1];
            f32 m10 = data->unk_23[i][j - 1];
            f32 m22 = data->unk_23[i + 1][j + 1];
            f32 m02 = data->unk_23[i - 1][j + 1];
            f32 m20 = data->unk_23[i + 1][j - 1];
            f32 m00 = data->unk_23[i - 1][j - 1];
            f32 temp1 = m21 + m01 + m12 + m10 - m11;
            f32 temp2 = (m22 + m02 + m20 + m00) * 0.5;

            data->unk_11A[i][j] += temp1 + temp2 - m11 * 0.7;
            data->unk_11A[i][j] *= 0.98;

            if (unk_10 < 32) {
                data->unk_23[i][j] *= factor;
            }
        }
    }

    for (i = 1; i < ARRAY_COUNT(data->unk_23) - 1; i++) {
        for (j = 1; j < ARRAY_COUNT(data->unk_23[0]) - 1; j++) {
            data->unk_23[i][j] += data->unk_11A[i][j] * 0.02;
        }
    }
}

void underwater_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = underwater_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 100;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

void func_E00BA618(void) {
}

extern Vtx D_09000428[];
extern Gfx D_09000528[];
extern Gfx D_09000570[];

#ifdef WIP
void underwater_appendGfx(void* effect) {
    EffectInstance* effectTemp = effect;
    UnderwaterFXData* data;
    Matrix4f sp20;
    s32 spA0;
    s32 spA8;
    s32 temp_a0_3;
    s32 temp_a1_5;
    s32 temp_a1_6;
    s32 temp_a1_7;
    s32 temp_a2_2;
    s32 temp_s3;
    s32 temp_t7;
    s32 temp_t8;
    s32 temp_v1_2;
    s32 temp_v1_4;
    s32 var_a0;
    s32 var_s1;
    s32 var_s2;
    s32 cond;
    s32 var_t3_2;
    s32 var_t4;
    s32 var_t9;
    s32 var_v1;
    u32 temp_v1_3;

    s32 i;
    s32 j;

    data = effectTemp->data.underwater;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->graphics->data));
    gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, nuGfxZBuffer);
    gSPDisplayList(gMasterGfxPos++, D_09000528);

    for (i = 0; i < 40; i++) {
        // todo probably a composite macro?
        gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, &nuGfxCfb_ptr[0xF00 * i]);
        gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 80, 0x0000, G_TX_LOADTILE, 0,
                   G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                   G_TX_NOLOD);
        gDPLoadSync(gMasterGfxPos++);
        gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, 0, 0, 0x04FC, 0x0014);
        gDPPipeSync(gMasterGfxPos++);
        gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 80, 0x0000, G_TX_RENDERTILE, 0,
                   G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                   G_TX_NOLOD);
        gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, 0, 0x04FC, 0x0014);
        gSPTextureRectangle(gMasterGfxPos++, 0, i * 0x18, 0x04FC, 20 + (i * 18), G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
        gDPPipeSync(gMasterGfxPos++);
    }

    gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, nuGfxCfb_ptr);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, data->unk_1C, data->unk_1D, data->unk_1E, data->unk_1F);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    gDPSetCombineLERP(gMasterGfxPos++, PRIMITIVE, 0, PRIMITIVE_ALPHA, TEXEL0, 0, 0, 0, SHADE, PRIMITIVE, 0,
                      PRIMITIVE_ALPHA, TEXEL0, 0, 0, 0, SHADE);
    gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, VIRTUAL_TO_PHYSICAL(nuGfxZBuffer));
    gDPSetRenderMode(gMasterGfxPos++, CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | G_RM_PASS,
                     CVG_DST_SAVE | ZMODE_OPA | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1));
    gDPSetTexturePersp(gMasterGfxPos++, G_TP_PERSP);
    gDPSetTextureFilter(gMasterGfxPos++, G_TF_BILERP);

    shim_guFrustumF(sp20, -80.0f, 80.0f, 60.0f, -60.0f, 160.0f, 640.0f, 1.0f);
    shim_guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPClearGeometryMode(gMasterGfxPos++, G_CULL_BOTH | G_LIGHTING);
    gSPSetGeometryMode(gMasterGfxPos++, G_SHADE | G_SHADING_SMOOTH);
    gSPVertex(gMasterGfxPos++, D_09000428, 16, 0);

    var_t9 = 0x18;
    for (i = 0; i < 12; i++) {
        var_s2 = 0;
        if (i == 0) {
            var_a0 = -4;
            var_s2 = 1;
        } else {
            var_a0 = 0;
        }
        var_v1 = 0;
        if (i == 11) {
            var_v1 = 4;
            var_s2 = 1;
        }
        temp_t8 = (var_t9 + var_a0) * 4;
        spA0 = (temp_t8 & 0xFFF) | 0xF4000000;
        temp_v1_2 = var_t9 + var_v1;
        temp_s3 = (temp_v1_2 + 0x10) * 4;
        spA8 = -var_s2;

        for (j = 0; j < 12; j++) {
            cond = FALSE;
            temp_t7 = (j * 0x10) + 0x10;
            if (j == 0) {
                var_t3_2 = -4;
                cond = TRUE;
            } else {
                var_t3_2 = 0;
            }
            var_s1 = 0;
            if (j == 0x11) {
                var_s1 = 4;
                cond = TRUE;
            }
            temp_a2_2 = temp_t7 + var_s1;
            temp_a0_3 = temp_t7 + var_t3_2;

            temp_v1_3 = ((((s32) ((((temp_a2_2 - (temp_a0_3 - 0x10)) + 1) * 2) + 7) >> 3) & 0x1FF) << 9) | 0xF5100000;

            temp_a3->words.w0 = temp_v1_3;
            temp_a3->words.w1 = 0x07098260;

            temp_a1_4->words.w0 = E600000000000000

            temp_a1_4->unkC = (s32) (((((temp_a2_2 + 0x10) * 4) & 0xFFF) << 0xC) | ((temp_s3 & 0xFFF) | 0x07000000));
            temp_a1_4->unk8 = (s32) ((((temp_a0_3 * 4) & 0xFFF) << 0xC) | spA0);

            temp_a1_4->unk10 = E700000000000000

            temp_a1_4->unk18 = temp_v1_3;
            temp_a1_4->unk1C = 00098260

            temp_a1_4->unk20 = F2000000
            temp_a1_4->unk24 = (s32) (((((temp_a2_2 + 0x1F) * 4) & 0xFFF) << 0xC) | (((temp_v1_2 + 0x1F) * 4) & 0xFFF));
            if (!cond || (var_t4 = 0xC, (var_s2 == 0))) {
                var_t4 = 4;
                if (!cond) {
                    var_t4 = spA8 & 8;
                }
            }
            temp_a1_5 = j * 0xD;

            temp_a0_4->words.w0 = (var_t4 * 2) | 0x02180000;
            temp_a0_4->words.w1 = ((temp_t7 + var_t3_2) << 0x12) | (temp_t8 + (data + (i + temp_a1_5))->unk23);

            temp_v1_4 = j * 0xD;
            temp_a2_3->words.w0 = ((var_t4 + 1) * 2) | 0x02180000;
            temp_a2_3->words.w1 = ((temp_t7 + var_s1 + 0x10) << 0x12) | (temp_t8 + (data + (i + temp_v1_4))->unk23);

            temp_a2_3->unk8 = (s32) (((var_t4 + 2) * 2) | 0x02180000);
            temp_a2_3->unkC = (s32) (((temp_t7 + var_t3_2) << 0x12) | (temp_s3 + (data + (i + (temp_a1_5 + 1)))->unk23));

            temp_a1_6 = (var_t4 + 3) * 2;
            temp_a2_3->unk10 = (s32) (temp_a1_6 | 0x02180000);
            temp_a2_3->unk14 = (s32) (((temp_t7 + var_s1 + 0x10) << 0x12) | (temp_s3 + (data + (i + (temp_v1_4 + 1)))->unk23));

            temp_a1_7 = temp_a1_6 & 0xFF;
            temp_a2_3->unk18 = (s32) (((var_t4 * 2) << 0x10) | (temp_a1_7 << 8) | ((var_t4 + 1) * 2) | 0x06000000);
            temp_a2_3->unk1C = (s32) (((var_t4 * 2) << 0x10) | (((var_t4 + 2) * 2) << 8) | temp_a1_7);

            temp_a2_3->unk20 = E700000000000000;
        }
        var_t9 += 0x10;
    }
    gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, nuGfxZBuffer);
    gSPDisplayList(gMasterGfxPos++, D_09000570);
    gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, nuGfxZBuffer);
    gDPPipeSync(gMasterGfxPos++);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos],
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gDPPipeSync(gMasterGfxPos++);
}
#else
INCLUDE_ASM(s32, "effects/underwater", underwater_appendGfx);
#endif
