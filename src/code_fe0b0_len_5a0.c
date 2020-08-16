#include "common.h"

INCLUDE_ASM(code_fe0b0_len_5a0, SetSpriteShading);

s32 EnableSpriteShading(Script* script) {
    if (get_variable(script, *script->ptrReadPos) != 0) {
        *D_80151328 |= 1;
    } else {
        *D_80151328 &= ~1;
    }
    return 2;
}

s32 getDemoState(Script* script) {
    set_variable(script, *script->ptrReadPos, (*gGameStatusPtr)->demoState);
    return 2;
}

s32 DemoPressButton(Script* script) {
    (*gGameStatusPtr)->demoButtonInput |= get_variable(script, *script->ptrReadPos);
    return 2;
}

s32 DemoReleaseButton(Script* script) {
    (*gGameStatusPtr)->demoButtonInput &= ~get_variable(script, *script->ptrReadPos);
    return 2;
}

s32 DemoSetButtons(Script* script) {
    (*gGameStatusPtr)->demoButtonInput = get_variable(script, *script->ptrReadPos);
    return 2;
}

s32 DemoJoystickRadial(Script* script) {
    f32 a;
    f32 b;
    s32* thisPos = script->ptrReadPos;

    a = get_float_variable(script, *thisPos++);
    b = get_float_variable(script, *thisPos++);

    (*gGameStatusPtr)->demoStickX = a * sin_deg(b);
    (*gGameStatusPtr)->demoStickY = a * cos_deg(b);

    return 2;
}

s32 DemoJoystickXY(Script* script) {
    f32 x;
    f32 y;
    s32* thisPos = script->ptrReadPos;

    x = get_float_variable(script, *thisPos++);
    y = get_float_variable(script, *thisPos++);

    (*gGameStatusPtr)->demoStickX = x;
    (*gGameStatusPtr)->demoStickY = y;

    return 2;
}
