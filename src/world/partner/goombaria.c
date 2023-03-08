#include "common.h"
#include "goombaria.h"
#include "../partners.h"

void world_goombaria_init(Npc* goombaria) {
    goombaria->collisionHeight = 24;
    goombaria->collisionRadius = 20;
}

API_CALLABLE(GoombariaTakeOut) {
    Npc* goombaria = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(goombaria);
    }

    return partner_get_out(goombaria) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

API_CALLABLE(GoombariaUpdate) {
    PlayerData* playerData = &gPlayerData;
    Npc* goombaria = script->owner2.npc;

    if (isInitialCall) {
        partner_walking_enable(goombaria, TRUE);
    }

    partner_walking_update_player_tracking(goombaria);
    partner_walking_update_motion(goombaria);
    playerData->partnerUsedTime[PARTNER_GOOMBARIA]++;

    return ApiStatus_BLOCK;
}

API_CALLABLE(GoombariaUseAbility) {
    return ApiStatus_DONE2;
}

API_CALLABLE(GoombariaPutAway) {
    Npc* goombaria = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(goombaria);
    }

    return partner_put_away(goombaria) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript EVS_WorldGoombariaTakeOut = {
    EVT_CALL(GoombariaTakeOut)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_WorldGoombariaUpdate = {
    EVT_CALL(GoombariaUpdate)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_WorldGoombariaUseAbility = {
    EVT_CALL(GoombariaUseAbility)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_WorldGoombariaPutAway = {
    EVT_CALL(GoombariaPutAway)
    EVT_RETURN
    EVT_END
};
