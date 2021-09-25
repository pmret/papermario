#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc47)(Evt* script, s32 isInitialCall) {
    f32 var1 = script->varTable[0] - gPlayerStatus.position.x;
    f32 var2 = script->varTable[2] - gPlayerStatus.position.y;
    f32 var3 = 0.0f - gPlayerStatus.position.z;

    script->varTable[4] = sqrtf((var1 * var1) + (var2 * var2) + (var3 * var3));

    return ApiStatus_DONE2;
}
