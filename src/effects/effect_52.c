#include "common.h"
#include "effects_internal.h"

typedef struct Effect52 {
    /* 0x00 */ s32 unk_00;
} Effect52; // size = 0x??

INCLUDE_ASM(s32, "effects/effect_52", fx_52_main);

void fx_52_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_52", fx_52_update);

void fx_52_appendGfx(EffectInstance* effect);
void fx_52_render(EffectInstance* effect) {
    Effect52* effect52 = effect->data;
    RenderTask renderTask;
    RenderTask* renderTaskTemp = &renderTask;
    RenderTask* retTask;

    renderTask.appendGfxArg = effect;
    renderTask.appendGfx = fx_52_appendGfx;
    renderTask.distance = 10;
    if (effect52->unk_00 == 0) {
        renderTaskTemp->renderMode = RENDER_MODE_SURFACE_OPA;
    } else {
        renderTaskTemp->renderMode = RENDER_MODE_2D;
    }
    
    retTask = shim_queue_render_task(renderTaskTemp);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_52", fx_52_appendGfx);
