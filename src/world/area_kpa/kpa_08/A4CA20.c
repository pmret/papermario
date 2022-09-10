#include "kpa_08.h"

static char* N(exit_str_0) = "kpa_52";
static char* N(exit_str_1) = "kpa_100";

#include "world/common/UnsetCamera0MoveFlag1.inc.c"

ApiStatus func_8024001C_A4CA3C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 floor = evt_get_variable(script, *args++);
    s32 yOffset = evt_get_variable(script, *args++);
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (floor == gCollisionStatus.currentFloor) {
        playerStatus->position.y = script->varTable[0] + yOffset;
    }
    return ApiStatus_DONE2;
}
