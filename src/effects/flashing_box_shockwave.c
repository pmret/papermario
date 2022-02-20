#include "common.h"
#include "effects_internal.h"

void flashing_box_shockwave_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/flashing_box_shockwave", flashing_box_shockwave_main);

void flashing_box_shockwave_init(void) {
}

INCLUDE_ASM(s32, "effects/flashing_box_shockwave", flashing_box_shockwave_update);

void flashing_box_shockwave_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = flashing_box_shockwave_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/flashing_box_shockwave", flashing_box_shockwave_appendGfx);
