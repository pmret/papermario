#include "kzn_09.h"

ApiStatus func_80240D40_C77A20(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    if (*args++ != 0) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        sfx_adjust_env_sound_pos(SOUND_168, 0, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80240DE4_C77AC4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    if (*args++ != 0) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        sfx_adjust_env_sound_pos(SOUND_185, 0, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77A20", func_80240E88_C77B68);

ApiStatus func_80241000_C77CE0(Evt* script, s32 isInitialCall) {
    script->varTable[8] = gGameStatusPtr->pressedButtons & BUTTON_A;
    return ApiStatus_DONE2;
}
