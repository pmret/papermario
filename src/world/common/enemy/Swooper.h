#include "common.h"
#include "sprite/npc/Swooper.h"

#define SWOOPULA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_VOLT_SHROOM, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 4, \
}

#define SWOOPULA_ANIMS \
{ \
    .idle   = ANIM_Swooper_Gray_Anim1B, \
    .walk   = ANIM_Swooper_Gray_Anim02, \
    .run    = ANIM_Swooper_Gray_Anim02, \
    .chase  = ANIM_Swooper_Gray_Anim02, \
    .anim_4 = ANIM_Swooper_Gray_Anim1B, \
    .anim_5 = ANIM_Swooper_Gray_Anim1B, \
    .death  = ANIM_Swooper_Gray_Anim04, \
    .hit    = ANIM_Swooper_Gray_Anim15, \
    .anim_8 = ANIM_Swooper_Gray_Anim00, \
    .anim_9 = ANIM_Swooper_Gray_Anim00, \
    .anim_A = ANIM_Swooper_Gray_Anim01, \
    .anim_B = ANIM_Swooper_Gray_Anim01, \
    .anim_C = ANIM_Swooper_Gray_Anim01, \
    .anim_D = ANIM_Swooper_Gray_Anim01, \
    .anim_E = ANIM_Swooper_Gray_Anim01, \
    .anim_F = ANIM_Swooper_Gray_Anim01, \
}
