#include "common.h"

#define NAMESPACE battle_move_earthquake_jump

#include "world/common/todo/UnkMoveFunc1.inc.c"

API_CALLABLE(func_802A10E4_785C04) {
    script->varTable[0] = 3;
    return ApiStatus_DONE2;
}

MATCHING_BSS(0x3CC0);
