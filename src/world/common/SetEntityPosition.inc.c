#include "common.h"
#include "map.h"

ApiStatus M(SetEntityPosition)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 entityIndex = get_variable(script, *args++);
    s32 x = get_variable(script, *args++);
    s32 y = get_variable(script, *args++);
    s32 z = get_variable(script, *args++);
    Entity* entity = get_entity_by_index(entityIndex);

    entity->position.x = x;
    entity->position.y = y;
    entity->position.z = z;
    return ApiStatus_DONE2;
}
