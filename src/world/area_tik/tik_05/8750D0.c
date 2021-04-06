#include "tik_05.h"

INCLUDE_ASM(s32, "world/area_tik/tik_05/8750D0", func_80240310_8750D0);

INCLUDE_ASM(s32, "world/area_tik/tik_05/8750D0", func_80240680_875440);
/*
ApiStatus N(func_80240680_875440)(ScriptInstance* script, s32 isInitialCall) {
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
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

INCLUDE_ASM(s32, "world/area_tik/tik_05/8750D0", func_8024093C_8756FC);

#include "world/common/SetEntityPosition.inc.c"