#include "common.h"
#include "effects_internal.h"

void huff_puff_breath_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/huff_puff_breath", huff_puff_breath_main);

void huff_puff_breath_init(void) {
}

void huff_puff_breath_update(EffectInstance* effect) {
    HuffPuffBreathFXData* data = effect->data.huffPuffBreath;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    s32 temp_a1 = effect->flags;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a2;

    if (temp_a1 & 16) {
        effect->flags = temp_a1 & ~16;
        data->unk_10 = 16;
    }
    temp_a1_2 = data->unk_10;
    if (temp_a1_2 < 1000) {
        data->unk_10 = (s32) (temp_a1_2 - 1);
    }
    temp_a1_3 = data->unk_10;
    temp_a2 = data->unk_14 + 1;
    data->unk_14 = temp_a2;
    if (temp_a1_3 < 0) {
        shim_remove_effect(effect);
        return;
    }
    if (temp_a1_3 < 16) {
        data->unk_24 = (s32) (temp_a1_3 * 16);
    }
    if (temp_a2 < 16) {
        data->unk_24 = (s32) ((temp_a2 * 16) + 15);
    }
    temp_f0 = data->unk_38 + data->unk_3C;
    data->unk_38 = temp_f0;
    if (temp_f0 >= 256.0f) {
        data->unk_38 = (f32) (temp_f0 - 256.0f);
    }
    temp_f0_2 = data->unk_38;
    if (temp_f0_2 < 0.0f) {
        data->unk_38 = (f32) (temp_f0_2 + 256.0f);
    }
    temp_f0_3 = data->unk_40 + data->unk_44;
    data->unk_40 = temp_f0_3;
    if (temp_f0_3 >= 256.0f) {
        data->unk_40 = (f32) (temp_f0_3 - 256.0f);
    }
    temp_f0_4 = data->unk_40;
    if (temp_f0_4 < 0.0f) {
        data->unk_40 = (f32) (temp_f0_4 + 256.0f);
    }
}

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
