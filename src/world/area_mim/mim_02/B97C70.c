#include "mim_02.h"

INCLUDE_ASM(s32, "world/area_mim/mim_02/B97C70", func_80240070_B97C70);

INCLUDE_ASM(s32, "world/area_mim/mim_02/B97C70", func_802402A0_B97EA0);

#include "world/common/UnkNpcAIFunc1.inc.c"

INCLUDE_ASM(s32, "world/area_mim/mim_02/B97C70", func_80240698_B98298);

#include "world/common/UnkNpcAIFunc15.inc.c"

INCLUDE_ASM(s32, "world/area_mim/mim_02/B97C70", func_8024091C_B9851C);

#include "world/common/UnkDurationCheck.inc.c"

INCLUDE_ASM(s32, "world/area_mim/mim_02/B97C70", func_80240C60_B98860);

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_mim/mim_02/B97C70", func_802410B0_B98CB0);
/*
s32 N(func_802410B0_B98CB0)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_mim/mim_02/B97C70", func_80241104_B98D04);
/*
s32 N(func_80241104_B98D04)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return 2;
}
*/

INCLUDE_ASM(s32, "world/area_mim/mim_02/B97C70", func_8024113C_B98D3C);