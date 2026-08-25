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
    .idle   = ANIM_Swooper_Gray_IdleRoost, \
    .walk   = ANIM_Swooper_Gray_Idle, \
    .run    = ANIM_Swooper_Gray_Idle, \
    .chase  = ANIM_Swooper_Gray_Idle, \
    .anim_4 = ANIM_Swooper_Gray_IdleRoost, \
    .anim_5 = ANIM_Swooper_Gray_IdleRoost, \
    .death  = ANIM_Swooper_Gray_WorldDead, \
    .hit    = ANIM_Swooper_Gray_Hurt, \
    .anim_8 = ANIM_Swooper_Gray_StillRoost, \
    .anim_9 = ANIM_Swooper_Gray_StillRoost, \
    .anim_A = ANIM_Swooper_Gray_Still, \
    .anim_B = ANIM_Swooper_Gray_Still, \
    .anim_C = ANIM_Swooper_Gray_Still, \
    .anim_D = ANIM_Swooper_Gray_Still, \
    .anim_E = ANIM_Swooper_Gray_Still, \
    .anim_F = ANIM_Swooper_Gray_Still, \
}
