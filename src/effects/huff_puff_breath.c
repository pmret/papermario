#include "common.h"
#include "effects_internal.h"

void huff_puff_breath_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/huff_puff_breath", huff_puff_breath_main);

void huff_puff_breath_init(void) {
}

// INCLUDE_ASM(s32, "effects/huff_puff_breath", huff_puff_breath_update);
void huff_puff_breath_update(EffectInstance *arg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    s32 *temp_v1;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a2;

    temp_a1 = arg0->flags;
    temp_v1 = arg0->data.any;
    if (temp_a1 & 0x10) {
        arg0->flags = temp_a1 & ~0x10;
        temp_v1->unk10 = 0x10;
    }
    temp_a1_2 = temp_v1->unk10;
    if (temp_a1_2 < 0x3E8) {
        temp_v1->unk10 = (s32) (temp_a1_2 - 1);
    }
    temp_a1_3 = temp_v1->unk10;
    temp_a2 = temp_v1->unk14 + 1;
    temp_v1->unk14 = temp_a2;
    if (temp_a1_3 < 0) {
        shim_remove_effect(arg0);
        return;
    }
    if (temp_a1_3 < 0x10) {
        temp_v1->unk24 = (s32) (temp_a1_3 * 0x10);
    }
    if (temp_a2 < 0x10) {
        temp_v1->unk24 = (s32) ((temp_a2 * 0x10) + 0xF);
    }
    temp_f0 = temp_v1->unk38 + temp_v1->unk3C;
    temp_v1->unk38 = temp_f0;
    if (temp_f0 >= 256.0f) {
        temp_v1->unk38 = (f32) (temp_f0 - 256.0f);
    }
    temp_f0_2 = temp_v1->unk38;
    if (temp_f0_2 < 0.0f) {
        temp_v1->unk38 = (f32) (temp_f0_2 + 256.0f);
    }
    temp_f0_3 = temp_v1->unk40 + temp_v1->unk44;
    temp_v1->unk40 = temp_f0_3;
    if (temp_f0_3 >= 256.0f) {
        temp_v1->unk40 = (f32) (temp_f0_3 - 256.0f);
    }
    temp_f0_4 = temp_v1->unk40;
    if (temp_f0_4 < 0.0f) {
        temp_v1->unk40 = (f32) (temp_f0_4 + 256.0f);
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
