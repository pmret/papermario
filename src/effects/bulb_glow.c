#include "common.h"
#include "effects_internal.h"

void bulb_glow_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/bulb_glow", bulb_glow_main);

void bulb_glow_init(void) {
}

INCLUDE_ASM(s32, "effects/bulb_glow", bulb_glow_update);

void bulb_glow_render(EffectInstance* effect) {
    BulbGlowFXData* effect60 = effect->data;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    RenderTask* retTask;

    renderTask.appendGfxArg = effect;
    renderTask.appendGfx = bulb_glow_appendGfx;
    if (effect60->unk_00 == 5) {
        renderTask.distance = 0;
        renderTaskPtr->renderMode = RENDER_MODE_SURFACE_OPA;
    } else {
        renderTask.distance = -100;
        renderTaskPtr->renderMode = RENDER_MODE_2D;
    }

    retTask = shim_queue_render_task(renderTaskPtr);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E0078274(void) {
}

INCLUDE_ASM(s32, "effects/bulb_glow", bulb_glow_appendGfx);
