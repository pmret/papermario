#include "common.h"
#include "effects_internal.h"

void fire_flower_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/fire_flower", fire_flower_main);

void fire_flower_init(void) {
}

INCLUDE_ASM(s32, "effects/fire_flower", fire_flower_update);

void fire_flower_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fire_flower_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/fire_flower", fire_flower_appendGfx);
