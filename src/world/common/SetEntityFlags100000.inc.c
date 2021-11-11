#include "common.h"
#include "npc.h"

ApiStatus N(SetEntityFlags100000)(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(script->varTable[0]);

    entity->flags |= ENTITY_FLAGS_100000;
    return ApiStatus_DONE2;
}
