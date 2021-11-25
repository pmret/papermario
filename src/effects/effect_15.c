#include "common.h"
#include "effects_internal.h"

typedef struct Effect15 {
    /* 0x00 */ char unk_00[0x38];
    /* 0x38 */ s32 unk_38;
} Effect15; // size = 0x??

INCLUDE_ASM(s32, "effects/effect_15", fx_15_main);

void fx_15_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_15", fx_15_update);

void fx_15_appendGfx(EffectInstance* effect);
void fx_15_render(EffectInstance* effect) {
    Effect15* effect15 = effect->data;
    RenderTask renderTask;
    RenderTask* renderTaskTemp = &renderTask;
    RenderTask* retTask;
    s32 renderModeTemp;

    renderTask.appendGfxArg = effect;
    renderTask.appendGfx = fx_15_appendGfx;
    renderTask.distance = 0;
    renderModeTemp = RENDER_MODE_SURF_SOLID_AA_ZB_LAYER0;
    if (effect15->unk_38 != 0) {
        renderModeTemp = RENDER_MODE_2D;
    }
    renderTaskTemp->renderMode = renderModeTemp;
    
    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/effect_15", fx_15_appendGfx);
