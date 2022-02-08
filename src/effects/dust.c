#include "common.h"
#include "effects_internal.h"

void dust_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/dust", dust_main);

void dust_init(void) {
}

INCLUDE_ASM(s32, "effects/dust", dust_update);

void dust_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = dust_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/dust", dust_appendGfx);
