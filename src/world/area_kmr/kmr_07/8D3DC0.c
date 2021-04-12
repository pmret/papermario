#include "kmr_07.h"

INCLUDE_ASM(s32, "world/area_kmr/kmr_07/8D3DC0", func_80240000_8D3DC0);

INCLUDE_ASM(s32, "world/area_kmr/kmr_07/8D3DC0", func_802400B4_8D3E74);

#include "world/common/NpcJumpFunc3.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13_2.inc.c"

#include "world/common/UnkNpcAIFunc11.inc.c"

#include "world/common/UnkNpcAIFunc10.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_07/8D3DC0", func_80240540_8D4300);

INCLUDE_ASM(s32, "world/area_kmr/kmr_07/8D3DC0", func_802405EC_8D43AC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_07/8D3DC0", func_802407F4_8D45B4);

// see func_802402BC_8D878C
#ifdef NON_MATCHING
ApiStatus func_80240A6C_8D482C(ScriptInstance* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(get_variable(NULL, SI_MAP_VAR(0)));

    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->unk_14, 0x1E4);
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_kmr/kmr_07/8D3DC0", func_80240A6C_8D482C);
/*
ApiStatus N(func_80240A6C_8D482C)(void) {
    Entity* entity = get_entity_by_index(get_variable(NULL, 0xFD050F80));

    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->virtualModelIndex, &D_000001E4);

    return ApiStatus_DONE2;
}
*/
#endif
