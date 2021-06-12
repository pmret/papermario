#include "kmr_11.h"

ApiStatus func_80240EC0_8DAFC0(ScriptInstance* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(script->varTable[10].s);

    entity->position.x = script->varTable[0].s;
    entity->position.y = script->varTable[1].s;
    entity->position.z = script->varTable[2].s;

    return ApiStatus_DONE2;
}
