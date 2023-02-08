#include "common.h"
#include "sprite/npc/JungleGuy.h"

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
    .idle   = ANIM_JungleGuy_Anim03, \
    .walk   = ANIM_JungleGuy_Anim05, \
    .run    = ANIM_JungleGuy_Anim06, \
    .chase  = ANIM_JungleGuy_Anim06, \
    .anim_4 = ANIM_JungleGuy_Anim03, \
    .anim_5 = ANIM_JungleGuy_Anim03, \
    .death  = ANIM_JungleGuy_Anim07, \
    .hit    = ANIM_JungleGuy_Anim07, \
    .anim_8 = ANIM_JungleGuy_Anim1A, \
    .anim_9 = ANIM_JungleGuy_Anim1B, \
    .anim_A = ANIM_JungleGuy_Anim03, \
    .anim_B = ANIM_JungleGuy_Anim03, \
    .anim_C = ANIM_JungleGuy_Anim03, \
    .anim_D = ANIM_JungleGuy_Anim03, \
    .anim_E = ANIM_JungleGuy_Anim03, \
    .anim_F = ANIM_JungleGuy_Anim03, \
}

#define SPEAR_GUY_HITBOX(npcID) \
{ \
    .id = npcID, \
    .settings = &N(NpcSettings_SpearGuy_Hitbox), \
    .pos = { NPC_DISPOSE_LOCATION }, \
    .yaw = 0, \
    .flags = ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_NO_DROPS, \
    .drops = NPC_NO_DROPS, \
    .animations = SPEAR_GUY_ANIMS, \
    .extraAnimations = N(ExtraAnims_SpearGuy_Hitbox), \
}

