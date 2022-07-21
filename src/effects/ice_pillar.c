#include "common.h"
#include "effects_internal.h"

void ice_pillar_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/ice_pillar", ice_pillar_main);

void ice_pillar_init(void) {
}

INCLUDE_ASM(s32, "effects/ice_pillar", ice_pillar_update);

void ice_pillar_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = ice_pillar_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 5;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/ice_pillar", ice_pillar_appendGfx);
