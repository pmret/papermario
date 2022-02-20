#include "common.h"
#include "effects_internal.h"

void merlin_house_stars_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/merlin_house_stars", merlin_house_stars_main);

void merlin_house_stars_init(void) {
}

INCLUDE_ASM(s32, "effects/merlin_house_stars", merlin_house_stars_update);

void merlin_house_stars_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = merlin_house_stars_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00A639C(void) {
}

INCLUDE_ASM(s32, "effects/merlin_house_stars", merlin_house_stars_appendGfx);
