#include "kzn_03.h"

#include "world/common/UnsetCamera0MoveFlag1.inc.c"

#include "world/common/SetCamera0MoveFlag1.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C63A10", func_80242D38_C63A48);

ApiStatus func_80242DB0_C63AC0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    if (*args++ != 0) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        sfx_adjust_env_sound_pos(SOUND_168, 0, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80242E54_C63B64(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    if (*args++ != 0) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        sfx_adjust_env_sound_pos(SOUND_185, 0, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C63A10", func_80242EF8_C63C08);

ApiStatus func_80243070_C63D80(Evt* script, s32 isInitialCall) {
    script->varTable[8] = gGameStatusPtr->pressedButtons & BUTTON_A;
    return ApiStatus_DONE2;
}
