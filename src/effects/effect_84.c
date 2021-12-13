#include "common.h"
#include "effects_internal.h"

s32 D_E00A8620[] = { 0x090030D8, 0x090030A0, 0x09003068, 0x09003030, 0x09002FF8, 0x09002FC0, 0x09002F88, 0x09002F50, 0x09002F18, 0x09002EE0 };

s32 D_E00A8648[] = { 0x00000100, 0x02000200, 0x03000300, 0x03000200, 0x02000100, 0x01000000, 0x0000FF00, 0xFE00FE00, 0xFD00FD00, 0xFD00FE00, 0xFE00FF00, 0xFF000000 };

s32 D_E00A8678[] = { 0x00000001, 0x00020002, 0x00030003, 0x00030002, 0x00020001, 0x00010000 };

s32 D_E00A8690[] = { D_E00A8648, 0x18000000, D_E00A8678, 0x0C000000 };

void fx_84_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_84", fx_84_main);

void fx_84_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_84", fx_84_update);

void fx_84_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_84_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00A8318(void) {
}

INCLUDE_ASM(s32, "effects/effect_84", fx_84_appendGfx);
