#include "common.h"
#include "effects_internal.h"

void hieroglyphs_appendGfx(void* effect);

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

// INCLUDE_ASM(s32, "effects/hieroglyphs", hieroglyphs_main);
void hieroglyphs_main(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5) {
    s32 sp10;
    s32 sp14;
    void (*sp18)();
    void (*sp1C)(EffectInstance *);
    void (*sp20)(EffectInstance *);
    s32 sp24;
    EffectInstance* effect;
    HieroglyphsFXData* data;

    sp18 = hieroglyphs_init;
    sp1C = hieroglyphs_update;
    sp20 = hieroglyphs_render;
    sp10 = 0;
    sp24 = 0;
    sp14 = 113;
    effect = shim_create_effect_instance((EffectBlueprint *) &sp10);
    effect->numParts = 1;
    data = shim_general_heap_malloc(60);
    effect->data.hieroglyphs = data;
    if (data == NULL) {
loop_1:
        goto loop_1;
    }
    data->unk_00 = arg0;
    data->lifeTime = 0;
    if (arg5 <= 0) {
        data->timeLeft = 1000;
    } else {
        data->timeLeft = arg5;
    }
    data->unk_24 = 0;
    data->pos.x = (f32) arg1;
    data->pos.y = (f32) arg2;
    data->pos.z = (f32) arg3;
    data->unk_18 = 70;
    data->unk_1C = 180;
    data->unk_20 = 120;
    data->unk_28 = 20;
    data->unk_2C = 230;
    data->unk_30 = 50;
    data->unk_34 = 255;
    data->unk_38 = arg4;
}
