#include "common.h"

// TODO: not sure where these go
u8 D_802D9D70 = 0xFE;
u8 D_802D9D71 = 0xFE;
u8 D_802D9D72 = 0x00;
u8 D_802D9D73 = 0xFF;

INCLUDE_ASM(ApiStatus, "evt/demo_api", SetSpriteShading, Evt* script, s32 isInitialCall);

ApiStatus EnableSpriteShading(Evt* script, s32 isInitialCall) {
    if (evt_get_variable(script, *script->ptrReadPos) != 0) {
        *D_80151328 |= 1;
    } else {
        *D_80151328 &= ~1;
    }
    return ApiStatus_DONE2;
}

ApiStatus GetDemoState(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gGameStatusPtr->demoState);
    return ApiStatus_DONE2;
}

ApiStatus DemoPressButton(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->demoButtonInput |= evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus DemoReleaseButton(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->demoButtonInput &= ~evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus DemoSetButtons(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->demoButtonInput = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus DemoJoystickRadial(Evt* script, s32 isInitialCall) {
    GameStatus** gameStatus = &gGameStatusPtr;
    f32 a;
    f32 b;
    s32* thisPos = script->ptrReadPos;

    a = evt_get_float_variable(script, *thisPos++);
    b = evt_get_float_variable(script, *thisPos++);

    (*gameStatus)->demoStickX = a * sin_deg(b);
    (*gameStatus)->demoStickY = a * cos_deg(b);

    return ApiStatus_DONE2;
}

ApiStatus DemoJoystickXY(Evt* script, s32 isInitialCall) {
    GameStatus** gameStatus = &gGameStatusPtr;
    f32 x;
    f32 y;
    s32* thisPos = script->ptrReadPos;

    x = evt_get_float_variable(script, *thisPos++);
    y = evt_get_float_variable(script, *thisPos++);

    (*gameStatus)->demoStickX = x;
    (*gameStatus)->demoStickY = y;

    return ApiStatus_DONE2;
}
