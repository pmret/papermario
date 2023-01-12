#include "common.h"
#include "sprite/npc/Luigi.h"

#define LUIGI_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .heartDrops  = NO_DROPS, \
    .flowerDrops = NO_DROPS, \
}

#define LUIGI_ANIMS \
{ \
    .idle   = ANIM_Luigi_Still, \
    .walk   = ANIM_Luigi_Still, \
    .run    = ANIM_Luigi_Still, \
    .chase  = ANIM_Luigi_Still, \
    .anim_4 = ANIM_Luigi_Still, \
    .anim_5 = ANIM_Luigi_Still, \
    .death  = ANIM_Luigi_Still, \
    .hit    = ANIM_Luigi_Still, \
    .anim_8 = ANIM_Luigi_Still, \
    .anim_9 = ANIM_Luigi_Still, \
    .anim_A = ANIM_Luigi_Still, \
    .anim_B = ANIM_Luigi_Still, \
    .anim_C = ANIM_Luigi_Still, \
    .anim_D = ANIM_Luigi_Still, \
    .anim_E = ANIM_Luigi_Still, \
    .anim_F = ANIM_Luigi_Still, \
}
