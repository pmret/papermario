#include "common.h"
#include "battle/battle.h"

API_CALLABLE(N(DivActorLevel4)) {
    ActorBlueprint* actorData = get_actor(script->owner1.actorID)->actorBlueprint;

    actorData->level /= 4;
    return ApiStatus_DONE2;
}
