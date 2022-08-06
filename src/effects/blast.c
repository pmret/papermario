#include "common.h"
#include "effects_internal.h"


void blast_init(EffectInstance* effect);
void blast_update(EffectInstance* effect);
void blast_render(EffectInstance* effect);
void blast_appendGfx(void* effect);

void blast_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    BlastFXData* part;
    s32 numParts = 1;
    s32 randInt;

    bp.init = blast_init;
    bp.update = blast_update;
    bp.renderWorld = blast_render;
    bp.unk_00 = 0;
    bp.unk_14 = 0;
    bp.effectID = EFFECT_BLAST;

    effect = shim_create_effect_instance(bpPtr);
    effect->numParts = numParts;

    part = effect->data.blast = shim_general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data.blast != NULL);

    shim_mem_clear(part, numParts * sizeof(*part));

    part->timeLeft = arg5;
    part->unk_18 = 0;
    part->unk_1C = arg5;
    part->unk_20 = 0;
    part->unk_00 = arg0;
    part->pos.x = arg1;
    part->pos.y = arg2;
    part->pos.z = arg3;
    part->unk_10 = arg4;
    part->unk_24 = 0;

    part->unk_28 = arg0 == 0 ? 0 : 40.0;
}

void blast_init(EffectInstance* effect) {
}

void blast_update(EffectInstance* effect) {
    BlastFXData* part = effect->data.blast;

    part->unk_20 = part->unk_18++ * 9.0f / part->unk_1C;
    part->timeLeft--;

    if (part->timeLeft < 0) {
        shim_remove_effect(effect);
        return;
    }

    part->unk_24 += part->unk_28;
}

void blast_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = blast_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/blast", blast_appendGfx);
