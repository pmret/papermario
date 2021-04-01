#include "kkj_18.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_kkj/kkj_18/AF2FE0", func_8024056C_AF320C);
/*
s32 N(func_8024056C_AF320C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_kkj/kkj_18/AF2FE0", func_802405C0_AF3260);
/*
s32 N(func_802405C0_AF3260)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return 2;
}
*/

INCLUDE_ASM(s32, "world/area_kkj/kkj_18/AF2FE0", func_802405F8_AF3298);

INCLUDE_ASM(s32, "world/area_kkj/kkj_18/AF2FE0", func_80240694_AF3334);

INCLUDE_ASM(s32, "world/area_kkj/kkj_18/AF2FE0", func_80240730_AF33D0);

INCLUDE_ASM(s32, "world/area_kkj/kkj_18/AF2FE0", func_80240774_AF3414);