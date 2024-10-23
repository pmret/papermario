#include "common.h"
#include "effects_internal.h"

extern Gfx D_090000E0_32ED30[];
extern Gfx D_090001B8_32EE08[];

void cloud_trail_init(EffectInstance* effect);
void cloud_trail_update(EffectInstance* effect);
void cloud_trail_render(EffectInstance* effect);
void cloud_trail_appendGfx(void* effect);

void cloud_trail_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    EffectBlueprint bp;
    EffectInstance* effect;
    CloudTrailFXData* part;
    s32 numParts = 1;
    s32 i;

    bp.unk_00 = 0;
    bp.init = cloud_trail_init;
    bp.update = cloud_trail_update;
    bp.renderScene = cloud_trail_render;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_CLOUD_TRAIL;

    effect = create_effect_instance(&bp);
    effect->numParts = 1;
    part = general_heap_malloc(numParts * sizeof(*part));
    effect->data.cloudTrail = part;

    ASSERT(effect->data.cloudTrail != NULL);

    mem_clear(part, numParts * sizeof(*part));

    for (i = 0; i < numParts; i++, part++) {
        part->alive = 1;
        part->unk_04 = arg0;
        part->unk_40 = 0;
        part->unk_44 = 0;
        part->unk_0C = arg1;
        part->unk_10 = arg2;
        part->unk_14 = arg3;
        part->unk_1C = 1.0f;
        part->unk_20 = 1.0f;
        part->unk_24 = 1.0f;
        part->alpha = -1;
        part->unk_28 = (rand_int(10) * 0.03) + 1.4;
        part->unk_2C = (rand_int(10) * 0.03) + 1.5;
        part->unk_30 = effect_rand_int(60);
        part->unk_04 = arg0;
        part->lifetime = 15;
        part->unk_38 = 2.0f;
        part->unk_3C = -0.5f;
        part->unk_18 = effect_rand_int(360);
        part->alpha = -1;
    }
}

void cloud_trail_init(EffectInstance* effect) {
}

void cloud_trail_update(EffectInstance* effect) {
    CloudTrailFXData* part = effect->data.cloudTrail;
    s32 cond = FALSE;
    s32 i;

    for (i = 0; i < effect->numParts; i++, part++) {
        if (part->alive) {
            part->lifetime--;
            if (part->lifetime <= 0) {
                part->alive = FALSE;
            } else {
                cond = TRUE;
                part->unk_30 = clamp_angle(part->unk_30 + 12.0f);
                part->unk_1C = part->unk_28 + sin_deg(part->unk_30) * 0.1;
                part->unk_20 = part->unk_2C + cos_deg(part->unk_30) * 0.1;

                if (part->unk_04 == 0 && (part->lifetime == 5 && gPlayerStatus.actionState == ACTION_STATE_IDLE)) {
                    part->lifetime++;
                    return;
                }

                part->alpha -= 15;
                part->unk_3C += part->unk_40;
                part->unk_38 += part->unk_3C;
                part->unk_10 += part->unk_38;
                part->unk_28 += 0.14;
                part->unk_2C *= 0.94;

                if (part->unk_38 < 0.0f) {
                    part->unk_3C = 0.0f;
                    part->unk_38 = 0.0f;
                }
            }
        }
    }

    if (!cond) {
        remove_effect(effect);
    }
}

void cloud_trail_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = cloud_trail_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_PASS_THROUGH;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void cloud_trail_appendGfx(void* effect) {
    EffectInstance* effectTemp = effect;
    CloudTrailFXData* part = effectTemp->data.cloudTrail;
    Matrix4f sp20;
    Matrix4f sp60;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->shared->graphics));
    gSPDisplayList(gMainGfxPos++, D_090000E0_32ED30);

    for (i = 0; i < effectTemp->numParts; i++, part++) {
        if (part->alive) {
            guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f,
                             part->unk_0C, part->unk_10, part->unk_14);
            guScaleF(sp60, part->unk_1C, part->unk_20, part->unk_24);
            guMtxCatF(sp60, sp20, sp20);
            guRotateF(sp60, part->unk_18, 0.0f, 0.0f, 1.0f);
            guMtxCatF(sp60, sp20, sp20);
            guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gDPSetPrimColor(gMainGfxPos++, 0, 0, 112, 96, 24, part->alpha);
            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                        G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_090001B8_32EE08);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }
    gDPPipeSync(gMainGfxPos++);
}
