#include "common.h"
#include "effects_internal.h"

void whirlwind_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/whirlwind", whirlwind_main);

void whirlwind_init(void) {
}

INCLUDE_ASM(s32, "effects/whirlwind", whirlwind_update);

void whirlwind_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = whirlwind_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00CE470(void) {
}

INCLUDE_ASM(s32, "effects/whirlwind", whirlwind_appendGfx);
