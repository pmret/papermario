#include "common.h"

ApiStatus N(IsAOrBPressed)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = FALSE;
    if (gGameStatusPtr->pressedButtons & BUTTON_A) {
        script->varTable[0] = TRUE;
    }
    if (gGameStatusPtr->pressedButtons & BUTTON_B) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}
