#include "common.h"
#include "effects_internal.h"

void fright_jar_eff_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/fright_jar_eff", fright_jar_eff_main);

void fright_jar_eff_init(void) {
}

INCLUDE_ASM(s32, "effects/fright_jar_eff", fright_jar_eff_update);

void fright_jar_eff_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fright_jar_eff_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00C2214(void) {
}

INCLUDE_ASM(s32, "effects/fright_jar_eff", fright_jar_eff_appendGfx);
