#include "common.h"
#include "map.h"

ApiStatus N(GetItemEntityPosition)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ItemEntity* entity = get_item_entity(evt_get_variable(script, *args++));

    evt_set_variable(script, *args++, entity->position.x);
    evt_set_variable(script, *args++, entity->position.y);
    evt_set_variable(script, *args++, entity->position.z);
    return ApiStatus_DONE2;
}
