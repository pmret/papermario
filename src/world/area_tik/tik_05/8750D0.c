#include "tik_05.h"

#include "world/common/UnkPosFunc2.inc.c"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

#include "battle/battle.h"
#include "effects.h"

#ifndef NON_MATCHING

void play_model_animation(s32, s32);                     /* extern */
extern s32 D_000001E4;

ApiStatus func_8024093C_8756FC(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(evt_get_variable(script, *script->ptrReadPos));

    if (entity == 0) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->virtualModelIndex, (s32) &D_000001E4);
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_tik/tik_05/8750D0", func_8024093C_8756FC);
#endif

#include "world/common/SetEntityPosition.inc.c"
