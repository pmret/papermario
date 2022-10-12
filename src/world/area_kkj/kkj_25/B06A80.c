#include "effects.h"
#include "kkj_25.h"

#include "world/common/todo/GetFloorCollider.inc.c"

#include "common/UnkLightningFXFunc.inc.c"

#include "world/common/todo/SetEntityPositionF.inc.c"

#include "world/common/todo/GetEntityPosition.inc.c"

ApiStatus func_80240264_B06C64(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 posX = evt_get_float_variable(script, *args++);
    f32 posY = evt_get_float_variable(script, *args++);
    f32 posZ = evt_get_float_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    fx_lens_flare(0, posX, posY, posZ, duration);
    return ApiStatus_DONE2;
}
