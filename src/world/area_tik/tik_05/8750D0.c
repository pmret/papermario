#include "tik_05.h"
#include "battle/battle.h"
#include "effects.h"
#include "functions.h"

#include "world/common/todo/UnkPosFunc2.inc.c"

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

#include "world/common/todo/SomeItemEntityFunc.inc.c"

#include "world/common/todo/IsItemBadge.inc.c"

extern s16 Entity_ScriptSpring_AnimLaunch[];

ApiStatus func_8024093C_8756FC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Entity* entity = get_entity_by_index(evt_get_variable(script, *args++));

    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->virtualModelIndex, Entity_ScriptSpring_AnimLaunch);
    return ApiStatus_DONE2;
}

#include "world/common/todo/SetEntityPosition.inc.c"
