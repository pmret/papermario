#include "trd_03.h"

ApiStatus func_80240000_9A4650(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    u32 stickX;

    stickX = 0;
    if (gCollisionStatus.pushingAgainstWall == COLLIDER_o84) {
        stickX = GAME_STATUS->stickX < 0;
    }
    if ((gCollisionStatus.pushingAgainstWall == COLLIDER_o85) && (GAME_STATUS->stickX > 0)) {
        stickX = 2;
    }

    set_variable(script, *args, stickX);
    return ApiStatus_DONE2;
}

ApiStatus GetFrameCounter(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, GAME_STATUS->frameCounter);
    return ApiStatus_DONE2;
}
