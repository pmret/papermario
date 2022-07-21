#include "common.h"
#include "effects_internal.h"

typedef struct EnergyOrbWaveFXData {
    /* 0x00 */ s32 unk_00;
} EnergyOrbWaveFXData; // size = ??

void energy_orb_wave_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/energy_orb_wave", energy_orb_wave_main);

void energy_orb_wave_init(void) {
}

INCLUDE_ASM(s32, "effects/energy_orb_wave", energy_orb_wave_update);

void energy_orb_wave_render(EffectInstance* effect) {
    EnergyOrbWaveFXData* effect82 = effect->data;
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
