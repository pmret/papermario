#include "common.h"
#include "map.h"

ApiStatus N(RemoveChillOut)(Evt* script, s32 isInitialCall) {
    Actor* actor = get_actor(script->owner1.actorID);
    s32 hudElementDataIndex = actor->hudElementDataIndex;

    actor->chillOutTurns = 0;
    actor->chillOutAmount = 0;
    remove_status_4(hudElementDataIndex);

    return ApiStatus_DONE2;
}
