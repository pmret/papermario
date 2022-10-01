#include "kkj_10.h"

#define NAMESPACE dup_kkj_10
#include "world/common/atomic/UnkPhysicsFuncs.inc.c"

#include "world/common/GetPeachDisguise.inc.c"

ApiStatus func_80240F44_ACBA64(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->peachFlags |= PEACH_STATUS_FLAG_8;
    return ApiStatus_DONE2;
}

#include "world/common/UnkGooberFunc.inc.c"
#define NAMESPACE kkj_10

const char* kkj_10_str2 = "kkj_14";
