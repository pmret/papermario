#include "common.h"
#include "map.h"

ApiStatus N(StashVars)(Evt* script, s32 isInitialCall) {
    static s32** varTable = NULL;
    s32 i;

    if (varTable == NULL) {
        varTable = heap_malloc(sizeof(script->varTable));

        for (i = 0; i < ARRAY_COUNT(script->varTable); i++) {
            varTable[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < ARRAY_COUNT(script->varTable); i++) {
            script->varTable[i] = varTable[i];
        }

        heap_free(varTable);
        varTable = NULL;
    }

    return ApiStatus_DONE2;
}
