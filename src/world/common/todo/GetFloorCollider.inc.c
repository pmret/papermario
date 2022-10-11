#include "common.h"
#include "npc.h"

ApiStatus N(GetFloorCollider)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, gCollisionStatus.currentFloor);
    return ApiStatus_DONE2;
}
