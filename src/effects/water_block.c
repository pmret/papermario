#include "common.h"
#include "effects_internal.h"

typedef struct WaterBlockVtxData {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ s8 unk_01;
    /* 0x02 */ s8 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ u8 unk_0A;
} WaterBlockVtxData; // size = 0xC

WaterBlockVtxData D_E00B4CF0[] = {
                     { 25,  4,  -25,    1025, 72,      176, 176, 176},
                     { 22,  0,  -22,    963,  0,       176, 176, 176},
                     {-22,  0,  -22,    61,   0,       176, 176, 176},
                     {-25,  4,  -25,    1,    72,      176, 176, 176},
                     { 25,  46, -25,    1025, 951,     176, 176, 176},
                     {-25,  46, -25,    1,    951,     176, 176, 176},
                     { 22,  50, -22,    890,  997,     174, 208, 216},
                     {-22,  50, -22,    133,  997,     174, 208, 216},
                     {-22,  50,  22,    133,  997,     174, 208, 216},
                     { 22,  50,  22,    890,  997,     174, 208, 216},
                     {-22,  0,  -22,    133,  25,      148, 165, 176},
                     { 22,  0,  -22,    890,  25,      148, 165, 176},
                     { 22,  0,   22,    890,  25,      148, 165, 176},
                     {-22,  0,   22,    133,  25,      148, 165, 176},
                     {-22,  50,  22,    963,  1021,    120, 110, 136},
                     {-22,  50, -22,    61,   1021,    120, 110, 136},
                     {-25,  46, -25,    0,    951,     120, 110, 136},
                     {-25,  46,  25,    1024, 951,     120, 110, 136},
                     {-25,  4,  -25,    0,    72,      120, 110, 136},
                     {-25,  4,   25,    1024, 72,      120, 110, 136},
                     {-22,  0,  -22,    61,   0,       120, 110, 136},
                     {-22,  0,   22,    963,  0,       120, 110, 136},
                     {-22,  50, -22,    61,   1021,    176, 176, 176},
                     { 22,  50, -22,    963,  1021,    176, 176, 176},
                     { 22,  0,   22,    963,  0,       120, 110, 136},
                     { 22,  0,  -22,    61,   0,       120, 110, 136},
                     { 25,  4,  -25,    0,    72,      120, 110, 136},
                     { 25,  4,   25,    1024, 72,      120, 110, 136},
                     { 25,  46, -25,    0,    951,     120, 110, 136},
                     { 25,  46,  25,    1024, 951,     120, 110, 136},
                     { 22,  50, -22,    61,   1021,    120, 110, 136},
                     {-22,  0,   22,    61,   0,       240, 240, 240},
                     { 25,  4,   25,    1025, 72,      240, 240, 240},
                     { 25,  46,  25,    1025, 951,     240, 240, 240},
                     { 22,  50,  22,    963,  1021,    120, 110, 136},
                     { 22,  0,   22,    963,  0,       240, 240, 240},
                     {-25,  4,   25,    1,    72,      240, 240, 240},
                     {-25,  46,  25,    1,    951,     240, 240, 240},
                     { 22,  50,  22,    963,  1021,    240, 240, 240},
                     {-22,  50,  22,    61,   1021,    240, 240, 240},
};

extern Gfx D_09000300_3B6EF0[];
extern Gfx D_090003B0_3B6FA0[];
extern Gfx D_090004A0_3B7090[];
extern Gfx D_090004D8_3B70C8[];
extern Gfx D_09000538_3B7128[];

void water_block_init(EffectInstance* effect);
void water_block_update(EffectInstance* effect);
void water_block_render(EffectInstance* effect);
void water_block_appendGfx(void* effect);

EffectInstance* water_block_main(s32 arg0, f32 x, f32 y, f32 z, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    WaterBlockFXData* data;
    s32 i;
    s32 var_a1;
    s32 numParts = 1;

    bpPtr->init = water_block_init;
    bpPtr->update = &water_block_update;
    bpPtr->renderWorld = water_block_render;
    bpPtr->unk_00 = 0;
    bpPtr->renderUI = NULL;
    bpPtr->effectID = EFFECT_WATER_BLOCK;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    data = effect->data.waterBlock = general_heap_malloc(sizeof(*data));
    ASSERT(data != NULL);

    data->unk_00 = arg0;
    data->unk_14 = 0;
    if (arg5 <= 0) {
        data->unk_10 = 1000;
    } else {
        data->unk_10 = arg5;
    }

    data->unk_24 = 0;
    data->pos.x = x;
    data->pos.y = y;
    data->pos.z = z;
    data->unk_2C = arg4;
    data->unk_18 = 47;
    data->unk_1C = 127;
    data->unk_20 = 255;
    data->unk_30 = 0.0f;
    data->unk_34 = 0.0f;

    for (i = NUM_WATER_BLOCK_COMPONENTS - 1, var_a1 = -13; i >= 0;  var_a1 += 4, i--) {
        data->unk_88[i] = var_a1;
    }
    return effect;
}

void water_block_init(EffectInstance* effect) {
}

EFFECT_DEF_WATER_SPLASH(water_splash_main);

void water_block_update(EffectInstance* effect) {
    WaterBlockFXData *data;
    f32 temp_f20;
    s32 temp_a0;
    s32 temp_s0;
    s32 temp_v1_3;
    s32 i;

    data = effect->data.waterBlock;
    temp_a0 = data->unk_00;
    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        if (temp_a0 == 1) {
            effect->flags = effect->flags & ~FX_INSTANCE_FLAG_DISMISS;
            data->unk_10 = 4;
        } else {
            effect->flags = effect->flags & ~FX_INSTANCE_FLAG_DISMISS;
            data->unk_10 = 16;
        }
    }

    if (data->unk_10 < 1000) {
        data->unk_10--;
    }

    data->unk_14++;
    if (data->unk_14 > 324000) {
        data->unk_14 = 256;
    }

    temp_v1_3 = data->unk_10;
    if (temp_v1_3 < 0) {
        if (temp_a0 == 1) {
            load_effect(EFFECT_WATER_SPLASH);
            water_splash_main(0, data->pos.x, data->pos.y + 24.0f, data->pos.z, 2.0f, 0x1E);
            water_splash_main(1, data->pos.x, data->pos.y + 24.0f, data->pos.z, 2.0f, 0x1E);
        }
        remove_effect(effect);
        return;
    }
    temp_s0 = data->unk_14;
    if (temp_a0 == 0) {
        if (temp_v1_3 < 16) {
            data->unk_24 = temp_v1_3 * 16;
            data->unk_28 = temp_v1_3 * 16;
        }
        if (temp_s0 < 16) {
            data->unk_24 = (temp_s0 * 16) + 15;
            data->unk_28 = (temp_s0 * 16) + 15;
        }
    } else if (temp_s0 < 4) {
        data->unk_24 = (temp_s0 * 64) + 63;
        data->unk_28 = (temp_s0 * 64) + 63;
    }


    data->unk_1C = sin_deg((temp_s0 * 6) + temp_s0) * 32.0f + 127.0f;
    temp_f20 = (f32)temp_s0 * 0.01;
    data->unk_30 = (sin_deg(temp_f20 * 6.0f) * 32.0f * sin_deg(temp_f20)) + 256.0f + (cos_deg(2.0f * temp_f20) * 32.0f) + (cos_deg(temp_f20) * 32.0f);
    data->unk_34 += 0.2;
    if (data->unk_34 >= 128.0f) {
        data->unk_34 = 0.0f;
    }

    for (i = 0; i < NUM_WATER_BLOCK_COMPONENTS; i++) {
        data->unk_88[i]++;
        if (data->unk_88[i] >= 0) {
            if (data->unk_88[i] == 0) {
                data->unk_38[i] = 0.0f;
                data->unk_48[i] = 240.0f;
                data->unk_58[i] = (rand_int(10) - 5) * 0.2;
                data->unk_68[i] = rand_int(10) + 2;
                data->unk_78[i] = rand_int(10) + 1;
            }
            data->unk_48[i] += data->unk_68[i];
            data->unk_38[i] += data->unk_58[i];
            data->unk_58[i] *= 0.97;
            data->unk_68[i] += (10.0f - data->unk_68[i]) * 0.1;
            if (data->unk_48[i] > 480.0f) {
                data->unk_88[i] = ~rand_int(10);
            }
        }
    }
}

void water_block_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = water_block_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 20;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00B4574(void) {
}

void water_block_appendGfx(void *effect) {
    Matrix4f sp20;
    Matrix4f sp60;
    WaterBlockFXData* data = ((EffectInstance*)effect)->data.waterBlock;
    s32 spA4 = data->unk_24;
    Vtx* spA8;
    EffectInstance* effectTemp = effect;
    WaterBlockVtxData* var_s6;
    Vtx* var_fp;
    s32 temp_s0;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->graphics->data));
    guTranslateF(sp20, data->pos.x, data->pos.y, data->pos.z);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPBranchList(gMainGfxPos, &gMainGfxPos[81]);
    spA8 = (Vtx*)++gMainGfxPos;
    gMainGfxPos = &gMainGfxPos[80];

    temp_s0 = gGameStatusPtr->frameCounter * 4;

    for (var_s6 = D_E00B4CF0, i = 0, var_fp = spA8; i < 40; i++, var_s6++, var_fp++) {
        f32 x = var_s6->unk_00 * 10;
        f32 y = var_s6->unk_01 * 10;
        f32 z = var_s6->unk_02 * 10;

        if (y != 0.0f) {
            f32 dx = sin_deg(temp_s0 + func_E0200044(1000, (x + (y * 10.0f) + (z * 100.0f)))) * 20.0f;
            f32 dy = sin_deg(temp_s0 + func_E0200044(1000, ((x * 10.0f) + (y * 100.0f) + z))) * 20.0f;
            f32 dz = sin_deg(temp_s0 + func_E0200044(1000, ((x * 100.0f) + y + (z * 10.0f)))) * 20.0f;
            x += dx;
            y += dy;
            z += dz;
        }

        var_fp->v.ob[0] = x;
        var_fp->v.ob[1] = y;
        var_fp->v.ob[2] = z;

        var_fp->v.tc[0] = var_s6->unk_04;
        var_fp->v.tc[1] = var_s6->unk_06;

        var_fp->v.cn[0] = var_s6->unk_08;
        var_fp->v.cn[1] = var_s6->unk_09;
        var_fp->v.cn[2] = var_s6->unk_0A;
        var_fp->v.cn[3] = 80;
    }

    guScaleF(sp20, 0.1f, 0.1f, 0.1f);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetEnvColor(gMainGfxPos++, 0, 0, 255, data->unk_28);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, spA4);
    gSPDisplayList(gMainGfxPos++, D_090003B0_3B6FA0);

    for (i = 0; i < NUM_WATER_BLOCK_COMPONENTS; i++) {
        if (data->unk_88[i] >= 0) {
            guPositionF(sp20, 0.0f, 0.0f, 0.0f, data->unk_78[i], data->unk_38[i], data->unk_48[i], 0.0f);
            guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);
            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_090004A0_3B7090);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }

    gSPDisplayList(gMainGfxPos++, D_09000300_3B6EF0);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->unk_18, data->unk_1C, data->unk_20, spA4 * 0.3);
    gSPClearGeometryMode(gMainGfxPos++, G_CULL_BOTH);
    gSPSetGeometryMode(gMainGfxPos++, G_CULL_BACK);

    gSPVertex(gMainGfxPos++, spA8, 30, 0);

    gSPDisplayList(gMainGfxPos++, D_090004D8_3B70C8);

    gSPVertex(gMainGfxPos++, &spA8[28], 12, 0);

    gSPDisplayList(gMainGfxPos++, D_09000538_3B7128)
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
