#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000E08_32DCC8[];

void flower_splash_init(EffectInstance* effect);
void flower_splash_update(EffectInstance* effect);
void flower_splash_render(EffectInstance* effect);
void flower_splash_appendGfx(void* effect);

void flower_splash_update_part_transform(FlowerFXData* effect) {
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

void flower_splash_update_part(FlowerFXData* effect) {
    effect->velocityScaleA *= 0.85;
    effect->pos.x += effect->velocityScaleA * effect->velocity.x;
    effect->integrator[2] += effect->integrator[3];
    effect->integrator[1] += effect->integrator[2];
    effect->integrator[0] += effect->integrator[1];
    effect->pos.y += effect->integrator[0];
    effect->pos.z += effect->velocityScaleA * effect->velocity.z;

    if (effect->integrator[0] < 0.0f) {
        effect->integrator[2] = 0.004f;
    }

    effect->rot.x -= 1.0f;
    if (effect->rot.x < -100.0f) {
        effect->rot.x = -100.0f;
    }
}

void flower_splash_main(f32 posX, f32 posY, f32 posZ, f32 angle) {
    EffectBlueprint bp;
    EffectInstance* effect;
    FlowerFXData* part;
    s32 numParts = 5;
    f32 partAngle;
    s32 i;

    bp.init = flower_splash_init;
    bp.update = flower_splash_update;
    bp.renderWorld = flower_splash_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_FLOWER_SPLASH;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;

    part = effect->data.flowerSplash = shim_general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.flowerSplash != NULL);

    shim_mem_clear(part, numParts * sizeof(*part));

    for (i = 0; i < numParts; i++, part++) {
        part->alive = TRUE;
        part->rot.y = angle + (i * 72);
        part->velocityScaleB = 0.29999998f;
        part->visibilityAmt = 0.0f;
        part->unk_7C = 0.0f;

        part->pos.x = posX;
        part->pos.y = posY;
        part->pos.z = posZ;

        part->scale.x = 1.0f;
        part->scale.y = 1.0f;
        part->scale.z = 1.0f;
        
        part->primAlpha = 255;
        part->timeLeft = 60;

        part->rot.x = 0.0f;
        part->rot.z = 0.0f;

        part->integrator[0] = 1.75f;
        part->integrator[1] = -0.08f;
        part->integrator[2] = 0.0f;
        part->integrator[3] = 0.0f;

        part->velocityScaleA = -3.9f;
        partAngle = shim_clamp_angle(part->rot.y);
        part->velocity.x = shim_sin_deg(partAngle);
        part->velocity.z = shim_cos_deg(partAngle);
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
                flower_splash_update_part(data);
                flower_splash_update_part_transform(data);
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
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void flower_splash_dispose(EffectInstance* effect) {
    shim_remove_effect(effect);
}

void flower_splash_appendGfx(void* effect) {
    EffectInstance* effectTemp = effect;
    FlowerFXData* data = effectTemp->data.flowerSplash;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->graphics->data));

    for (i = 0; i < effectTemp->numParts; i++, data++) {
        if (data->alive) {
            Gfx* dlist = D_09000E08_32DCC8;

            gDisplayContext->matrixStack[gMatrixListPos] = data->transformMtx;

            gDPSetPrimColor(gMainGfxPos++, 0, 0, 112, 96, 24, data->primAlpha);
            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                        G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, dlist);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }
    gDPPipeSync(gMainGfxPos++);
}
