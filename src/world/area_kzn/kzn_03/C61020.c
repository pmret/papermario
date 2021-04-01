#include "kzn_03.h"

#include "world/common/set_script_owner_npc_anim.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_8024038C_C6109C);

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_802406A4_C613B4);

#include "world/common/AwaitPlayerNearNpc.inc.c"

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80240E00_C61B10);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80240FB4_C61CC4);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80241214_C61F24);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_802414C8_C621D8);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80241534_C62244);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80241630_C62340);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242070_C62D80);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242100_C62E10);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242200_C62F10);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242260_C62F70);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_8024234C_C6305C);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_8024259C_C632AC);
/*
s32 N(func_8024259C_C632AC)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_802428E0_C635F0);
/*
s32 N(func_802428E0_C635F0)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242934_C63644);
/*
s32 N(func_80242934_C63644)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return 2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_8024296C_C6367C);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242C84_C63994);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242CC8_C639D8);