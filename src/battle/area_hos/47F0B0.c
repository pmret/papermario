#include "common.h"

#define NAMESPACE b_area_hos

ApiStatus func_80218000_47F0B0(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->currentPartner = PARTNER_GOOMBARIO;
    return ApiStatus_DONE2;
}
