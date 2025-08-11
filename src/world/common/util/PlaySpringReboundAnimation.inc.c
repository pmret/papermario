#include "common.h"
#include "animation_script.h"

extern AnimScript Entity_SimpleSpring_AnimLaunch;

API_CALLABLE(N(PlaySpringReboundAnimation)) {
    Bytecode* args = script->ptrReadPos;
    Entity* entity = get_entity_by_index(evt_get_variable(script, *args++));

    if (entity == nullptr) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->virtualModelIndex, Entity_SimpleSpring_AnimLaunch);
    return ApiStatus_DONE2;
}
