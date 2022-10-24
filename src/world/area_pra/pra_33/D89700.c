#include "pra_33.h"

#include "world/common/atomic/Reflection.inc.c"

ApiStatus func_80240F20_D8A600(Evt* script, s32 isInitialCall) {
    script->varTable[10] = 0;
    if (gCollisionStatus.currentFloor == 0x1C) {
        script->varTable[10] = 1;
    }
    if (gCollisionStatus.lastTouchedFloor == 0x1C) {
        script->varTable[10] = 1;
    }
    return ApiStatus_DONE2;
}


ApiStatus func_80240F58_D8A638(Evt* script, s32 isInitialCall) {
    script->varTable[6] = dist2D(200.0f, 0.0f, gPlayerStatus.position.x, gPlayerStatus.position.z);
    script->varTable[7] = atan2(200.0f, 0.0f, gPlayerStatus.position.x, gPlayerStatus.position.z);
    script->varTable[7] = clamp_angle(script->varTable[7]);
    return ApiStatus_DONE2;
}

ApiStatus func_80241000_D8A6E0(Evt* script, s32 isInitialCall) {
    f32 sinTheta, cosTheta;

    sin_cos_deg(script->varTable[7], &sinTheta, &cosTheta);
    gPlayerStatus.position.x = (script->varTable[6] * sinTheta) + 200.0f;
    gPlayerStatus.position.z = (script->varTable[6] * -cosTheta) + 0.0f;
    return ApiStatus_DONE2;
}
