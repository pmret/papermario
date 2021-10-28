#include "dead.h"
#include "common.h"

#define NAMESPACE EA36E0

// Copy of kzn_17 (C887B0.c)

#define UNK_FUNC_50_VAR1 -583.0
#define UNK_FUNC_50_VAR2 165.0

ApiStatus N(SpinyTrompHit)(Evt* script, s32 isInitialCall) {
    subtract_hp(1);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "EA36E0", func_80242E00_EA3700);

#include "world/common/UnkFunc46.inc.c"

// TODO: Linker magic
// Normally this would be #include "world/common/UnkFunc47.inc.c"
// Due to sqrtf being an inline/instrinsic func, we can't use dead.h
#ifdef NON_MATCHING
ApiStatus func_80242EC4_EA37C4(Evt* script, s32 isInitialCall) {
    f32 var1 = script->varTable[0] - gPlayerStatus.position.x;
    f32 var2 = script->varTable[2] - gPlayerStatus.position.y;
    f32 var3 = 0.0f - gPlayerStatus.position.z;

    script->varTable[4] = sqrtf((var1 * var1) + (var2 * var2) + (var3 * var3));

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "EA36E0", func_80242EC4_EA37C4);
#endif

#include "world/common/UnkFunc48.inc.c"

#include "world/common/UnkFunc49.inc.c"

// TODO: Linker magic
// Normally this would be #include "world/common/UnkFunc50.inc.c"
// Due to sqrtf being an inline/instrinsic func, we can't use dead.h
#ifdef NON_MATCHING
ApiStatus func_80243054_EA3954(Evt* script, s32 isInitialCall) {
    f32 temp_f2 = UNK_FUNC_50_VAR1 - script->varTable[0]; //-469.0
    f32 temp_f0 = UNK_FUNC_50_VAR2 - script->varTable[2]; //46.0

    script->varTable[3] = -sqrtf((temp_f2 * temp_f2) + (temp_f0 * temp_f0));

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "EA36E0", func_80243054_EA3954);
#endif

#include "world/common/UnkFunc51.inc.c"
