#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000E08_32DCC8[];

void flower_splash_init(EffectInstance* effect);
void flower_splash_update(EffectInstance* effect);
void flower_splash_render(EffectInstance* effect);
void flower_splash_appendGfx(void* effect);

void func_E0010000(FlowerFXData* effect) {
    Matrix4f transformMtx;
    Matrix4f tempMtx;

    shim_guRotateF(transformMtx, effect->rot.x, 1.0f, 0.0f, 0.0f);
    shim_guRotateF(tempMtx, effect->rot.z, 0.0f, 0.0f, 1.0f);
    shim_guMtxCatF(tempMtx, transformMtx, transformMtx);
    shim_guRotateF(tempMtx, effect->rot.y, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(transformMtx, tempMtx, transformMtx);
    shim_guScaleF(tempMtx, effect->scale.x, effect->scale.y, effect->scale.z);
    shim_guMtxCatF(tempMtx, transformMtx, transformMtx);
    shim_guTranslateF(tempMtx, effect->pos.x, effect->pos.y, effect->pos.z);
    shim_guMtxCatF(transformMtx, tempMtx, transformMtx);
    shim_guMtxF2L(transformMtx, &effect->transformMtx);
}

void func_E0010104(FlowerFXData* effect) {
    effect->rotVelocity *= 0.85;
    effect->pos.x += effect->rotVelocity * effect->unk_90;
    effect->unk_80[2] += effect->unk_80[3];
    effect->unk_80[1] += effect->unk_80[2];
    effect->unk_80[0] += effect->unk_80[1];
    effect->pos.y += effect->unk_80[0];
    effect->pos.z += effect->rotVelocity * effect->unk_94;

    if (effect->unk_80[0] < 0.0f) {
        effect->unk_80[2] = 0.004f;
    }

    effect->rot.x -= 1.0f;
    if (effect->rot.x < -100.0f) {
        effect->rot.x = -100.0f;
    }
}

void flower_splash_main(f32 posX, f32 posY, f32 posZ, f32 angle) {
    EffectBlueprint bp;
    EffectInstance* effect;
    FlowerFXData* data;
    s32 numParts = 5;
    f32 angle;
    s32 i;

    bp.init = flower_splash_init;
    bp.update = flower_splash_update;
    bp.renderWorld = flower_splash_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_FLOWER_SPLASH;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;

    data = effect->data.flowerSplash = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.flowerSplash != NULL);

    shim_mem_clear(data, numParts * sizeof(*data));

    for (i = 0; i < numParts; i++, data++) {
        data->alive = TRUE;
        data->rot.y = angle + (i * 72);
        data->linVelocity = 0.29999998f;
        data->unk_78 = 0.0f;
        data->unk_7C = 0.0f;

        data->pos.x = posX;
        data->pos.y = posY;
        data->pos.z = posZ;

        data->scale.x = 1.0f;
        data->scale.y = 1.0f;
        data->scale.z = 1.0f;
        
        data->primAlpha = 255;
        data->timeLeft = 60;

        data->rot.x = 0.0f;
        data->rot.z = 0.0f;

        data->unk_80[0] = 1.75f;
        data->unk_80[1] = -0.08f;
        data->unk_80[2] = 0.0f;
        data->unk_80[3] = 0.0f;

        data->rotVelocity = -3.9f;
        angle = shim_clamp_angle(data->rot.y);
        data->unk_90 = shim_sin_deg(angle);
        data->unk_94 = shim_cos_deg(angle);
    }
}

void flower_splash_init(EffectInstance* effect) {
}

void flower_splash_update(EffectInstance* effect) {
    FlowerFXData* data = effect->data.flowerSplash;
    s32 anyAlive = FALSE;
    s32 i;

    for (i = 0; i < effect->numParts; i++, data++) {
        if (data->alive) {
            data->timeLeft--;
            if (data->timeLeft <= 0) {
                data->alive = FALSE;
            } else {
                anyAlive = TRUE;
                func_E0010104(data);
                func_E0010000(data);
            }
        }
    }

    if (!anyAlive) {
        shim_remove_effect(effect);
    }
}

void flower_splash_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = flower_splash_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00104F4(EffectInstance* effect) {
    shim_remove_effect(effect);
}

void flower_splash_appendGfx(void* effect) {
    EffectInstance* effectTemp = effect;
    FlowerFXData* data = effectTemp->data.flowerSplash;
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->graphics->data));

    for (i = 0; i < effectTemp->numParts; i++, data++) {
        if (data->alive != 0) {
            Gfx* dlist = D_09000E08_32DCC8;

            gDisplayContext->matrixStack[gMatrixListPos] = data->transformMtx;

            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 112, 96, 24, data->primAlpha);
            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                        G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMasterGfxPos++, dlist);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        }
    }
    gDPPipeSync(gMasterGfxPos++);
}
