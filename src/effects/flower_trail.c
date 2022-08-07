#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000E20_32DCE0[];
extern Gfx D_09000E38_32DCF8[];

void flower_trail_init(EffectInstance* effect);
void flower_trail_update(EffectInstance* effect);
void flower_trail_render(EffectInstance* effect);
void flower_trail_appendGfx(void* effect);

void func_E0012000(FlowerFXData* effect) {
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

void func_E0012104(FlowerFXData* effect) {
    if (effect->unk_04 == 0 && effect->unk_78 != 0.0f && gPlayerStatus.actionState == ACTION_STATE_IDLE) {
        effect->timeLeft++;
        return;
    }

    effect->primAlpha -= 12;
    effect->unk_80[2] += effect->unk_80[3];
    effect->unk_80[1] += effect->unk_80[2];
    effect->unk_80[0] += effect->unk_80[1];
    effect->rot.z += effect->unk_80[0] * effect->rotVelocity;
    effect->pos.x -= effect->unk_80[0] * effect->linVelocity * effect->unk_90;
    effect->pos.z -= effect->unk_80[0] * effect->linVelocity * effect->unk_94;

    if (effect->unk_80[0] < 0.0f) {
        effect->unk_78 = 0.0f;
    }
}

void flower_trail_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    FlowerFXData* part;
    s32 numParts = 1;
    f32 angle;
    f32 temp;
    s32 i;

    bp.init = flower_trail_init;
    bp.update = flower_trail_update;
    bp.renderWorld = flower_trail_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_FLOWER_TRAIL;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;

    part = shim_general_heap_malloc(numParts * sizeof(*part));
    effect->data.flowerTrail = part;
    ASSERT(effect->data.flowerTrail != NULL);

    shim_mem_clear(part, numParts * sizeof(*part));

    for (i = 0; i < numParts; i++, part++) {
        part->alive = 1;
        part->unk_04 = arg0;
        part->unk_7C = 0.0f;
        part->pos.x = arg1;
        part->pos.y = arg2;
        part->pos.z = arg3;
        part->scale.x = 1.0f;
        part->scale.y = 1.0f;
        part->scale.z = 1.0f;
        part->primAlpha = 255;
        part->unk_78 = 1.0f;
        part->linVelocity = 5.4f;

        if (arg5 != 0.0f) {
            part->rotVelocity = -10.0f;
        } else {
            part->rotVelocity = 10.0f;
        }

        part->unk_80[0] = 0.5f;
        part->unk_80[1] = -0.07f;
        part->unk_80[2] = 0.003f;
        part->unk_80[3] = 0;

        part->timeLeft = 15;
        part->rot.y = arg4;
        part->rot.x = 0.0f;
        part->rot.z = 0.0f;
        part->unk_09 = (shim_rand_int(100) >> 4) & 1;

        if (arg5 != 0.0f) {
            temp = -90.0f;
            angle = shim_clamp_angle(arg4 + temp);
        } else {
            temp = 90.0f;
            angle = shim_clamp_angle(arg4 + temp);
        }

        part->unk_90 = shim_sin_deg(angle);
        part->unk_94 = shim_cos_deg(angle);
    }
}

void flower_trail_init(EffectInstance* effect) {
}

void flower_trail_update(EffectInstance* effect) {
    FlowerFXData* part = effect->data.flowerTrail;
    s32 cond = FALSE;
    s32 i;

    for (i = 0; i < effect->numParts; i++, part++) {
        if (part->alive != 0) {
            part->timeLeft--;
            if (part->timeLeft <= 0) {
                part->alive = 0;
            } else {
                cond = TRUE;
                func_E0012104(part);
                func_E0012000(part);
            }
        }
    }

    if (!cond) {
        shim_remove_effect(effect);
    }
}

void flower_trail_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = flower_trail_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E0012548(EffectInstance* effect) {
    shim_remove_effect(effect);
}

void flower_trail_appendGfx(void* effect) {
    EffectInstance* effectTemp = effect;
    FlowerFXData* part = effectTemp->data.flowerTrail;
    Gfx* dlist;
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->graphics->data));

    for (i = 0; i < effectTemp->numParts; i++, part++) {
        if (part->alive != 0) {
            if (part->unk_09 != 0) {
                dlist = D_09000E20_32DCE0;
            } else {
                dlist = D_09000E38_32DCF8;
            }

            gDisplayContext->matrixStack[gMatrixListPos] = part->transformMtx;

            gDPPipeSync(gMasterGfxPos++);
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 112, 96, 24, part->primAlpha);
            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                        G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMasterGfxPos++, dlist);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        }
    }
    gDPPipeSync(gMasterGfxPos++);
}
