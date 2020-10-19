#include "common.h"

void func_802BD100_324F10(Npc* npc) {
    npc->collisionHeight = 24;
    npc->collisionRadius = 20;
}

ApiStatus func_802BD114_324F10(ScriptInstance* script, s32 isInitialCall) {
    s32 ownerID = script->ownerID;

    if (isInitialCall) {
        func_800EECC4(ownerID);
    }
    return func_800EECE8(ownerID) != 0;
}


ApiStatus func_802BD14C_324F10(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    s32 ownerID = script->ownerID;

    if (isInitialCall) {
        enable_partner_walking(ownerID, TRUE);
    }

    func_800EBA3C(ownerID);
    func_800EBB40(ownerID);
    playerData->unk_2F4[PartnerId_GOOMBARIA]++;

    return ApiStatus_BLOCK;
}

ApiStatus func_802BD1AC_324F10(ScriptInstance* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

ApiStatus func_802BD1B4(ScriptInstance* script, s32 isInitialCall) {
    s32 ownerID = script->ownerID;

    if (isInitialCall) {
        func_800EE994(ownerID);
    }
    return func_800EE9B8(ownerID) != 0;
}
