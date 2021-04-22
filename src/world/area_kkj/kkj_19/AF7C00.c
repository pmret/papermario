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
/*
ApiStatus N(func_80240568_AF7EB8)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* temp_v0 = get_variable(script, *args);
    s32* ptr = temp_v0;
    s32 i;

    i = 0;
    if (ptr != NULL) {
        s32 new_var;
        for (new_var = ptr[0]; new_var != 0; i++) {
            *(N(D_8024F080) + i) = ptr[i];
        }
        N(D_8024F080)[i] = 0;
    } else {
        for (; i < 0x70; i++) {
            *(N(D_8024F080) + i) = i + 16;
            N(D_8024F080)[0x70] = 0;
        }
    }
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240604_AF7F54);
/*
ApiStatus N(func_80240604_AF7F54)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* temp_v0 = get_variable(script, *args);
    s32* ptr = temp_v0;
    s32 i;

    i = 0;
    if (ptr != NULL) {
        s32 new_var;
        for (new_var = ptr[0]; new_var != 0; i++) {
            *(N(D_8024F080) + i) = ptr[i];
        }
        N(D_8024F080)[i] = 0;
    } else {
        for (; i < 0x70; i++) {
            *(N(D_8024F080) + i) = i + 16;
            N(D_8024F080)[0x70] = 0;
        }
    }
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_802406A0_AF7FF0);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_802406C4_AF8014);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240B4C_AF849C);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240B8C_AF84DC);

#include "world/common/UnkFunc30.inc.c"

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240C10_AF8560);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240C4C_AF859C);

INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_80240CB4_AF8604);
