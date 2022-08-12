#include "kkj_19.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_802404DC_AF7E2C);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240530_AF7E80);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240568_AF7EB8);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240604_AF7F54);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_802406A0_AF7FF0);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_802406C4_AF8014);

static char* N(exit_str_0) = "kkj_18";

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240B4C_AF849C);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240B8C_AF84DC);

#include "world/common/GetFloorCollider.inc.c"

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240C10_AF8560);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240C4C_AF859C);

ApiStatus func_80240CB4_AF8604(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[1] = 255;
    }

    script->functionTemp[1] -= 16;
    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = 0;
        return ApiStatus_DONE2;
    }

    set_screen_overlay_params_front(0, script->functionTemp[1]);
    return ApiStatus_BLOCK;
}
