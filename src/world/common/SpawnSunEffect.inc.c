#include "common.h"
#include "map.h"
#include "effects.h"

ApiStatus N(SpawnSunEffect)(ScriptInstance* script, s32 isInitialCall) {
    playFX_82(0, 0.0f, 0.0f, 0.0f, 0.0f, 0);
    return ApiStatus_DONE2;
}
