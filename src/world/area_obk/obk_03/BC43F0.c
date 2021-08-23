#include "obk_03.h"

INCLUDE_ASM(s32, "world/area_obk/obk_03/BC43F0", func_80240170_BC43F0);
/*
ApiStatus N(func_80240170_BC43F0)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80242ECC_BC714C) == NULL) {
        N(D_80242ECC_BC714C) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80242ECC_BC714C)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80242ECC_BC714C)[i];
        }
        heap_free(N(D_80242ECC_BC714C));
        N(D_80242ECC_BC714C) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_obk/obk_03/BC43F0", func_802404B4_BC4734);
/*
ApiStatus N(func_802404B4_BC4734)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80242F30_BC71B0) = FALSE;
    }

    if (N(D_80242F30_BC71B0)) {
        N(D_80242F30_BC71B0) = FALSE;
        set_variable(script, *args, N(D_80242F34_BC71B4));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_obk/obk_03/BC43F0", func_80240508_BC4788);
/*
ApiStatus N(func_80240508_BC4788)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80242F34_BC71B4) = get_variable(script, *args);
    N(D_80242F30_BC71B0) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_obk/obk_03/BC43F0", func_80240540_BC47C0);
/*
ApiStatus N(func_80240540_BC47C0)(Evt* script, s32 isInitialCall) {
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
            N(D_80244A20)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_obk/obk_03/BC43F0", func_80240858_BC4AD8);
/*
ApiStatus N(func_80240858_BC4AD8)(Evt *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_obk/obk_03/BC43F0", func_8024089C_BC4B1C);
/*
ApiStatus N(func_8024089C_BC4B1C)(Evt *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
*/
