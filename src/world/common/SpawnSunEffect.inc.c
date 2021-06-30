#include "common.h"
#include "map.h"

void playFX_82(s32, f32, f32, f32, f32, s32);

ApiStatus N(SpawnSunEffect)(ScriptInstance* script, s32 isInitialCall) {
    playFX_82(0, 0.0f, 0.0f, 0.0f, 0.0f, 0);
    return ApiStatus_DONE2;
}
