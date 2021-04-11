#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc33)(ScriptInstance *script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 camIdx = get_variable(script, *args++);

    CAM2(camIdx)->vfov = get_variable(script, *args++);

    return ApiStatus_DONE2;
}