#include "kpa_134.h"

ApiStatus func_80240510_AA94B0(Evt* script, s32 isInitialCall) {
    Entity* temp_v0 = get_entity_by_index(script->varTable[10]);
    temp_v0->position.x = script->varTable[0];
    temp_v0->position.y = script->varTable[1];
    temp_v0->position.z = script->varTable[2];
    return ApiStatus_DONE2;
}

#include "world/common/SetEntityPosition.inc.c"

#include "world/common/SetEntityFlags100000.inc.c"

#include "world/common/GetEntityPosition.inc.c"
