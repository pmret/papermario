#include "common.h"
#include "effects_internal.h"

void snowman_doll_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/snowman_doll", snowman_doll_main);

void snowman_doll_init(void) {
}

INCLUDE_ASM(s32, "effects/snowman_doll", snowman_doll_update);

void snowman_doll_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = snowman_doll_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = -10;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00C0758(void) {
}

INCLUDE_ASM(s32, "effects/snowman_doll", snowman_doll_appendGfx);
