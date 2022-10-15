#include "kzn_18.h"

#include "world/common/todo/SetCamera0Flag1000.inc.c"

#include "world/common/todo/UnsetCamera0Flag1000.inc.c"

ApiStatus func_80240388_EA7358(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gCollisionStatus.currentFloor);
    return ApiStatus_DONE2;
}
