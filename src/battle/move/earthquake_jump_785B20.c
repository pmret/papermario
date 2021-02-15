#include "common.h"

#define NAMESPACE battle_move_earthquake_jump

#include "world/common/UnkMoveFunc1.inc.c"

#ifdef NON_MATCHING
ApiStatus func_802A10E4_785C04(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = 3;
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "battle/move/earthquake_jump_785B20", func_802A10E4_785C04);
#endif
