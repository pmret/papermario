#include "nok_02.h"

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_802438D0_9DA8F0);

#define NAMESPACE dup2_nok_02
#include "world/common/GetNpcCollisionHeight.inc.c"
#define NAMESPACE nok_02

#define NAMESPACE dup2_nok_02
#include "world/common/AddPlayerHandsOffset.inc.c"
#define NAMESPACE nok_02

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80243BEC_9DAC0C);
/*
ApiStatus N(func_80243BEC_9DAC0C)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80243C40_9DAC60);
/*
ApiStatus N(func_80243C40_9DAC60)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80243C78_9DAC98);
/*
ApiStatus N(func_80243C78_9DAC98)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80243D14_9DAD34);
/*
ApiStatus N(func_80243D14_9DAD34)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80243DB0_9DADD0);
/*
ApiStatus N(func_80243DB0_9DADD0)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80252720_9E9740) == NULL) {
        N(D_80252720_9E9740) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80252720_9E9740)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80252720_9E9740)[i];
        }
        heap_free(N(D_80252720_9E9740));
        N(D_80252720_9E9740) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#define NAMESPACE dup2_nok_02
#include "world/common/GetItemName.inc.c"
#define NAMESPACE nok_02

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80243EC8_9DAEE8);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80243F10_9DAF30);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80244078_9DB098);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80244224_9DB244);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80244288_9DB2A8);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_802442E0_9DB300);
