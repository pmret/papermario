#include "common.h"
#include "sprite/npc/LavaPiranha.h"
#include "sprite/npc/LavaBud.h"

#define LAVA_PIRANHA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_SUPER_SHROOM, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 3, \
}

#define LAVA_PIRANHA_HEAD_ANIMS \
{ \
    .idle   = ANIM_LavaPiranha_Idle, \
    .walk   = ANIM_LavaPiranha_Idle, \
    .run    = ANIM_LavaPiranha_Idle, \
    .chase  = ANIM_LavaPiranha_Idle, \
    .anim_4 = ANIM_LavaPiranha_Idle, \
    .anim_5 = ANIM_LavaPiranha_Idle, \
    .death  = ANIM_LavaPiranha_Idle, \
    .hit    = ANIM_LavaPiranha_Idle, \
    .anim_8 = ANIM_LavaPiranha_Idle, \
    .anim_9 = ANIM_LavaPiranha_Idle, \
    .anim_A = ANIM_LavaPiranha_Idle, \
    .anim_B = ANIM_LavaPiranha_Idle, \
    .anim_C = ANIM_LavaPiranha_Idle, \
    .anim_D = ANIM_LavaPiranha_Idle, \
    .anim_E = ANIM_LavaPiranha_Idle, \
    .anim_F = ANIM_LavaPiranha_Idle, \
}

#define LAVA_PIRANHA_BUD_ANIMS \
{ \
    .idle   = ANIM_LavaBud_Idle, \
    .walk   = ANIM_LavaBud_Idle, \
    .run    = ANIM_LavaBud_Idle, \
    .chase  = ANIM_LavaBud_Idle, \
    .anim_4 = ANIM_LavaBud_Idle, \
    .anim_5 = ANIM_LavaBud_Idle, \
    .death  = ANIM_LavaBud_Idle, \
    .hit    = ANIM_LavaBud_Idle, \
    .anim_8 = ANIM_LavaBud_Idle, \
    .anim_9 = ANIM_LavaBud_Idle, \
    .anim_A = ANIM_LavaBud_Idle, \
    .anim_B = ANIM_LavaBud_Idle, \
    .anim_C = ANIM_LavaBud_Idle, \
    .anim_D = ANIM_LavaBud_Idle, \
    .anim_E = ANIM_LavaBud_Idle, \
    .anim_F = ANIM_LavaBud_Idle, \
}
