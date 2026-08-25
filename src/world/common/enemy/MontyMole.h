#include "common.h"
#include "sprite/npc/MontyMole.h"

#define MONTY_MOLE_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 10, \
    .itemDrops = { \
        { ITEM_HONEY_SYRUP, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 1, \
}

#define MONTY_MOLE_AMBUSH_ANIMS \
{ \
    .idle   = ANIM_MontyMole_Stand, \
    .walk   = ANIM_MontyMole_Walk, \
    .run    = ANIM_MontyMole_Run, \
    .chase  = ANIM_MontyMole_Run, \
    .anim_4 = ANIM_MontyMole_Stand, \
    .anim_5 = ANIM_MontyMole_Stand, \
    .death  = ANIM_MontyMole_Panic, \
    .hit    = ANIM_MontyMole_Panic, \
    .anim_8 = ANIM_MontyMole_Stand, \
    .anim_9 = ANIM_MontyMole_Stand, \
    .anim_A = ANIM_MontyMole_Stand, \
    .anim_B = ANIM_MontyMole_Stand, \
    .anim_C = ANIM_MontyMole_Stand, \
    .anim_D = ANIM_MontyMole_Stand, \
    .anim_E = ANIM_MontyMole_Stand, \
    .anim_F = ANIM_MontyMole_Stand, \
}

#define MONTY_MOLE_THROWER_ANIMS \
{ \
    .idle   = ANIM_MontyMole_Idle, \
    .walk   = ANIM_MontyMole_Walk, \
    .run    = ANIM_MontyMole_Run, \
    .chase  = ANIM_MontyMole_Run, \
    .anim_4 = ANIM_MontyMole_Idle, \
    .anim_5 = ANIM_MontyMole_Idle, \
    .death  = ANIM_MontyMole_Hurt, \
    .hit    = ANIM_MontyMole_Hurt, \
    .anim_8 = ANIM_MontyMole_Still, \
    .anim_9 = ANIM_MontyMole_Still, \
    .anim_A = ANIM_MontyMole_Still, \
    .anim_B = ANIM_MontyMole_Still, \
    .anim_C = ANIM_MontyMole_Still, \
    .anim_D = ANIM_MontyMole_Still, \
    .anim_E = ANIM_MontyMole_Still, \
    .anim_F = ANIM_MontyMole_Still, \
}
