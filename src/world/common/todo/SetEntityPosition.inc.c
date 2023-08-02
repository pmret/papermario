#include "common.h"

API_CALLABLE(N(SetEntityPosition)) {
    Bytecode* args = script->ptrReadPos;
    s32 entityIndex = evt_get_variable(script, *args++);
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    Entity* entity = get_entity_by_index(entityIndex);

    entity->pos.x = x;
    entity->pos.y = y;
    entity->pos.z = z;
    return ApiStatus_DONE2;
}
