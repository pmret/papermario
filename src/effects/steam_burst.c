#include "common.h"
#include "effects_internal.h"

void steam_burst_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/steam_burst", steam_burst_main);

void steam_burst_init(void) {
}

INCLUDE_ASM(s32, "effects/steam_burst", steam_burst_update);

void steam_burst_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = steam_burst_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/steam_burst", steam_burst_appendGfx);
