#include "common.h"
#include "effects_internal.h"

void thunderbolt_ring_init(EffectInstance* effect);
void thunderbolt_ring_update(EffectInstance* effect);
void thunderbolt_ring_render(EffectInstance* effect);
void thunderbolt_ring_appendGfx(void* effect);

EffectInstance* thunderbolt_ring_main(s32 arg0, f32 posX, f32 posY, f32 posZ, f32 arg4, s32 lifeTime) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    ThunderboltRingFXData* data;
    s32 numParts = 1;

    effectBp.init = thunderbolt_ring_init;
    effectBp.update = thunderbolt_ring_update;
    effectBp.renderWorld = thunderbolt_ring_render;
    effectBp.unk_00 = 0;
    effectBp.unk_14 = 0;
    effectBp.effectID = EFFECT_THUNDERBOLT_RING;

    effect = shim_create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.thunderboltRing = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->unk_00 = arg0;
    data->lifeTime = 0;
    if (lifeTime <= 0) {
        data->timeLeft = 1000;
    } else {
        data->timeLeft = lifeTime;
    }
    data->unk_24 = 255;
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->unk_28 = arg4;
    data->unk_18 = 255;
    data->unk_1C = 230;
    data->unk_20 = 50;
    data->unk_30 = 0;
    data->unk_2C = 1.0f;

    return effect;
}

void thunderbolt_ring_init(EffectInstance* effect) {
}

void thunderbolt_ring_update(EffectInstance *effect) {
    ThunderboltRingFXData* data = effect->data.thunderboltRing;
    s32 lifeTime;
    s32 timeLeft;

    if (effect->flags & 16) {
        effect->flags &= ~16;
        data->timeLeft = 16;
    }
    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }

    timeLeft = data->timeLeft;
    data->lifeTime++;
    lifeTime = data->lifeTime;

    if (timeLeft < 0) {
        shim_remove_effect(effect);
        return;
    }
    if (timeLeft < 8) {
        data->unk_2C = data->unk_2C + ((8 - timeLeft) * 0.3);
    }
    if (lifeTime < 16) {
        data->unk_24 = (lifeTime * 16) + 15;
    }
    if (timeLeft < 8) {
        data->unk_24 = (timeLeft << 5) + 31;
    }
}

void thunderbolt_ring_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = thunderbolt_ring_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/thunderbolt_ring", thunderbolt_ring_appendGfx);
