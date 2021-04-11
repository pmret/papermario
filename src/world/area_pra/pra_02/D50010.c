#include "pra_02.h"

#include "world/common/UnkFunc2.inc.c"

#include "world/common/UnkFunc3.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_802400EC_D500DC);

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_80240128_D50118);

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_802402F0_D502E0);

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_8024049C_D5048C);

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_80240500_D504F0);

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_8024068C_D5067C);

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_80240870_D50860);

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_80240D3C_D50D2C);

#include "world/common/SetPartnerFlagsA0000.inc.c"

#include "world/common/SetPartnerFlags80000.inc.c"

#include "world/common/SetPartnerFlags20000.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_8024114C_D5113C);
/*
ApiStatus N(func_8024114C_D5113C)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_802411A0_D51190);
/*
ApiStatus N(func_802411A0_D51190)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_802411D8_D511C8);
/*
ApiStatus N(func_802411D8_D511C8)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* temp_v0 = get_variable(script, *args);
    s32* ptr = temp_v0;
    s32 i;

    i = 0;
    if (ptr != NULL) {
        s32 new_var;
        for (new_var = ptr[0]; new_var != 0; i++) {
            *(N(D_8024F080) + i) = ptr[i];
        }
        N(D_8024F080)[i] = 0;
    } else {
        for (; i < 0x70; i++) {
            *(N(D_8024F080) + i) = i + 16;
            N(D_8024F080)[0x70] = 0;
        }
    }
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_80241274_D51264);
/*
ApiStatus N(func_80241274_D51264)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* temp_v0 = get_variable(script, *args);
    s32* ptr = temp_v0;
    s32 i;

    i = 0;
    if (ptr != NULL) {
        s32 new_var;
        for (new_var = ptr[0]; new_var != 0; i++) {
            *(N(D_8024F080) + i) = ptr[i];
        }
        N(D_8024F080)[i] = 0;
    } else {
        for (; i < 0x70; i++) {
            *(N(D_8024F080) + i) = i + 16;
            N(D_8024F080)[0x70] = 0;
        }
    }
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_80241310_D51300);

#include "world/common/GetEntityPosition.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_80241478_D51468);

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_802414A8_D51498);

#include "world/common/SetEntityFlags100000.inc.c"

#define NAMESPACE dup_pra_02
#include "world/common/GetEntityPosition.inc.c"
#define NAMESPACE pra_02
