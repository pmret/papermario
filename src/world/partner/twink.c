#include "common.h"
#include "../partners.h"
#include "twink.h"

void world_twink_init(Npc* partner) {
    partner->collisionHeight = 20;
    partner->collisionRadius = 20;
}

ApiStatus TwinkTakeOut(Evt* script, s32 isInitialCall) {
    Npc* npc = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(npc);
    }
    if (partner_get_out(npc)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus TwinkUpdate(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* npc = script->owner2.npc;

    if (isInitialCall) {
        partner_flying_enable(npc, TRUE);
    }

    partner_flying_update_player_tracking(npc);
    partner_flying_update_motion(npc);
    playerData->unk_2F4[PARTNER_TWINK]++;

    return ApiStatus_BLOCK;
}

ApiStatus TwinkUseAbility(Evt* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

ApiStatus TwinkPutAway(Evt* script, s32 isInitialCall) {
    Npc* npc = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(npc);
    }

    if (partner_put_away(npc)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtSource world_twink_take_out = SCRIPT({
    TwinkTakeOut();
});

EvtSource world_twink_update = SCRIPT({
    TwinkUpdate();
});

EvtSource world_twink_use_ability = SCRIPT({
    TwinkUseAbility();
});

EvtSource world_twink_put_away = SCRIPT({
    TwinkPutAway();
});
