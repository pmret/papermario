#include "common.h"
#include "../partners.h"
#include "twink.h"

void world_twink_init(Npc* npc) {
    npc->collisionHeight = 20;
    npc->collisionRadius = 20;
}

ApiStatus TwinkTakeOut(ScriptInstance* script, s32 isInitialCall) {
    Npc* owner = script->owner2.npc;

    if (isInitialCall) {
        func_800EECC4(owner);
    }
    return func_800EECE8(owner) != 0;
}

ApiStatus TwinkUpdate(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* owner = script->owner2.npc;

    if (isInitialCall) {
        enable_partner_flying(owner, TRUE);
    }

    update_player_move_history(owner);
    func_800ED5D0(owner);
    playerData->unk_2F4[PartnerID_TWINK]++;

    return ApiStatus_BLOCK;
}

ApiStatus TwinkUseAbility(ScriptInstance* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

ApiStatus TwinkPutAway(ScriptInstance* script, s32 isInitialCall) {
    Npc* owner = script->owner2.npc;

    if (isInitialCall) {
        func_800EE994(owner);
    }
    return func_800EE9B8(owner) != 0;
}

Script world_twink_take_out = SCRIPT({
    TwinkTakeOut()
});

Script world_twink_update = SCRIPT({
    TwinkUpdate()
});

Script world_twink_use_ability = SCRIPT({
    TwinkUseAbility()
});

Script world_twink_put_away = SCRIPT({
    TwinkPutAway()
});
