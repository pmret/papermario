#include "common.h"
#include "effects_internal.h"

s32 D_E00AA6C0[] = { 0x090038F8, 0x09003968, 0x090039D8, 0x09003A48, 0x09003AB8, 0x09003B28, 0x09003B98, 0x09003C08, 0x09003C78, 0x09003CE8, 0x09003D58 };

s8 D_E00AA6EC[] = { 0xFF, 0xFE, 0xFD, 0xFC, 0xFB, 0xFA, 0xF9, 0xF8, 0xF7, 0xF6, 0xF5, 0xF4, 0xF3, 0xF2, 0xF1, 0xF0, 0xEF, 0xEE, 0xED, 0xEF, 0xF1, 0xF3, 0xF5, 0xF7, 0xF9, 0xFB, 0xFD, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

void fx_85_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_85", fx_85_main);

void fx_85_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_85", fx_85_update);

void fx_85_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_85_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_85", fx_85_appendGfx);
