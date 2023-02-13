#include "common.h"
#include "map.h"

API_CALLABLE(N(RemoveChillOut)) {
    Actor* actor = get_actor(script->owner1.actorID);
    s32 hudElementDataIndex = actor->hudElementDataIndex;

    actor->chillOutTurns = 0;
    actor->chillOutAmount = 0;
    remove_status_chill_out(hudElementDataIndex);

    return ApiStatus_DONE2;
}
