#include "common.h"
#include "map.h"

ApiStatus N(SetEntityPositionF)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 entityIndex = evt_get_variable(script, *args++);
    f32 x = evt_get_variable(script, *args++);
    f32 y = evt_get_variable(script, *args++);
    f32 z = evt_get_variable(script, *args++);
    Entity* entity = get_entity_by_index(entityIndex);

    entity->position.x = x;
    entity->position.y = y;
    entity->position.z = z;
    return ApiStatus_DONE2;
}
