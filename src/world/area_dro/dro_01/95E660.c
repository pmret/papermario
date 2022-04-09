#include "dro_01.h"

#define NAMESPACE dro_01_dup
#include "world/common/StashVars.inc.c"
#define NAMESPACE dro_01

#define NAMESPACE dro_01_dup
#include "world/common/GetItemName.inc.c"
#define NAMESPACE dro_01

ApiStatus N(func_80243578_95E778)(Evt* script, s32 isInitialCall) {
    hide_coin_counter_immediately();
    return ApiStatus_DONE2;
}
