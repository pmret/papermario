#include "isk_09.h"
#include "entity.h"

static char* N(exit_str_0) = "isk_08";
static char* N(exit_str_1) = "";

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

ApiStatus func_802402BC_98679C(Evt* script, s32 isInitialCall) {
    Entity* bigChest = get_entity_by_index(script->varTable[0]);
    bigChest->dataBuf.chest->gotItemDone = TRUE;
    return ApiStatus_DONE2;
}
