#include "common.h"

INCLUDE_ASM(s32, "code_ECAA80", func_80240D80_ECAA80);

INCLUDE_ASM(s32, "code_ECAA80", func_80241364_ECB064);

INCLUDE_ASM(s32, "code_ECAA80", func_802414C8_ECB1C8);

INCLUDE_ASM(s32, "code_ECAA80", func_8024150C_ECB20C);

INCLUDE_ASM(s32, "code_ECAA80", func_80241770_ECB470);

INCLUDE_ASM(s32, "code_ECAA80", func_802417CC_ECB4CC);

INCLUDE_ASM(s32, "code_ECAA80", func_8024199C_ECB69C);
/*
ApiStatus N(func_8024199C_ECB69C)(ScriptInstance* script, s32 isInitialCall) {
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
        return 2;
    }

    return 0;
}
*/

INCLUDE_ASM(s32, "code_ECAA80", func_802419F0_ECB6F0);
/*
ApiStatus N(func_802419F0_ECB6F0)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return 2;
}
*/

INCLUDE_ASM(s32, "code_ECAA80", func_80241A28_ECB728);

INCLUDE_ASM(s32, "code_ECAA80", func_80241AC4_ECB7C4);

INCLUDE_ASM(s32, "code_ECAA80", func_80241B88_ECB888);

INCLUDE_ASM(s32, "code_ECAA80", func_80241BF8_ECB8F8);
