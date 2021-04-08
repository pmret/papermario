#include "sam_04.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_04/D138E0", func_8024053C_D13B0C);
/*
ApiStatus N(func_8024053C_D13B0C)(ScriptInstance* script, s32 isInitialCall) {
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
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_sam/sam_04/D138E0", func_80240590_D13B60);
/*
ApiStatus N(func_80240590_D13B60)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_sam/sam_04/D138E0", func_802405C8_D13B98);

INCLUDE_ASM(s32, "world/area_sam/sam_04/D138E0", func_80240664_D13C34);
