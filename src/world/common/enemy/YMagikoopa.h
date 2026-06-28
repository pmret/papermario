#include "common.h"
#include "sprite/npc/Magikoopa.h"
#include "sprite/npc/FlyingMagikoopa.h"

#define MAGINO_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 25, \
    .itemDrops = { \
        { ITEM_SUPER_SHROOM, 2, 0 }, \
        { ITEM_MAPLE_SYRUP, 2, 0 }, \
        { ITEM_THUNDER_RAGE, 2, 0 }, \
        { ITEM_STOP_WATCH, 2, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(3), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 2, \
}

#define MAGIKOOPA_YELLOW_ANIMS \
{ \
    .idle   = ANIM_Magikoopa_Yellow_Idle, \
    .walk   = ANIM_Magikoopa_Yellow_Idle, \
    .run    = ANIM_Magikoopa_Yellow_Idle, \
    .chase  = ANIM_Magikoopa_Yellow_Idle, \
    .anim_4 = ANIM_Magikoopa_Yellow_Idle, \
    .anim_5 = ANIM_Magikoopa_Yellow_Idle, \
    .death  = ANIM_Magikoopa_Yellow_Hurt, \
    .hit    = ANIM_Magikoopa_Yellow_Hurt, \
    .anim_8 = ANIM_Magikoopa_Yellow_Idle, \
    .anim_9 = ANIM_Magikoopa_Yellow_Idle, \
    .anim_A = ANIM_Magikoopa_Yellow_Idle, \
    .anim_B = ANIM_Magikoopa_Yellow_Idle, \
    .anim_C = ANIM_Magikoopa_Yellow_Idle, \
    .anim_D = ANIM_Magikoopa_Yellow_Idle, \
    .anim_E = ANIM_Magikoopa_Yellow_Idle, \
    .anim_F = ANIM_Magikoopa_Yellow_Idle, \
}

#define FLYING_MAGIKOOPA_YELLOW_ANIMS \
{ \
    .idle   = ANIM_FlyingMagikoopa_Yellow_Idle, \
    .walk   = ANIM_FlyingMagikoopa_Yellow_Idle, \
    .run    = ANIM_FlyingMagikoopa_Yellow_Idle, \
    .chase  = ANIM_FlyingMagikoopa_Yellow_Idle, \
    .anim_4 = ANIM_FlyingMagikoopa_Yellow_Idle, \
    .anim_5 = ANIM_FlyingMagikoopa_Yellow_Idle, \
    .death  = ANIM_FlyingMagikoopa_Yellow_Hurt, \
    .hit    = ANIM_FlyingMagikoopa_Yellow_Hurt, \
    .anim_8 = ANIM_FlyingMagikoopa_Yellow_Idle, \
    .anim_9 = ANIM_FlyingMagikoopa_Yellow_Idle, \
    .anim_A = ANIM_FlyingMagikoopa_Yellow_Idle, \
    .anim_B = ANIM_FlyingMagikoopa_Yellow_Idle, \
    .anim_C = ANIM_FlyingMagikoopa_Yellow_Idle, \
    .anim_D = ANIM_FlyingMagikoopa_Yellow_Idle, \
    .anim_E = ANIM_FlyingMagikoopa_Yellow_Idle, \
    .anim_F = ANIM_FlyingMagikoopa_Yellow_Idle, \
}
