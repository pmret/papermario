#include "common.h"
#include "npc.h"

// remove this when all data from all maps that use this are migrated to C
extern s32** N(varTable);

ApiStatus N(StashVars)(Evt* script, s32 isInitialCall) {
    //static s32** varTable = NULL;
    s32 i;

    if (N(varTable) == NULL) {
        N(varTable) = heap_malloc(sizeof(script->varTable));

        for (i = 0; i < ARRAY_COUNT(script->varTable); i++) {
            N(varTable)[i] = (s32*) script->varTable[i];
        }
    } else {
        for (i = 0; i < ARRAY_COUNT(script->varTable); i++) {
            script->varTable[i] = (s32) N(varTable)[i];
        }

        heap_free(N(varTable));
        N(varTable) = NULL;
    }

    return ApiStatus_DONE2;
}
