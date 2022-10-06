#include "common.h"
#include "effects_internal.h"

void huff_puff_breath_init(EffectInstance* effect);
void huff_puff_breath_update(EffectInstance* effect);
void huff_puff_breath_render(EffectInstance* effect);
void huff_puff_breath_appendGfx(void* effect);

EffectInstance* huff_puff_breath_main(s32 arg0, f32 posX, f32 posY, f32 posZ, f32 arg4, f32 arg5, f32 arg6, s32 timeLeft) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    HuffPuffBreathFXData* data;
    s32 numParts = 1;
    f32 temp_f0;

    effectBp.init = huff_puff_breath_init;
    effectBp.update = huff_puff_breath_update;
    effectBp.renderWorld = huff_puff_breath_render;
    effectBp.unk_00 = 0;
    effectBp.unk_14 = 0;
    effectBp.effectID = EFFECT_HUFF_PUFF_BREATH;

    effect = shim_create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.huffPuffBreath = shim_general_heap_malloc(numParts * sizeof(*data));
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
    data->unk_4C = arg6;
    data->unk_18 = 255;
    data->unk_2C = 230;
    data->unk_1C = 255;
    data->unk_20 = 255;
    data->unk_28 = 255;
    data->unk_30 = 50;
    data->unk_34 = 255;
    data->unk_48 = arg4;
    data->unk_44 = 0;
    data->unk_3C = arg5;
    data->unk_38 = shim_rand_int(32);
    data->unk_40 = shim_rand_int(16);
    data->unk_20 = 150;
    data->unk_28 = 215;
    data->unk_2C = 210;
    data->unk_18 = 255;
    data->unk_1C = 255;
    data->unk_30 = 10;

    return effect;
}

void huff_puff_breath_init(EffectInstance* effect) {
}

void huff_puff_breath_update(EffectInstance* effect) {
    HuffPuffBreathFXData* data = effect->data.huffPuffBreath;
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
