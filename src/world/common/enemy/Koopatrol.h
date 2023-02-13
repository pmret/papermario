#include "common.h"
#include "sprite/npc/WorldKoopatrol.h"

#define KOOPATROL_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_SUPER_SHROOM, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(5), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 3, \
}

#define KOOPATROL_ANIMS \
{ \
    .idle   = ANIM_WorldKoopatrol_Anim01, \
    .walk   = ANIM_WorldKoopatrol_Anim04, \
    .run    = ANIM_WorldKoopatrol_Anim06, \
    .chase  = ANIM_WorldKoopatrol_Anim06, \
    .anim_4 = ANIM_WorldKoopatrol_Anim01, \
    .anim_5 = ANIM_WorldKoopatrol_Anim01, \
    .death  = ANIM_WorldKoopatrol_Anim10, \
    .hit    = ANIM_WorldKoopatrol_Anim10, \
    .anim_8 = ANIM_WorldKoopatrol_Anim0C, \
    .anim_9 = ANIM_WorldKoopatrol_Anim0B, \
    .anim_A = ANIM_WorldKoopatrol_Anim0D, \
    .anim_B = ANIM_WorldKoopatrol_Anim01, \
    .anim_C = ANIM_WorldKoopatrol_Anim01, \
    .anim_D = ANIM_WorldKoopatrol_Anim01, \
    .anim_E = ANIM_WorldKoopatrol_Anim01, \
    .anim_F = ANIM_WorldKoopatrol_Anim01, \
}
