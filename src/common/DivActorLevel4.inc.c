#include "common.h"
#include "battle/battle.h"

ApiStatus N(DivActorLevel4)(ScriptInstance* script, s32 isInitialCall) {
    ActorDesc* actorData = get_actor(script->owner1.actorID)->staticActorData;

    actorData->level /= 4;
    return ApiStatus_DONE2;
}
