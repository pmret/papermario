#include "common.h"

#define NAMESPACE b_area_omo2_3

ApiStatus func_80231000_54CC70(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_get_variable(script, args[1]);
    return ApiStatus_DONE2;
}
