#include "common.h"
#include "effects_internal.h"

typedef struct WaterBlockVtxData {
    /* 0x00 */ Vec3b pos;
    /* 0x04 */ s16 normX;
    /* 0x06 */ s16 normY;
    /* 0x08 */ Color_RGB8 color;
} WaterBlockVtxData; // size = 0xC

WaterBlockVtxData D_E00B4CF0[] = {
    {{ 25,  4,  -25 },    1025, 72,     { 176, 176, 176 }},
    {{ 22,  0,  -22 },    963,  0,      { 176, 176, 176 }},
    {{-22,  0,  -22 },    61,   0,      { 176, 176, 176 }},
    {{-25,  4,  -25 },    1,    72,     { 176, 176, 176 }},
    {{ 25,  46, -25 },    1025, 951,    { 176, 176, 176 }},
    {{-25,  46, -25 },    1,    951,    { 176, 176, 176 }},
    {{ 22,  50, -22 },    890,  997,    { 174, 208, 216 }},
    {{-22,  50, -22 },    133,  997,    { 174, 208, 216 }},
    {{-22,  50,  22 },    133,  997,    { 174, 208, 216 }},
    {{ 22,  50,  22 },    890,  997,    { 174, 208, 216 }},
    {{-22,  0,  -22 },    133,  25,     { 148, 165, 176 }},
    {{ 22,  0,  -22 },    890,  25,     { 148, 165, 176 }},
    {{ 22,  0,   22 },    890,  25,     { 148, 165, 176 }},
    {{-22,  0,   22 },    133,  25,     { 148, 165, 176 }},
    {{-22,  50,  22 },    963,  1021,   { 120, 110, 136 }},
    {{-22,  50, -22 },    61,   1021,   { 120, 110, 136 }},
    {{-25,  46, -25 },    0,    951,    { 120, 110, 136 }},
    {{-25,  46,  25 },    1024, 951,    { 120, 110, 136 }},
    {{-25,  4,  -25 },    0,    72,     { 120, 110, 136 }},
    {{-25,  4,   25 },    1024, 72,     { 120, 110, 136 }},
    {{-22,  0,  -22 },    61,   0,      { 120, 110, 136 }},
    {{-22,  0,   22 },    963,  0,      { 120, 110, 136 }},
    {{-22,  50, -22 },    61,   1021,   { 176, 176, 176 }},
    {{ 22,  50, -22 },    963,  1021,   { 176, 176, 176 }},
    {{ 22,  0,   22 },    963,  0,      { 120, 110, 136 }},
    {{ 22,  0,  -22 },    61,   0,      { 120, 110, 136 }},
    {{ 25,  4,  -25 },    0,    72,     { 120, 110, 136 }},
    {{ 25,  4,   25 },    1024, 72,     { 120, 110, 136 }},
    {{ 25,  46, -25 },    0,    951,    { 120, 110, 136 }},
    {{ 25,  46,  25 },    1024, 951,    { 120, 110, 136 }},
    {{ 22,  50, -22 },    61,   1021,   { 120, 110, 136 }},
    {{-22,  0,   22 },    61,   0,      { 240, 240, 240 }},
    {{ 25,  4,   25 },    1025, 72,     { 240, 240, 240 }},
    {{ 25,  46,  25 },    1025, 951,    { 240, 240, 240 }},
    {{ 22,  50,  22 },    963,  1021,   { 120, 110, 136 }},
    {{ 22,  0,   22 },    963,  0,      { 240, 240, 240 }},
    {{-25,  4,   25 },    1,    72,     { 240, 240, 240 }},
    {{-25,  46,  25 },    1,    951,    { 240, 240, 240 }},
    {{ 22,  50,  22 },    963,  1021,   { 240, 240, 240 }},
    {{-22,  50,  22 },    61,   1021,   { 240, 240, 240 }},
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

EffectInstance* water_block_main(s32 type, f32 x, f32 y, f32 z, f32 arg4, s32 duration) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    WaterBlockFXData* data;
    s32 i;
    s32 var_a1;
    s32 numParts = 1;

    bpPtr->init = water_block_init;
    bpPtr->update = &water_block_update;
    bpPtr->renderScene = water_block_render;
    bpPtr->unk_00 = 0;
    bpPtr->renderUI = NULL;
    bpPtr->effectID = EFFECT_WATER_BLOCK;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    data = effect->data.waterBlock = general_heap_malloc(sizeof(*data));
    ASSERT(data != NULL);

    data->type = type;
    data->lifetime = 0;
    if (duration <= 0) {
        data->timeLeft = 1000;
    } else {
        data->timeLeft = duration;
    }

    data->color.a = 0;
    data->pos.x = x;
    data->pos.y = y;
    data->pos.z = z;
    data->unk_2C = arg4;
    data->color.r = 47;
    data->color.g = 127;
    data->color.b = 255;
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
    s32 type;
    s32 time;
    s32 timeLeft;
    s32 i;

    data = effect->data.waterBlock;
    type = data->type;
    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        if (type == FX_WATER_BLOCK_DESTROY) {
            effect->flags = effect->flags & ~FX_INSTANCE_FLAG_DISMISS;
            data->timeLeft = 4;
        } else {
            effect->flags = effect->flags & ~FX_INSTANCE_FLAG_DISMISS;
            data->timeLeft = 16;
        }
    }

    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }

    data->lifetime++;
    if (data->lifetime > 90 * 60 * 60) {
        data->lifetime = 256;
    }

    timeLeft = data->timeLeft;
    if (timeLeft < 0) {
        if (type == FX_WATER_BLOCK_DESTROY) {
            load_effect(EFFECT_WATER_SPLASH);
            water_splash_main(0, data->pos.x, data->pos.y + 24.0f, data->pos.z, 2.0f, 30);
            water_splash_main(1, data->pos.x, data->pos.y + 24.0f, data->pos.z, 2.0f, 30);
        }
        remove_effect(effect);
        return;
    }

    time = data->lifetime;
    if (type == FX_WATER_BLOCK_CREATE) {
        if (timeLeft < 16) {
            data->color.a = timeLeft * 16;
            data->alpha = timeLeft * 16;
        }
        if (time < 16) {
            data->color.a = (time * 16) + 15;
            data->alpha = (time * 16) + 15;
        }
    } else if (time < 4) {
        data->color.a = (time * 64) + 63;
        data->alpha = (time * 64) + 63;
    }

    data->color.g = sin_deg((time * 6) + time) * 32.0f + 127.0f;
    temp_f20 = (f32)time * 0.01;
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
                data->unk_88[i] = -rand_int(10) - 1;
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
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00B4574(void) {
}

void water_block_appendGfx(void* effect) {
    Matrix4f sp20;
    Matrix4f sp60;
    WaterBlockFXData* data = ((EffectInstance*)effect)->data.waterBlock;
    s32 alpha = data->color.a;
    Vtx* vtxBase;
    EffectInstance* effectTemp = effect;
    WaterBlockVtxData* vtxData;
    Vtx* curVtx;
    s32 timePhase;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->shared->graphics));
    guTranslateF(sp20, data->pos.x, data->pos.y, data->pos.z);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPBranchList(gMainGfxPos, &gMainGfxPos[81]);
    vtxBase = (Vtx*)++gMainGfxPos;
    gMainGfxPos = &gMainGfxPos[80];

    timePhase = gGameStatusPtr->frameCounter * 4;

    for (vtxData = D_E00B4CF0, i = 0, curVtx = vtxBase; i < ARRAY_COUNT(D_E00B4CF0); i++, vtxData++, curVtx++) {
        f32 x = vtxData->pos.x * 10;
        f32 y = vtxData->pos.y * 10;
        f32 z = vtxData->pos.z * 10;

        if (y != 0.0f) {
            f32 dx = sin_deg(timePhase + effect_simple_rand(1000, (x + (y * 10.0f) + (z * 100.0f)))) * 20.0f;
            f32 dy = sin_deg(timePhase + effect_simple_rand(1000, ((x * 10.0f) + (y * 100.0f) + z))) * 20.0f;
            f32 dz = sin_deg(timePhase + effect_simple_rand(1000, ((x * 100.0f) + y + (z * 10.0f)))) * 20.0f;
            x += dx;
            y += dy;
            z += dz;
        }

        curVtx->v.ob[0] = x;
        curVtx->v.ob[1] = y;
        curVtx->v.ob[2] = z;

        curVtx->v.tc[0] = vtxData->normX;
        curVtx->v.tc[1] = vtxData->normY;

        curVtx->v.cn[0] = vtxData->color.r;
        curVtx->v.cn[1] = vtxData->color.g;
        curVtx->v.cn[2] = vtxData->color.b;
        curVtx->v.cn[3] = 80;
    }

    guScaleF(sp20, 0.1f, 0.1f, 0.1f);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetEnvColor(gMainGfxPos++, 0, 0, 255, data->alpha);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, alpha);
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
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->color.r, data->color.g, data->color.b, alpha * 0.3);
    gSPClearGeometryMode(gMainGfxPos++, G_CULL_BOTH);
    gSPSetGeometryMode(gMainGfxPos++, G_CULL_BACK);

    gSPVertex(gMainGfxPos++, vtxBase, 30, 0);

    gSPDisplayList(gMainGfxPos++, D_090004D8_3B70C8);

    gSPVertex(gMainGfxPos++, &vtxBase[28], 12, 0);

    gSPDisplayList(gMainGfxPos++, D_09000538_3B7128)
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
