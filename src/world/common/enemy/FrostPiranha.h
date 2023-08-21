#include "common.h"
#include "sprite/npc/LargePiranha.h"

#define FROST_PIRANHA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_FIRE_FLOWER, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(4), \
    .minCoinBonus = 1, \
    .maxCoinBonus = 4, \
}

#define FROST_PIRANHA_ANIMS \
{ \
    .idle   = ANIM_LargePiranha_Frost_Anim01, \
    .walk   = ANIM_LargePiranha_Frost_Anim02, \
    .run    = ANIM_LargePiranha_Frost_Anim03, \
    .chase  = ANIM_LargePiranha_Frost_Anim03, \
    .anim_4 = ANIM_LargePiranha_Frost_Anim01, \
    .anim_5 = ANIM_LargePiranha_Frost_Anim01, \
    .death  = ANIM_LargePiranha_Frost_Anim0E, \
    .hit    = ANIM_LargePiranha_Frost_Anim0E, \
    .anim_8 = ANIM_LargePiranha_Frost_Anim18, \
    .anim_9 = ANIM_LargePiranha_Frost_Anim17, \
    .anim_A = ANIM_LargePiranha_Frost_Anim05, \
    .anim_B = ANIM_LargePiranha_Frost_Anim06, \
    .anim_C = ANIM_LargePiranha_Frost_Anim12, \
    .anim_D = ANIM_LargePiranha_Frost_Anim13, \
    .anim_E = ANIM_LargePiranha_Frost_Anim14, \
    .anim_F = ANIM_LargePiranha_Frost_Anim01, \
}

// auxiliary NPC used for triggering enemy first strikes during the bite animation
#define FROST_PIRANHA_HITBOX(npcID) \
{ \
    .id = npcID, \
    .settings = &N(NpcSettings_FrostPiranha_Hitbox), \
    .pos = { NPC_DISPOSE_LOCATION }, \
    .yaw = 0, \
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DROPS, \
    .drops = NO_DROPS, \
    .animations = FROST_PIRANHA_ANIMS, \
    .extraAnimations = N(ExtraAnims_FrostPiranha_Hitbox), \
}
