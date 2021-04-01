#include "sbk_30.h"

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80240000_93F5B0);

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80240040_93F5F0);

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80240164_93F714);

#include "world/common/SpawnSunEffect.inc.c"

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80240370_93F920);

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80240424_93F9D4);

# include "world/common/NpcJumpFunc3.inc.c"

# include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13_2.inc.c"

# include "world/common/UnkNpcAIFunc11.inc.c"

# include "world/common/UnkNpcAIFunc10.inc.c"

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_802408B0_93FE60);

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_8024095C_93FF0C);

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80240B64_940114);

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80240DDC_94038C);
/*
s32 N(func_80240DDC_94038C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80241120_9406D0);
/*
s32 N(func_80241120_9406D0)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80241174_940724);
/*
s32 N(func_80241174_940724)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return 2;
}
*/

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_802411AC_94075C);

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80241248_9407F8);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_80241560_940B10);

INCLUDE_ASM(s32, "world/area_sbk/sbk_30/93F5B0", func_802415A4_940B54);

#include "world/common/SomeMatrixOperations.inc.c"