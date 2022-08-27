#include "kkj_12.h"

#include "world/common/atomic/UnkPhysicsFuncs.inc.c"

#include "world/common/GetPeachDisguise.inc.c"

ApiStatus func_80240714_AD47A4(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->peachFlags |= 0x8;
    return ApiStatus_DONE2;
}

#include "world/common/UnkGooberFunc.inc.c"

ApiStatus func_8024089C_AD492C(Evt* script, s32 isInitialCall) {
    D_80151328->sources[1].flags = 0;
    return ApiStatus_DONE2;
}

const char* kkj_12_str = "kkj_14";
