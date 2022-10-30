#include "kmr_20.h"

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EDFC0", func_802421A0_8EDFC0);

void func_80242870_8EE690(void*);
INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EDFC0", func_80242870_8EE690);

void func_80242A04_8EE824(void) {
    RenderTask rt;

    rt.renderMode = RENDER_MODE_2D;
    rt.appendGfxArg = NULL;
    rt.appendGfx = func_80242870_8EE690;
    rt.distance = 0;
    queue_render_task(&rt);
}

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EDFC0", func_80242A3C_8EE85C);

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EDFC0", func_80242B04_8EE924);
