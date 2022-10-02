#include "common.h"
#include "effects_internal.h"

void hieroglyphs_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/hieroglyphs", hieroglyphs_main);

void hieroglyphs_init(void) {
}

void hieroglyphs_update(EffectInstance* effect) {
    HieroglyphsFXData* data = effect->data.hieroglyphs;
    s32 temp_a2;
    s32 temp_v1 = effect->flags;
    s32 temp_v1_2;
    s32 temp_v1_3;

    if (temp_v1 & 16) {
        effect->flags = temp_v1 & ~16;
        data->unk_10 = 16;
    }
    temp_v1_2 = data->unk_10;
    if (temp_v1_2 < 1000) {
        data->unk_10 = (s32) (temp_v1_2 - 1);
    }
    temp_v1_3 = data->unk_10;
    temp_a2 = data->unk_14 + 1;
    data->unk_14 = temp_a2;
    if (temp_v1_3 < 0) {
        shim_remove_effect(effect);
        return;
    }
    if (temp_v1_3 < 16) {
        data->unk_24 = (s32) (temp_v1_3 * 16);
    }
    if (temp_a2 < 16) {
        data->unk_24 = (s32) ((temp_a2 * 16) + 15);
    }
}

void hieroglyphs_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = hieroglyphs_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00E2210(void) {
}

INCLUDE_ASM(s32, "effects/hieroglyphs", hieroglyphs_appendGfx);
