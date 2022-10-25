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

ApiStatus func_80241168_B852E8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 mode = evt_get_variable(script, *args++);
    f32* array = (f32*) script->array[0];

    f32 dx = array[3] - array[0];
    f32 dy = array[4] - array[1];
    f32 dz = array[5] - array[2];

    script->varTable[5] = (dx / 1000.0f) * script->varTable[0];
    script->varTable[6] = (dy / 1000.0f) * script->varTable[0];
    script->varTable[7] = (dz / 1000.0f) * script->varTable[0];

    if (mode == 0) {
        Npc* partner = get_npc_safe(-4);
        gPlayerStatus.position.x = (script->varTable[2] + script->varTable[5]);
        gPlayerStatus.position.y = (script->varTable[3] + script->varTable[6]);
        gPlayerStatus.position.z = (script->varTable[4] + script->varTable[7]);
        gPlayerStatus.targetYaw = atan2(array[0], array[2], array[3], array[5]);
        partner->pos.x = gPlayerStatus.position.x;
        partner->pos.y = gPlayerStatus.position.y - 10.0f;
        partner->pos.z = gPlayerStatus.position.z - 5.0f;
    }
    return ApiStatus_DONE2;
}

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
        script->varTable[8] = gGameStatusPtr->pressedButtons[0] & BUTTON_A;
    }
    return ApiStatus_DONE2;
}

#include "common/foliage.inc.c"

#include "world/common/todo/PullVineSub.inc.c"
