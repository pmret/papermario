#include "common.h"
#include "effects_internal.h"

void misc_particles_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/misc_particles", misc_particles_main);

void misc_particles_init(void) {
}

INCLUDE_ASM(s32, "effects/misc_particles", misc_particles_update);

void misc_particles_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = misc_particles_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 7;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00E4954(void) {
}

INCLUDE_ASM(s32, "effects/misc_particles", misc_particles_appendGfx);
