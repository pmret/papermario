#include "dead_11.h"

ApiStatus func_80240040_EF2650(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gCollisionStatus.floorBelow);
    return ApiStatus_DONE2;
}
