#include "common.h"
#include "sprite/npc/SpearGuy.h"

#define SPEAR_GUY_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_SLEEPY_SHEEP, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(3), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 3, \
}

#define SPEAR_GUY_ANIMS \
{ \
    .idle   = ANIM_SpearGuy_Anim03, \
    .walk   = ANIM_SpearGuy_Anim05, \
    .run    = ANIM_SpearGuy_Anim06, \
    .chase  = ANIM_SpearGuy_Anim06, \
    .anim_4 = ANIM_SpearGuy_Anim03, \
    .anim_5 = ANIM_SpearGuy_Anim03, \
    .death  = ANIM_SpearGuy_Anim07, \
    .hit    = ANIM_SpearGuy_Anim07, \
    .anim_8 = ANIM_SpearGuy_Anim1A, \
    .anim_9 = ANIM_SpearGuy_Anim1B, \
    .anim_A = ANIM_SpearGuy_Anim03, \
    .anim_B = ANIM_SpearGuy_Anim03, \
    .anim_C = ANIM_SpearGuy_Anim03, \
    .anim_D = ANIM_SpearGuy_Anim03, \
    .anim_E = ANIM_SpearGuy_Anim03, \
    .anim_F = ANIM_SpearGuy_Anim03, \
}

#define SPEAR_GUY_HITBOX(npcID) \
{ \
    .id = npcID, \
    .settings = &N(NpcSettings_SpearGuy_Hitbox), \
    .pos = { NPC_DISPOSE_LOCATION }, \
    .yaw = 0, \
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DROPS, \
    .drops = NO_DROPS, \
    .animations = SPEAR_GUY_ANIMS, \
    .extraAnimations = N(ExtraAnims_SpearGuy_Hitbox), \
}

