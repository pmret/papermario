#include "common.h"
#include "effects_internal.h"

void explosion_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/explosion", explosion_main);

void explosion_init(void) {
}

INCLUDE_ASM(s32, "effects/explosion", explosion_update);

void explosion_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = explosion_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/explosion", explosion_appendGfx);
