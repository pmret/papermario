#include "common.h"
#include "map.h"

ApiStatus N(GetSelectedMoveID)(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.selectedMoveID);
    return ApiStatus_DONE2;
}
