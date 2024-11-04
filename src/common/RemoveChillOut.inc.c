#include "common.h"
#include "map.h"
#include "hud_element.h"

API_CALLABLE(N(RemoveChillOut)) {
    Actor* actor = get_actor(script->owner1.actorID);
    HudElemID hid = actor->hudElementDataIndex;

    actor->chillOutTurns = 0;
    actor->chillOutAmount = 0;
    remove_status_chill_out(hid);

    return ApiStatus_DONE2;
}
