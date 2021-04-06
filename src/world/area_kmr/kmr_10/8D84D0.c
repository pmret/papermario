#include "kmr_10.h"

INCLUDE_ASM(s32, "world/area_kmr/kmr_10/8D84D0", func_80240000_8D84D0);
/*
ApiStatus N(func_80240000_8D84D0)(ScriptInstance* script, s32 isInitialCall) {
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
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

#ifdef NON_MATCHING
// 0x1E4 is probably a linker constant. We need to learn more about animations,
// play_model_animation, and entity->unk_14 before we can tackle this
ApiStatus func_802402BC_8D878C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Entity* entity = get_entity_by_index(get_variable(script, *args++));

    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->unk_14, 0x1E4);
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_kmr/kmr_10/8D84D0", func_802402BC_8D878C);
#endif

#include "world/common/SetEntityPosition.inc.c"