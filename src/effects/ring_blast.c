#include "common.h"
#include "effects_internal.h"

void ring_blast_appendGfx(void* effect);
void ring_blast_init(EffectInstance* effect);
void ring_blast_update(EffectInstance* effect);
void ring_blast_render(EffectInstance* effect);

void ring_blast_main(s32 arg0, f32 posX, f32 posY, f32 posZ, f32 arg4, s32 arg5) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    RingBlastFXData* data;
    s32 numParts = 1;

    effectBp.init = ring_blast_init;
    effectBp.update = &ring_blast_update;
    effectBp.renderWorld = ring_blast_render;
    effectBp.unk_00 = 0;
    effectBp.unk_14 = 0;
    effectBp.effectID = EFFECT_RING_BLAST;

    effect = shim_create_effect_instance(&effectBp);
    effect->numParts = numParts;
    data = effect->data.ringBlast = shim_general_heap_malloc(numParts * sizeof(*data));

    ASSERT(data != NULL);
    shim_mem_clear(data, numParts * sizeof(*data));

    data->timeLeft = arg5;
    data->lifeTime = 0;
    data->unk_1C = arg5;
    data->unk_20 = 0;
    data->unk_00 = arg0;
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->unk_10 = arg4;
    data->unk_24 = 0;
    if (arg0 == 0) {
        data->unk_28 = 0;
        return;
    }
    data->unk_28 = 0x28;
}

void ring_blast_init(EffectInstance* effect) {
}

void ring_blast_update(EffectInstance* effect) {
    RingBlastFXData* data = effect->data.ringBlast;

    data->unk_20 = data->lifeTime * 8.0f / data->unk_1C;

    data->lifeTime++;
    data->timeLeft--;

    if (data->timeLeft < 0) {
        shim_remove_effect(effect);
        return;
    }
    data->unk_24 = data->unk_24 + data->unk_28;
    if (data->unk_00 == 0) {
        data->unk_10 = data->unk_10 + 0.1;
    }
}

void ring_blast_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = ring_blast_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/ring_blast", ring_blast_appendGfx);
