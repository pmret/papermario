#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_68", func_E0088000);

INCLUDE_ASM(s32, "effects/effect_68", fx_68_main);

void fx_68_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_68", fx_68_update);

void fx_68_appendGfx(EffectInstance* effect);
void fx_68_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_68_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/effect_68", fx_68_appendGfx);
