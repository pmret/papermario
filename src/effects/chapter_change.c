#include "common.h"
#include "effects_internal.h"

extern s32 D_E010E750[];

void chapter_change_init(EffectInstance* effect);
void chapter_change_update(EffectInstance* effect);
void chapter_change_render(EffectInstance* effect);
void chapter_change_appendGfx(EffectInstance* effect);
s32 shim_get_msg_width(s32, u16);

INCLUDE_ASM(s32, "effects/chapter_change", func_E010E000);

EffectInstance* chapter_change_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    ChapterChangeFXData* data;
    EffectInstance* effect;
    s32 numParts = 1;

    bp.init = chapter_change_init;
    bp.update = chapter_change_update;
    bp.renderWorld = chapter_change_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_CHAPTER_CHANGE;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.chapterChange = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.chapterChange != NULL);

    data->unk_00 = arg0;
    data->unk_1C = 0;
    if (arg5 <= 0) {
        data->unk_18 = 1000;
    } else {
        data->unk_18 = arg5;
    }
    data->unk_10 = arg1;
    data->unk_04 = arg1;
    data->unk_14 = arg2;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_50 = arg4;
    data->unk_20 = 255;
    data->unk_24 = 255;
    data->unk_28 = 255;
    data->unk_2C = 255;
    data->unk_30 = 0;
    data->unk_34 = 0;
    data->unk_38 = 0;
    if (arg0 == 0 || arg0 - 10 < 9U) {
        data->unk_3C = 0;
    } else {
        data->unk_3C = 255;
    }
    data->unk_54 = D_E010E750[arg0];
    if (data->unk_54 >= 0) {
        data->unk_40 = 160;
        data->unk_44 = 160;
        data->unk_48 = shim_get_msg_width(data->unk_54, 0);
        data->unk_4C = 24;
    }

    return effect;
}

void chapter_change_init(EffectInstance* effect) {
}

void chapter_change_update(EffectInstance* effect) {
    ChapterChangeFXData* data = effect->data.chapterChange;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        data->unk_18 = 0x10;
    }

    if (data->unk_18 < 1000) {
        data->unk_18--;
    }

    data->unk_1C++;

    if (data->unk_18 < 0) {
        shim_remove_effect(effect);
    }
}

void chapter_change_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = chapter_change_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/chapter_change", chapter_change_appendGfx);
