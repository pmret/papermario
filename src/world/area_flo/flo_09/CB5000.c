#include "flo_09.h"

void playFX_82();

ApiStatus N(func_80240000_CB5000)(ScriptInstance* script, s32 isInitialCall) {
    playFX_82(1, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
