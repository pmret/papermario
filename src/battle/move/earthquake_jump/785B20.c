#include "common.h"

#define NAMESPACE battle_move_earthquake_jump

#include "world/common/todo/UnkMoveFunc1.inc.c"

ApiStatus func_802A10E4_785C04(Evt* script, s32 isInitialCall) {
    script->varTable[0] = 3;
    return ApiStatus_DONE2;
}

#ifndef SHIFT
static BSS u8 bss_padding[0x3CC0];
#endif
