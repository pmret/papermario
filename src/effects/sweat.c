#include "common.h"
#include "effects_internal.h"

void sweat_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/sweat", sweat_main);

void sweat_init(void) {
}

INCLUDE_ASM(s32, "effects/sweat", sweat_update);

void sweat_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = sweat_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/sweat", sweat_appendGfx);
