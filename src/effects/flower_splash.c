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

    guRotateF(transformMtx, effect->rot.x, 1.0f, 0.0f, 0.0f);
    guRotateF(tempMtx, effect->rot.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guRotateF(tempMtx, effect->rot.y, 0.0f, 1.0f, 0.0f);
    guMtxCatF(transformMtx, tempMtx, transformMtx);
    guScaleF(tempMtx, effect->scale.x, effect->scale.y, effect->scale.z);
    guMtxCatF(tempMtx, transformMtx, transformMtx);
    guTranslateF(tempMtx, effect->pos.x, effect->pos.y, effect->pos.z);
    guMtxCatF(transformMtx, tempMtx, transformMtx);
    guMtxF2L(transformMtx, &effect->transformMtx);
}

void flower_splash_update_part(FlowerFXData* effect) {
    effect->velScaleA *= 0.85;
    effect->pos.x += effect->velScaleA * effect->vel.x;
    effect->integrator[2] += effect->integrator[3];
    effect->integrator[1] += effect->integrator[2];
    effect->integrator[0] += effect->integrator[1];
    effect->pos.y += effect->integrator[0];
    effect->pos.z += effect->velScaleA * effect->vel.z;

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
    bp.renderScene = flower_splash_render;
    bp.unk_00 = 0;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_FLOWER_SPLASH;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;

    part = effect->data.flowerSplash = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.flowerSplash != nullptr);

    mem_clear(part, numParts * sizeof(*part));

    for (i = 0; i < numParts; i++, part++) {
        part->alive = true;
        part->rot.y = angle + (i * 72);
        part->velScaleB = 0.29999998f;
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

        part->velScaleA = -3.9f;
        partAngle = clamp_angle(part->rot.y);
        part->vel.x = sin_deg(partAngle);
        part->vel.z = cos_deg(partAngle);
    }
}

void flower_splash_init(EffectInstance* effect) {
}

void flower_splash_update(EffectInstance* effect) {
    FlowerFXData* data = effect->data.flowerSplash;
    s32 anyAlive = false;
    s32 i;

    for (i = 0; i < effect->numParts; i++, data++) {
        if (data->alive) {
            data->timeLeft--;
            if (data->timeLeft <= 0) {
                data->alive = false;
            } else {
                anyAlive = true;
                flower_splash_update_part(data);
                flower_splash_update_part_transform(data);
            }
        }
    }

    if (!anyAlive) {
        remove_effect(effect);
    }
}

void flower_splash_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = flower_splash_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_PASS_THROUGH;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void flower_splash_dispose(EffectInstance* effect) {
    remove_effect(effect);
}

void flower_splash_appendGfx(void* effect) {
    EffectInstance* effectTemp = effect;
    FlowerFXData* data = effectTemp->data.flowerSplash;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->shared->graphics));

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
