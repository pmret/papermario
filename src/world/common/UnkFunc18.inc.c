#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc18)(ScriptInstance *script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Bytecode* args = script->ptrReadPos;
    s32 partnerIdx = get_variable(script, *args++);
    s32 si_var = *args++;

    playerData->partners[partnerIdx].level++;
    set_variable(script, si_var, playerData->partners[partnerIdx].level);

    return ApiStatus_DONE2;
}