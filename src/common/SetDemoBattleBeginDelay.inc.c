#include "common.h"
#include "npc.h"

extern s16 DemoBattleBeginDelay;

API_CALLABLE(N(SetDemoBattleBeginDelay)) {
    DemoBattleBeginDelay = script->varTable[0];
    return ApiStatus_DONE2;
}
