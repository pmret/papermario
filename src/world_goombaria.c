#include "common.h"

void func_802BD100_324F10(Npc* npc) {
    npc->collisionHeight = 24;
    npc->collisionRadius = 20;
}

ApiStatus func_802BD114_324F10(ScriptInstance* script, s32 isInitialCall) {
    Npc* owner = script->owner2.npc;

    if (isInitialCall) {
        func_800EECC4(owner);
    }
    return func_800EECE8(owner) != 0;
}

ApiStatus func_802BD14C_324F10(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* owner = script->owner2.npc;

    if (isInitialCall) {
        enable_partner_walking(owner, TRUE);
    }

    func_800EBA3C(owner);
    func_800EBB40(owner);
    playerData->unk_2F4[PartnerId_GOOMBARIA]++;

    return ApiStatus_BLOCK;
}

ApiStatus func_802BD1AC_324F10(ScriptInstance* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

ApiStatus func_802BD1B4(ScriptInstance* script, s32 isInitialCall) {
    Npc* owner = script->owner2.npc;

    if (isInitialCall) {
        func_800EE994(owner);
    }
    return func_800EE9B8(owner) != 0;
}
