#include "common.h"

ApiStatus N(UnkBattleFunc5)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = get_variable(script, *args++);
    s32 partID = get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    set_variable(script, *args++, lookup_defense(get_actor_part(get_actor(actorID), partID)->defenseTable, 1));

    return ApiStatus_DONE2;
}
