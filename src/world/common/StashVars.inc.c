#include "common.h"
#include "npc.h"

// remove this and uncomment other when all data from all maps that use this are migrated to C
extern s32** N(VarStash);

ApiStatus N(StashVars)(Evt* script, s32 isInitialCall) {
    //static s32** varTable = NULL;
    s32 i;

    if (N(VarStash) == NULL) {
        N(VarStash) = heap_malloc(sizeof(script->varTable));

        for (i = 0; i < ARRAY_COUNT(script->varTable); i++) {
            N(VarStash)[i] = (s32*) script->varTable[i];
        }
    } else {
        for (i = 0; i < ARRAY_COUNT(script->varTable); i++) {
            script->varTable[i] = (s32) N(VarStash)[i];
        }

        heap_free(N(VarStash));
        N(VarStash) = NULL;
    }

    return ApiStatus_DONE2;
}
