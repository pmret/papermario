#include "kmr_20.h"
#include "animation_script.h"

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

extern AnimScript Entity_SimpleSpring_AnimLaunch;

ApiStatus func_80241738_8ED558(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(0);

    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->virtualModelIndex, Entity_SimpleSpring_AnimLaunch);
    return ApiStatus_DONE2;
}
