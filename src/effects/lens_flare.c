#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000240_345420[];
extern Gfx D_090002E0_3454C0[];

Gfx* D_E0034780[] = { D_090002E0_3454C0, D_090002E0_3454C0 };
Gfx* D_E0034788[] = { D_09000240_345420, D_09000240_345420 };

u8 D_E0034790[] = {
    255, 255,  82,
    255, 255,  82,
    181, 148,   0,
    181, 148,   0,
    255, 255, 214,
    255, 255, 214,
    181, 148,   0,
    181, 148,   0
};

void lens_flare_init(EffectInstance* effect);
void lens_flare_update(EffectInstance* effect);
void lens_flare_render(EffectInstance* effect);
void lens_flare_appendGfx(void* effect);

void lens_flare_main(s32 type, f32 posX, f32 posY, f32 posZ, s32 duration) {
    EffectBlueprint bp;
    EffectInstance* effect;
    LensFlareFXData* data;
    s32 numParts = 1;

    bp.init = lens_flare_init;
    bp.update = lens_flare_update;
    bp.renderScene = lens_flare_render;
    bp.unk_00 = 0;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_LENS_FLARE;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.lensFlare = general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.lensFlare != nullptr);

    data->type = type;
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->timeLeft = duration;
    data->lifetime = 0;

    data->largeFlareAlpha = 0;
    data->largeFlareRot = 0;
    if (type == 0) {
        data->largeFlareRotVel = 30.0f;
    } else {
        data->largeFlareRotVel = 0;
    }
    data->largeFlareScale = 0;
    data->largeFlareScaleVel = 0.8f;

    data->smallFlareAlpha = 0;
    data->smallFlareScale = 0;
}

void lens_flare_init(EffectInstance* effect) {
}

void lens_flare_update(EffectInstance* effect) {
    LensFlareFXData* data = effect->data.lensFlare;
    s32 time;

    data->timeLeft--;
    data->lifetime++;

    if (data->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    time = data->timeLeft;

    if (data->lifetime < 7) {
        data->largeFlareAlpha += (218 - data->largeFlareAlpha) * 0.5;
    } else {
        data->largeFlareAlpha *= 0.78;
    }

    data->largeFlareScale += data->largeFlareScaleVel;
    data->largeFlareScaleVel += 0.29;
    data->largeFlareRot += data->largeFlareRotVel;
    data->largeFlareRotVel *= 0.93;
    data->smallFlareScale = sin_deg(time * 50) * 0.5 + 0.9;
    data->smallFlareAlpha = sin_deg(time * 40) * 64.0f + 144.0f;
}

void lens_flare_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = lens_flare_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 20;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void lens_flare_appendGfx(void* effect) {
    LensFlareFXData* data = ((EffectInstance*)effect)->data.lensFlare;
    s32 type = data->type;
    s32 alpha;
    s32 idx;
    Matrix4f mtxTransform;
    Matrix4f mtxTemp;
    Matrix4f mtxShared;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));
    gSPDisplayList(gMainGfxPos++, D_E0034788[type]);

    guTranslateF(mtxTransform, data->pos.x, data->pos.y, data->pos.z);
    guRotateF(mtxTemp, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(mtxTemp, mtxTransform, mtxShared);

    alpha = data->smallFlareAlpha;
    idx = data->lifetime * 3;

    // small twinkling shine which changes color
    if (type == 0) {
        guScaleF(mtxTemp, data->smallFlareScale, data->smallFlareScale, data->smallFlareScale);
        guMtxCatF(mtxTemp, mtxShared, mtxTransform);
        guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

        idx %= ARRAY_COUNT(D_E0034790);

        gDPSetPrimColor(gMainGfxPos++, 0, 0, D_E0034790[idx], D_E0034790[idx + 1], D_E0034790[idx + 2], alpha);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_E0034780[0]);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    alpha = data->largeFlareAlpha;
    if (alpha > 255) {
        alpha = 255;
    }

    // large growing white shine
    if (alpha > 0) {
        guScaleF(mtxTemp, data->largeFlareScale, data->largeFlareScale, data->largeFlareScale);
        guMtxCatF(mtxTemp, mtxShared, mtxTransform);
        guRotateF(mtxTemp, data->largeFlareRot, 0.0f, 0.0f, 1.0f);
        guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
        guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

        gDPSetPrimColor(gMainGfxPos++, 0, 0, D_E0034790[idx], D_E0034790[idx + 1], D_E0034790[idx + 2], alpha);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, alpha);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, D_E0034780[type]);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gDPPipeSync(gMainGfxPos++);
}
