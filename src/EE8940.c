#include "dead.h"
#include "common.h"

extern s16 D_80169B16;

ApiStatus func_80242390_EE8940(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, D_80169B16);
    return ApiStatus_DONE2;
}
