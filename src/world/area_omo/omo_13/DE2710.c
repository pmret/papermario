#include "omo_13.h"

INCLUDE_ASM(s32, "world/area_omo/omo_13/DE2710", func_80240280_DE2710);

INCLUDE_ASM(s32, "world/area_omo/omo_13/DE2710", func_802402F0_DE2780);

INCLUDE_ASM(s32, "world/area_omo/omo_13/DE2710", func_802403C0_DE2850);

INCLUDE_ASM(s32, "world/area_omo/omo_13/DE2710", func_80240458_DE28E8);

INCLUDE_ASM(s32, "world/area_omo/omo_13/DE2710", func_802404B8_DE2948);

#include "world/common/UnkNpcAIFunc4.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_13/DE2710", func_8024083C_DE2CCC);

INCLUDE_ASM(s32, "world/area_omo/omo_13/DE2710", func_80240A00_DE2E90);

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_13/DE2710", func_80240F00_DE3390);
/*
ApiStatus N(func_80240F00_DE3390)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_omo/omo_13/DE2710", func_80240F54_DE33E4);
/*
ApiStatus N(func_80240F54_DE33E4)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_omo/omo_13/DE2710", func_80240F8C_DE341C);
/*
ApiStatus N(func_80240F8C_DE341C)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_omo/omo_13/DE2710", func_80241028_DE34B8);
