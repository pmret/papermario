#include "common.h"
#include "npc.h"

ApiStatus N(GetSelectedMoveID)(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.selectedMoveID);
    return ApiStatus_DONE2;
}
