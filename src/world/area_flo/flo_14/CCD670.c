#include "flo_14.h"

ApiStatus N(func_80242360_CCD670)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gCollisionStatus.floorBelow);
    return ApiStatus_DONE2;
}
