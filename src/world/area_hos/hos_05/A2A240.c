#include "hos_05.h"

static char* N(exit_str_0) = "hos_04";
static char* N(exit_str_1) = "";

#include "world/common/atomic/UnkFunc27.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

ApiStatus N(AwaitScriptComplete)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 waitingScriptID = evt_get_variable(script, *args++);

    if (!does_script_exist(waitingScriptID)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus func_80240634_A2A874(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);

    script->varTable[idx] = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_80240690_A2A8D0(Evt* script, s32 isInitialCall) {
    f32 vt2 = script->varTable[2];
    f32 temp_f20;
    f32 temp_f26;

    script->varTable[2] = EVT_FLOAT(0);
    script->varTable[3] = EVT_FLOAT(100);
    script->varTable[4] = EVT_FLOAT(0);

    temp_f26 = (script->varTable[1] * 180.0f) / PI;
    temp_f20 = (rand_int(10) / vt2) + 3.0f;

    script->varTable[10] = EVT_FLOAT_TO_FIXED(temp_f20 * cos_rad(temp_f26));
    script->varTable[11] = EVT_FLOAT_TO_FIXED(rand_int(15) + 5);
    script->varTable[12] = EVT_FLOAT_TO_FIXED(temp_f20 * sin_rad(temp_f26));
    script->varTable[13] = EVT_FLOAT_TO_FIXED((f32)(rand_int(10) + 10) * -0.05);

    return ApiStatus_DONE2;
}
