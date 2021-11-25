#include "common.h"
#include "effects_internal.h"

typedef struct Effect60 {
    /* 0x00 */ s32 unk_00;
} Effect60; // size = 0x??

void fx_60_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_60", fx_60_main);

void fx_60_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_60", fx_60_update);

void fx_60_render(EffectInstance* effect) {
    Effect60* effect60 = effect->data;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    RenderTask* retTask;

    renderTask.appendGfxArg = effect;
    renderTask.appendGfx = fx_60_appendGfx;
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

INCLUDE_ASM(s32, "effects/effect_60", fx_60_appendGfx);
