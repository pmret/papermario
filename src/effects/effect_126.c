#include "common.h"
#include "effects_internal.h"

void fx_126_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/effect_126", fx_126_main);

void fx_126_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_126", fx_126_update);

void fx_126_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_126_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_126", fx_126_appendGfx);
