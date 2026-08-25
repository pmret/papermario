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
    .idle   = ANIM_SpearGuy_IdleUp, \
    .walk   = ANIM_SpearGuy_Walk, \
    .run    = ANIM_SpearGuy_Run, \
    .chase  = ANIM_SpearGuy_Run, \
    .anim_4 = ANIM_SpearGuy_IdleUp, \
    .anim_5 = ANIM_SpearGuy_IdleUp, \
    .death  = ANIM_SpearGuy_HurtUp, \
    .hit    = ANIM_SpearGuy_HurtUp, \
    .anim_8 = ANIM_SpearGuy_StabWindup, \
    .anim_9 = ANIM_SpearGuy_StabThrust, \
    .anim_A = ANIM_SpearGuy_IdleUp, \
    .anim_B = ANIM_SpearGuy_IdleUp, \
    .anim_C = ANIM_SpearGuy_IdleUp, \
    .anim_D = ANIM_SpearGuy_IdleUp, \
    .anim_E = ANIM_SpearGuy_IdleUp, \
    .anim_F = ANIM_SpearGuy_IdleUp, \
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

