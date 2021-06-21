#include "common.h"
#include "map.h"

void func_80072950(s32, f32, f32, f32, f32, s32);

ApiStatus N(SpawnSunEffect)(ScriptInstance* script, s32 isInitialCall) {
    func_80072950(0, 0.0f, 0.0f, 0.0f, 0.0f, 0);
    return ApiStatus_DONE2;
}
