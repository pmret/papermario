#include "sam_09.h"

static char* N(exit_str_0) = "sam_08";
static char* N(exit_str_1) = "sam_10";

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

ApiStatus func_80240118_D36408(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);

    script->varTable[0] = get_item_entity(var1)->itemID;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_sam/sam_09/D362F0", func_80240158_D36448);

INCLUDE_ASM(s32, "world/area_sam/sam_09/D362F0", func_80240264_D36554);

ApiStatus func_802403A0_D36690(Evt* script, s32 isInitialCall) {
    s32* array;
    s32 len = 92;
    s32 i;

    script->varTable[0] = array = heap_malloc(92 * sizeof(*array));
    for (i = 0; i < 91; i++) {
        array[i] = 128 + i;
    }
    array[i] = 0;
    return ApiStatus_DONE2;
}
