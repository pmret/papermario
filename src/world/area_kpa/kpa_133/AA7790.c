#include "kpa_133.h"

ApiStatus func_80240310_AA7790(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Entity* entity = get_entity_by_index(evt_get_variable(NULL, -50000000));

    entity->rotation.x = evt_get_variable(script, *args++);
    entity->rotation.y = evt_get_variable(script, *args++);
    entity->rotation.z = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_802403C0_AA7840(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Entity* entity = get_entity_by_index(evt_get_variable(NULL, -50000000));

    entity->position.x = evt_get_variable(script, *args++);
    entity->position.y = evt_get_variable(script, *args++);
    entity->position.z = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}
