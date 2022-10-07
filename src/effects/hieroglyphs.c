#include "common.h"
#include "effects_internal.h"

void hieroglyphs_init(EffectInstance* effect);
void hieroglyphs_update(EffectInstance* effect);
void hieroglyphs_render(EffectInstance* effect);
void hieroglyphs_appendGfx(void* effect);

EffectInstance* hieroglyphs_main(s32 arg0, f32 posX, f32 posY, f32 posZ, f32 arg4, s32 timeLeft) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    HieroglyphsFXData* data;
    s32 numParts = 1;

    effectBp.init = hieroglyphs_init;
    effectBp.update = hieroglyphs_update;
    effectBp.renderWorld = hieroglyphs_render;
    effectBp.unk_00 = 0;
    effectBp.unk_14 = 0;
    effectBp.effectID = EFFECT_HIEROGLYPHS;

    effect = shim_create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.hieroglyphs = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->unk_00 = arg0;
    data->lifeTime = 0;
    if (timeLeft <= 0) {
        data->timeLeft = 1000;
    } else {
        data->timeLeft = timeLeft;
    }
    data->unk_24 = 0;
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->unk_38 = arg4;
    data->unk_18 = 70;
    data->unk_1C = 180;
    data->unk_20 = 120;
    data->unk_28 = 20;
    data->unk_2C = 230;
    data->unk_30 = 50;
    data->unk_34 = 255;

    return effect;
}

void hieroglyphs_init(EffectInstance* effect) {
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
