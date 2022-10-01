#include "common.h"
#include "effects_internal.h"

void ice_shard_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/ice_shard", ice_shard_main);

void ice_shard_init(void) {
}

INCLUDE_ASM(s32, "effects/ice_shard", ice_shard_update);

void ice_shard_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = ice_shard_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/ice_shard", ice_shard_appendGfx);
