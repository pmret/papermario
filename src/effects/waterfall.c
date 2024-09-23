#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000200_3B7AD0[];

void waterfall_init(EffectInstance* effect);
void waterfall_update(EffectInstance* effect);
void waterfall_render(EffectInstance* effect);
void waterfall_appendGfx(void* effect);

EffectInstance* waterfall_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    s32 arg5
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    WaterfallFXData* data;
    s32 numParts = 1;
    s32 i;

    bp.init = waterfall_init;
    bp.update = waterfall_update;
    bp.renderWorld = waterfall_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_WATERFALL;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.waterfall = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.waterfall != NULL);

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
    data->unk_18 = 20;
    data->unk_1C = 120;
    data->unk_20 = 255;

    for (i = 0; i < 12; i++) {
        data->unk_2C[i] = 0;
        data->unk_5C[i] = (f32) rand_int(10) * 0.01 + -1.0;
    }

    return effect;
}

void waterfall_init(EffectInstance* effect) {
}

void waterfall_update(EffectInstance* effect) {
    WaterfallFXData* data = effect->data.waterfall;
    s32 unk_14;
    s32 i;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        data->unk_10 = 16;
    }

    if (data->unk_10 < 1000) {
        data->unk_10--;
    }

    data->unk_14++;

    if (data->unk_10 < 0) {
        remove_effect(effect);
        return;
    }

    unk_14 = data->unk_14;

    if (data->unk_10 < 16) {
        data->unk_24 = data->unk_10 * 16;
    }

    if (unk_14 < 16) {
        data->unk_24 = unk_14 * 16 + 15;
    }

    for (i = 0; i < 12; i++) {
        data->unk_2C[i] += data->unk_5C[i];
        data->unk_5C[i] += -0.1;
        if (data->unk_5C[i] > 5.0f) {
            data->unk_5C[i] += (5.0 - data->unk_5C[i]) * 0.1;
        }
    }
}

void waterfall_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = waterfall_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
}

void func_E00B62D8(void) {
}

void waterfall_appendGfx(void* effect) {
    WaterfallFXData* data = ((EffectInstance*)effect)->data.waterfall;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 unk_14 = data->unk_14;
    s32 unk_24 = data->unk_24;
    f32 scale = data->unk_28 * 0.1;
    s32 savedIdx;
    Vtx_t* vtx;
    Gfx* savedGfxPos;
    Matrix4f sp10;
    Matrix4f sp50;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guTranslateF(sp10, data->unk_04, data->unk_08, data->unk_0C);
    guScaleF(sp50, scale, scale, scale);
    guMtxCatF(sp50, sp10, sp10);
    guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMainGfxPos++, camera->mtxBillboard, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->unk_18, data->unk_1C, data->unk_20, unk_24);
    gSPDisplayList(gMainGfxPos++, D_09000200_3B7AD0);
    gSPBranchList(gMainGfxPos, &gMainGfxPos[49]);

    savedGfxPos = gMainGfxPos + 1;
    gMainGfxPos = &gMainGfxPos[49];

    vtx = (Vtx_t*) savedGfxPos;

    for (i = 0; i < ARRAY_COUNT(data->unk_2C); i++) {
        vtx->ob[0] = i * 50 - 300;
        vtx->ob[1] = 600;
        vtx->ob[2] = 0;
        vtx->tc[0] = (unk_14 + i * 4) * 32;
        vtx->tc[1] = (s32) data->unk_2C[i] * 32;
        vtx->cn[0] = 255;
        vtx->cn[1] = 255;
        vtx->cn[2] = 255;
        vtx->cn[3] = -i * 20 - 1;
        vtx++;

        vtx->ob[0] = i * 50 - 300;
        vtx->ob[1] = (data->unk_2C[i] + 60.0f) * 10.0f;
        vtx->ob[2] = 0;
        vtx->tc[0] = (unk_14 + i * 4) * 32;
        vtx->tc[1] = 1024;
        vtx->cn[0] = 255;
        vtx->cn[1] = 255;
        vtx->cn[2] = 255;
        vtx->cn[3] = -i * 20 - 1;
        vtx++;
    }

    savedIdx = i;

    gSPVertex(gMainGfxPos++, savedGfxPos, i * 2, 0);

    for (i = 0; i < savedIdx - 1; i++) {
        s32 i2 = i * 2;
        gSP2Triangles(gMainGfxPos++,
            i2    , i2 + 2, i2 + 1, i2,
            i2 + 1, i2 + 2, i2 + 3, i2);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
