#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000600_3936A0[];
extern Gfx D_090008E8_393988[];
extern Gfx D_09000950_3939F0[];
extern Gfx D_09000FF8_394098[];

void flashing_box_shockwave_init(EffectInstance* effect);
void flashing_box_shockwave_update(EffectInstance* effect);
void flashing_box_shockwave_render(EffectInstance* effect);
void flashing_box_shockwave_appendGfx(void* effect);

EffectInstance* flashing_box_shockwave_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    f32 arg5
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    FlashingBoxShockwaveFXData* data;
    s32 numParts = 1;

    bp.init = flashing_box_shockwave_init;
    bp.update = flashing_box_shockwave_update;
    bp.renderWorld = flashing_box_shockwave_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_FLASHING_BOX_SHOCKWAVE;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.flashingBoxShockwave = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.flashingBoxShockwave != NULL);

    data->unk_1C = 30;
    data->unk_10 = 255;
    data->unk_14 = 255;
    data->unk_18 = 255;
    data->unk_00 = arg0;
    data->unk_20 = 0;
    data->pos.x = arg1;
    data->pos.y = arg2;
    data->pos.z = arg3;
    if (arg0 == 2) {
        data->unk_24 = 1.0f;
    } else {
        data->unk_24 = 0;
    }
    data->unk_28 = arg4 * 0.5;
    data->unk_2C = arg5 * 0.5;

    switch (arg0) {
        case 0:
        case 1:
        case 3:
            data->unk_30 = 255;
            data->unk_34 = 255;
            data->unk_38 = 0;
            data->unk_3C = 255;
            data->unk_40 = 255;
            data->unk_44 = 255;
            break;
        default:
            data->unk_30 = 70;
            data->unk_34 = 180;
            data->unk_38 = 120;
            data->unk_3C = 255;
            data->unk_40 = 255;
            data->unk_44 = 255;
            break;
    }

    return effect;
}

void flashing_box_shockwave_init(EffectInstance* effect) {
}

void flashing_box_shockwave_update(EffectInstance* effect) {
    FlashingBoxShockwaveFXData* data = effect->data.flashingBoxShockwave;
    s32 unk_00 = data->unk_00;
    s32 unk_1C;
    s32 unk_20;

    if (data->unk_1C < 100) {
        data->unk_1C--;
    }

    data->unk_20++;

    if (data->unk_1C < 0) {
        remove_effect(effect);
        return;
    }

    unk_1C = data->unk_1C;
    unk_20 = data->unk_20;

    if (unk_00 == 2) {
        if (unk_20 < 21) {
            data->unk_24 *= 1.1;
        }
    } else {
        data->unk_24 += (8.0 - data->unk_24) * 0.05;
    }

    data->unk_14 *= 0.9;

    if (unk_1C < 5) {
        data->unk_18 *= 0.8;
    }

    if (unk_20 >= 7) {
        data->unk_10 -= 13;
        if (data->unk_10 < 0) {
            data->unk_10 = 0;
        }
    }
}

void flashing_box_shockwave_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = flashing_box_shockwave_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;

    retTask = queue_render_task(&renderTask);
}

void flashing_box_shockwave_appendGfx(void* effect) {
    FlashingBoxShockwaveFXData* data = ((EffectInstance*)effect)->data.flashingBoxShockwave;
    s32 unk_00 = data->unk_00;
    s32 unk_20 = data->unk_20;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;

    guRotateF(sp98, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guTranslateF(sp18, data->pos.x, data->pos.y, data->pos.z);
    guMtxCatF(sp98, sp18, sp18);
    guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->unk_30, data->unk_34, data->unk_38, data->unk_18);
    gDPSetEnvColor(gMainGfxPos++, data->unk_3C, data->unk_40, data->unk_44, 0);

    if ((unk_00 == 0 || unk_00 == 1) && unk_20 % 2) {
        guScaleF(sp18, data->unk_28, data->unk_2C, 15.0f / 14);
        guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_09000600_3936A0);
        gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, unk_20 * 8, unk_20 * 8, unk_20 * 8 + 128, unk_20 * 8 + 128);
        gSPDisplayList(gMainGfxPos++, D_090008E8_393988);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    if (unk_00 >= 1 && unk_00 <= 3) {
        if (unk_00 == 1) {
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 0, data->unk_14);
        }

        guTranslateF(sp18, 0.0f, data->unk_2C, 0.0f);
        guScaleF(sp58, data->unk_24 * 0.25, data->unk_24 * 0.25, 1.0f);
        guMtxCatF(sp58, sp18, sp18);
        guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_09000950_3939F0);
        gSPDisplayList(gMainGfxPos++, D_09000FF8_394098);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
