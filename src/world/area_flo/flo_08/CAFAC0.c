#include "flo_08.h"

INCLUDE_ASM(s32, "world/area_flo/flo_08/CAFAC0", func_80240D80_CAFAC0);

INCLUDE_ASM(s32, "world/area_flo/flo_08/CAFAC0", func_80241364_CB00A4);

INCLUDE_ASM(s32, "world/area_flo/flo_08/CAFAC0", func_802414C8_CB0208);

INCLUDE_ASM(s32, "world/area_flo/flo_08/CAFAC0", func_8024150C_CB024C);

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_08/CAFAC0", func_80241970_CB06B0);
/*
ApiStatus N(func_80241970_CB06B0)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_flo/flo_08/CAFAC0", func_802419C4_CB0704);
/*
ApiStatus N(func_802419C4_CB0704)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_flo/flo_08/CAFAC0", func_802419FC_CB073C);
/*
ApiStatus N(func_802419FC_CB073C)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_flo/flo_08/CAFAC0", func_80241A98_CB07D8);

INCLUDE_ASM(s32, "world/area_flo/flo_08/CAFAC0", func_80241B5C_CB089C);

INCLUDE_ASM(s32, "world/area_flo/flo_08/CAFAC0", func_80241BCC_CB090C);

#include "world/common/SomeMatrixOperations.inc.c"
