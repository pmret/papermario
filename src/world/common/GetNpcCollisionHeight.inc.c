#include "common.h"
#include "map.h"

ApiStatus N(GetNpcCollisionHeight)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    Npc* npc = get_npc_safe(npcID);

    if (npc != NULL) {
        evt_set_variable(script, *args++, npc->collisionHeight);
    }
    return ApiStatus_DONE2;
}
