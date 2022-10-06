#include "common.h"
#include "effects_internal.h"

void smoke_burst_init(EffectInstance* effect);
void smoke_burst_update(EffectInstance* effect);
void smoke_burst_render(EffectInstance* effect);
void smoke_burst_appendGfx(void* effect);

void smoke_burst_main(s32 arg0, f32 posX, f32 posY, f32 posZ, f32 arg4, s32 timeLeft) {
   EffectBlueprint effectBp;
    EffectInstance* effect;
    SmokeBurstFXData* data;
    s32 numParts = 1;

    effectBp.init = smoke_burst_init;
    effectBp.update = smoke_burst_update;
    effectBp.renderWorld = smoke_burst_render;
    effectBp.unk_00 = 0;
    effectBp.unk_14 = 0;
    effectBp.effectID = EFFECT_SMOKE_BURST;

    effect = shim_create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.smokeBurst = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    shim_mem_clear(data, numParts * sizeof(*data));
    data->timeLeft = timeLeft;
    data->lifeTime = 0;
    data->unk_1C = timeLeft;
    data->unk_20 = 0;
    data->unk_00 = arg0;
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->unk_10 = arg4;

    switch (arg0) {
        case 0:
            data->unk_26 = 0;
            data->unk_25 = 0;
            data->unk_24 = 0;
            data->unk_27 = 0x82;
            break;
        case 1:
            data->unk_24 = 0xFF;
            data->unk_26 = 0;
            data->unk_25 = 0;
            data->unk_27 = 0x82;
            break;
        default:
            data->unk_24 = 0xE1;
            data->unk_25 = 0xD7;
            data->unk_26 = 0xFF;
            data->unk_27 = 0xB4;
            break;
    }
}

void smoke_burst_init(EffectInstance* effect) {
}

void smoke_burst_update(EffectInstance *effect) {
    SmokeBurstFXData* data = effect->data.smokeBurst;

    data->unk_20 = (data->lifeTime * 8.0f) / data->unk_1C;
    data->lifeTime++;
    data->timeLeft--;

    if (data->timeLeft < 0) {
        shim_remove_effect(effect);
    }
}

void smoke_burst_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = smoke_burst_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/smoke_burst", smoke_burst_appendGfx);
