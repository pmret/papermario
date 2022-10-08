#include "common.h"
#include "effects_internal.h"

void sweat_init(EffectInstance* effect);
void sweat_update(EffectInstance* effect);
void sweat_render(EffectInstance* effect);
void sweat_appendGfx(void* effect);

void sweat_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 timeLeft) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    SweatFXData* data;
    Matrix4f matrix;
    f32 temp_f2;
    s32 numParts = 1;

    effectBp.init = (void*)sweat_init;
    effectBp.update = sweat_update;
    effectBp.renderWorld = sweat_render;
    effectBp.unk_00 = 0;
    effectBp.unk_14 = 0;
    effectBp.effectID = EFFECT_SWEAT;

    effect = shim_create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.sweat = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->unk_00 = arg0;
    shim_guRotateF(matrix, -arg5, shim_sin_deg(gCameras[gCurrentCameraID].currentYaw), 0.0f, -shim_cos_deg(gCameras[gCurrentCameraID].currentYaw));
    temp_f2 = arg4 + 16.0f;
    data->pos.x = arg1 + (matrix[1][0] * temp_f2);
    data->pos.y = arg2 + (matrix[1][1] * temp_f2);
    data->pos.z = arg3 + (matrix[1][2] * temp_f2);
    data->unk_18 = matrix[1][0];
    data->unk_1C = matrix[1][1];
    data->unk_20 = matrix[1][2];
    data->unk_10 = arg5;
    data->timeLeft = timeLeft;
}


void sweat_init(EffectInstance* effect) {
}

void sweat_update(EffectInstance *effect) {
    SweatFXData* data = effect->data.sweat;

    data->timeLeft--;
    if (data->timeLeft < 0) {
        shim_remove_effect(effect);
        return;
    }
    data->pos.x += data->unk_18;
    data->pos.y += data->unk_1C;
    data->pos.z += data->unk_20;
    data->unk_1C -= 0.05;
    data->unk_18 *= 0.94;
    if (data->unk_1C < -0.1) {
        data->unk_1C = -0.1f;
    }
    data->unk_20 *= 0.94;
}

void sweat_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = sweat_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/sweat", sweat_appendGfx);
