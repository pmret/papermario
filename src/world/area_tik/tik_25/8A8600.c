#include "tik_25.h"
#include "entity.h"

API_CALLABLE(N(func_80240680_8A8600)) {
    get_entity_by_index(script->varTable[0])->dataBuf.chest->gotItemDone = TRUE;
    return ApiStatus_DONE2;
}

#include "world/common/todo/SetEntityPosition.inc.c"

#include "world/common/util/PlaySpringReboundAnimation.inc.c"
