#include "common.h"

API_CALLABLE(N(IsAOrBPressed)) {
    script->varTable[0] = FALSE;
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
        script->varTable[0] = TRUE;
    }
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_B) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}
