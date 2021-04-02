#include "hos_06.h"

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3B4B0", func_80241FD0_A3B4B0);
/*
ApiStatus N(func_80241FD0_A3B4B0)(ScriptInstance* script, s32 isInitialCall) {
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

#define NAMESPACE dup_hos_06
#include "world/common/GetItemName.inc.c"
#define NAMESPACE hos_06

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3B4B0", func_8024228C_A3B76C);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3B4B0", func_802424CC_A3B9AC);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3B4B0", func_80242534_A3BA14);
