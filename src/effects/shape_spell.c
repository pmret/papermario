#include "common.h"
#include "effects_internal.h"

void shape_spell_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/shape_spell", shape_spell_main);

void shape_spell_init(void) {
}

INCLUDE_ASM(s32, "effects/shape_spell", shape_spell_update);

void shape_spell_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = shape_spell_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/shape_spell", func_E0024324);

INCLUDE_ASM(s32, "effects/shape_spell", func_E00243BC);

INCLUDE_ASM(s32, "effects/shape_spell", shape_spell_appendGfx);
