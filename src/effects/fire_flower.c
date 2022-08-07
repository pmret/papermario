#include "common.h"
#include "effects_internal.h"

void fire_flower_appendGfx(void* effect);
void fire_flower_init(EffectInstance* effect);
void fire_flower_update(EffectInstance* effect);
void fire_flower_render(EffectInstance* effect);

s32 D_E007EC30[] = { 0x323C4650, 0x5A646964 };

EffectInstance* fire_flower_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    FireFlowerFXData* part;
    Vec3i* partData;
    s32 numParts = 31;
    s32 i;

    bp.unk_00 = 0;
    bp.init = fire_flower_init;
    bp.update = fire_flower_update;
    bp.renderWorld = fire_flower_render;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_FIRE_FLOWER;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    part = shim_general_heap_malloc(numParts * sizeof(*part));
    effect->data = part;

    ASSERT(effect->data != NULL);

    part->unk_04 = 0;
    part->unk_00 = arg0;
    part->pos.x = arg1;
    part->pos.y = arg2;
    part->pos.z = arg3;
    part->unk_40.x = arg4;
    part->unk_40.y = 0;
    part->unk_34 = 0;
    part->unk_38 = 0;
    part->unk_28 = 0;

    part->unk_3C = 255;
    part->unk_30 = 0.5f;
    part->unk_2C = -10.0f;

    part++;

    for (i = 1; i < numParts; i++, part++) {
        partData = &part->unk_40;
        part->unk_00 = 1;
        part->pos.x = 0;
        part->pos.y = 0;
        part->pos.z = 0;
        part->unk_14 = 8.0f;
        part->unk_18 = 0;
        part->unk_1C = func_E0200000(20) - 8;
        part->unk_20 = (func_E0200000(10) - 5) * 0.05;
        part->unk_24 = func_E0200000(80) + 5;
        part->unk_3C = 255;
        partData->z = i - 1;
        partData->x = 10;
    }

    return effect;
}

void fire_flower_init(EffectInstance* effect) {
}

INCLUDE_ASM(s32, "effects/fire_flower", fire_flower_update);

void fire_flower_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fire_flower_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/fire_flower", fire_flower_appendGfx);
