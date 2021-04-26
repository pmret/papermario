#include "kpa_12.h"

ApiStatus N(D_80240350_A54CA0)(ScriptInstance *script, s32 isInitialCall) {
    CollisionStatus* collisionStatus = &gCollisionStatus;

    set_variable(script, *script->ptrReadPos, collisionStatus->floorBelow);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_kpa/kpa_12/A54CA0", func_8024037C_A54CCC);

INCLUDE_ASM(s32, "world/area_kpa/kpa_12/A54CA0", func_80240444_A54D94);
