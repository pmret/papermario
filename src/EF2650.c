#include "common.h"

extern s16 D_80169B16;

ApiStatus func_80240040_EF2650(ScriptInstance* script, s32 isInitialCall) {
    dead_set_variable(script, *script->ptrReadPos, D_80169B16);
    return ApiStatus_DONE2;
}
