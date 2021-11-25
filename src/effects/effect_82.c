#include "common.h"
#include "effects_internal.h"

typedef struct Effect82 {
    /* 0x00 */ s32 unk_00;
} Effect82; // size = ??

INCLUDE_ASM(s32, "effects/effect_82", fx_82_main);

void fx_82_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_82", fx_82_update);

void fx_82_appendGfx(EffectInstance* effect);
void fx_82_render(EffectInstance* effect) {
    Effect82* effect82 = effect->data;
    RenderTask renderTask;
    RenderTask* retTask;
    RenderTask* renderTaskPointer = &renderTask;

    renderTask.appendGfx = fx_82_appendGfx;
    renderTask.distance = 10;
    renderTask.appendGfxArg = effect;
    renderTask.renderMode = RENDER_MODE_2D;
    if (effect82->unk_00 >= 3) {
        shim_queue_render_task(renderTaskPointer);
        return;
    }

    retTask = shim_queue_render_task(renderTaskPointer);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00A4648(void) {
}

INCLUDE_ASM(s32, "effects/effect_82", fx_82_appendGfx);
