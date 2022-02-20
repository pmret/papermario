#include "common.h"
#include "effects_internal.h"

void huff_puff_breath_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/huff_puff_breath", huff_puff_breath_main);

void huff_puff_breath_init(void) {
}

INCLUDE_ASM(s32, "effects/huff_puff_breath", huff_puff_breath_update);

void huff_puff_breath_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = huff_puff_breath_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

void func_E00DC2FC(void) {
}

INCLUDE_ASM(s32, "effects/huff_puff_breath", huff_puff_breath_appendGfx);
