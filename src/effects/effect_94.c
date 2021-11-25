#include "common.h"
#include "effects_internal.h"

typedef struct Effect94 {
    /* 0x00 */ char unk_00[0xC];
    /* 0x0C */ f32 unk_0C;
} Effect94; // size = 0x??

void fx_94_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_94", fx_94_main);

void fx_94_init(void) {
}

f32 func_E00BC1D8(f32 arg0) {
    return (f32)shim_rand_int((s32)arg0) - arg0 * 0.5;
}

INCLUDE_ASM(s32, "effects/effect_94", fx_94_update);

void fx_94_render(EffectInstance *effect) {
    Effect94* effect94 = effect->data;
    RenderTask renderTask;
    RenderTask* retTask;
    RenderTask* renderTaskPointer = &renderTask;

    renderTask.appendGfx = fx_94_appendGfx;
    renderTask.appendGfxArg = effect;
    if (gGameStatusPtr->isBattle == TRUE) {
        renderTask.distance = effect94->unk_0C + 1000.0f;
    } else {
        renderTask.distance = 10;
    }

    renderTaskPointer->renderMode = RENDER_MODE_2D;
    retTask = shim_queue_render_task(renderTaskPointer);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00BC36C(void) {
}

INCLUDE_ASM(s32, "effects/effect_94", fx_94_appendGfx);
