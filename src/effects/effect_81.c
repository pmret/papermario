#include "common.h"
#include "effects_internal.h"

s32 D_E00A29D0[] = {0x09000200, 0x090002A8, 0x09000358};

s32 D_E00A29DC[] = {0x00000010, 0x00000010, 0x3F800000, 0x3F800000, 0x00000008, 0x00000008, 0x00000010, 0x00000010, 0x3F800000, 0x3F800000, 0x00000008, 0x00000008, 0x00000010, 0x00000010, 0x3F800000, 0x3F800000, 0x00000008, 0x00000008};

s32 D_E00A2A24[] = {0x00000064, 0x0000003C, 0x0000001E, 0x0000000A, 0x00000000, 0x00000000, 0x00000000};

void fx_81_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_81", fx_81_main);

void fx_81_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_81", fx_81_update);

void fx_81_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_81_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 100;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00A2234(void) {
}

INCLUDE_ASM(s32, "effects/effect_81", fx_81_appendGfx);
