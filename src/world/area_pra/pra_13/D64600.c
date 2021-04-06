#include "pra_13.h"

#include "world/common/UnkFunc2.inc.c"

#include "world/common/UnkFunc3.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_802400EC_D646CC);

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_80240128_D64708);

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_802402F0_D648D0);

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_8024049C_D64A7C);

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_80240500_D64AE0);

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_8024068C_D64C6C);

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_80240870_D64E50);

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_80240D3C_D6531C);

#include "world/common/SetPartnerFlagsA0000.inc.c"

#include "world/common/SetPartnerFlags80000.inc.c"

#include "world/common/SetPartnerFlags20000.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_8024114C_D6572C);
/*
ApiStatus N(func_8024114C_D6572C)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr;

    if (isInitialCall) {
        ptr = &D_80241CCC_BE0A5C;
        *ptr = 0;
    }

    ptr = &D_80241CCC_BE0A5C;
    if (*ptr != NULL) {
        ptr = &D_80241CCC_BE0A5C;
        *ptr = 0;
        set_variable(script, *args, D_80241CD0_BE0A60);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_802411A0_D65780);
/*
ApiStatus N(func_802411A0_D65780)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_802411D8_D657B8);

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_80241274_D65854);

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_80241310_D658F0);

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_802413A4_D65984);
/*
ApiStatus N(func_802413A4_D65984)(ScriptInstance* script, s32 isInitialCall) {
    func_800EB168(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_802413D0_D659B0);

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_8024140C_D659EC);

INCLUDE_ASM(s32, "world/area_pra/pra_13/D64600", func_802414BC_D65A9C);