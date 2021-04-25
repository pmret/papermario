#include "hos_06.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80240F7C_A3A45C);
/*
ApiStatus N(func_80240F7C_A3A45C)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_802445D0_A3DAB0) = FALSE;
    }

    if (N(D_802445D0_A3DAB0)) {
        N(D_802445D0_A3DAB0) = FALSE;
        set_variable(script, *args, N(D_802445D4_A3DAB4));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80240FD0_A3A4B0);
/*
ApiStatus N(func_80240FD0_A3A4B0)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_802445D4_A3DAB4) = get_variable(script, *args);
    N(D_802445D0_A3DAB0) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80241008_A3A4E8);
/*
ApiStatus N(func_80241008_A3A4E8)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_802410A4_A3A584);
/*
ApiStatus N(func_802410A4_A3A584)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_8024476C_A3DC4C) == NULL) {
        N(D_8024476C_A3DC4C) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_8024476C_A3DC4C)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_8024476C_A3DC4C)[i];
        }
        heap_free(N(D_8024476C_A3DC4C));
        N(D_8024476C_A3DC4C) = NULL;
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
