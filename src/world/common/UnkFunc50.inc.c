#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc50)(Evt* script, s32 isInitialCall) {
    f32 temp_f2 = UNK_FUNC_50_VAR1 - script->varTable[0]; //-469.0
    f32 temp_f0 = UNK_FUNC_50_VAR2 - script->varTable[2]; //46.0

    script->varTable[3] = -sqrtf((temp_f2 * temp_f2) + (temp_f0 * temp_f0));

    return ApiStatus_DONE2;
}
