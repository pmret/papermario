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
    .idle   = ANIM_LavaPiranha_Anim03, \
    .walk   = ANIM_LavaPiranha_Anim03, \
    .run    = ANIM_LavaPiranha_Anim03, \
    .chase  = ANIM_LavaPiranha_Anim03, \
    .anim_4 = ANIM_LavaPiranha_Anim03, \
    .anim_5 = ANIM_LavaPiranha_Anim03, \
    .death  = ANIM_LavaPiranha_Anim03, \
    .hit    = ANIM_LavaPiranha_Anim03, \
    .anim_8 = ANIM_LavaPiranha_Anim03, \
    .anim_9 = ANIM_LavaPiranha_Anim03, \
    .anim_A = ANIM_LavaPiranha_Anim03, \
    .anim_B = ANIM_LavaPiranha_Anim03, \
    .anim_C = ANIM_LavaPiranha_Anim03, \
    .anim_D = ANIM_LavaPiranha_Anim03, \
    .anim_E = ANIM_LavaPiranha_Anim03, \
    .anim_F = ANIM_LavaPiranha_Anim03, \
}

#define LAVA_PIRANHA_BUD_ANIMS \
{ \
    .idle   = ANIM_LavaBud_Anim03, \
    .walk   = ANIM_LavaBud_Anim03, \
    .run    = ANIM_LavaBud_Anim03, \
    .chase  = ANIM_LavaBud_Anim03, \
    .anim_4 = ANIM_LavaBud_Anim03, \
    .anim_5 = ANIM_LavaBud_Anim03, \
    .death  = ANIM_LavaBud_Anim03, \
    .hit    = ANIM_LavaBud_Anim03, \
    .anim_8 = ANIM_LavaBud_Anim03, \
    .anim_9 = ANIM_LavaBud_Anim03, \
    .anim_A = ANIM_LavaBud_Anim03, \
    .anim_B = ANIM_LavaBud_Anim03, \
    .anim_C = ANIM_LavaBud_Anim03, \
    .anim_D = ANIM_LavaBud_Anim03, \
    .anim_E = ANIM_LavaBud_Anim03, \
    .anim_F = ANIM_LavaBud_Anim03, \
}
