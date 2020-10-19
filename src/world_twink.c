#include "common.h"

// Init
void func_802BD100_325070(Npc* npc) {
    npc->collisionHeight = 20;
    npc->collisionRadius = 20;
}

ApiStatus func_802BD110(ScriptInstance* script, s32 isInitialCall) {
    s32 ownerID = script->ownerID;

    if (isInitialCall) {
        func_800EECC4(ownerID);
    }
    return func_800EECE8(ownerID) != 0;
}

ApiStatus func_802BD148_325070(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    s32 ownerID = script->ownerID;

    if (isInitialCall) {
        enable_partner_flying(ownerID, TRUE);
    }

    update_player_move_history(ownerID);
    func_800ED5D0(ownerID);
    playerData->unk_2F4[PartnerId_TWINK]++;

    return ApiStatus_BLOCK;
}

ApiStatus func_802BD1A8(ScriptInstance* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

ApiStatus func_802BD1B0(ScriptInstance* script, s32 isInitialCall) {
    s32 ownerID = script->ownerID;

    if (isInitialCall) {
        func_800EE994(ownerID);
    }
    return func_800EE9B8(ownerID) != 0;
}
