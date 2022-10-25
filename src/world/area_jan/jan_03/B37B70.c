#include "jan_03.h"

ApiStatus func_80242FA0_B37B70(Evt* script, s32 isInitialCall) {
    f32 x = gPlayerStatus.currentSpeed * 5.0f * sin_deg(gPlayerStatus.targetYaw);
    f32 z = gPlayerStatus.currentSpeed * 5.0f * -cos_deg(gPlayerStatus.targetYaw);

    script->varTable[0] = gPlayerStatus.position.x + x;
    script->varTable[1] = gPlayerStatus.position.z + z;
    return ApiStatus_DONE2;
}
