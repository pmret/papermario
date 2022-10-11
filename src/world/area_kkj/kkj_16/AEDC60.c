#include "kkj_16.h"

#define NAMESPACE dup_kkj_16
#include "world/common/atomic/UnkPhysicsFuncs.inc.c"
#define NAMESPACE kkj_16

#include "world/common/todo/GetPeachDisguise.inc.c"

ApiStatus func_80240EF4_AEE304(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->peachFlags |= PEACH_STATUS_FLAG_8;
    return ApiStatus_DONE2;
}

#define NAMESPACE dup_kkj_16
#include "world/common/todo/UnkGooberFunc50.inc.c"
#define NAMESPACE kkj_16

const char* kkj_16_str2 = "kkj_14";
