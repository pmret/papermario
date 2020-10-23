#include "common.h"

ApiStatus GetNpcCollisionHeight(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcId npcID = get_variable(script, *args++);
    Npc* npc = get_npc_safe(npcID);

    if (npc != NULL) {
        set_variable(script, *args++, npc->collisionHeight);
    }
    return ApiStatus_DONE2;
}
