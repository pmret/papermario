#include "common.h"
#include "effects_internal.h"

typedef struct UnkStruct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
} UnkStruct; // size = 0xC

extern Gfx D_09001000_3CC890[];

u8 D_E00C49D0[] = { 120, 80, 40, 60 };

u8 D_E00C49D4[] = {
    255, 255, 255, 198, 138, 130, 130, 130, 130, 130,
    175, 215, 250, 255, 255, 255, 255
};

u8 D_E00C49E8[] = {
    130, 130, 130, 130, 130, 165, 213, 255, 255, 255,
    255, 255, 255, 225, 198, 159, 130
};

u8 D_E00C49FC[] = {
    130, 196, 255, 255, 255, 255, 255, 255, 202, 144,
    130, 130, 130, 130, 130, 130, 130
};

UnkStruct D_E00C4A10[] = {
    { -50, -70,  5 },
    {  80, -90, 20 },
    {  20, -50, 45 },
    { -80,  30, 10 },
    {  30,   0, 35 },
    { 120, -30, 50 },
    {  10,  50, 30 },
    { 100,  30, 15 },
    {  40, 100, 40 },
    { 140,  90, 25 }
};

void stop_watch_init(EffectInstance* effect);
void stop_watch_update(EffectInstance* effect);
void stop_watch_render(EffectInstance* effect);
void stop_watch_appendGfx(void* effect);

EffectInstance* stop_watch_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    s32 arg5
) {
    EffectBlueprint bp;
    StopWatchFXData* data;
    EffectInstance* effect;
    s32 numParts = 1;
    s32 i;

    bp.init = stop_watch_init;
    bp.update = stop_watch_update;
    bp.renderWorld = stop_watch_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_STOP_WATCH;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.stopWatch = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.stopWatch != NULL);

    data->unk_00 = arg0;
    data->unk_14 = 0;
    if (arg5 <= 0) {
        data->unk_10 = 1000;
    } else {
        data->unk_10 = arg5;
    }
    data->unk_24 = 0;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_28 = arg4;
    data->unk_18 = 70;
    data->unk_1C = 180;
    data->unk_20 = 120;
    data->unk_2C = 0;
    data->unk_30 = 1.0f;

    for (i = 0; i < 10; i++) {
        data->unk_34[i] = D_E00C4A10[i].unk_00;
        data->unk_5C[i] = D_E00C4A10[i].unk_04;
        data->unk_84[i] = 0;
        data->unk_AC[i] = 0;
        data->unk_D4[i] = 0;
        data->unk_FC[i] = 0;
        data->unk_124[i] = 0;
        data->unk_14C[i] = D_E00C4A10[i].unk_08;
    }

    return effect;
}

void stop_watch_init(EffectInstance* effect) {
}

void stop_watch_update(EffectInstance* effect) {
    StopWatchFXData* data = effect->data.stopWatch;
    s32 unk_10;
    s32 unk_14;
    s32 i;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->unk_10 = 64;
    }

    if (data->unk_10 < 1000) {
        data->unk_10--;
    }

    data->unk_14++;

    if (data->unk_10 < 0) {
        remove_effect(effect);
        return;
    }

    unk_10 = data->unk_10;
    unk_14 = data->unk_14;

    if (unk_10 < 64) {
        data->unk_30 -= 0.05;
        if (data->unk_30 < 0.0f) {
            data->unk_30 = 0.0f;
        }
    }

    if (unk_10 < 32) {
        data->unk_2C += 128;
        if (data->unk_2C > 255) {
            data->unk_2C = 255;
        }
        data->unk_30 = 0.0f;
    }

    if (unk_10 < 16) {
        data->unk_24 = unk_10 * 16;
    }
    if (unk_14 < 16) {
        data->unk_24 = unk_14 * 16 + 15;
    }

    for (i = 0; i < 10; i++) {
        if (data->unk_14C[i] == 0 || --data->unk_14C[i] == 0) {
            data->unk_124[i] += 8;
            if (data->unk_124[i] > 255) {
                data->unk_124[i] = 255;
            }
        }
    }
}

void stop_watch_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = stop_watch_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
}

void func_E00C4300(void) {
}

void stop_watch_appendGfx(void* effect) {
    StopWatchFXData* data = ((EffectInstance*)effect)->data.stopWatch;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 unk_14 = data->unk_14;
    s32 unk_24 = data->unk_24;
    Vtx_t* vtxBuffer;
    Gfx* savedGfxPos;
    Matrix4f sp20;
    Matrix4f sp60;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guTranslateF(sp20, data->unk_04, data->unk_08, data->unk_0C);
    guScaleF(sp60, data->unk_28, data->unk_28, data->unk_28);
    guMtxCatF(sp60, sp20, sp20);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMainGfxPos++, camera->mtxBillboard, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, D_09001000_3CC890);
    gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, data->unk_2C);
    gSPBranchList(gMainGfxPos, &gMainGfxPos[65]);

    vtxBuffer = (Vtx_t*) (gMainGfxPos + 1);
    gMainGfxPos = &gMainGfxPos[65];

    for (i = 0; i < 16; i++) {
        Vtx_t* vtx = &vtxBuffer[i * 2];
        f32 unk_30 = data->unk_30;
        s32 temp_s1 = sin_deg(unk_14 * 10 + i * 60) * 500.0f * unk_30;
        s32 temp_f0 = sin_deg(unk_14 * 10 + i * 6) * 200.0f * unk_30;

        vtx->ob[0] = temp_s1 - 3200;
        vtx->ob[1] = i * 400 + temp_f0 - 3000;
        vtx->ob[2] = 0;
        vtx->tc[0] = 0;
        vtx->tc[1] = i * 128;

        vtx++;

        vtx->ob[0] = temp_s1 + 3200;
        vtx->ob[1] = i * 400 + temp_f0 - 3000;
        vtx->ob[2] = 0;
        vtx->tc[0] = 2048;
        vtx->tc[1] = i * 128;
    }

    gSPBranchList(gMainGfxPos, &gMainGfxPos[20]);

    gMainGfxPos++;
    savedGfxPos = gMainGfxPos;

    guScaleF(sp20, 0.01f, 0.01f, 0.01f);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPVertex(gMainGfxPos++, vtxBuffer, 32, 0);

    for (i = 0; i < 15; i++) {
        s32 i2 = i * 2;
        gSP2Triangles(gMainGfxPos++,
            i2    , i2 + 2, i2 + 1, i2,
            i2 + 1, i2 + 2, i2 + 3, i2);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gSPEndDisplayList(gMainGfxPos++);

    for (i = 0; i < 10; i++) {
        guPositionF(sp20, data->unk_AC[i], data->unk_D4[i], data->unk_FC[i], D_E00C49D0[i % 4] * 0.01, data->unk_34[i], data->unk_5C[i], data->unk_84[i]);
        guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, D_E00C49D4[i], D_E00C49E8[i], D_E00C49FC[i], unk_24 * data->unk_124[i] / 255);
        gSPDisplayList(gMainGfxPos++, savedGfxPos);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
