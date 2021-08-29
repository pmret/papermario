#include "trd_03.h"

static char* N(exit_str_0) = "trd_02";
static char* N(exit_str_1) = "trd_04";

ApiStatus func_80240000_9A4650(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    u32 stickX;

    stickX = 0;
    if (gCollisionStatus.pushingAgainstWall == COLLIDER_o84) {
        stickX = gGameStatusPtr->stickX < 0;
    }
    if ((gCollisionStatus.pushingAgainstWall == COLLIDER_o85) && (gGameStatusPtr->stickX > 0)) {
        stickX = 2;
    }

    evt_set_variable(script, *args, stickX);
    return ApiStatus_DONE2;
}

ApiStatus GetFrameCounter(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gGameStatusPtr->frameCounter);
    return ApiStatus_DONE2;
}
