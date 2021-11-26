#include "common.h"
#include "effects_internal.h"

typedef struct Effect55 {
    /* 0x00 */ char unk_00[0x14];
    /* 0x14 */ f32 unk_14;
} Effect55; // size = 0x??

void fx_55_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_55", fx_55_main);

void fx_55_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_55", fx_55_update);

void fx_55_render(EffectInstance *effect) {
    Effect55* effect55 = effect->data;
    RenderTask renderTask;
    RenderTask* retTask;
    RenderTask* renderTaskPointer = &renderTask;

    renderTask.appendGfx = fx_55_appendGfx;
    renderTask.appendGfxArg = effect;
    if (gGameStatusPtr->isBattle == 1) {
        renderTask.distance = effect55->unk_14 + 1000.0f;
    } else {
        renderTask.distance = 0;
    }

    renderTaskPointer->renderMode = RENDER_MODE_2D;
    retTask = shim_queue_render_task(renderTaskPointer);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_55", fx_55_appendGfx);
