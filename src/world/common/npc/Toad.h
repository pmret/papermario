#include "common.h"
#include "sprite/npc/Toad.h"

#define TOAD_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .heartDrops  = NO_DROPS, \
    .flowerDrops = NO_DROPS, \
}

#define TOAD_ANIMS(pal) \
{ \
    .idle   = ANIM_Toad_##pal##_Idle, \
    .walk   = ANIM_Toad_##pal##_Walk, \
    .run    = ANIM_Toad_##pal##_Run, \
    .chase  = ANIM_Toad_##pal##_Run, \
    .anim_4 = ANIM_Toad_##pal##_Idle, \
    .anim_5 = ANIM_Toad_##pal##_Idle, \
    .death  = ANIM_Toad_##pal##_Disappointed, \
    .hit    = ANIM_Toad_##pal##_Disappointed, \
    .anim_8 = ANIM_Toad_##pal##_Run, \
    .anim_9 = ANIM_Toad_##pal##_Run, \
    .anim_A = ANIM_Toad_##pal##_Run, \
    .anim_B = ANIM_Toad_##pal##_Run, \
    .anim_C = ANIM_Toad_##pal##_Run, \
    .anim_D = ANIM_Toad_##pal##_Run, \
    .anim_E = ANIM_Toad_##pal##_Run, \
    .anim_F = ANIM_Toad_##pal##_Run, \
}

#define TOAD_RED_ANIMS      TOAD_ANIMS(Red)
#define TOAD_GREEN_ANIMS    TOAD_ANIMS(Green)
#define TOAD_BLUE_ANIMS     TOAD_ANIMS(Blue)
#define TOAD_YELLOW_ANIMS   TOAD_ANIMS(Yellow)
#define TOAD_PINK_ANIMS     TOAD_ANIMS(Pink)
