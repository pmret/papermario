#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000268[];
extern Gfx D_09000288[];
extern Gfx D_090002A8[];

Gfx* D_E00BEAF0[] = {
    D_09000268, D_09000288, D_09000268, D_090002A8
};

void water_splash_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/water_splash", water_splash_main);

void water_splash_init(void) {
}

INCLUDE_ASM(s32, "effects/water_splash", water_splash_update);

void water_splash_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = water_splash_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

void func_E00BE5B4(void) {
}

INCLUDE_ASM(s32, "effects/water_splash", water_splash_appendGfx);
