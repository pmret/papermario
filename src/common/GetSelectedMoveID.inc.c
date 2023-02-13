#include "common.h"
#include "npc.h"

API_CALLABLE(N(GetSelectedMoveID)) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.selectedMoveID);
    return ApiStatus_DONE2;
}
