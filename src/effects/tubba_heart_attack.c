#include "common.h"
#include "effects_internal.h"

void tubba_heart_attack_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/tubba_heart_attack", tubba_heart_attack_main);

void tubba_heart_attack_init(void) {
}

INCLUDE_ASM(s32, "effects/tubba_heart_attack", tubba_heart_attack_update);

void tubba_heart_attack_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = tubba_heart_attack_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00CC9C8(void) {
}

INCLUDE_ASM(s32, "effects/tubba_heart_attack", tubba_heart_attack_appendGfx);
