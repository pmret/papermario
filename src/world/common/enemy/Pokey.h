#include "common.h"
#include "sprite/npc/Pokey.h"

#define POKEY_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 15, \
    .itemDrops = { \
        { ITEM_DRIED_FRUIT, 9, 0 }, \
        { ITEM_TASTY_TONIC, 1, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 1, \
}

#define POKEY_ANIMS \
{ \
    .idle   = ANIM_Pokey_Idle4, \
    .walk   = ANIM_Pokey_Run4, \
    .run    = ANIM_Pokey_Run4, \
    .chase  = ANIM_Pokey_Run4, \
    .anim_4 = ANIM_Pokey_Idle4, \
    .anim_5 = ANIM_Pokey_Idle4, \
    .death  = ANIM_Pokey_Hurt4, \
    .hit    = ANIM_Pokey_Hurt4, \
    .anim_8 = ANIM_Pokey_Run4, \
    .anim_9 = ANIM_Pokey_Run4, \
    .anim_A = ANIM_Pokey_Run4, \
    .anim_B = ANIM_Pokey_Run4, \
    .anim_C = ANIM_Pokey_Run4, \
    .anim_D = ANIM_Pokey_Run4, \
    .anim_E = ANIM_Pokey_Run4, \
    .anim_F = ANIM_Pokey_Run4, \
}
