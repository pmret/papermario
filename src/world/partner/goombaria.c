#include "common.h"
#include "goombaria.h"
#include "../partners.h"

#define NAMESPACE world_goombaria

void N(init)(Npc* goombaria) {
    goombaria->collisionHeight = 24;
    goombaria->collisionDiameter = 20;
}

API_CALLABLE(N(TakeOut)) {
    Npc* goombaria = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(goombaria);
    }

    return partner_get_out(goombaria) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

API_CALLABLE(N(Update)) {
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

API_CALLABLE(N(UseAbility)) {
    return ApiStatus_DONE2;
}

API_CALLABLE(N(PutAway)) {
    Npc* goombaria = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(goombaria);
    }

    return partner_put_away(goombaria) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript EVS_WorldGoombaria_TakeOut = {
    Call(N(TakeOut))
    Return
    End
};

EvtScript EVS_WorldGoombaria_Update = {
    Call(N(Update))
    Return
    End
};

EvtScript EVS_WorldGoombaria_UseAbility = {
    Call(N(UseAbility))
    Return
    End
};

EvtScript EVS_WorldGoombaria_PutAway = {
    Call(N(PutAway))
    Return
    End
};
