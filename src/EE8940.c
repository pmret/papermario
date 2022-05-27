#include "dead.h"
#include "common.h"

#define NAMESPACE EE8940

ApiStatus func_80242390_EE8940(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gCollisionStatus.floorBelow);
    return ApiStatus_DONE2;
}
