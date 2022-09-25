#include "kzn_06.h"

extern f32 D_80241120_C6DA40[27];

// push block gravity
#ifdef NON_NATCHING
extern f32 D_80241120_C6DA40[27];

s32 func_80240310_C6CC30(Entity* block, Evt* source) {
    block->position.y = source->varTable[0] - (D_80241120_C6DA40[source->functionTemp[0]] * 25.0f);
    if (source->functionTemp[0] == 0) {
        sfx_play_sound_at_position(SOUND_1DA, 0, block->position.x, block->position.y, block->position.z);
    }
    if (source->functionTemp[0] >= 5) {
        if (source->functionTemp[0] & 1) {
            fx_smoke_burst(1, block->position.x, block->position.y, block->position.z, 1.0f, 20);
        }
    }
    source->functionTemp[0]++;
    if (source->functionTemp[0] == 0x1C)
        return 1;
    else
        return 0;
}
#else
INCLUDE_ASM(s32, "world/area_kzn/kzn_06/C6CC30", func_80240310_C6CC30);
#endif
