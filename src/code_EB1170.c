#include "common.h"

INCLUDE_ASM(s32, "code_EB1170", func_80240310_EB1170);
/*
s32 N(func_80240310_EB1170)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "code_EB1170", func_802403C4_EB1224);

INCLUDE_ASM(s32, "code_EB1170", func_80240428_EB1288);

INCLUDE_ASM(s32, "code_EB1170", func_80240484_EB12E4);

INCLUDE_ASM(s32, "code_EB1170", func_80240654_EB14B4);
/*
s32 N(func_80240654_EB14B4)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "code_EB1170", func_802406A8_EB1508);
/*
s32 N(func_802406A8_EB1508)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return 2;
}
*/

INCLUDE_ASM(s32, "code_EB1170", func_802406E0_EB1540);

INCLUDE_ASM(s32, "code_EB1170", func_8024077C_EB15DC);

INCLUDE_ASM(s32, "code_EB1170", func_8024086C_EB16CC);

INCLUDE_ASM(s32, "code_EB1170", func_802409F8_EB1858);

INCLUDE_ASM(s32, "code_EB1170", func_80240A3C_EB189C);

INCLUDE_ASM(s32, "code_EB1170", func_80240A68_EB18C8);

INCLUDE_ASM(s32, "code_EB1170", func_80240A8C_EB18EC);