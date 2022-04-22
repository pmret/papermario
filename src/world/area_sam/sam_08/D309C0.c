#include "sam_08.h"

#include "world/common/enemy/MeleeHitbox_States.inc.c"

#include "world/common/enemy/MeleeWanderAI.inc.c"

ApiStatus func_80241610_D31290(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    fx_big_smoke_puff(x, y, z);
    
    return ApiStatus_DONE2;
}

ApiStatus func_802416A4_D31324(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    sfx_adjust_env_sound_pos(0x8000006C, 0, x, y, z);
    
    return ApiStatus_DONE2;
}

ApiStatus func_8024174C_D313CC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 rumbleFreq = evt_get_variable(script, *args++);
    s32 rumbleTime = evt_get_variable(script, *args++);

    start_rumble(rumbleFreq & 0xFF, rumbleTime & 0xFFFF);
    
    return ApiStatus_DONE2;
}
