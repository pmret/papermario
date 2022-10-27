#include "sam_10.h"

static char* N(exit_str_0) = "sam_09";
static char* N(exit_str_1) = "pra_01";
static char* N(exit_str_2) = "sam_12";
static char* N(exit_str_3) = "";

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

#include "world/common/todo/SomeItemEntityFunc.inc.c"

#include "world/common/todo/IsItemBadge.inc.c"

ApiStatus func_802402BC_D37ABC(Evt* script, s32 isInitialCall) {
    get_item_entity(script->varTable[0])->scale = 0.8f;
    return ApiStatus_DONE2;
}

ApiStatus func_802402F0_D37AF0(Evt* script, s32 isInitialCall) {
    script->varTable[0] = gPlayerStatus.position.x + (sin_deg(310.0f) * 100.0f);
    script->varTable[1] = gPlayerStatus.position.z - (cos_deg(310.0f) * 100.0f);
    script->varTable[2] = gPlayerStatus.position.x + (sin_deg(130.0f) * 100.0f);
    script->varTable[3] = gPlayerStatus.position.z - (cos_deg(130.0f) * 100.0f);
    return ApiStatus_DONE2;
}
