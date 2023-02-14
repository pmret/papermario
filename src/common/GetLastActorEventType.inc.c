#include "common.h"
#include "npc.h"

API_CALLABLE(N(GetLastActorEventType)) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);

    actor->lastEventType = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}
