#include "pra_19.h"

#include "world/common/reflection.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_19/D6E9D0", func_8024114C_D6FAFC);
/*
ApiStatus N(func_8024114C_D6FAFC)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_pra/pra_19/D6E9D0", func_802411A0_D6FB50);
/*
ApiStatus N(func_802411A0_D6FB50)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_19/D6E9D0", func_802411D8_D6FB88);
/*
ApiStatus N(func_802411D8_D6FB88)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_80244A20)[i] = ptr[i];
        }
        N(D_80244A20)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(D_80244A20)[i] = i + 16;
            N(D_80244A20)[0x70] = 0;
        }
    }
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_19/D6E9D0", func_80241274_D6FC24);
/*
ApiStatus N(func_80241274_D6FC24)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_80244A20)[i] = ptr[i];
        }
        N(D_80244A20)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(D_80244A20)[i] = i + 16;
            N(D_80244A20)[0x70] = 0;
        }
    }
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_19/D6E9D0", func_80241310_D6FCC0);

INCLUDE_ASM(s32, "world/area_pra/pra_19/D6E9D0", func_802413A4_D6FD54);

INCLUDE_ASM(s32, "world/area_pra/pra_19/D6E9D0", func_802414F4_D6FEA4);

INCLUDE_ASM(s32, "world/area_pra/pra_19/D6E9D0", func_80241530_D6FEE0);

INCLUDE_ASM(s32, "world/area_pra/pra_19/D6E9D0", func_802415E0_D6FF90);

INCLUDE_ASM(s32, "world/area_pra/pra_19/D6E9D0", func_802416F8_D700A8);

INCLUDE_ASM(s32, "world/area_pra/pra_19/D6E9D0", func_80241710_D700C0);

INCLUDE_ASM(s32, "world/area_pra/pra_19/D6E9D0", func_8024175C_D7010C);

INCLUDE_ASM(s32, "world/area_pra/pra_19/D6E9D0", func_80241838_D701E8);
