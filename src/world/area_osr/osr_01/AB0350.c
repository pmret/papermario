#include "osr_01.h"

INCLUDE_ASM(s32, "world/area_osr/osr_01/AB0350", func_80240360_AB0350);
/*
s32 N(func_80240360_AB0350)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_osr/osr_01/AB0350", func_802406A4_AB0694);
/*
s32 N(func_802406A4_AB0694)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_osr/osr_01/AB0350", func_802406F8_AB06E8);
/*
s32 N(func_802406F8_AB06E8)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return 2;
}
*/

INCLUDE_ASM(s32, "world/area_osr/osr_01/AB0350", func_80240730_AB0720);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_osr/osr_01/AB0350", func_80240A48_AB0A38);

INCLUDE_ASM(s32, "world/area_osr/osr_01/AB0350", func_80240A8C_AB0A7C);