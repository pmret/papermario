#include "common.h"
#include "effects_internal.h"

void moving_cloud_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/moving_cloud", moving_cloud_main);

void moving_cloud_init(void) {
}

INCLUDE_ASM(s32, "effects/moving_cloud", moving_cloud_update);

void moving_cloud_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = moving_cloud_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/moving_cloud", moving_cloud_appendGfx);
