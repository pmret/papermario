#include "common.h"
#include "sprite/npc/MontyMole.h"

#define MONTY_MOLE_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .itemDropChance = 10, \
    .itemDrops = { \
        { ITEM_HONEY_SYRUP, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 1, \
}

#define MONTY_MOLE_ANIMS \
{ \
    .idle   = ANIM_MontyMole_Anim19, \
    .walk   = ANIM_MontyMole_Anim02, \
    .run    = ANIM_MontyMole_Anim03, \
    .chase  = ANIM_MontyMole_Anim03, \
    .anim_4 = ANIM_MontyMole_Anim19, \
    .anim_5 = ANIM_MontyMole_Anim19, \
    .death  = ANIM_MontyMole_Anim09, \
    .hit    = ANIM_MontyMole_Anim09, \
    .anim_8 = ANIM_MontyMole_Anim19, \
    .anim_9 = ANIM_MontyMole_Anim19, \
    .anim_A = ANIM_MontyMole_Anim19, \
    .anim_B = ANIM_MontyMole_Anim19, \
    .anim_C = ANIM_MontyMole_Anim19, \
    .anim_D = ANIM_MontyMole_Anim19, \
    .anim_E = ANIM_MontyMole_Anim19, \
    .anim_F = ANIM_MontyMole_Anim19, \
}
