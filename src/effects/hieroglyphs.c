#include "common.h"
#include "effects_internal.h"

void hieroglyphs_appendGfx(void* effect);

// INCLUDE_ASM(s32, "effects/hieroglyphs", hieroglyphs_main);
void hieroglyphs_main(f32 arg4, s32 arg5) {
    s32 sp10;
    s32 sp14;
    void (*sp18)();
    void (*sp1C)(EffectInstance *);
    void (*sp20)(EffectInstance *);
    s32 sp24;
    EffectInstance *temp_v0;
    s32 *temp_v0_2;

    sp18 = hieroglyphs_init;
    sp1C = hieroglyphs_update;
    sp20 = hieroglyphs_render;
    sp10 = 0;
    sp24 = 0;
    sp14 = 0x71;
    temp_v0 = shim_create_effect_instance((EffectBlueprint *) &sp10);
    temp_v0->numParts = 1;
    temp_v0_2 = shim_general_heap_malloc(0x3C);
    temp_v0->data.any = temp_v0_2;
    if (temp_v0_2 == NULL) {
loop_1:
        goto loop_1;
    }
    temp_v0_2->unk0 = M2C_ERROR(Read from unset register $a0);
    temp_v0_2->unk14 = 0;
    if (arg5 <= 0) {
        temp_v0_2->unk10 = 0x3E8;
    } else {
        temp_v0_2->unk10 = arg5;
    }
    temp_v0_2->unk24 = 0;
    temp_v0_2->unk4 = (f32) M2C_ERROR(Read from unset register $a1);
    temp_v0_2->unk8 = (f32) M2C_ERROR(Read from unset register $a2);
    temp_v0_2->unkC = (f32) M2C_ERROR(Read from unset register $a3);
    temp_v0_2->unk18 = 0x46;
    temp_v0_2->unk1C = 0xB4;
    temp_v0_2->unk20 = 0x78;
    temp_v0_2->unk28 = 0x14;
    temp_v0_2->unk2C = 0xE6;
    temp_v0_2->unk30 = 0x32;
    temp_v0_2->unk34 = 0xFF;
    temp_v0_2->unk38 = arg4;
}

void hieroglyphs_init(void) {
}

void hieroglyphs_update(EffectInstance* effect) {
    HieroglyphsFXData* data = effect->data.hieroglyphs;
    s32 temp_a2;

    if (effect->flags & 16) {
        effect->flags &= ~16;
        data->timeLeft = 16;
    }

    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }
    temp_a2 = ++data->lifeTime;
    if (data->timeLeft < 0) {
        shim_remove_effect(effect);
        return;
    }
    if (data->timeLeft < 16) {
        data->unk_24 = data->timeLeft * 16;
    }
    if (temp_a2 < 16) {
        data->unk_24 = (temp_a2 * 16) + 15;
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
