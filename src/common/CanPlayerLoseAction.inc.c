#include "common.h"

API_CALLABLE(N(CanPlayerLoseAction)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (get_actor(script->owner1.actorID)->debuff != STATUS_KEY_SHRINK) {
        if (gBattleStatus.hammerLossTurns == -1 || gBattleStatus.jumpLossTurns == -1 || gBattleStatus.itemLossTurns == -1) {
            evt_set_variable(script, *args++, 0);
            return ApiStatus_DONE2;
        } else {
            evt_set_variable(script, *args++, -1);
            return ApiStatus_DONE2;
        }
    } else {
        evt_set_variable(script, *args++, -1);
        return ApiStatus_DONE2;
    }
}
