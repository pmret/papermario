#include "common.h"
#include "npc.h"

// remove this and uncomment other when all data from all maps that use this are migrated to C
extern s32** N(varStash);

API_CALLABLE(N(StashVars)) {
    //static s32** varTable = nullptr;
    s32 i;

    if (N(varStash) == nullptr) {
        N(varStash) = heap_malloc(sizeof(script->varTable));

        for (i = 0; i < ARRAY_COUNT(script->varTable); i++) {
            N(varStash)[i] = (s32*) script->varTable[i];
        }
    } else {
        for (i = 0; i < ARRAY_COUNT(script->varTable); i++) {
            script->varTable[i] = (s32) N(varStash)[i];
        }

        heap_free(N(varStash));
        N(varStash) = nullptr;
    }

    return ApiStatus_DONE2;
}
