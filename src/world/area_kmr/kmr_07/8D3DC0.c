#include "kmr_07.h"

static char* N(exit_str_0) = "kmr_06";
static char* N(exit_str_1) = "kmr_12";

#include "world/common/UnkNpcAIFunc43.inc.c"

#include "world/common/UnkNpcAIFunc44.inc.c"

#include "world/common/NpcJumpFunc3.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13_2.inc.c"

#include "world/common/UnkNpcAIFunc11.inc.c"

#include "world/common/UnkNpcAIFunc10.inc.c"

#include "world/common/UnkNpcAIFunc42.inc.c"

#include "world/common/UnkNpcAIFunc45.inc.c"

#include "world/common/UnkNpcAIMainFunc4.inc.c"

// see func_802402BC_8D878C
#ifdef NON_MATCHING
ApiStatus func_80240A6C_8D482C(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(evt_get_variable(NULL, EVT_MAP_VAR(0)));

    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->unk_14, 0x1E4);
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_kmr/kmr_07/8D3DC0", func_80240A6C_8D482C);
#endif
