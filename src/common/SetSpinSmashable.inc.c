#include "battle/battle.h"

API_CALLABLE(N(SetSpinSmashable)) {
    s32 canSpinSmash = evt_get_variable(script, *script->ptrReadPos);
    Actor* actor = get_actor(script->owner1.actorID);

    if (!canSpinSmash) {
        actor->actorBlueprint->spinSmashReq = 4;
    } else {
        actor->actorBlueprint->spinSmashReq = 0;
    }

    return ApiStatus_DONE2;
}
