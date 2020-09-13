#include "common.h"

INCLUDE_API_ASM("code_fe0b0_len_5a0", SetSpriteShading);

ApiStatus EnableSpriteShading(ScriptInstance* script, s32 isInitialCall) {
    if (get_variable(script, *script->ptrReadPos) != 0) {
        *D_80151328 |= 1;
    } else {
        *D_80151328 &= ~1;
    }
    return ApiStatus_DONE2;
}

s32 getDemoState(ScriptInstance* script) {
    set_variable(script, *script->ptrReadPos, GAME_STATUS->demoState);
    return ApiStatus_DONE2;
}

ApiStatus DemoPressButton(ScriptInstance* script, s32 isInitialCall) {
    GAME_STATUS->demoButtonInput |= get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus DemoReleaseButton(ScriptInstance* script, s32 isInitialCall) {
    GAME_STATUS->demoButtonInput &= ~get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus DemoSetButtons(ScriptInstance* script, s32 isInitialCall) {
    GAME_STATUS->demoButtonInput = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus DemoJoystickRadial(ScriptInstance* script, s32 isInitialCall) {
    f32 a;
    f32 b;
    s32* thisPos = script->ptrReadPos;

    a = get_float_variable(script, *thisPos++);
    b = get_float_variable(script, *thisPos++);

    GAME_STATUS->demoStickX = a * sin_deg(b);
    GAME_STATUS->demoStickY = a * cos_deg(b);

    return ApiStatus_DONE2;
}

ApiStatus DemoJoystickXY(ScriptInstance* script, s32 isInitialCall) {
    f32 x;
    f32 y;
    s32* thisPos = script->ptrReadPos;

    x = get_float_variable(script, *thisPos++);
    y = get_float_variable(script, *thisPos++);

    GAME_STATUS->demoStickX = x;
    GAME_STATUS->demoStickY = y;

    return ApiStatus_DONE2;
}
