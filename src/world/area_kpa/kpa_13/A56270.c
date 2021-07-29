#include "kpa_13.h"

ApiStatus N(func_80240350_A56270)(ScriptInstance* script, s32 isInitialCall) {
    CollisionStatus* collisionStatus = &gCollisionStatus;

    set_variable(script, *script->ptrReadPos, collisionStatus->floorBelow);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_kpa/kpa_13/A56270", func_8024037C_A5629C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_13/A56270", func_80240444_A56364);
