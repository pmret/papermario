#include "common.h"
#include "npc.h"

ApiStatus N(UnkBattleFunc2)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    show_start_recovery_shimmer(x, y, z, evt_get_variable(script, *args++));

    return ApiStatus_DONE2;
}

ApiStatus N(UnkBattleFunc2_2)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    show_recovery_shimmer(x, y, z, evt_get_variable(script, *args++));

    return ApiStatus_DONE2;
}
