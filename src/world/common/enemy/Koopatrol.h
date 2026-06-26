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
    .idle   = ANIM_WorldKoopatrol_Idle, \
    .walk   = ANIM_WorldKoopatrol_Walk, \
    .run    = ANIM_WorldKoopatrol_Run, \
    .chase  = ANIM_WorldKoopatrol_Run, \
    .anim_4 = ANIM_WorldKoopatrol_Idle, \
    .anim_5 = ANIM_WorldKoopatrol_Idle, \
    .death  = ANIM_WorldKoopatrol_Hurt, \
    .hit    = ANIM_WorldKoopatrol_Hurt, \
    .anim_8 = ANIM_WorldKoopatrol_ShellEnter, \
    .anim_9 = ANIM_WorldKoopatrol_ShellSpin, \
    .anim_A = ANIM_WorldKoopatrol_ShellExit, \
    .anim_B = ANIM_WorldKoopatrol_Idle, \
    .anim_C = ANIM_WorldKoopatrol_Idle, \
    .anim_D = ANIM_WorldKoopatrol_Idle, \
    .anim_E = ANIM_WorldKoopatrol_Idle, \
    .anim_F = ANIM_WorldKoopatrol_Idle, \
}
