#include "common.h"
#include "effects_internal.h"

void hieroglyphs_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/hieroglyphs", hieroglyphs_main);

void hieroglyphs_init(void) {
}

INCLUDE_ASM(s32, "effects/hieroglyphs", hieroglyphs_update);

void hieroglyphs_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = hieroglyphs_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00E2210(void) {
}

INCLUDE_ASM(s32, "effects/hieroglyphs", hieroglyphs_appendGfx);
