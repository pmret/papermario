#include "pra_12.h"

INCLUDE_ASM(s32, "world/area_pra/pra_12/D62D10", func_80240000_D62D10);

#include "world/common/reflection.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_12/D62D10", func_80240F50_D63C60);
/*
ApiStatus N(func_80240F50_D63C60)(ScriptInstance* script, s32 isInitialCall) {
    s32** ptr = &N(D_80241C68_BE09F8);
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
        ptr = &N(D_80241C68_BE09F8);
        heap_free(*ptr);
        *ptr = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
