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
    .idle   = ANIM_Gulpit_Idle, \
    .walk   = ANIM_Gulpit_Walk, \
    .run    = ANIM_Gulpit_Run, \
    .chase  = ANIM_Gulpit_Run, \
    .anim_4 = ANIM_Gulpit_Idle, \
    .anim_5 = ANIM_Gulpit_Idle, \
    .death  = ANIM_Gulpit_Hurt, \
    .hit    = ANIM_Gulpit_Hurt, \
    .anim_8 = ANIM_Gulpit_Lick, \
    .anim_9 = ANIM_Gulpit_Lick, \
    .anim_A = ANIM_Gulpit_Idle, \
    .anim_B = ANIM_Gulpit_Idle, \
    .anim_C = ANIM_Gulpit_Idle, \
    .anim_D = ANIM_Gulpit_Idle, \
    .anim_E = ANIM_Gulpit_Idle, \
    .anim_F = ANIM_Gulpit_Idle, \
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
