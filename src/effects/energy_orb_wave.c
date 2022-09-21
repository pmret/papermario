#include "common.h"
#include "effects_internal.h"

void energy_orb_wave_init(EffectInstance* effect);
void energy_orb_wave_update(EffectInstance* effect);
void energy_orb_wave_render(EffectInstance* effect);
void energy_orb_wave_appendGfx(void* effect);

EffectInstance* energy_orb_wave_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    EnergyOrbWaveFXData* data;
    s32 numParts = 1;

    bp.init = energy_orb_wave_init;
    bp.update = energy_orb_wave_update;
    bp.renderWorld = energy_orb_wave_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_ENERGY_ORB_WAVE;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.energyOrbWave = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.energyOrbWave != NULL);

    data->unk_00 = arg0;
    data->unk_14 = 0;
    if (arg5 <= 0) {
        data->unk_10 = 100;
    } else {
        data->unk_10 = arg5;
    }
    data->unk_2C = 0;
    data->pos.x = arg1;
    data->pos.y = arg2;
    data->pos.z = arg3;
    data->scale = arg4;
    data->unk_18 = 0;

    switch (arg0) {
        case 0:
            data->unk_1C = 0;
            break;
        case 1:
            data->unk_1C = 2;
            break;
        case 2:
            data->unk_1C = 4;
            break;
        case 3:
            data->unk_1C = 6;
            break;
        case 4:
            data->unk_1C = 7;
            break;
        case 5:
            data->unk_1C = 8;
            break;
        case 6:
            data->unk_1C = 9;
            break;
        default:
            data->unk_1C = 10;
            data->unk_34 = -(arg4 - 0.1) / arg5;
            break;
    }

    return effect;
}

void energy_orb_wave_init(EffectInstance* effect) {
}

INCLUDE_ASM(s32, "effects/energy_orb_wave", energy_orb_wave_update);

void energy_orb_wave_render(EffectInstance* effect) {
    EnergyOrbWaveFXData* effect82 = effect->data.energyOrbWave;
    RenderTask renderTask;
    RenderTask* retTask;
    RenderTask* renderTaskPointer = &renderTask;

    renderTask.appendGfx = energy_orb_wave_appendGfx;
    renderTask.distance = 10;
    renderTask.appendGfxArg = effect;
    renderTask.renderMode = RENDER_MODE_2D;
    if (effect82->unk_00 >= 3) {
        shim_queue_render_task(renderTaskPointer);
        return;
    }

    retTask = shim_queue_render_task(renderTaskPointer);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00A4648(void) {
}

INCLUDE_ASM(s32, "effects/energy_orb_wave", energy_orb_wave_appendGfx);
