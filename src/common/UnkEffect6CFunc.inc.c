#include "battle/battle.h"
#include "effects.h"

ApiStatus N(UnkEffect6CFunc)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, (s32) playFX_6C(0, 106.0f, 144.0f, 0, 1.0f, 0));
    return ApiStatus_DONE2;
}
