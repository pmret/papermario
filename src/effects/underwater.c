#include "common.h"
#include "effects_internal.h"

void underwater_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/underwater", underwater_main);

void underwater_init(void) {
}

INCLUDE_ASM(s32, "effects/underwater", underwater_update);

void underwater_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = underwater_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 100;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

void func_E00BA618(void) {
}

INCLUDE_ASM(s32, "effects/underwater", underwater_appendGfx);
