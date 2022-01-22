#include "common.h"
#include "effects_internal.h"

void pink_sparkles_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/pink_sparkles", pink_sparkles_main);

void pink_sparkles_init(void) {
}

INCLUDE_ASM(s32, "effects/pink_sparkles", pink_sparkles_update);

void pink_sparkles_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = pink_sparkles_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/pink_sparkles", pink_sparkles_appendGfx);
