#include "kkj_12.h"

#include "world/common/atomic/UnkPhysicsFuncs.inc.c"

#include "world/common/todo/GetPeachDisguise.inc.c"

ApiStatus func_80240714_AD47A4(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->peachFlags |= PEACH_STATUS_FLAG_8;
    return ApiStatus_DONE2;
}

#include "world/common/todo/UnkGooberFunc.inc.c"

ApiStatus func_8024089C_AD492C(Evt* script, s32 isInitialCall) {
    D_80151328->sources[1].flags = 0;
    return ApiStatus_DONE2;
}

const char* kkj_12_str = "kkj_14";
