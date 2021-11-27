#include "common.h"
#include "effects_internal.h"

void fx_97_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_97", fx_97_main);

void fx_97_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_97", fx_97_update);

void fx_97_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_97_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00C2214(void) {
}

INCLUDE_ASM(s32, "effects/effect_97", fx_97_appendGfx);
