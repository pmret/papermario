#include "common.h"

API_CALLABLE(N(SetNpcCollision32)) {
    Npc* npc = get_npc_unsafe(100);

    npc->collisionHeight = 32;
    npc->collisionRadius = 32;
    return ApiStatus_DONE2;
}
