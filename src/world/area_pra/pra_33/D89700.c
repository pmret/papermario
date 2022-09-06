#include "pra_33.h"

#include "world/common/atomic/Reflection.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_33/D89700", func_80240F20_D8A600);

ApiStatus func_80240F58_D8A638(Evt* script, s32 isInitialCall) {
    s32 temp_f2;

    script->varTable[6] = dist2D(200.0f, 0.0f, gPlayerStatus.position.x, gPlayerStatus.position.z);
    temp_f2 = atan2(200.0f, 0.0f, gPlayerStatus.position.x, gPlayerStatus.position.z);
    script->varTable[7] = temp_f2;
    script->varTable[7] = clamp_angle(temp_f2);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_pra/pra_33/D89700", func_80241000_D8A6E0);
