#include "common.h"
#include "effects_internal.h"

extern Gfx D_090000E0_32ED30[];
extern Gfx D_090001B8_32EE08[];

void cloud_puff_init(EffectInstance* effect);
void cloud_puff_update(EffectInstance* effect);
void cloud_puff_render(EffectInstance* effect);
void cloud_puff_appendGfx(void* effect);

void cloud_puff_main(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    EffectBlueprint bp;
    EffectInstance* effect;
    f32 temp_f20;
    CloudPuffFXData* part;
    s32 numParts = 8;
    s32 i;

    bp.unk_00 = 0;
    bp.init = cloud_puff_init;
    bp.update = cloud_puff_update;
    bp.renderWorld = cloud_puff_render;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_CLOUD_PUFF;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    part = general_heap_malloc(numParts * sizeof(*part));
    effect->data.cloudPuff = part;
    ASSERT(effect->data.cloudPuff != NULL);

    mem_clear(part, numParts * sizeof(*part));

    for (i = 0; i < numParts; i++, part++) {
        part->alive = TRUE;
        part->unk_40 = 0;
        part->unk_0C = arg0;
        part->unk_10 = arg1;
        part->unk_14 = arg2;
        part->unk_18 = 1.0f;
        part->unk_1C = 1.0f;
        part->unk_20 = 1.0f;
        part->alpha = 255;
        part->unk_24 = (rand_int(10) * 0.03) + 1.0;
        part->unk_28 = (rand_int(10) * 0.03) + 1.7;
        part->unk_2C = effect_rand_int(60);
        part->timeLeft = 30;
        part->unk_34 = 0.5f;
        part->unk_38 = -0.02f;
        part->unk_3C = 0.00005f;
        part->unk_30 = -3.9f;
        temp_f20 = clamp_angle(arg3 + i * 45);
        part->unk_44 = sin_deg(temp_f20);
        part->unk_48 = cos_deg(temp_f20);
    }
}

void cloud_puff_init(EffectInstance* effect) {
}

void cloud_puff_update(EffectInstance* effect) {
    CloudPuffFXData* part = effect->data.cloudPuff;
    s32 cond = FALSE;
    s32 i;

    for (i = 0; i < effect->numParts; i++, part++) {
        if (part->alive) {
            part->timeLeft--;
            if (part->timeLeft <= 0) {
                part->alive = FALSE;
            } else {
                cond = TRUE;
                part->unk_2C = clamp_angle(part->unk_2C + 12.0f);
                part->unk_18 = part->unk_24 + sin_deg(part->unk_2C) * 0.1;
                part->unk_1C = part->unk_28 + cos_deg(part->unk_2C) * 0.1;
                part->unk_30 *= 0.83;
                part->unk_0C += part->unk_30 * part->unk_44;
                part->unk_14 += part->unk_30 * part->unk_48;
                part->unk_24 += (7.5 - part->unk_24) * 0.006;
                part->unk_38 += part->unk_3C;
                part->unk_34 += part->unk_38;
                part->unk_10 += part->unk_34;
                part->unk_28 *= 0.98;

                if (part->timeLeft < 10) {
                    part->unk_28 *= 0.9;
                }

                if (part->timeLeft < 15) {
                    part->alpha -= 16;
                }
            }
        }
    }

    if (!cond) {
        remove_effect(effect);
    }
}

void cloud_puff_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = cloud_puff_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void cloud_puff_appendGfx(void* effect) {
    EffectInstance* effectTemp = effect;
    CloudPuffFXData* part = effectTemp->data.cloudPuff;
    Matrix4f sp20;
    Matrix4f sp60;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(effectTemp->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_090000E0_32ED30);

    for (i = 0; i < effectTemp->numParts; i++, part++) {
        if (part->alive) {
            guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f,
                             part->unk_0C, part->unk_10, part->unk_14);
            guScaleF(sp60, part->unk_18, part->unk_1C, part->unk_20);
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
