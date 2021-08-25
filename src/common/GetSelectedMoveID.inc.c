#include "common.h"
#include "map.h"

ApiStatus N(GetSelectedMoveID)(Evt* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.selectedMoveID);
    return ApiStatus_DONE2;
}
