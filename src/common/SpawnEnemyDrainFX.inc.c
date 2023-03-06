#include "common.h"
#include "npc.h"

API_CALLABLE(N(SpawnDrainHealthStartFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    show_start_recovery_shimmer(x, y, z, evt_get_variable(script, *args++));

    return ApiStatus_DONE2;
}

API_CALLABLE(N(SpawnDrainHealthContinueFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    show_recovery_shimmer(x, y, z, evt_get_variable(script, *args++));

    return ApiStatus_DONE2;
}
