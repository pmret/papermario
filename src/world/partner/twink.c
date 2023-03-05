#include "common.h"
#include "../partners.h"
#include "twink.h"

void world_twink_init(Npc* twink) {
    twink->collisionHeight = 20;
    twink->collisionRadius = 20;
}

API_CALLABLE(TwinkTakeOut) {
    Npc* twink = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(twink);
    }

    if(partner_get_out(twink)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(TwinkUpdate) {
    PlayerData* playerData = &gPlayerData;
    Npc* twink = script->owner2.npc;

    if (isInitialCall) {
        partner_flying_enable(twink, TRUE);
    }

    partner_flying_update_player_tracking(twink);
    partner_flying_update_motion(twink);
    playerData->partnerUsedTime[PARTNER_TWINK]++;

    return ApiStatus_BLOCK;
}

API_CALLABLE(TwinkUseAbility) {
    return ApiStatus_DONE2;
}

API_CALLABLE(TwinkPutAway) {
    Npc* twink = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(twink);
    }

    if(partner_put_away(twink)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript EVS_TwinkTakeOut = {
    EVT_CALL(TwinkTakeOut)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_TwinkUpdate = {
    EVT_CALL(TwinkUpdate)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_TwinkUseAbility = {
    EVT_CALL(TwinkUseAbility)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_TwinkPutAway = {
    EVT_CALL(TwinkPutAway)
    EVT_RETURN
    EVT_END
};
