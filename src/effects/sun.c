#include "common.h"
#include "effects_internal.h"

void sun_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/sun", sun_main);

void sun_init(void) {
}

INCLUDE_ASM(s32, "effects/sun", sun_update);

void sun_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = sun_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/sun", sun_appendGfx);
