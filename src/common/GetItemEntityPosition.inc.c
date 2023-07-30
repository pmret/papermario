#include "common.h"
#include "npc.h"

API_CALLABLE(N(GetItemEntityPosition)) {
    Bytecode* args = script->ptrReadPos;
    ItemEntity* entity = get_item_entity(evt_get_variable(script, *args++));

    evt_set_variable(script, *args++, entity->pos.x);
    evt_set_variable(script, *args++, entity->pos.y);
    evt_set_variable(script, *args++, entity->pos.z);
    return ApiStatus_DONE2;
}
