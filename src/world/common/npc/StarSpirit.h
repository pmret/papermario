#include "common.h"
#include "sprite/npc/WorldMisstar.h"

#define MISSTAR_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .heartDrops  = NO_DROPS, \
    .flowerDrops = NO_DROPS, \
}

#define MISSTAR_ANIMS \
{ \
    .idle   = ANIM_WorldMisstar_Idle, \
    .walk   = ANIM_WorldMisstar_Idle, \
    .run    = ANIM_WorldMisstar_Idle, \
    .chase  = ANIM_WorldMisstar_Idle, \
    .anim_4 = ANIM_WorldMisstar_Idle, \
    .anim_5 = ANIM_WorldMisstar_Idle, \
    .death  = ANIM_WorldMisstar_Idle, \
    .hit    = ANIM_WorldMisstar_Idle, \
    .anim_8 = ANIM_WorldMisstar_Still, \
    .anim_9 = ANIM_WorldMisstar_Idle, \
    .anim_A = ANIM_WorldMisstar_Idle, \
    .anim_B = ANIM_WorldMisstar_Idle, \
    .anim_C = ANIM_WorldMisstar_Idle, \
    .anim_D = ANIM_WorldMisstar_Idle, \
    .anim_E = ANIM_WorldMisstar_Idle, \
    .anim_F = ANIM_WorldMisstar_Idle, \
}
