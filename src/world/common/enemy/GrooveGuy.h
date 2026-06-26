#include "common.h"
#include "sprite/npc/GrooveGuy.h"

#define GROOVE_GUY_DROPS_A \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_FIRE_FLOWER, 2, 0 }, \
        { ITEM_THUNDER_RAGE, 2, 0 }, \
        { ITEM_THUNDER_BOLT, 2, 0 }, \
        { ITEM_DUSTY_HAMMER, 2, 0 }, \
        { ITEM_PEBBLE, 2, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(3), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 3, \
}

#define GROOVE_GUY_DROPS_B \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_MYSTERY, 5, 0 }, \
        { ITEM_FRIGHT_JAR, 5, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(4), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 3, \
}

#define GROOVE_GUY_ANIMS \
{ \
    .idle   = ANIM_GrooveGuy_Idle, \
    .walk   = ANIM_GrooveGuy_Walk, \
    .run    = ANIM_GrooveGuy_Run, \
    .chase  = ANIM_GrooveGuy_Walk, \
    .anim_4 = ANIM_GrooveGuy_Idle, \
    .anim_5 = ANIM_GrooveGuy_Idle, \
    .death  = ANIM_GrooveGuy_Hurt, \
    .hit    = ANIM_GrooveGuy_Hurt, \
    .anim_8 = ANIM_GrooveGuy_Idle, \
    .anim_9 = ANIM_GrooveGuy_Idle, \
    .anim_A = ANIM_GrooveGuy_Idle, \
    .anim_B = ANIM_GrooveGuy_Idle, \
    .anim_C = ANIM_GrooveGuy_Idle, \
    .anim_D = ANIM_GrooveGuy_Idle, \
    .anim_E = ANIM_GrooveGuy_Idle, \
    .anim_F = ANIM_GrooveGuy_Idle, \
}
