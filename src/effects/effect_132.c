#include "common.h"
#include "effects_internal.h"

void fx_132_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_132", fx_132_main);

void fx_132_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_132", fx_132_update);

void fx_132_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_132_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/effect_132", fx_132_appendGfx);
