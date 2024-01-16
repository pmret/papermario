#include "common.h"
#include "npc.h"

API_CALLABLE(N(RemovePadlock)) {
    Entity* entity = get_entity_by_index(script->varTable[0]);

    entity->flags |= ENTITY_FLAG_USED;
    return ApiStatus_DONE2;
}
