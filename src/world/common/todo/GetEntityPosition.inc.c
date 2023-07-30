#include "common.h"
#include "npc.h"

API_CALLABLE(N(GetEntityPosition)) {
    Bytecode* args = script->ptrReadPos;
    Entity* entity = get_entity_by_index(evt_get_variable(script, *args++));

    evt_set_variable(script, *args++, entity->pos.x);
    evt_set_variable(script, *args++, entity->pos.y);
    evt_set_variable(script, *args++, entity->pos.z);
    return ApiStatus_DONE2;
}
