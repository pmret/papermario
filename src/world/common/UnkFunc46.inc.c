#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc46)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (UNK_FUNC46_VAR == NULL) {
        UNK_FUNC46_VAR = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < ARRAY_COUNT(script->varTable); i++) {
            UNK_FUNC46_VAR[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < ARRAY_COUNT(script->varTable); i++) {
            script->varTable[i] = UNK_FUNC46_VAR[i];
        }
        heap_free(UNK_FUNC46_VAR);
        UNK_FUNC46_VAR = NULL;
    }
    return ApiStatus_DONE2;
}
