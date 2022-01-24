#include "common.h"
#include "effects_internal.h"

void spiky_white_aura_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/spiky_white_aura", spiky_white_aura_main);

void spiky_white_aura_init(void) {
}

INCLUDE_ASM(s32, "effects/spiky_white_aura", spiky_white_aura_update);

void spiky_white_aura_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = spiky_white_aura_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/spiky_white_aura", spiky_white_aura_appendGfx);
