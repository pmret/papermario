#include "common.h"

API_CALLABLE(N(CheckPlayerCanLoseCommand)) {
    BattleStatus* status = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (status->hammerLossTurns == -1 || status->jumpLossTurns == -1 || status->itemLossTurns == -1) {
        evt_set_variable(script, *args++, 0);
    } else {
        evt_set_variable(script, *args++, -1);
    }

    return ApiStatus_DONE2;
}
