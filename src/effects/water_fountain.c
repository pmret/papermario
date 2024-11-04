#include "common.h"
#include "effects_internal.h"

typedef struct UnkStruct {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ s8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8 sizeScale;
    /* 0x09 */ char unk_09[1];
} UnkStruct; // size = 0xA

extern Gfx D_09000280_3B8AE0[];
extern Gfx D_09000328_3B8B88[];
extern Gfx D_09000348_3B8BA8[];

UnkStruct D_E00B8900[] = {
    {   0,  0,  30, 140,    0, 255, { 0 } },
    {   0,  6,  30, 120,    0, 250, { 0 } },
    {   1, 12,  30, 110,   -5, 240, { 0 } },
    {   1, 17,  50, 100,  -20, 240, { 0 } },
    {   2, 22,  60,  90,  -30, 240, { 0 } },
    {   2, 26,  70,  90,  -40, 240, { 0 } },
    {   3, 28,  80,  85,  -50, 240, { 0 } },
    {   4, 32,  90,  90,  -60, 240, { 0 } },
    {   5, 35, 100, 100,  -70, 240, { 0 } },
    {   7, 38, 110, 110,  -80, 240, { 0 } },
    {   8, 40, 120, 120,  -90, 240, { 0 } },
    {  11, 42, 130, 130, -100, 240, { 0 } },
    {  14, 43, 150, 150, -110, 240, { 0 } },
    {  18, 44, 190, 190, -120, 240, { 0 } },
    {  21, 45, 230, 230, -130, 240, { 0 } },
    {  24, 46, 270, 270, -140, 240, { 0 } },
    {  27, 47, 310, 310, -150, 240, { 0 } },
    {  30, 48, 350, 350, -160, 200, { 0 } },
    {  33, 49, 380, 380, -170, 140, { 0 } },
    {  36, 50, 400, 400, -180,  40, { 0 } },
    {   0,  0,  30, 140,    0, 255, { 0 } },
    {   0,  6,  30, 120,    0, 240, { 0 } },
    {  -1, 12,  30, 110,    5, 230, { 0 } },
    {  -1, 17,  50, 100,   20, 220, { 0 } },
    {  -2, 22,  60,  90,   30, 210, { 0 } },
    {  -2, 26,  70,  90,   40, 200, { 0 } },
    {  -3, 28,  80,  85,   50, 190, { 0 } },
    {  -4, 32,  90,  80,   60, 180, { 0 } },
    {  -5, 35, 100,  77,   70, 170, { 0 } },
    {  -7, 38, 110,  65,   80, 160, { 0 } },
    {  -8, 40, 120,  54,   90, 150, { 0 } },
    { -11, 42, 130,  60,  100, 140, { 0 } },
    { -14, 43, 140,  70,  110, 130, { 0 } },
    { -18, 44, 150,  80,  120, 120, { 0 } },
    { -21, 45, 160,  90,  130, 110, { 0 } },
    { -24, 46, 170, 100,  140,  90, { 0 } },
    { -27, 47, 180, 110,  150,  80, { 0 } },
    { -30, 48, 190, 120,  160,  70, { 0 } },
    { -33, 49, 200, 130,  170,  30, { 0 } },
    { -36, 50, 210, 140,  180,  10, { 0 } },
    {   0,  0,  30, 140,    0, 255, { 0 } },
    {   0,  6,  30, 120,    0, 240, { 0 } },
    {   0, 12,  30, 110,    5, 230, { 0 } },
    {   0, 17,  50, 100,   20, 220, { 0 } },
    {   0, 22,  60,  90,   30, 210, { 0 } },
    {   0, 26,  70,  90,   40, 200, { 0 } },
    {   0, 28,  80,  85,   50, 190, { 0 } },
    {   0, 32,  90,  80,   60, 180, { 0 } },
    {   0, 35, 100,  77,   70, 170, { 0 } },
    {   0, 38, 110,  65,   80, 160, { 0 } },
    {   0, 40, 120,  54,   90, 150, { 0 } },
    {   0, 42, 130,  60,  100, 140, { 0 } },
    {   0, 43, 140,  70,  110, 130, { 0 } },
    {   0, 44, 150,  80,  120, 120, { 0 } },
    {   0, 45, 160,  90,  130, 110, { 0 } },
    {   0, 46, 170, 100,  140,  90, { 0 } },
    {   0, 47, 180, 110,  150,  80, { 0 } },
    {   0, 48, 190, 120,  160,  70, { 0 } },
    {   0, 49, 200, 130,  170,  30, { 0 } },
    {   0, 50, 210, 140,  180,  10, { 0 } }
};

UnkStruct D_E00B8B58[] = {
    {  0,  0,  30, 140,   0, 255, { 0 } },
    {  0,  6,  30, 120,   0, 240, { 0 } },
    {  1, 12,  30, 110,  -5, 230, { 0 } },
    {  1, 17,  50, 100, -20, 220, { 0 } },
    {  2, 22,  60,  90, -30, 210, { 0 } },
    {  2, 26,  70,  90, -40, 200, { 0 } },
    {  3, 28,  80,  85, -50, 190, { 0 } },
    {  4, 32,  90,  80, -60, 180, { 0 } },
    {  5, 35, 100,  77, -70, 120, { 0 } },
    {  7, 38, 110,  65, -80,  80, { 0 } },
    {  8, 40, 120,  54, -90,  40, { 0 } },
    {  0,  0,  30, 140,   0, 255, { 0 } },
    {  0,  6,  30, 120,   0, 240, { 0 } },
    { -1, 12,  30, 110,   5, 230, { 0 } },
    { -1, 17,  50, 100,  20, 220, { 0 } },
    { -2, 22,  60,  90,  30, 210, { 0 } },
    { -2, 26,  70,  90,  40, 200, { 0 } },
    { -3, 28,  80,  85,  50, 190, { 0 } },
    { -4, 32,  90,  80,  60, 180, { 0 } },
    { -5, 35, 100,  77,  70, 120, { 0 } },
    { -7, 38, 110,  65,  80,  80, { 0 } },
    { -8, 40, 120,  54,  90,  40, { 0 } },
    {  0,  0,  30, 140,   0, 255, { 0 } },
    {  0,  6,  30, 120,   0, 240, { 0 } },
    {  0, 12,  30, 110,   5, 230, { 0 } },
    {  0, 17,  50, 100,  20, 220, { 0 } },
    {  0, 22,  60,  90,  30, 210, { 0 } },
    {  0, 26,  70,  90,  40, 200, { 0 } },
    {  0, 28,  80,  85,  50, 190, { 0 } },
    {  0, 32,  90,  80,  60, 180, { 0 } },
    {  0, 36, 100,  77,  70, 120, { 0 } },
    {  0, 39, 110,  65,  80,  80, { 0 } },
    {  0, 42, 120,  54,  90,  40, { 0 } }
};

s32 D_E00B8CA4[] = { 0, 40, 55, 190, 20, 130, 270, 300 };

void water_fountain_init(EffectInstance* effect);
void water_fountain_update(EffectInstance* effect);
void water_fountain_render(EffectInstance* effect);
void water_fountain_appendGfx(void* effect);

EffectInstance* water_fountain_main(s32 arg0, f32 posX, f32 posY, f32 posZ, f32 arg4, s32 arg5) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    WaterFountainFXData* data;
    s32 numParts = 1;

    effectBp.init = water_fountain_init;
    effectBp.update = water_fountain_update;
    effectBp.renderScene = water_fountain_render;
    effectBp.unk_00 = 0;
    effectBp.renderUI = NULL;
    effectBp.effectID = EFFECT_WATER_FOUNTAIN;

    effect = create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.waterFountain = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->unk_00 = arg0;
    data->lifeTime = 0;
    if (arg5 <= 0) {
        data->timeLeft = 1000;
    } else {
        data->timeLeft = arg5;
    }
    data->unk_24 = 255;
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->unk_34 = arg4;
    data->unk_18 = 70;
    data->unk_1C = 180;
    data->unk_20 = 255;
    data->unk_28 = 255;
    data->unk_2C = 255;
    data->unk_30 = 255;
    data->unk_38 = 0;
    data->unk_3C = 1.0f;
    data->unk_40 = 1.0f;

    return effect;
}

void water_fountain_init(EffectInstance* effect) {
}

void water_fountain_update(EffectInstance* effect) {
    WaterFountainFXData* data = effect->data.waterFountain;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->timeLeft = 16;
    }
    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }
    data->lifeTime++;
    if (data->timeLeft < 0) {
        remove_effect(effect);
        return;
    }
    if (data->lifeTime < 8) {
        data->unk_24 = (data->lifeTime * 32) + 31;
    }
}

void water_fountain_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = water_fountain_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00B8200(void) {
}

void water_fountain_appendGfx(void* effect) {
    WaterFountainFXData* data = ((EffectInstance*)effect)->data.waterFountain;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 lifeTime = data->lifeTime;
    s32 timeLeft = data->timeLeft;
    s32 sp9C;
    s32 unk_24 = data->unk_24;
    s32 unk_00 = data->unk_00;
    s32 unk_18 = data->unk_18;
    s32 unk_1C = data->unk_1C;
    s32 unk_20 = data->unk_20;
    s32 spB0;
    s32 var_s6;
    s32 temp;
    UnkStruct* basePtr;
    Matrix4f sp18;
    Matrix4f sp58;
    s32 i;
    s32 j;

    if (unk_00 == 0) {
        spB0 = 3;
        basePtr = D_E00B8900;
        var_s6 = 20;
    } else {
        var_s6 = 11;
        spB0 = 3;
        basePtr = D_E00B8B58;
    }

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

    guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    guScaleF(sp58, data->unk_34, data->unk_34, data->unk_34);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMainGfxPos++, camera->mtxBillboard, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, D_09000280_3B8AE0);

    guRotateF(sp18, data->unk_38, 0.0f, 0.0f, 1.0f);
    guScaleF(sp58, data->unk_3C, data->unk_40, 1.0f);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetEnvColor(gMainGfxPos++, data->unk_28, data->unk_2C, data->unk_30, unk_24);

    temp = sp9C + 1;
    if (timeLeft >= var_s6 - temp) {
        gDPSetPrimColor(gMainGfxPos++, 0, 0, unk_18, unk_1C, unk_20, unk_24);
        gSPDisplayList(gMainGfxPos++, D_09000348_3B8BA8);
    }

    for (i = 0; i < var_s6 / 2; i++) {
        for (j = 0; j < spB0; j++) {
            s32 idx = (lifeTime + i * 2) % var_s6;
            UnkStruct* ptr = &basePtr[j * var_s6];

            if (lifeTime * 5 >= idx) {
                s32 temp2 = idx + 1;
                if (timeLeft >= var_s6 - temp2) {
                    guTranslateF(sp18, (f32) ptr[idx].unk_00, (f32) ptr[idx].unk_01 + 10.0f, 0.0f);
                    guScaleF(sp58, (f32) basePtr[idx].unk_02 * 0.01, (f32) basePtr[idx].unk_04 * 0.01, 1.0f);
                    guMtxCatF(sp58, sp18, sp18);
                    guRotateF(sp58, (f32) ptr[idx].unk_06 + D_E00B8CA4[(j + i) & 7], 0.0f, 0.0f, 1.0f);
                    guMtxCatF(sp58, sp18, sp18);
                    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

                    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                    gDPSetPrimColor(gMainGfxPos++, 0, 0, unk_18, unk_1C, unk_20, (unk_24 * basePtr[idx].sizeScale) >> 8);
                    gSPDisplayList(gMainGfxPos++, D_09000328_3B8B88);
                    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
                }
            }
        }
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
