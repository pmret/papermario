#include "common.h"

void __attribute__((naked)) SetSpriteShading(void) {
    __asm__(
".include \"asm/code_fe0b0_len_5a0/SetSpriteShading.s\"\n"
    );
}

s32 EnableSpriteShading(ScriptContext* script) {
    if (get_variable(script, *script->ptrReadPos) != 0) {
        *D_80151328 |= 1;
    } else {
        *D_80151328 &= ~1;
    }
    return 2;
}

s32 getDemoState(ScriptContext* script) {
    set_variable(script, *script->ptrReadPos, (*gGameStatus)->demoState);
    return 2;
}

s32 DemoPressButton(ScriptContext* script) {
    (*gGameStatus)->demoButtonInput |= get_variable(script, *script->ptrReadPos);
    return 2;
}

s32 DemoReleaseButton(ScriptContext* script) {
    (*gGameStatus)->demoButtonInput &= ~get_variable(script, *script->ptrReadPos);
    return 2;
}

s32 DemoSetButtons(ScriptContext* script) {
    (*gGameStatus)->demoButtonInput = get_variable(script, *script->ptrReadPos);
    return 2;
}

s32 DemoJoystickRadial(ScriptContext* script) {
    float a;
    float b;
    s32* thisPos = script->ptrReadPos;

    a = get_float_variable(script, *thisPos++);
    b = get_float_variable(script, *thisPos++);

    (*gGameStatus)->demoStickX = a * sin_deg(b);
    (*gGameStatus)->demoStickY = a * cos_deg(b);
    
    return 2;
}

s32 DemoJoystickXY(ScriptContext* script) {
    float a;
    float b;
    s32* thisPos = script->ptrReadPos;

    a = get_float_variable(script, *thisPos++);
    b = get_float_variable(script, *thisPos++);

    (*gGameStatus)->demoStickX = a;
    (*gGameStatus)->demoStickY = b;

    return 2;
}
