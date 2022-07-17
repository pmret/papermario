#include "common.h"
#include "effects_internal.h"

void light_rays_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/light_rays", func_E006A000);

INCLUDE_ASM(s32, "effects/light_rays", func_E006A0BC);

INCLUDE_ASM(s32, "effects/light_rays", light_rays_main);

void light_rays_init(void) {
}

INCLUDE_ASM(s32, "effects/light_rays", func_E006A464);

INCLUDE_ASM(s32, "effects/light_rays", light_rays_update);

void light_rays_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = light_rays_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/light_rays", func_E006A85C);

INCLUDE_ASM(s32, "effects/light_rays", light_rays_appendGfx);
