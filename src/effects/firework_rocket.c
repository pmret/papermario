#include "common.h"
#include "effects_internal.h"

void firework_rocket_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/firework_rocket", firework_rocket_main);

void firework_rocket_init(void) {
}

INCLUDE_ASM(s32, "effects/firework_rocket", firework_rocket_update);

void firework_rocket_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = firework_rocket_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 700;
    renderTask.renderMode =  RENDER_MODE_SURFACE_OPA;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/firework_rocket", firework_rocket_appendGfx);
