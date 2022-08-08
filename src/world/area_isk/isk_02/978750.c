#include "isk_02.h"

ApiStatus func_80240040_978750(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 x = evt_get_variable(script, *args++);
    f32 y = evt_get_variable(script, *args++);

    if (dist2D(x, y, gPlayerStatus.position.x, gPlayerStatus.position.z) > 250.0f) {
        script->varTable[0] = FALSE;
    } else {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}
