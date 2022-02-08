#include "common.h"
#include "effects_internal.h"

void lil_oink_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/lil_oink", lil_oink_main);

void lil_oink_init(void) {
}

INCLUDE_ASM(s32, "effects/lil_oink", lil_oink_update);

void lil_oink_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = lil_oink_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/lil_oink", lil_oink_appendGfx);
