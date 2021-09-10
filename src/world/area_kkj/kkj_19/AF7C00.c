#include "kkj_19.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_802404DC_AF7E2C);
/*
ApiStatus N(func_802404DC_AF7E2C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80241B10_AF9460) = FALSE;
    }

    if (N(D_80241B10_AF9460)) {
        N(D_80241B10_AF9460) = FALSE;
        evt_set_variable(script, *args, N(D_80241B14_AF9464));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240530_AF7E80);
/*
ApiStatus N(func_80240530_AF7E80)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80241B14_AF9464) = evt_get_variable(script, *args);
    N(D_80241B10_AF9460) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240568_AF7EB8);
/*
ApiStatus N(func_80240568_AF7EB8)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_80244A20)[i] = ptr[i];
        }
        N(D_80244A20)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(D_80244A20)[i] = i + 16;
            N(D_80244A20)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240604_AF7F54);
/*
ApiStatus N(func_80240604_AF7F54)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_80244A20)[i] = ptr[i];
        }
        N(D_80244A20)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(D_80244A20)[i] = i + 16;
            N(D_80244A20)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_802406A0_AF7FF0);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_802406C4_AF8014);

static char* N(exit_str_0) = "kkj_18";

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240B4C_AF849C);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240B8C_AF84DC);

#include "world/common/GetFloorCollider.inc.c"

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240C10_AF8560);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240C4C_AF859C);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240CB4_AF8604);
