#include "kmr_10.h"

static char* N(exit_str_0) = "kmr_11";
static char* N(exit_str_1) = "mac_00";

INCLUDE_ASM(s32, "world/area_kmr/kmr_10/8D84D0", func_80240000_8D84D0);
/*
ApiStatus N(func_80240000_8D84D0)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80240C20_8D90F0) == NULL) {
        N(D_80240C20_8D90F0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80240C20_8D90F0)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80240C20_8D90F0)[i];
        }
        heap_free(N(D_80240C20_8D90F0));
        N(D_80240C20_8D90F0) = NULL;
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
ApiStatus func_802402BC_8D878C(Evt* script, s32 isInitialCall) {
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
