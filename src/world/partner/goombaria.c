#include "common.h"
#include "goombaria.h"
#include "../partners.h"

void world_goombaria_init(Npc* partner) {
    partner->collisionHeight = 24;
    partner->collisionRadius = 20;
}

ApiStatus GoombariaTakeOut(Evt* script, s32 isInitialCall) {
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

ApiStatus GoombariaUpdate(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* npc = script->owner2.npc;

    if (isInitialCall) {
        partner_walking_enable(npc, TRUE);
    }

    partner_walking_update_player_tracking(npc);
    partner_walking_update_motion(npc);
    playerData->unk_2F4[PARTNER_GOOMBARIA]++;

    return ApiStatus_BLOCK;
}

ApiStatus GoombariaUseAbility(Evt* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

ApiStatus GoombariaPutAway(Evt* script, s32 isInitialCall) {
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

EvtSource world_goombaria_take_out = {
    EVT_CALL(GoombariaTakeOut)
    EVT_RETURN
    EVT_END
};

EvtSource world_goombaria_update = {
    EVT_CALL(GoombariaUpdate)
    EVT_RETURN
    EVT_END
};

EvtSource world_goombaria_use_ability = {
    EVT_CALL(GoombariaUseAbility)
    EVT_RETURN
    EVT_END
};

EvtSource world_goombaria_put_away = {
    EVT_CALL(GoombariaPutAway)
    EVT_RETURN
    EVT_END
};
