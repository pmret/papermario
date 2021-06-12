#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc43)(ScriptInstance *script, s32 isInitialCall) {
    f32 var1 = script->varTable[0].s - script->varTable[3].s;
    f32 var2 = script->varTable[1].s - script->varTable[4].s;
    f32 var3 = script->varTable[2].s - script->varTable[5].s;

    script->varTable[0].s = SQ(var1) + SQ(var2) + SQ(var3) < SQ(60.0f);

    return ApiStatus_DONE2;
}
