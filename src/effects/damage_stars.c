#include "common.h"
#include "effects_internal.h"

void damage_stars_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/damage_stars", damage_stars_main);

void damage_stars_init(void) {
}

INCLUDE_ASM(s32, "effects/damage_stars", damage_stars_update);

void damage_stars_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = damage_stars_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/damage_stars", damage_stars_appendGfx);
