#include "common.h"
#include "effects.h"

INCLUDE_ASM(s32, "effects/effect_66", func_E0084000);

INCLUDE_ASM(s32, "effects/effect_66", func_E008403C);

INCLUDE_ASM(s32, "effects/effect_66", func_E0084060);

INCLUDE_ASM(s32, "effects/effect_66", fx_66_main);

void fx_66_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_66", fx_66_update);

void fx_66_appendGfx(EffectInstance* effect);
void fx_66_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_66_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_66", fx_66_appendGfx);
