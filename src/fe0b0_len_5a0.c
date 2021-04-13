#include "common.h"

INCLUDE_ASM(ApiStatus, "fe0b0_len_5a0", SetSpriteShading, ScriptInstance* script, s32 isInitialCall);

ApiStatus EnableSpriteShading(ScriptInstance* script, s32 isInitialCall) {
    if (get_variable(script, *script->ptrReadPos) != 0) {
        *D_80151328 |= 1;
    } else {
        *D_80151328 &= ~1;
    }
    return ApiStatus_DONE2;
}

ApiStatus GetDemoState(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gGameStatusPtr->demoState);
    return ApiStatus_DONE2;
}

ApiStatus DemoPressButton(ScriptInstance* script, s32 isInitialCall) {
    gGameStatusPtr->demoButtonInput |= get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus DemoReleaseButton(ScriptInstance* script, s32 isInitialCall) {
    gGameStatusPtr->demoButtonInput &= ~get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus DemoSetButtons(ScriptInstance* script, s32 isInitialCall) {
    gGameStatusPtr->demoButtonInput = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus DemoJoystickRadial(ScriptInstance* script, s32 isInitialCall) {
    GameStatus** gameStatus = &gGameStatusPtr;
    f32 a;
    f32 b;
    s32* thisPos = script->ptrReadPos;

    a = get_float_variable(script, *thisPos++);
    b = get_float_variable(script, *thisPos++);

    (*gameStatus)->demoStickX = a * sin_deg(b);
    (*gameStatus)->demoStickY = a * cos_deg(b);

    return ApiStatus_DONE2;
}

ApiStatus DemoJoystickXY(ScriptInstance* script, s32 isInitialCall) {
    GameStatus** gameStatus = &gGameStatusPtr;
    f32 x;
    f32 y;
    s32* thisPos = script->ptrReadPos;

    x = get_float_variable(script, *thisPos++);
    y = get_float_variable(script, *thisPos++);

    (*gameStatus)->demoStickX = x;
    (*gameStatus)->demoStickY = y;

    return ApiStatus_DONE2;
}
