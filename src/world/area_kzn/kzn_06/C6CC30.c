#include "kzn_06.h"
#include "effects.h"

extern f32 D_80241120_C6DA40[27];

s32 func_80240310_C6CC30(Entity* block, Evt* source) {
    
    block->position.y = source->varTable[0] - (D_80241120_C6DA40[source->functionTemp[0]] * 25);
    if (source->functionTemp[0] == 0) {
        sfx_play_sound_at_position(0x1DA, 0, block->position.x, block->position.y, block->position.z);
    }
    
    if ((source->functionTemp[0] > 4) && (source->functionTemp[0] & 1)) {
        fx_smoke_burst(1, block->position.x, block->position.y, block->position.z, 1.0f, 20);
    }

    do {
        source->functionTemp[0]++;
    } while(0); // required to match

    return source->functionTemp[0] == 28;
}
