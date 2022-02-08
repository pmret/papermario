#include "common.h"
#include "effects_internal.h"

void throw_spiny_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/throw_spiny", throw_spiny_main);

void throw_spiny_init(void) {
}

INCLUDE_ASM(s32, "effects/throw_spiny", throw_spiny_update);

void throw_spiny_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = throw_spiny_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00C844C(void) {
}

INCLUDE_ASM(s32, "effects/throw_spiny", throw_spiny_appendGfx);
