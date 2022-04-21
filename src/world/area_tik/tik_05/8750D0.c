#include "tik_05.h"
#include "battle/battle.h"
#include "effects.h"
#include "functions.h"

#include "world/common/UnkPosFunc2.inc.c"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

#ifdef NON_MATCHING

extern s32 D_000001E4;

ApiStatus func_8024093C_8756FC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPosition;
    Entity* entity = get_entity_by_index(evt_get_variable(script, *args++));

    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->virtualModelIndex, &D_000001E4);
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_tik/tik_05/8750D0", func_8024093C_8756FC);
#endif

#include "world/common/SetEntityPosition.inc.c"
