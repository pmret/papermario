#include "common.h"
#include "effects_internal.h"

void fx_3D_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/effect_3D", fx_3D_main);

void fx_3D_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_3D", fx_3D_update);

void fx_3D_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_3D_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E007A884(void) {
}

INCLUDE_ASM(s32, "effects/effect_3D", fx_3D_appendGfx);
