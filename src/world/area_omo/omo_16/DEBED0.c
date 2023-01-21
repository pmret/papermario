#include "omo_16.h"

static char* N(exit_str_0) = "omo_10";
static char* N(exit_str_1) = "omo_08";
static char* N(exit_str_2) = "omo_06";
static char* N(exit_str_3) = "omo_03";

#include "world/common/todo/UnsetCamera0MoveFlag1.inc.c"

#include "common/SetAngleClamped.inc.c"

#include "common/CompareFloats.inc.c"

#include "common/AdvanceBuffer.inc.c"

#include "common/SetPlayerStatusPosYaw.inc.c"

#include "common/SetNpcPosYaw.inc.c"

#include "common/CosInterpMinMax.inc.c"

#include "common/IsAOrBPressed.inc.c"

ApiStatus func_8024055C_DEC42C(Evt* script, s32 isInitialCall) {
    f32 temp_f0 = evt_get_float_variable(script, MapVar(11));

    script->varTable[0] = 0;
    if (fabsf(temp_f0) < 2000.0f && (gGameStatusPtr->pressedButtons[0] & BUTTON_A)) {
        script->varTable[0] = 1;
    }

    if (fabsf(temp_f0) < 2000.0f && (gGameStatusPtr->pressedButtons[0] & BUTTON_B)) {
        script->varTable[0] = 1;
    }
    return ApiStatus_DONE2;
}
