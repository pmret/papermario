#include "common.h"
#include "effects_internal.h"

void bombette_breaking_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/bombette_breaking", func_E0084000);

INCLUDE_ASM(s32, "effects/bombette_breaking", func_E008403C);

INCLUDE_ASM(s32, "effects/bombette_breaking", func_E0084060);

INCLUDE_ASM(s32, "effects/bombette_breaking", bombette_breaking_main);

void bombette_breaking_init(void) {
}

INCLUDE_ASM(s32, "effects/bombette_breaking", bombette_breaking_update);

void bombette_breaking_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = bombette_breaking_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/bombette_breaking", bombette_breaking_appendGfx);
