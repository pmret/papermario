#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc43)(ScriptInstance *script, s32 isInitialCall) {
    f32 var1 = script->varTable[0] - script->varTable[3];
    f32 var2 = script->varTable[1] - script->varTable[4];
    f32 var3 = script->varTable[2] - script->varTable[5];

    script->varTable[0] = SQ(var1) + SQ(var2) + SQ(var3) < SQ(60.0f);

    return ApiStatus_DONE2;
}
