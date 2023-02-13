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
    .idle   = ANIM_Magikoopa_Yellow_Anim01, \
    .walk   = ANIM_Magikoopa_Yellow_Anim01, \
    .run    = ANIM_Magikoopa_Yellow_Anim01, \
    .chase  = ANIM_Magikoopa_Yellow_Anim01, \
    .anim_4 = ANIM_Magikoopa_Yellow_Anim01, \
    .anim_5 = ANIM_Magikoopa_Yellow_Anim01, \
    .death  = ANIM_Magikoopa_Yellow_Anim04, \
    .hit    = ANIM_Magikoopa_Yellow_Anim04, \
    .anim_8 = ANIM_Magikoopa_Yellow_Anim01, \
    .anim_9 = ANIM_Magikoopa_Yellow_Anim01, \
    .anim_A = ANIM_Magikoopa_Yellow_Anim01, \
    .anim_B = ANIM_Magikoopa_Yellow_Anim01, \
    .anim_C = ANIM_Magikoopa_Yellow_Anim01, \
    .anim_D = ANIM_Magikoopa_Yellow_Anim01, \
    .anim_E = ANIM_Magikoopa_Yellow_Anim01, \
    .anim_F = ANIM_Magikoopa_Yellow_Anim01, \
}

#define FLYING_MAGIKOOPA_YELLOW_ANIMS \
{ \
    .idle   = ANIM_FlyingMagikoopa_Yellow_Anim01, \
    .walk   = ANIM_FlyingMagikoopa_Yellow_Anim01, \
    .run    = ANIM_FlyingMagikoopa_Yellow_Anim01, \
    .chase  = ANIM_FlyingMagikoopa_Yellow_Anim01, \
    .anim_4 = ANIM_FlyingMagikoopa_Yellow_Anim01, \
    .anim_5 = ANIM_FlyingMagikoopa_Yellow_Anim01, \
    .death  = ANIM_FlyingMagikoopa_Yellow_Anim04, \
    .hit    = ANIM_FlyingMagikoopa_Yellow_Anim04, \
    .anim_8 = ANIM_FlyingMagikoopa_Yellow_Anim01, \
    .anim_9 = ANIM_FlyingMagikoopa_Yellow_Anim01, \
    .anim_A = ANIM_FlyingMagikoopa_Yellow_Anim01, \
    .anim_B = ANIM_FlyingMagikoopa_Yellow_Anim01, \
    .anim_C = ANIM_FlyingMagikoopa_Yellow_Anim01, \
    .anim_D = ANIM_FlyingMagikoopa_Yellow_Anim01, \
    .anim_E = ANIM_FlyingMagikoopa_Yellow_Anim01, \
    .anim_F = ANIM_FlyingMagikoopa_Yellow_Anim01, \
}
