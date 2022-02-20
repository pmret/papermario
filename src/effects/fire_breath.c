#include "common.h"
#include "effects_internal.h"

typedef struct FireBreathFXData {
    /* 0x00 */ char unk_00[0x14];
    /* 0x14 */ f32 unk_14;
} FireBreathFXData; // size = 0x??

void fire_breath_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/fire_breath", fire_breath_main);

void fire_breath_init(void) {
}

INCLUDE_ASM(s32, "effects/fire_breath", fire_breath_update);

void fire_breath_render(EffectInstance *effect) {
    FireBreathFXData* effect55 = effect->data;
    RenderTask renderTask;
    RenderTask* retTask;
    RenderTask* renderTaskPointer = &renderTask;

    renderTask.appendGfx = fire_breath_appendGfx;
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

INCLUDE_ASM(s32, "effects/fire_breath", fire_breath_appendGfx);
