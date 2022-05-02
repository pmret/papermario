#include "iwa_03.h"

static char* N(exit_str_0) = "iwa_01";
static char* N(exit_str_1) = "";

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

ApiStatus func_802402BC_918E6C(Evt* script, s32 isInitialCall) {
    s32 result = -1;
    
    if (gPlayerStatus.lastGoodPosition.y > 200.0) {
        result = 0;
    }
    if (gPlayerStatus.lastGoodPosition.y < 40.0) {
        result = 1;
    }
    if (result >= 0) {
        evt_set_variable(script, GW(9), result);
    }
    return ApiStatus_BLOCK;
}
