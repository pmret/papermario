#include "common.h"
#include "../partners.h"
#include "twink.h"

void world_twink_init(Npc* partner) {
    partner->collisionHeight = 20;
    partner->collisionRadius = 20;
}

ApiStatus TwinkTakeOut(ScriptInstance* script, s32 isInitialCall) {
    Npc* owner = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(owner);
    }
    return partner_get_out(owner) != 0;
}

ApiStatus TwinkUpdate(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* owner = script->owner2.npc;

    if (isInitialCall) {
        partner_flying_enable(owner, TRUE);
    }

    partner_flying_update_player_tracking(owner);
    partner_flying_update_motion(owner);
    playerData->unk_2F4[PARTNER_TWINK]++;

    return ApiStatus_BLOCK;
}

ApiStatus TwinkUseAbility(ScriptInstance* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

ApiStatus TwinkPutAway(ScriptInstance* script, s32 isInitialCall) {
    Npc* owner = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(owner);
    }
    return partner_put_away(owner) != 0;
}

Script world_twink_take_out = SCRIPT({
    TwinkTakeOut();
});

Script world_twink_update = SCRIPT({
    TwinkUpdate();
});

Script world_twink_use_ability = SCRIPT({
    TwinkUseAbility();
});

Script world_twink_put_away = SCRIPT({
    TwinkPutAway();
});
