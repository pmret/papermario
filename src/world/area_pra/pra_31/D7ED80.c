#include "pra_31.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7ED80", func_8024024C_D7EFAC);
/*
s32 N(func_8024024C_D7EFAC)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7ED80", func_802402A0_D7F000);
/*
s32 N(func_802402A0_D7F000)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return 2;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7ED80", func_802402D8_D7F038);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7ED80", func_80240374_D7F0D4);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7ED80", func_80240410_D7F170);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7ED80", func_80240468_D7F1C8);