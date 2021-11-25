#include "common.h"
#include "effects_internal.h"

void fx_119_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_119", fx_119_main);

void fx_119_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_119", fx_119_update);

void fx_119_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_119_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 700;
    renderTask.renderMode =  RENDER_MODE_SURFACE_OPA;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_119", fx_119_appendGfx);
