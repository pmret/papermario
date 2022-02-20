#include "common.h"
#include "effects_internal.h"

void breaking_junk_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/breaking_junk", breaking_junk_main);

void breaking_junk_init(void) {
}

INCLUDE_ASM(s32, "effects/breaking_junk", breaking_junk_update);

void breaking_junk_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = breaking_junk_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/breaking_junk", breaking_junk_appendGfx);
