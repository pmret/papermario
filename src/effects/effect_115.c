#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_115", fx_115_main);

void fx_115_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_115", fx_115_update);

void fx_115_appendGfx(EffectInstance* effect);
void fx_115_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_115_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_OPA;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00E651C(void) {
}

INCLUDE_ASM(s32, "effects/effect_115", fx_115_appendGfx);
