#include "common.h"
#include "effects_internal.h"

void aura_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/aura", aura_main);

void aura_init(void) {
}

INCLUDE_ASM(s32, "effects/aura", aura_update);

void aura_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = aura_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E007684C(void) {
}

void func_E0076854(void) {
}

INCLUDE_ASM(s32, "effects/aura", aura_appendGfx);
