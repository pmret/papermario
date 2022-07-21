#include "common.h"
#include "effects_internal.h"

void shiny_flare_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/shiny_flare", shiny_flare_main);

void shiny_flare_init(void) {
}

INCLUDE_ASM(s32, "effects/shiny_flare", shiny_flare_update);

void shiny_flare_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = shiny_flare_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00DA228(void) {
}

INCLUDE_ASM(s32, "effects/shiny_flare", shiny_flare_appendGfx);
