#include "sam_07.h"

static char* N(exit_str_0) = "sam_04";
static char* N(exit_str_1) = "sam_08";

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80240000_D2BD30);

#include "world/common/todo/SetEntityPositionF.inc.c"

#include "world/common/todo/GetEntityPosition.inc.c"

ApiStatus func_802405B0_D2C2E0(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 floor = evt_get_variable(script, *args++);
    s32 floor2 = evt_get_variable(script, *args++);

    if (gCollisionStatus.currentFloor == floor || gCollisionStatus.currentFloor == floor2) {
        if (playerStatus->actionState == ACTION_STATE_SPIN_POUND ||
            playerStatus->actionState == ACTION_STATE_TORNADO_POUND)
        {
            return ApiStatus_BLOCK;
        }
    }
    return ApiStatus_DONE2;
}

#include "world/common/todo/UnsetCamera0MoveFlag1.inc.c"

#include "world/common/enemy/ai/PiranhaPlantAI.inc.c"
