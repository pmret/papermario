#include "trd_03.h"

static ApiStatus func_80240000_9A4650(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    u32 stickX;

    stickX = 0;
    if (gCollisionStatus.pushingAgainstWall == 35) {
        stickX = ((u32)GAME_STATUS->stickX) >> 0x1F;
    }
    if ((gCollisionStatus.pushingAgainstWall == 37) && (GAME_STATUS->stickX > 0)) {
        stickX = 2;
    }

    set_variable(script, *args, stickX);
    return ApiStatus_DONE2;
}

static ApiStatus GetFrameCounter(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, GAME_STATUS->frameCounter);
    return ApiStatus_DONE2;
}
