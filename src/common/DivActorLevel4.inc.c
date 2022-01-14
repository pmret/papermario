#include "common.h"
#include "battle/battle.h"

ApiStatus N(DivActorLevel4)(Evt* script, s32 isInitialCall) {
    ActorBlueprint* actorData = get_actor(script->owner1.actorID)->actorBlueprint;

    actorData->level /= 4;
    return ApiStatus_DONE2;
}
