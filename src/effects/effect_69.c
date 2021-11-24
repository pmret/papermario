#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_69", func_E008A000);

INCLUDE_ASM(s32, "effects/effect_69", fx_69_main);

void fx_69_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_69", func_E008A290);

INCLUDE_ASM(s32, "effects/effect_69", fx_69_update);

void fx_69_appendGfx(EffectInstance* effect);
void fx_69_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_69_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_69", fx_69_appendGfx);
