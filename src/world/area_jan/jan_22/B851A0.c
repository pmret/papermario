#include "jan_22.h"

ApiStatus func_80241020_B851A0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    if (*args++ != 0) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        sfx_adjust_env_sound_pos(SOUND_168, 0, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802410C4_B85244(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    if (*args++ != 0) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        sfx_adjust_env_sound_pos(SOUND_185, 0, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_jan/jan_22/B851A0", func_80241168_B852E8);

ApiStatus func_802412E0_B85460(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 posA = evt_get_variable(script, *args++);
    s32 ax1 = posA - 17;
    s32 ax2 = posA + 17;
    s32 posB = evt_get_variable(script, *args++);
    s32 bx1 = posB - 17;
    s32 bx2 = posB + 17;
    
    script->varTable[8] = -1;
    if (((gPlayerStatus.position.x < ax1) || (ax2 < gPlayerStatus.position.x))
     && ((gPlayerStatus.position.x < bx1) || (bx2 < gPlayerStatus.position.x))) {
        script->varTable[8] = gGameStatusPtr->pressedButtons & BUTTON_A;
    }
    return ApiStatus_DONE2;
}

#include "common/foliage.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_22/B851A0", func_8024160C_B8578C);

INCLUDE_ASM(s32, "world/area_jan/jan_22/B851A0", func_80241668_B857E8);
