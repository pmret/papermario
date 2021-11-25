#include "common.h"
#include "effects_internal.h"

void fx_53_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_53", func_E006A000);

INCLUDE_ASM(s32, "effects/effect_53", func_E006A0BC);

INCLUDE_ASM(s32, "effects/effect_53", fx_53_main);

void fx_53_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_53", func_E006A464);

INCLUDE_ASM(s32, "effects/effect_53", fx_53_update);

void fx_53_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_53_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_53", func_E006A85C);

INCLUDE_ASM(s32, "effects/effect_53", fx_53_appendGfx);
