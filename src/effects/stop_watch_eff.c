#include "common.h"
#include "effects_internal.h"

void stop_watch_eff_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/stop_watch_eff", stop_watch_eff_main);

void stop_watch_eff_init(void) {
}

INCLUDE_ASM(s32, "effects/stop_watch_eff", stop_watch_eff_update);

void stop_watch_eff_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = stop_watch_eff_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

void func_E00C4300(void) {
}

INCLUDE_ASM(s32, "effects/stop_watch_eff", stop_watch_eff_appendGfx);
