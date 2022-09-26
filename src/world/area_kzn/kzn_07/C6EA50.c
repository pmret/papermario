#include "kzn_07.h"
#include "effects.h"
#include "entity.h"

extern f32 N(PushBlockFallCurve)[28];

s32 func_80240720_C6EA50(Entity* block, Evt* source) {
    
    block->position.y = source->varTable[0] - (N(PushBlockFallCurve)[source->functionTemp[0]] * BLOCK_GRID_SIZE);
    if (source->functionTemp[0] == 0) {
        sfx_play_sound_at_position(SOUND_1DA, 0, block->position.x, block->position.y, block->position.z);
    }
    
    if ((source->functionTemp[0] > 4) && (source->functionTemp[0] & 1)) {
        fx_smoke_burst(1, block->position.x, block->position.y, block->position.z, 1.0f, 20);
    }

    do {
        source->functionTemp[0]++;
    } while(0); // required to match

    return source->functionTemp[0] == ARRAY_COUNT(N(PushBlockFallCurve));
}

ApiStatus func_802407F4_C6EB24(Evt* script, s32 isInitialCall) {
    get_entity_by_index(script->varTable[0])->dataBuf.chest->gotItemDone = TRUE;
    return ApiStatus_DONE2;
}

#include "world/common/enemy/FlyingAI.inc.c"

#include "world/common/enemy/FlyingNoAttackAI.inc.c"
