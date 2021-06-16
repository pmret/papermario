#include "kmr_04.h"

#include "world/common/CheckPartnerFlags1000.inc.c"

ApiStatus N(func_8024002C_8CA92C)(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = get_player_data()->curHP;

    return ApiStatus_DONE2;
}
