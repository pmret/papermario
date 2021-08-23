#include "mim_04.h"

INCLUDE_ASM(s32, "world/area_mim/mim_04/B9DB60", func_80240200_B9DB60);

INCLUDE_ASM(s32, "world/area_mim/mim_04/B9DB60", func_80240430_B9DD90);

#include "world/common/UnkNpcAIFunc1.inc.c"

INCLUDE_ASM(s32, "world/area_mim/mim_04/B9DB60", func_80240828_B9E188);

#include "world/common/UnkNpcAIFunc15.inc.c"

INCLUDE_ASM(s32, "world/area_mim/mim_04/B9DB60", func_80240AAC_B9E40C);

#include "world/common/UnkDurationCheck.inc.c"

INCLUDE_ASM(s32, "world/area_mim/mim_04/B9DB60", func_80240DF0_B9E750);

INCLUDE_ASM(s32, "world/area_mim/mim_04/B9DB60", func_80241014_B9E974);
/*
ApiStatus N(func_80241014_B9E974)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80242614_B9FF74) == NULL) {
        N(D_80242614_B9FF74) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80242614_B9FF74)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80242614_B9FF74)[i];
        }
        heap_free(N(D_80242614_B9FF74));
        N(D_80242614_B9FF74) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"
