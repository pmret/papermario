#include "kzn_17.h"

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80240518_C85FC8);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_802406CC_C8617C);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_8024092C_C863DC);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80240BE0_C86690);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80240C4C_C866FC);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80240D48_C867F8);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80241788_C87238);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80241818_C872C8);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80241918_C873C8);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80241978_C87428);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80241A64_C87514);

#include "world/common/set_script_owner_npc_anim.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80241D30_C877E0);

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80242048_C87AF8);

#include "world/common/AwaitPlayerNearNpc.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_8024259C_C8804C);
/*
ApiStatus N(func_8024259C_C8804C)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_802428E0_C88390);
/*
ApiStatus N(func_802428E0_C88390)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr;

    if (isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80242934_C883E4);
/*
ApiStatus N(func_80242934_C883E4)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return 2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_8024296C_C8841C);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80242C84_C88734);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80242CC8_C88778);
