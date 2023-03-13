#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000E20_32DCE0[];
extern Gfx D_09000E38_32DCF8[];

void flower_trail_init(EffectInstance* effect);
void flower_trail_update(EffectInstance* effect);
void flower_trail_render(EffectInstance* effect);
void flower_trail_appendGfx(void* effect);

void flower_trail_update_part_transform(FlowerFXData* effect) {
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

void flower_trail_update_part(FlowerFXData* effect) {
    if (!effect->triggeredByNpc && effect->visibilityAmt != 0.0f && gPlayerStatus.actionState == ACTION_STATE_IDLE) {
        effect->timeLeft++;
        return;
    }

    effect->primAlpha -= 12;
    effect->integrator[2] += effect->integrator[3];
    effect->integrator[1] += effect->integrator[2];
    effect->integrator[0] += effect->integrator[1];
    effect->rot.z += effect->integrator[0] * effect->velocityScaleA;
    effect->pos.x -= effect->integrator[0] * effect->velocityScaleB * effect->velocity.x;
    effect->pos.z -= effect->integrator[0] * effect->velocityScaleB * effect->velocity.z;

    if (effect->integrator[0] < 0.0f) {
        effect->visibilityAmt = 0.0f;
    }
}

void flower_trail_main(s32 triggeredByNpc, f32 posX, f32 posY, f32 posZ, f32 angle, f32 direction) {
    EffectBlueprint bp;
    EffectInstance* effect;
    FlowerFXData* part;
    s32 numParts = 1;
    f32 partAngle;
    f32 angleOffset;
    s32 i;

    bp.init = flower_trail_init;
    bp.update = flower_trail_update;
    bp.renderWorld = flower_trail_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_FLOWER_TRAIL;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;

    part = effect->data.flowerTrail = shim_general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.flowerTrail != NULL);

    shim_mem_clear(part, numParts * sizeof(*part));

    for (i = 0; i < numParts; i++, part++) {
        part->alive = TRUE;
        part->triggeredByNpc = triggeredByNpc;
        part->unk_7C = 0.0f;
        
        part->pos.x = posX;
        part->pos.y = posY;
        part->pos.z = posZ;

        part->scale.x = 1.0f;
        part->scale.y = 1.0f;
        part->scale.z = 1.0f;

        part->primAlpha = 255;

        part->visibilityAmt = 1.0f;
        part->velocityScaleB = 5.4f;
        if (direction != 0.0f) {
            part->velocityScaleA = -10.0f;
        } else {
            part->velocityScaleA = 10.0f;
        }

        part->integrator[0] = 0.5f;
        part->integrator[1] = -0.07f;
        part->integrator[2] = 0.003f;
        part->integrator[3] = 0;

        part->timeLeft = 15;
        part->rot.y = angle;
        part->rot.x = 0.0f;
        part->rot.z = 0.0f;
        part->useAltColor = (shim_rand_int(100) >> 4) & 1;

        if (direction != 0.0f) {
            angleOffset = -90.0f;
            partAngle = shim_clamp_angle(angle + angleOffset);
        } else {
            angleOffset = 90.0f;
            partAngle = shim_clamp_angle(angle + angleOffset);
        }

        part->velocity.x = shim_sin_deg(partAngle);
        part->velocity.z = shim_cos_deg(partAngle);
    }
}

void flower_trail_init(EffectInstance* effect) {
}

void flower_trail_update(EffectInstance* effect) {
    FlowerFXData* part = effect->data.flowerTrail;
    s32 anyAlive = FALSE;
    s32 i;

    for (i = 0; i < effect->numParts; i++, part++) {
        if (part->alive) {
            part->timeLeft--;
            if (part->timeLeft <= 0) {
                part->alive = FALSE;
            } else {
                anyAlive = TRUE;
                flower_trail_update_part(part);
                flower_trail_update_part_transform(part);
            }
        }
    }

    if (!anyAlive) {
        shim_remove_effect(effect);
    }
}

void flower_trail_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* queuedTaskPtr;

    renderTask.appendGfx = flower_trail_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    queuedTaskPtr = shim_queue_render_task(&renderTask);
    queuedTaskPtr->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void flower_trail_dispose(EffectInstance* effect) {
    shim_remove_effect(effect);
}

void flower_trail_appendGfx(void* argEffect) {
    EffectInstance* effect = argEffect;
    FlowerFXData* part = effect->data.flowerTrail;
    Gfx* dlist;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effect->graphics->data));

    for (i = 0; i < effect->numParts; i++, part++) {
        if (part->alive) {
            if (part->useAltColor) {
                dlist = D_09000E20_32DCE0;
            } else {
                dlist = D_09000E38_32DCF8;
            }

            gDisplayContext->matrixStack[gMatrixListPos] = part->transformMtx;

            gDPPipeSync(gMainGfxPos++);
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 112, 96, 24, part->primAlpha);
            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                        G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, dlist);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }
    gDPPipeSync(gMainGfxPos++);
}
