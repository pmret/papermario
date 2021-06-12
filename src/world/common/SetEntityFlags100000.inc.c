#include "common.h"
#include "map.h"

ApiStatus N(SetEntityFlags100000)(ScriptInstance* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(script->varTable[0].s);

    entity->flags |= 0x100000;
    return ApiStatus_DONE2;
}
