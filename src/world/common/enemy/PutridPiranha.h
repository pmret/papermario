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
    .idle   = ANIM_LargePiranha_Putrid_Anim01, \
    .walk   = ANIM_LargePiranha_Putrid_Anim02, \
    .run    = ANIM_LargePiranha_Putrid_Anim03, \
    .chase  = ANIM_LargePiranha_Putrid_Anim03, \
    .anim_4 = ANIM_LargePiranha_Putrid_Anim01, \
    .anim_5 = ANIM_LargePiranha_Putrid_Anim01, \
    .death  = ANIM_LargePiranha_Putrid_Anim0E, \
    .hit    = ANIM_LargePiranha_Putrid_Anim0E, \
    .anim_8 = ANIM_LargePiranha_Putrid_Anim18, \
    .anim_9 = ANIM_LargePiranha_Putrid_Anim17, \
    .anim_A = ANIM_LargePiranha_Putrid_Anim05, \
    .anim_B = ANIM_LargePiranha_Putrid_Anim06, \
    .anim_C = ANIM_LargePiranha_Putrid_Anim07, \
    .anim_D = ANIM_LargePiranha_Putrid_Anim01, \
    .anim_E = ANIM_LargePiranha_Putrid_Anim01, \
    .anim_F = ANIM_LargePiranha_Putrid_Anim01, \
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
