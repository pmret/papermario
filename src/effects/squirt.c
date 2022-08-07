#include "common.h"
#include "effects_internal.h"

s32 D_E00B2BA0[] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFC88020, 0x00000000 };

void squirt_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/squirt", squirt_main);

void squirt_init(void) {
}

INCLUDE_ASM(s32, "effects/squirt", squirt_update);

void squirt_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = squirt_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00B24A8(void) {
}

INCLUDE_ASM(s32, "effects/squirt", squirt_appendGfx);
