#include "kmr_22.h"

INCLUDE_ASM(s32, "world/area_kmr/kmr_22/8FF8B0", func_80240240_8FF8B0);

INCLUDE_ASM(s32, "world/area_kmr/kmr_22/8FF8B0", func_80240314_8FF984);

INCLUDE_ASM(s32, "world/area_kmr/kmr_22/8FF8B0", func_80240418_8FFA88);

ApiStatus func_802404E4_8FFB54(Evt* script) {
    Bytecode* args = script->ptrReadPos;

    evt_get_variable(script, *args++);
    evt_get_variable(script, *args++);
    evt_get_variable(script, *args++);
    evt_get_variable(script, *args++);
    evt_get_variable(script, *args++);
    evt_get_variable(NULL, MapVar(0));
    return ApiStatus_DONE2;
}

void func_8024056C_8FFBDC(void*);
INCLUDE_ASM(s32, "world/area_kmr/kmr_22/8FF8B0", func_8024056C_8FFBDC);

void func_80240B00_900170(void) {
    RenderTask rt;

    rt.appendGfx = &func_8024056C_8FFBDC;
    rt.distance = 10;
    rt.appendGfxArg = NULL;
    rt.renderMode = RENDER_MODE_SURFACE_OPA;
    queue_render_task(&rt);
}

extern s32 D_802483D0;

ApiStatus func_80240B3C_9001AC(Evt* script, s32 isInitialCall) {
    D_802483D0 = 0;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_kmr/kmr_22/8FF8B0", func_80240B4C_9001BC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_22/8FF8B0", func_80240BA8_900218);
