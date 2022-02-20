#include "common.h"
#include "effects_internal.h"

void waterfall_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/waterfall", waterfall_main);

void waterfall_init(void) {
}

INCLUDE_ASM(s32, "effects/waterfall", waterfall_update);

void waterfall_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = waterfall_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

void func_E00B62D8(void) {
}

INCLUDE_ASM(s32, "effects/waterfall", waterfall_appendGfx);
