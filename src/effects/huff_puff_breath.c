#include "common.h"
#include "effects_internal.h"

void huff_puff_breath_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/huff_puff_breath", huff_puff_breath_main);

void huff_puff_breath_init(void) {
}

void huff_puff_breath_update(EffectInstance* effect) {
    HuffPuffBreathFXData* data = effect->data.huffPuffBreath;
    s32 temp_a1;
    s32 temp_a2;

    if (effect->flags & 16) {
        effect->flags &= ~16;
        data->unk_10 = 16;
    }
    if (data->unk_10 < 1000) {
        data->unk_10--;
    }
    temp_a1 = data->unk_10;     // Needed for match?
    temp_a2 = data->unk_14 + 1; // Needed for match?
    data->unk_14++;
    if (temp_a1 < 0) {
        shim_remove_effect(effect);
        return;
    }
    if (temp_a1 < 16) {
        data->unk_24 = temp_a1 * 16;
    }
    if (temp_a2 < 16) {
        data->unk_24 = (temp_a2 * 16) + 15;
    }
    data->unk_38 += data->unk_3C;
    if (data->unk_38 >= 256.0f) {
        data->unk_38 -= 256.0f;
    }
    if (data->unk_38 < 0.0f) {
        data->unk_38 += 256.0f;
    }
    data->unk_40 += data->unk_44;
    if (data->unk_40 >= 256.0f) {
        data->unk_40 -= 256.0f;
    }
    if (data->unk_40 < 0.0f) {
        data->unk_40 += 256.0f;
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
