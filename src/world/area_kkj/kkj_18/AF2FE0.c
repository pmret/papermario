#include "kkj_18.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kkj/kkj_18/AF2FE0", func_8024056C_AF320C);
/*
ApiStatus N(func_8024056C_AF320C)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80241F10_AF4BB0) = FALSE;
    }

    if (N(D_80241F10_AF4BB0)) {
        N(D_80241F10_AF4BB0) = FALSE;
        set_variable(script, *args, N(D_80241F14_AF4BB4));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_kkj/kkj_18/AF2FE0", func_802405C0_AF3260);
/*
ApiStatus N(func_802405C0_AF3260)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80241F14_AF4BB4) = get_variable(script, *args);
    N(D_80241F10_AF4BB0) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kkj/kkj_18/AF2FE0", func_802405F8_AF3298);
/*
ApiStatus N(func_802405F8_AF3298)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = get_variable(script, *args);
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

INCLUDE_ASM(s32, "world/area_kkj/kkj_18/AF2FE0", func_80240694_AF3334);
/*
ApiStatus N(func_80240694_AF3334)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = get_variable(script, *args);
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

INCLUDE_ASM(s32, "world/area_kkj/kkj_18/AF2FE0", func_80240730_AF33D0);

INCLUDE_ASM(s32, "world/area_kkj/kkj_18/AF2FE0", func_80240774_AF3414);
