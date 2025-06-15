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
    s32 type,
    f32 posX,
    f32 posY,
    f32 posZ,
    f32 sizeX,
    f32 sizeY
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    ShockOverlayFXData* data;
    s32 numParts = 1;

    bp.init = flashing_box_shockwave_init;
    bp.update = flashing_box_shockwave_update;
    bp.renderScene = flashing_box_shockwave_render;
    bp.unk_00 = 0;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_FLASHING_BOX_SHOCKWAVE;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.flashingBoxShockwave = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.flashingBoxShockwave != nullptr);

    data->type = type;
    data->timeLeft = 30;
    data->lifetime = 0;

    data->unk_10 = 255;
    data->unk_14 = 255;
    data->unk_18 = 255;

    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;

    if (type == FX_SHOCK_OVERLAY_MEGA_SHOCK) {
        data->unk_24 = 1.0f;
    } else {
        data->unk_24 = 0.0f;
    }
    data->scaleX = sizeX * 0.5;
    data->scaleY = sizeY * 0.5;

    switch (type) {
        case FX_SHOCK_OVERLAY_SHOCK_HIT:
        case FX_SHOCK_OVERLAY_LIGHTNING_WORLD:
        case FX_SHOCK_OVERLAY_LIGHTNING_BATTLE:
            data->primCol.r = 255;
            data->primCol.g = 255;
            data->primCol.b = 0;
            data->envCol.r = 255;
            data->envCol.g = 255;
            data->envCol.b = 255;
            break;
        default:
            data->primCol.r = 70;
            data->primCol.g = 180;
            data->primCol.b = 120;
            data->envCol.r = 255;
            data->envCol.g = 255;
            data->envCol.b = 255;
            break;
    }

    return effect;
}

void flashing_box_shockwave_init(EffectInstance* effect) {
}

void flashing_box_shockwave_update(EffectInstance* effect) {
    ShockOverlayFXData* data = effect->data.flashingBoxShockwave;
    s32 type = data->type;
    s32 left;
    s32 time;

    if (data->timeLeft < 100) {
        data->timeLeft--;
    }

    data->lifetime++;

    if (data->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    left = data->timeLeft;
    time = data->lifetime;

    if (type == FX_SHOCK_OVERLAY_MEGA_SHOCK) {
        if (time < 21) {
            data->unk_24 *= 1.1;
        }
    } else {
        // interp toward 8.0
        data->unk_24 += (8.0 - data->unk_24) * 0.05;
    }

    data->unk_14 *= 0.9;

    if (left < 5) {
        data->unk_18 *= 0.8;
    }

    if (time >= 7) {
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
    ShockOverlayFXData* data = ((EffectInstance*)effect)->data.flashingBoxShockwave;
    s32 type = data->type;
    s32 time = data->lifetime;
    Matrix4f mtxTransform;
    Matrix4f mtxUnkScale;
    Matrix4f mtxCamRot;

    guRotateF(mtxCamRot, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

    guTranslateF(mtxTransform, data->pos.x, data->pos.y, data->pos.z);
    guMtxCatF(mtxCamRot, mtxTransform, mtxTransform);
    guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, data->primCol.r, data->primCol.g, data->primCol.b, data->unk_18);
    gDPSetEnvColor(gMainGfxPos++, data->envCol.r, data->envCol.g, data->envCol.b, 0);

    if ((type == FX_SHOCK_OVERLAY_SHOCK_HIT || type == FX_SHOCK_OVERLAY_LIGHTNING_WORLD) && time % 2) {
        guScaleF(mtxTransform, data->scaleX, data->scaleY, 15.0f / 14);
        guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_09000600_3936A0);
        gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, time * 8, time * 8, time * 8 + 128, time * 8 + 128);
        gSPDisplayList(gMainGfxPos++, D_090008E8_393988);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    if (type == FX_SHOCK_OVERLAY_LIGHTNING_WORLD || type == FX_SHOCK_OVERLAY_MEGA_SHOCK || type == FX_SHOCK_OVERLAY_LIGHTNING_BATTLE) {
        if (type == FX_SHOCK_OVERLAY_LIGHTNING_WORLD) {
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 0, data->unk_14);
        }

        guTranslateF(mtxTransform, 0.0f, data->scaleY, 0.0f);
        guScaleF(mtxUnkScale, data->unk_24 * 0.25, data->unk_24 * 0.25, 1.0f);
        guMtxCatF(mtxUnkScale, mtxTransform, mtxTransform);
        guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_09000950_3939F0);
        gSPDisplayList(gMainGfxPos++, D_09000FF8_394098);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
