#include "kmr_04.h"

#include "world/common/SomeMatrixOperations.inc.c"

#define NAMESPACE dup_kmr_04
#include "world/common/CheckPartnerFlags1000.inc.c"
#define NAMESPACE kmr_04

INCLUDE_ASM(s32, "world/area_kmr/kmr_04/8CA960", func_802402C8_8CABC8);
/*
ApiStatus N(func_802402C8_8CABC8)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_kmr/kmr_04/8CA960", func_802403E0_8CACE0);

ApiStatus func_80240434_8CAD34(ScriptInstance* script, s32 isInitialCall) {
    gPlayerData.hammerLevel = 0;

    return ApiStatus_DONE2;
}

ApiStatus func_80240444_8CAD44(ScriptInstance* script, s32 isInitialCall) {
    exec_entity_updatecmd(get_entity_by_index(script->varTable[0]));

    return ApiStatus_DONE2;
}
