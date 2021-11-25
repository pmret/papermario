#include "common.h"
#include "effects_internal.h"

void fx_107_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_107", fx_107_main);

void fx_107_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_107", fx_107_update);

void fx_107_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_107_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

void func_E00D6978(void) {
}

INCLUDE_ASM(s32, "effects/effect_107", fx_107_appendGfx);
