#include "common.h"
#include "effects_internal.h"

void snowman_doll_eff_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/snowman_doll_eff", snowman_doll_eff_main);

void snowman_doll_eff_init(void) {
}

INCLUDE_ASM(s32, "effects/snowman_doll_eff", snowman_doll_eff_update);

void snowman_doll_eff_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = snowman_doll_eff_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = -10;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00C0758(void) {
}

INCLUDE_ASM(s32, "effects/snowman_doll_eff", snowman_doll_eff_appendGfx);
