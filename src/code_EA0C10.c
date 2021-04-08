#include "common.h"

const char* ascii_EA6D70 = "kzn_11";
const char* ascii_EA6D78 = "kzn_18";

INCLUDE_ASM(s32, "code_EA0C10", func_80240310_EA0C10);

INCLUDE_ASM(s32, "code_EA0C10", func_8024037C_EA0C7C);

INCLUDE_ASM(s32, "code_EA0C10", func_802403EC_EA0CEC);

INCLUDE_ASM(s32, "code_EA0C10", func_802404C4_EA0DC4);

INCLUDE_ASM(s32, "code_EA0C10", func_80240518_EA0E18);

INCLUDE_ASM(s32, "code_EA0C10", func_802406CC_EA0FCC);

INCLUDE_ASM(s32, "code_EA0C10", func_8024097C_EA127C);

INCLUDE_ASM(s32, "code_EA0C10", func_80240C5C_EA155C);

INCLUDE_ASM(s32, "code_EA0C10", func_80240CC8_EA15C8);

INCLUDE_ASM(s32, "code_EA0C10", func_80240DC4_EA16C4);

INCLUDE_ASM(s32, "code_EA0C10", func_80241804_EA2104);

INCLUDE_ASM(s32, "code_EA0C10", func_80241894_EA2194);

INCLUDE_ASM(s32, "code_EA0C10", func_80241994_EA2294);

INCLUDE_ASM(s32, "code_EA0C10", func_802419F4_EA22F4);

INCLUDE_ASM(s32, "code_EA0C10", func_80241AE0_EA23E0);

INCLUDE_ASM(s32, "code_EA0C10", func_80241D68_EA2668);

INCLUDE_ASM(s32, "code_EA0C10", func_80241DE4_EA26E4);

INCLUDE_ASM(s32, "code_EA0C10", func_80241F18_EA2818);

INCLUDE_ASM(s32, "code_EA0C10", func_8024207C_EA297C);

INCLUDE_ASM(s32, "code_EA0C10", func_802420FC_EA29FC);

INCLUDE_ASM(s32, "code_EA0C10", func_80242568_EA2E68);

INCLUDE_ASM(s32, "code_EA0C10", func_802425B0_EA2EB0);

INCLUDE_ASM(s32, "code_EA0C10", func_80242608_EA2F08);

INCLUDE_ASM(s32, "code_EA0C10", func_8024267C_EA2F7C);
/*
ApiStatus N(func_8024267C_EA2F7C)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "code_EA0C10", func_80242730_EA3030);

INCLUDE_ASM(s32, "code_EA0C10", func_80242794_EA3094);

INCLUDE_ASM(s32, "code_EA0C10", func_802427F0_EA30F0);

INCLUDE_ASM(s32, "code_EA0C10", func_802429C0_EA32C0);
/*
ApiStatus N(func_802429C0_EA32C0)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "code_EA0C10", func_80242A14_EA3314);
/*
ApiStatus N(func_80242A14_EA3314)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "code_EA0C10", func_80242A4C_EA334C);

INCLUDE_ASM(s32, "code_EA0C10", func_80242AE8_EA33E8);

INCLUDE_ASM(s32, "code_EA0C10", func_80242BD8_EA34D8);

INCLUDE_ASM(s32, "code_EA0C10", func_80242D64_EA3664);

INCLUDE_ASM(s32, "code_EA0C10", func_80242DA8_EA36A8);
