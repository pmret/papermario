#include "common.h"
#include "map.h"

ApiStatus N(GetItemEntityPosition)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ItemEntity* entity = get_item_entity(get_variable(script, *args++));

    set_variable(script, *args++, entity->position.x);
    set_variable(script, *args++, entity->position.y);
    set_variable(script, *args++, entity->position.z);
    return ApiStatus_DONE2;
}
