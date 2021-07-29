#include "common.h"

#define NAMESPACE battle_star_peach_focus

#include "common/StarPower.inc.c"

ApiStatus func_802A1518_79C4B8(ScriptInstance* script, s32 isInitialCall) {
    ((s32*)script->varTable[0])[1]++; // TODO replace with actual struct when we know what this is
    return ApiStatus_DONE2;
}
