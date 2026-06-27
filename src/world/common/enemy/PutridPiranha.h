#include "common.h"
#include "sprite/npc/LargePiranha.h"

#define PUTRID_PIRANHA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_SUPER_SHROOM, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 3, \
}

#define PUTRID_PIRANHA_ANIMS \
{ \
    .idle   = ANIM_LargePiranha_Putrid_Idle, \
    .walk   = ANIM_LargePiranha_Putrid_Walk, \
    .run    = ANIM_LargePiranha_Putrid_Run, \
    .chase  = ANIM_LargePiranha_Putrid_Run, \
    .anim_4 = ANIM_LargePiranha_Putrid_Idle, \
    .anim_5 = ANIM_LargePiranha_Putrid_Idle, \
    .death  = ANIM_LargePiranha_Putrid_Hurt, \
    .hit    = ANIM_LargePiranha_Putrid_Hurt, \
    .anim_8 = ANIM_LargePiranha_Putrid_Burrow, \
    .anim_9 = ANIM_LargePiranha_Putrid_Emerge, \
    .anim_A = ANIM_LargePiranha_Putrid_Windup, \
    .anim_B = ANIM_LargePiranha_Putrid_Bite, \
    .anim_C = ANIM_LargePiranha_Putrid_PostBite, \
    .anim_D = ANIM_LargePiranha_Putrid_Idle, \
    .anim_E = ANIM_LargePiranha_Putrid_Idle, \
    .anim_F = ANIM_LargePiranha_Putrid_Idle, \
}

// auxiliary NPC used for triggering enemy first strikes during the bite animation
#define PUTRID_PIRANHA_HITBOX(npcID) \
{ \
    .id = npcID, \
    .settings = &N(NpcSettings_PutridPiranha_Hitbox), \
    .pos = { NPC_DISPOSE_LOCATION }, \
    .yaw = 0, \
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DROPS, \
    .drops = NO_DROPS, \
    .animations = PUTRID_PIRANHA_ANIMS, \
}
