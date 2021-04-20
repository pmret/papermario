#include "hos_06.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80240F7C_A3A45C);
/*
ApiStatus N(func_80240F7C_A3A45C)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80240FD0_A3A4B0);
/*
ApiStatus N(func_80240FD0_A3A4B0)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80241008_A3A4E8);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_802410A4_A3A584);
/*
ApiStatus N(func_802410A4_A3A584)(ScriptInstance* script, s32 isInitialCall) {
    s32** ptr = &N(D_80241C68_BE09F8);
    s32 i;
    s32* test;

    if (*ptr == NULL) {
        i = heap_malloc(16 * sizeof(s32));
        *ptr = i;
        for (i = 0, test = *ptr; i < 16; i++) {
            *test++ = script->varTable[i];
        }
    } else {
        for (i = 0, test = *ptr; i < 16; i++) {
            script->varTable[i] = *test++;
        }
        ptr = &N(D_80241C68_BE09F8);
        heap_free(*ptr);
        *ptr = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_802411BC_A3A69C);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_802411F0_A3A6D0);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_8024126C_A3A74C);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_802414E4_A3A9C4);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80241668_A3AB48);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_802417EC_A3ACCC);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80241860_A3AD40);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_802418A4_A3AD84);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_802418E8_A3ADC8);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80241A58_A3AF38);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80241B74_A3B054);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80241CCC_A3B1AC);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80241F98_A3B478);
