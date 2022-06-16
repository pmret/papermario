#include "common.h"
#include "effects_internal.h"

s32 D_E009EDF0[] = { 0x09001490 };

s32 D_E009EDF4[] = { 0x090014B0 };

s32 D_E009EDF8[] = { 0x090014D0 };

s32 D_E009EDFC[] = { 0x090014F0 };

void radiating_energy_orb_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/radiating_energy_orb", radiating_energy_orb_main);

void radiating_energy_orb_init(void) {
}

INCLUDE_ASM(s32, "effects/radiating_energy_orb", radiating_energy_orb_update);

void radiating_energy_orb_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = radiating_energy_orb_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/radiating_energy_orb", radiating_energy_orb_appendGfx);
