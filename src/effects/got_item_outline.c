#include "common.h"
#include "effects_internal.h"

void got_item_outline_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/got_item_outline", got_item_outline_main);

void got_item_outline_init(void) {
}

INCLUDE_ASM(s32, "effects/got_item_outline", got_item_outline_update);

void got_item_outline_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = got_item_outline_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E003621C(void) {
}

INCLUDE_ASM(s32, "effects/got_item_outline", got_item_outline_appendGfx);
