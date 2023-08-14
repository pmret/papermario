#include "common.h"
#include "sprite/npc/Gulpit.h"

#define GULPIT_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_PEBBLE, 2, 0 }, \
        { ITEM_SUPER_SHROOM, 8, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(3), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 1, \
    .maxCoinBonus = 4, \
}

#define GULPIT_ANIMS \
{ \
    .idle   = ANIM_Gulpit_Anim01, \
    .walk   = ANIM_Gulpit_Anim02, \
    .run    = ANIM_Gulpit_Anim03, \
    .chase  = ANIM_Gulpit_Anim03, \
    .anim_4 = ANIM_Gulpit_Anim01, \
    .anim_5 = ANIM_Gulpit_Anim01, \
    .death  = ANIM_Gulpit_Anim0B, \
    .hit    = ANIM_Gulpit_Anim0B, \
    .anim_8 = ANIM_Gulpit_Anim04, \
    .anim_9 = ANIM_Gulpit_Anim04, \
    .anim_A = ANIM_Gulpit_Anim01, \
    .anim_B = ANIM_Gulpit_Anim01, \
    .anim_C = ANIM_Gulpit_Anim01, \
    .anim_D = ANIM_Gulpit_Anim01, \
    .anim_E = ANIM_Gulpit_Anim01, \
    .anim_F = ANIM_Gulpit_Anim01, \
}

#define GULPIT_HITBOX(npcID) \
{ \
    .id = npcID, \
    .settings = &N(NpcSettings_Gulpit_Hitbox), \
    .pos = { NPC_DISPOSE_LOCATION }, \
    .yaw = 0, \
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DROPS, \
    .drops = NO_DROPS, \
    .animations = GULPIT_ANIMS, \
    .extraAnimations = N(ExtraAnims_Gulpit_Hitbox), \
}
