#include "kkj_12.h"

#include "world/common/atomic/UnkPhysicsFuncs.inc.c"

#include "world/common/GetPeachDisguise.inc.c"

INCLUDE_ASM(s32, "world/area_kkj/kkj_12/AD4100", func_80240714_AD47A4);

#include "world/common/UnkGooberFunc.inc.c"

ApiStatus func_8024089C_AD492C(Evt* script, s32 isInitialCall) {
    D_80151328->sources[1].flags = 0;
    return ApiStatus_DONE2;
}

const char* kkj_12_str = "kkj_14";
