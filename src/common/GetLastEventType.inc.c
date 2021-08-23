#include "common.h"

ApiStatus N(GetLastEventType)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);

    actor->lastEventType = get_variable(script, *args++);

    return ApiStatus_DONE2;
}
