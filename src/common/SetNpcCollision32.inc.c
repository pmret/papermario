#include "common.h"

ApiStatus N(SetNpcCollision32)(ScriptInstance* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(100);

    npc->collisionHeight = 32;
    npc->collisionRadius = 32;
    return ApiStatus_DONE2;
}
