#include "common.h"
#include "effects_internal.h"

void hieroglyphs_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/hieroglyphs", hieroglyphs_main);

void hieroglyphs_init(void) {
}

// INCLUDE_ASM(s32, "effects/hieroglyphs", hieroglyphs_update);
void hieroglyphs_update(EffectInstance *arg0) {
    s32 *temp_a1;
    s32 temp_a2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;

    temp_v1 = arg0->flags;
    temp_a1 = arg0->data.any;
    if (temp_v1 & 0x10) {
        arg0->flags = temp_v1 & ~0x10;
        temp_a1->unk10 = 0x10;
    }
    temp_v1_2 = temp_a1->unk10;
    if (temp_v1_2 < 0x3E8) {
        temp_a1->unk10 = (s32) (temp_v1_2 - 1);
    }
    temp_v1_3 = temp_a1->unk10;
    temp_a2 = temp_a1->unk14 + 1;
    temp_a1->unk14 = temp_a2;
    if (temp_v1_3 < 0) {
        shim_remove_effect(arg0);
        return;
    }
    if (temp_v1_3 < 0x10) {
        temp_a1->unk24 = (s32) (temp_v1_3 * 0x10);
    }
    if (temp_a2 < 0x10) {
        temp_a1->unk24 = (s32) ((temp_a2 * 0x10) + 0xF);
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
