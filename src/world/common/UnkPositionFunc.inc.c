#include "common.h"
#include "map.h"

ApiStatus N(UnkPositionFunc)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 var0 = get_variable(script, *args++);
    f32 var1 = get_variable(script, *args++);
    f32 var2 = get_variable(script, *args++);
    f32 var3 = get_variable(script, *args++);
    f32 temp;

    temp = (var3 - var1) / (var2 - var0);

    if (playerStatus->position.z < ((temp * playerStatus->position.x) + (var1 - (temp * var0)))) {
        script->varTable[0].s = 0;
    } else {
        script->varTable[0].s = 1;
    }

    return ApiStatus_DONE2;
}
