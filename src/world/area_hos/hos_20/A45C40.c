#include "hos_20.h"

s32 func_80240310_A45C40(Evt* script, s32 isInitialCall) {
    script->varTable[8] = FALSE;
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
        script->varTable[8] = TRUE;
    }
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_B) {
        script->varTable[8] = TRUE;
    }
    return ApiStatus_DONE2;
}
