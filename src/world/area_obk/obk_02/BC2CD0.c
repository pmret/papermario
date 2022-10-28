#include "obk_02.h"

ApiStatus func_80240240_BC2CD0(Evt* script, s32 isInitialCall) {
    script->varTable[0] = sin_deg(script->varTable[1]) * 10.0f;
    script->varTable[1] = clamp_angle(script->varTable[1] + 6);
    return ApiStatus_DONE2;
}
