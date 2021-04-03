#include "kmr_20.h"

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8ED440", func_80241620_8ED440);
/*
ApiStatus N(func_80241620_8ED440)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8ED440", func_80241738_8ED558);
