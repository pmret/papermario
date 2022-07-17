#include "common.h"
#include "effects_internal.h"

void fright_jar_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/fright_jar", fright_jar_main);

void fright_jar_init(void) {
}

INCLUDE_ASM(s32, "effects/fright_jar", fright_jar_update);

void fright_jar_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fright_jar_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00C2214(void) {
}

INCLUDE_ASM(s32, "effects/fright_jar", fright_jar_appendGfx);
