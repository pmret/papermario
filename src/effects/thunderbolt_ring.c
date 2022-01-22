#include "common.h"
#include "effects_internal.h"

void thunderbolt_ring_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/thunderbolt_ring", thunderbolt_ring_main);

void thunderbolt_ring_init(void) {
}

INCLUDE_ASM(s32, "effects/thunderbolt_ring", thunderbolt_ring_update);

void thunderbolt_ring_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = thunderbolt_ring_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/thunderbolt_ring", thunderbolt_ring_appendGfx);
