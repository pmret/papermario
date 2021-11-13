#include "kmr_04.h"

#include "world/common/foliage.inc.c"

#define NAMESPACE dup_kmr_04
#include "world/common/CheckPartnerFlags1000.inc.c"
#define NAMESPACE kmr_04

#if 0 // NON_MATCHING
ApiStatus N(func_802402C8_8CABC8)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_802429F4_8CD2F4) == NULL) {
        N(D_802429F4_8CD2F4) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_802429F4_8CD2F4)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_802429F4_8CD2F4)[i];
        }
        heap_free(N(D_802429F4_8CD2F4));
        N(D_802429F4_8CD2F4) = NULL;
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_kmr/kmr_04/8CA960", func_802402C8_8CABC8);
#endif

#include "world/common/GetItemName.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_04/8CA960", func_802403E0_8CACE0);

ApiStatus N(func_80240434_8CAD34)(Evt* script, s32 isInitialCall) {
    gPlayerData.hammerLevel = 0;

    return ApiStatus_DONE2;
}

ApiStatus N(func_80240444_8CAD44)(Evt* script, s32 isInitialCall) {
    exec_entity_commandlist(get_entity_by_index(script->varTable[0]));

    return ApiStatus_DONE2;
}
