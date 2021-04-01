#include "kzn_19.h"

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_8024030C_C8DEBC);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240358_C8DF08);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_802404B8_C8E068);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_802408C8_C8E478);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240908_C8E4B8);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240A14_C8E5C4);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240B00_C8E6B0);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240BD4_C8E784);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240CD8_C8E888);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240DA4_C8E954);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240E2C_C8E9DC);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_802413C0_C8EF70);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_802413FC_C8EFAC);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_8024140C_C8EFBC);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80241468_C8F018);
/*
s32 N(func_80241468_C8F018)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_802417AC_C8F35C);
/*
s32 N(func_802417AC_C8F35C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80241800_C8F3B0);
/*
s32 N(func_80241800_C8F3B0)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return 2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80241838_C8F3E8);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80241B50_C8F700);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80241B94_C8F744);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80241BC0_C8F770);