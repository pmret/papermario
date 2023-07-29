#include "common.h"
#include "entity.h"

f32 N(PushBlockFallCurve)[] = {
    0.02, 0.02, 0.04, 0.08, 0.11, 0.2, 0.3, 0.31,
    0.42, 0.46, 0.5, 0.53, 0.56, 0.59, 0.62, 0.65,
    0.68, 0.71, 0.74, 0.77, 0.8, 0.83, 0.86, 0.89,
    0.92, 0.95, 0.98, 1.0,
};

s32 N(push_block_handle_fall)(Entity* block, Evt* source) {

    block->pos.y = source->varTable[0] - (N(PushBlockFallCurve)[source->functionTemp[0]] * BLOCK_GRID_SIZE);
    if (source->functionTemp[0] == 0) {
        sfx_play_sound_at_position(SOUND_1DA, SOUND_SPACE_MODE_0, block->pos.x, block->pos.y, block->pos.z);
    }

    if ((source->functionTemp[0] > 4) && (source->functionTemp[0] & 1)) {
        fx_smoke_burst(1, block->pos.x, block->pos.y, block->pos.z, 1.0f, 20);
    }

    do {
        source->functionTemp[0]++;
    } while (0); // required to match

    return source->functionTemp[0] == ARRAY_COUNT(N(PushBlockFallCurve));
}
