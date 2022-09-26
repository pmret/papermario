#include "kzn_06.h"
#include "effects.h"
#include "entity.h"

extern f32 N(PushBlockFallCurve)[28];

s32 N(push_block_handle_fall)(Entity* block, Evt* source) {
    
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
