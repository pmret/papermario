#include "common.h"
#include "effects_internal.h"

void rising_bubble_init(EffectInstance* effect);
void rising_bubble_update(EffectInstance* effect);
void rising_bubble_render(EffectInstance* effect);
void rising_bubble_appendGfx(void* effect);

void rising_bubble_main(s32 arg0, f32 posX, f32 posY, f32 posZ, f32 arg4) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    RisingBubbleFXData* data;
    s32 numParts = 1;

    effectBp.unk_00 = 0;
    effectBp.init = rising_bubble_init;
    effectBp.update = rising_bubble_update;
    effectBp.renderWorld = rising_bubble_render;
    effectBp.unk_14 = 0;
    effectBp.effectID = EFFECT_RISING_BUBBLE;
    effect = shim_create_effect_instance(&effectBp);
    effect->numParts = numParts;
    data = effect->data.risingBubble = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->unk_00 = arg0;
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->unk_14 = 0;
    data->lifeTime = 0;
    if (arg4 != 0.0f) {
        data->unk_10 = ((shim_rand_int(3) * 0.1) + 0.7) * 0.4;
    } else {
        data->unk_10 = 1.f;
    }
    data->timeLeft = 0x20;
    data->unk_20 = shim_rand_int(0x1F);
    data->unk_24 = posY + arg4;
}
void rising_bubble_init(EffectInstance* effect) {
}

void rising_bubble_update(EffectInstance* effect) {
    RisingBubbleFXData* data = effect->data.risingBubble;
    s32 temp_a2 = data->timeLeft;

    if (data->pos.y >= data->unk_24) {
        data->timeLeft--;
        data->lifeTime++;

        if (data->timeLeft < 0) {
            shim_remove_effect(effect);
            return;
        }

        if (temp_a2 >= 6) {
            data->unk_14 += (120 - data->unk_14) * 0.3;
        } else {
            data->unk_14 = temp_a2 * 20;
        }

        data->unk_20++;
        if (data->unk_20 >= 32) {
            data->unk_20 -= 32;
        }

        data->unk_10 += 0.1;
        return;
    }

    data->unk_14 = 255;
    data->lifeTime++;
    data->pos.y += 2.0f;
}

void rising_bubble_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = rising_bubble_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/rising_bubble", rising_bubble_appendGfx);
