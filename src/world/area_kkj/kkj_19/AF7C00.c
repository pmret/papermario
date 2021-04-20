#include "kkj_19.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_802404DC_AF7E2C);
/*
ApiStatus N(func_802404DC_AF7E2C)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr;

    if (isInitialCall) {
        ptr = &D_80241CCC_BE0A5C;
        *ptr = 0;
    }

    ptr = &D_80241CCC_BE0A5C;
    if (*ptr != NULL) {
        ptr = &D_80241CCC_BE0A5C;
        *ptr = 0;
        set_variable(script, *args, D_80241CD0_BE0A60);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240530_AF7E80);
/*
ApiStatus N(func_80240530_AF7E80)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240568_AF7EB8);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240604_AF7F54);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_802406A0_AF7FF0);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_802406C4_AF8014);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240B4C_AF849C);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240B8C_AF84DC);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240BE4_AF8534);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240C10_AF8560);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240C4C_AF859C);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240CB4_AF8604);
