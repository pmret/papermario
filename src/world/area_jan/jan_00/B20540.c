#include "jan_00.h"

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_8024030C_B2084C);

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240340_B20880);

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_802403F4_B20934);
/*
ApiStatus N(func_802403F4_B20934)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_802423C8_B22908) == NULL) {
        N(D_802423C8_B22908) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_802423C8_B22908)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_802423C8_B22908)[i];
        }
        heap_free(N(D_802423C8_B22908));
        N(D_802423C8_B22908) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240738_B20C78);
/*
ApiStatus N(func_80240738_B20C78)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_8024078C_B20CCC);
/*
ApiStatus N(func_8024078C_B20CCC)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_802407C4_B20D04);
/*
ApiStatus N(func_802407C4_B20D04)(ScriptInstance* script, s32 isInitialCall) {
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

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240ADC_B2101C);
/*
ApiStatus N(func_80240ADC_B2101C)(ScriptInstance *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240B20_B21060);
/*
ApiStatus N(func_80240B20_B21060)(ScriptInstance *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240B4C_B2108C);

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240CF8_B21238);

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240F14_B21454);

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80241134_B21674);
