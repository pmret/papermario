#include "common.h"
#include "../partners.h"
#include "twink.h"

void world_twink_init(Npc* twink) {
    twink->collisionHeight = 20;
    twink->collisionRadius = 20;
}

ApiStatus TwinkTakeOut(Evt* script, s32 isInitialCall) {
    Npc* twink = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(twink);
    }

    return partner_get_out(twink) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

ApiStatus TwinkUpdate(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* twink = script->owner2.npc;

    if (isInitialCall) {
        partner_flying_enable(twink, TRUE);
    }

    partner_flying_update_player_tracking(twink);
    partner_flying_update_motion(twink);
    playerData->unk_2F4[PARTNER_TWINK]++;

    return ApiStatus_BLOCK;
}

ApiStatus TwinkUseAbility(Evt* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

ApiStatus TwinkPutAway(Evt* script, s32 isInitialCall) {
    Npc* twink = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(twink);
    }

    return partner_put_away(twink) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtSource world_twink_take_out = {
    EVT_CALL(TwinkTakeOut)
    EVT_RETURN
    EVT_END
};

EvtSource world_twink_update = {
    EVT_CALL(TwinkUpdate)
    EVT_RETURN
    EVT_END
};

EvtSource world_twink_use_ability = {
    EVT_CALL(TwinkUseAbility)
    EVT_RETURN
    EVT_END
};

EvtSource world_twink_put_away = {
    EVT_CALL(TwinkPutAway)
    EVT_RETURN
    EVT_END
};
