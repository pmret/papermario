#include "kzn_09.h"

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80241228_C77F08);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_802413DC_C780BC);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_8024163C_C7831C);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_802418F0_C785D0);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_8024195C_C7863C);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80241A58_C78738);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80242498_C79178);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80242528_C79208);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80242628_C79308);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80242688_C79368);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80242774_C79454);

#include "world/common/set_script_owner_npc_anim.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80242A40_C79720);

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80242D58_C79A38);

#include "world/common/AwaitPlayerNearNpc.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_802432AC_C79F8C);
/*
s32 N(func_802432AC_C79F8C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_802435F0_C7A2D0);
/*
s32 N(func_802435F0_C7A2D0)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80243644_C7A324);
/*
s32 N(func_80243644_C7A324)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return 2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_8024367C_C7A35C);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80243994_C7A674);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_802439D8_C7A6B8);