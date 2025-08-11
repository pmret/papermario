#include "common.h"

API_CALLABLE(N(IsAOrBPressed)) {
    script->varTable[0] = false;
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
        script->varTable[0] = true;
    }
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_B) {
        script->varTable[0] = true;
    }
    return ApiStatus_DONE2;
}
