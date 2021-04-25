#include "flo_14.h"

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_14/CCB310", func_8024030C_CCB61C);

INCLUDE_ASM(s32, "world/area_flo/flo_14/CCB310", func_80240340_CCB650);
/*
ApiStatus N(func_80240340_CCB650)(ScriptInstance *script, s32 isInitialCall) {
    f32 var1 = script->varTable[0] - script->varTable[3];
    f32 var2 = script->varTable[1] - script->varTable[4];
    f32 var3 = script->varTable[2] - script->varTable[5];
    s32 flag = TRUE;
    
    if (!((SQ(var1) + SQ(var2) + SQ(var3)) < 3600.0f)) {
        flag = FALSE;
    }
    script->varTable[0] = flag;

    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_flo/flo_14/CCB310", func_802403D4_CCB6E4);

INCLUDE_ASM(s32, "world/area_flo/flo_14/CCB310", func_8024042C_CCB73C);

INCLUDE_ASM(s32, "world/area_flo/flo_14/CCB310", func_8024046C_CCB77C);

INCLUDE_ASM(s32, "world/area_flo/flo_14/CCB310", func_80240504_CCB814);

INCLUDE_ASM(s32, "world/area_flo/flo_14/CCB310", func_802407D4_CCBAE4);
