#include "common.h"
#include "effects_internal.h"

typedef struct Effect76 {
    /* 0x00 */ char unk_00[0xC];
    /* 0x0C */ f32 unk_0C;
} Effect76; // size = 0x??

void fx_76_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_76", fx_76_main);

void fx_76_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_76", fx_76_update);

void fx_76_render(EffectInstance *effect) {
    Effect76* effect76 = effect->data;
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_76_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = effect76->unk_0C;
    renderTask.renderMode = RENDER_MODE_2D;
    
    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_76", fx_76_appendGfx);
