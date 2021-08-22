#include "kmr_04.h"

static char* N(exit_str_0) = "kmr_03";
static char* N(exit_str_1) = "";

#include "world/common/CheckPartnerFlags1000.inc.c"

ApiStatus N(func_8024002C_8CA92C)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = get_player_data()->curHP;

    return ApiStatus_DONE2;
}
