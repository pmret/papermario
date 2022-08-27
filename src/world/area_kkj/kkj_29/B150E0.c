#include "kkj_29.h"

ApiStatus func_80240030_B150E0(Evt* script, s32 isInitialCall) {
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
        script->varTable[0] = 1;
        return ApiStatus_DONE2;
    }

    script->varTable[0]--;
    if (script->varTable[0] == 0) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
