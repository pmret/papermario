#include "common.h"

// Init
void func_802BD100_325070(Npc* npc) {
    npc->collisionHeight = 20;
    npc->collisionRadius = 20;
}

ApiStatus func_802BD110(ScriptInstance* script, s32 isInitialCall) {
    Npc* owner = script->owner2.npc;

    if (isInitialCall) {
        func_800EECC4(owner);
    }
    return func_800EECE8(owner) != 0;
}

ApiStatus func_802BD148_325070(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* owner = script->owner2.npc;

    if (isInitialCall) {
        enable_partner_flying(owner, TRUE);
    }

    update_player_move_history(owner);
    func_800ED5D0(owner);
    playerData->unk_2F4[PartnerId_TWINK]++;

    return ApiStatus_BLOCK;
}

ApiStatus func_802BD1A8(ScriptInstance* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

ApiStatus func_802BD1B0(ScriptInstance* script, s32 isInitialCall) {
    Npc* owner = script->owner2.npc;

    if (isInitialCall) {
        func_800EE994(owner);
    }
    return func_800EE9B8(owner) != 0;
}
