#include "common.h"

typedef s32 SparkleScript[];

enum {
    SPARKLE_OP_End      = 0,
    SPARKLE_OP_SetGfx   = 1,
    SPARKLE_OP_Restart  = 2,
    SPARKLE_OP_Jump     = 3,
    SPARKLE_OP_Break    = 4,
    SPARKLE_OP_SetCI    = 7
};

#define sp_End SPARKLE_OP_End,
#define sp_SetGfx(time, gfx) SPARKLE_OP_SetGfx, time, (s32)gfx,
#define sp_Restart SPARKLE_OP_Restart,
#define sp_Jump(dest) SPARKLE_OP_Jump, (s32)dest,
/// Purpose unknown; arg is not read
#define sp_Break(unk) SPARKLE_OP_Break, unk,
#define sp_SetCI(time, name, width, height) SPARKLE_OP_SetCI, time, (s32)name##_png, (s32)name##_pal, width, height,
