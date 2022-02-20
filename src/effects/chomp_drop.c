#include "common.h"
#include "effects_internal.h"

void chomp_drop_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/chomp_drop", chomp_drop_main);

void chomp_drop_init(void) {
}

INCLUDE_ASM(s32, "effects/chomp_drop", chomp_drop_update);

void chomp_drop_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = chomp_drop_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = -10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/chomp_drop", chomp_drop_appendGfx);
