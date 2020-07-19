#include "common.h"

INCLUDE_ASM(code_fe0b0_len_5a0, SetSpriteShading);

s32 EnableSpriteShading(ScriptContext* script) {
    if (get_variable(script, *script->ptrReadPos) != 0) {
        *D_80151328 |= 1;
    } else {
        *D_80151328 &= ~1;
    }
    return 2;
}

s32 getDemoState(ScriptContext* script) {
    set_variable(script, *script->ptrReadPos, (*gGameStatusPtr)->demoState);
    return 2;
}

s32 DemoPressButton(ScriptContext* script) {
    (*gGameStatusPtr)->demoButtonInput |= get_variable(script, *script->ptrReadPos);
    return 2;
}

s32 DemoReleaseButton(ScriptContext* script) {
    (*gGameStatusPtr)->demoButtonInput &= ~get_variable(script, *script->ptrReadPos);
    return 2;
}

s32 DemoSetButtons(ScriptContext* script) {
    (*gGameStatusPtr)->demoButtonInput = get_variable(script, *script->ptrReadPos);
    return 2;
}

s32 DemoJoystickRadial(ScriptContext* script) {
    f32 a;
    f32 b;
    s32* thisPos = script->ptrReadPos;

    a = get_float_variable(script, *thisPos++);
    b = get_float_variable(script, *thisPos++);

    (*gGameStatusPtr)->demoStickX = a * sin_deg(b);
    (*gGameStatusPtr)->demoStickY = a * cos_deg(b);
    
    return 2;
}

s32 DemoJoystickXY(ScriptContext* script) {
    f32 a;
    f32 b;
    s32* thisPos = script->ptrReadPos;

    a = get_float_variable(script, *thisPos++);
    b = get_float_variable(script, *thisPos++);

    (*gGameStatusPtr)->demoStickX = a;
    (*gGameStatusPtr)->demoStickY = b;

    return 2;
}
