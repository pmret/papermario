#include "common.h"
#include "effects_internal.h"

void spirit_card_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/spirit_card", spirit_card_main);

void spirit_card_init(void) {
}

INCLUDE_ASM(s32, "effects/spirit_card", spirit_card_update);

void spirit_card_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = spirit_card_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/spirit_card", func_E0112330);

INCLUDE_ASM(s32, "effects/spirit_card", spirit_card_appendGfx);
