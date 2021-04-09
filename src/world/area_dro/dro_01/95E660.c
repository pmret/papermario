#include "dro_01.h"

ApiStatus N(func_80243460_95E660)(ScriptInstance* script, s32 isInitialCall) {
    s32** ptr = &N(D_8024B5B0_9667B0);
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
        ptr = &N(D_8024B5B0_9667B0);
        heap_free(*ptr);
        *ptr = NULL;
    }
    return ApiStatus_DONE2;
}

#define NAMESPACE dro_01_dup
#include "world/common/GetItemName.inc.c"
#define NAMESPACE dro_01

ApiStatus N(func_80243578_95E778)(ScriptInstance* script, s32 isInitialCall) {
    func_800E96C8();
    return ApiStatus_DONE2;
}
