#include "common.h"
#include "effects_internal.h"

void snowfall_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/snowfall", func_E008A000);

INCLUDE_ASM(s32, "effects/snowfall", snowfall_main);

void snowfall_init(void) {
}

INCLUDE_ASM(s32, "effects/snowfall", func_E008A290);

INCLUDE_ASM(s32, "effects/snowfall", snowfall_update);

void snowfall_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = snowfall_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/snowfall", snowfall_appendGfx);
