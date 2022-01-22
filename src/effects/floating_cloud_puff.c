#include "common.h"
#include "effects_internal.h"

void floating_cloud_puff_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/floating_cloud_puff", floating_cloud_puff_main);

void floating_cloud_puff_init(void) {
}

INCLUDE_ASM(s32, "effects/floating_cloud_puff", floating_cloud_puff_update);

void floating_cloud_puff_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = floating_cloud_puff_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00D227C(void) {
}

INCLUDE_ASM(s32, "effects/floating_cloud_puff", floating_cloud_puff_appendGfx);
