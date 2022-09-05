#include "kpa_134.h"

ApiStatus func_80240510_AA94B0(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(script->varTable[10]);

    entity->position.x = script->varTable[0];
    entity->position.y = script->varTable[1];
    entity->position.z = script->varTable[2];
    return ApiStatus_DONE2;
}

#include "world/common/SetEntityPosition.inc.c"

#include "world/common/SetEntityFlags100000.inc.c"

#include "world/common/GetEntityPosition.inc.c"
