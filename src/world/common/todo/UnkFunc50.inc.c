#include "common.h"
#include "npc.h"

API_CALLABLE(N(UnkFunc50)) {
    f32 x = UNK_FUNC_50_LVar1 - script->varTable[0];
    f32 z = UNK_FUNC_50_LVar2 - script->varTable[2];

    script->varTable[3] = -sqrtf(SQ(x) + SQ(z));

    return ApiStatus_DONE2;
}
