#include "common.h"
#include "effects_internal.h"

void gather_energy_pink_init(EffectInstance* effect);
void gather_energy_pink_render(EffectInstance* effect);
void gather_energy_pink_update(EffectInstance* effect);
void gather_energy_pink_appendGfx(void* effect);

void gather_energy_pink_main(s32 type, f32 posX, f32 posY, f32 posZ, f32 scale, s32 duration) {
    EffectBlueprint bp;
    EffectInstance* effect;
    GatherEnergyPinkFXData* data;
    s32 numParts = 1;

    bp.unk_00 = 0;
    bp.init = gather_energy_pink_init;
    bp.update = gather_energy_pink_update;
    bp.renderWorld = gather_energy_pink_render;
    bp.unk_14 = 0;
    bp.effectID = EFFECT_GATHER_ENERGY_PINK;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.gatherEnergyPink = shim_general_heap_malloc(sizeof(*data));
    ASSERT (data != NULL);
    
    data->unk_00 = type;
    data->unk_28 = duration;
    data->unk_2C = 0;
    data->unk_24 = 0;
    data->posB.x = posX;
    data->posB.y = posY;
    data->posB.z = posZ;
    data->unk_44 = 0;
    data->unk_40 = 0;
    data->unk_4C = 0;
    data->unk_48 = 0;
    data->unk_34 = 0;
    data->unk_30 = 0;
    data->unk_3C = 0;
    data->unk_38 = 0;
    data->posA.x = posX;
    data->posA.y = posY;
    data->posA.z = posZ;

    data->unk_1C = 10.0f;

    data->unk_58 = func_E0200000(360);
    data->unk_5C = 4.0f;

    data->unk_50 = 0;
    data->unk_54 = 0;
    
    if (type == 1) {
        data->unk_3C = 96;
        data->unk_20 = scale;
    } else {
        data->unk_44 = -2;
        data->unk_4C = -4;
        data->unk_20 = scale * 0.2;
    }
    return;
}

void gather_energy_pink_init(EffectInstance* effect) {
}

INCLUDE_ASM(s32, "effects/gather_energy_pink", gather_energy_pink_update);

void gather_energy_pink_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = gather_energy_pink_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/gather_energy_pink", gather_energy_pink_appendGfx);
