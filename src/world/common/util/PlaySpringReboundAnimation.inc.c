#include "common.h"

extern Addr EntityModel_Spring_ReboundAnim;

API_CALLABLE(N(PlaySpringReboundAnimation)) {
    Bytecode* args = script->ptrReadPos;
    Entity* entity = get_entity_by_index(evt_get_variable(script, *args++));

    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->virtualModelIndex, (s16*) EntityModel_Spring_ReboundAnim);
    return ApiStatus_DONE2;
}
