#include "common.h"

INCLUDE_ASM(s32, "code_EDC020", func_80240040_EDC020);

INCLUDE_ASM(s32, "code_EDC020", func_802400B0_EDC090);

INCLUDE_ASM(s32, "code_EDC020", func_8024027C_EDC25C);
/*
ApiStatus N(func_8024027C_EDC25C)(ScriptInstance* script, s32 isInitialCall) {
    s32** ptr = &D_80241C68_BE09F8;
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
        ptr = &D_80241C68_BE09F8;
        heap_free(*ptr);
        *ptr = NULL;
    }
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "code_EDC020", func_80240330_EDC310);

INCLUDE_ASM(s32, "code_EDC020", func_80240394_EDC374);

INCLUDE_ASM(s32, "code_EDC020", func_802403F0_EDC3D0);

INCLUDE_ASM(s32, "code_EDC020", func_802405C0_EDC5A0);
/*
ApiStatus N(func_802405C0_EDC5A0)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "code_EDC020", func_80240614_EDC5F4);
/*
ApiStatus N(func_80240614_EDC5F4)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "code_EDC020", func_8024064C_EDC62C);