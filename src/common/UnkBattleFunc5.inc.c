#include "common.h"

API_CALLABLE(N(UnkBattleFunc5)) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    evt_set_variable(script, *args++, lookup_defense(get_actor_part(get_actor(actorID), partID)->defenseTable, 1));

    return ApiStatus_DONE2;
}
