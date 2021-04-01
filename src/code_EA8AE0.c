#include "common.h"

#define NAMESPACE code_EA8AE0

#include "world/common/DeadUnkTexturePanFunc.inc.c"

#include "world/common/DeadUnkTexturePanFunc2.inc.c"

INCLUDE_ASM(s32, "code_EA8AE0", func_8024030C_EA8DEC);

INCLUDE_ASM(s32, "code_EA8AE0", func_80240358_EA8E38);

INCLUDE_ASM(s32, "code_EA8AE0", func_802404B8_EA8F98);

INCLUDE_ASM(s32, "code_EA8AE0", func_802408C8_EA93A8);

INCLUDE_ASM(s32, "code_EA8AE0", func_80240908_EA93E8);

INCLUDE_ASM(s32, "code_EA8AE0", func_80240A14_EA94F4);

INCLUDE_ASM(s32, "code_EA8AE0", func_80240B00_EA95E0);

INCLUDE_ASM(s32, "code_EA8AE0", func_80240BD4_EA96B4);

INCLUDE_ASM(s32, "code_EA8AE0", func_80240CD8_EA97B8);

INCLUDE_ASM(s32, "code_EA8AE0", func_80240DA4_EA9884);

INCLUDE_ASM(s32, "code_EA8AE0", func_80240E2C_EA990C);

INCLUDE_ASM(s32, "code_EA8AE0", func_802413C0_EA9EA0);

INCLUDE_ASM(s32, "code_EA8AE0", func_802413FC_EA9EDC);

INCLUDE_ASM(s32, "code_EA8AE0", func_8024140C_EA9EEC);

INCLUDE_ASM(s32, "code_EA8AE0", func_80241468_EA9F48);
/*
s32 N(func_80241468_EA9F48)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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
    return 2;
}
*/

INCLUDE_ASM(s32, "code_EA8AE0", func_8024151C_EA9FFC);

INCLUDE_ASM(s32, "code_EA8AE0", func_80241580_EAA060);

INCLUDE_ASM(s32, "code_EA8AE0", func_802415DC_EAA0BC);

INCLUDE_ASM(s32, "code_EA8AE0", func_802417AC_EAA28C);
/*
s32 N(func_802417AC_EAA28C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr;

    if (aiSettings != NULL) {
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

INCLUDE_ASM(s32, "code_EA8AE0", func_80241800_EAA2E0);
/*
s32 N(func_80241800_EAA2E0)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return 2;
}
*/

INCLUDE_ASM(s32, "code_EA8AE0", func_80241838_EAA318);

INCLUDE_ASM(s32, "code_EA8AE0", func_802418D4_EAA3B4);

INCLUDE_ASM(s32, "code_EA8AE0", func_802419C4_EAA4A4);

INCLUDE_ASM(s32, "code_EA8AE0", func_80241B50_EAA630);

INCLUDE_ASM(s32, "code_EA8AE0", func_80241B94_EAA674);

INCLUDE_ASM(s32, "code_EA8AE0", func_80241BC0_EAA6A0);