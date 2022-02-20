#include "common.h"
#include "effects_internal.h"

void snaking_static_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/snaking_static", snaking_static_main);

void snaking_static_init(void) {
}

INCLUDE_ASM(s32, "effects/snaking_static", snaking_static_update);

void snaking_static_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = snaking_static_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00AE544(void) {
}

INCLUDE_ASM(s32, "effects/snaking_static", snaking_static_appendGfx);
