#include "common.h"
#include "sprite/npc/Pokey.h"

#define POKEY_MUMMY_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_TASTY_TONIC, 10, 0 }, \
    }, \
    .heartDrops  = GENEROUS_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 1, \
    .maxCoinBonus = 2, \
}

#define POKEY_MUMMY_ANIMS \
{ \
    .idle   = ANIM_Pokey_Mummy_Anim04, \
    .walk   = ANIM_Pokey_Mummy_Anim08, \
    .run    = ANIM_Pokey_Mummy_Anim08, \
    .chase  = ANIM_Pokey_Mummy_Anim08, \
    .anim_4 = ANIM_Pokey_Mummy_Anim04, \
    .anim_5 = ANIM_Pokey_Mummy_Anim04, \
    .death  = ANIM_Pokey_Mummy_Anim0C, \
    .hit    = ANIM_Pokey_Mummy_Anim0C, \
    .anim_8 = ANIM_Pokey_Mummy_Anim08, \
    .anim_9 = ANIM_Pokey_Mummy_Anim08, \
    .anim_A = ANIM_Pokey_Mummy_Anim08, \
    .anim_B = ANIM_Pokey_Mummy_Anim08, \
    .anim_C = ANIM_Pokey_Mummy_Anim08, \
    .anim_D = ANIM_Pokey_Mummy_Anim08, \
    .anim_E = ANIM_Pokey_Mummy_Anim08, \
    .anim_F = ANIM_Pokey_Mummy_Anim08, \
}
