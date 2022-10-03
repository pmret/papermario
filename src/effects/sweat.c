#include "common.h"
#include "effects_internal.h"

void sweat_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/sweat", sweat_main);

void sweat_init(void) {
}

void sweat_update(EffectInstance *effect) {
    SweatFXData* data = effect->data.sweat;

    data->unk_24--;
    if (data->unk_24 < 0) {
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
