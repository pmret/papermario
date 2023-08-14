#include "common.h"
#include "sprite/npc/WorldClubba.h"

#define FROST_CLUBBA_DROPS \
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

#define FROST_CLUBBA_ANIMS \
{ \
    .idle   = ANIM_WorldClubba_Frost_Anim02, \
    .walk   = ANIM_WorldClubba_Frost_Anim03, \
    .run    = ANIM_WorldClubba_Frost_Anim04, \
    .chase  = ANIM_WorldClubba_Frost_Anim04, \
    .anim_4 = ANIM_WorldClubba_Frost_Anim02, \
    .anim_5 = ANIM_WorldClubba_Frost_Anim02, \
    .death  = ANIM_WorldClubba_Frost_Anim0C, \
    .hit    = ANIM_WorldClubba_Frost_Anim0C, \
    .anim_8 = ANIM_WorldClubba_Frost_Anim11, \
    .anim_9 = ANIM_WorldClubba_Frost_Anim12, \
    .anim_A = ANIM_WorldClubba_Frost_Anim07, \
    .anim_B = ANIM_WorldClubba_Frost_Anim08, \
    .anim_C = ANIM_WorldClubba_Frost_Anim02, \
    .anim_D = ANIM_WorldClubba_Frost_Anim02, \
    .anim_E = ANIM_WorldClubba_Frost_Anim02, \
    .anim_F = ANIM_WorldClubba_Frost_Anim02, \
}

#define FROST_CLUBBA_MACE_HITBOX(npcID) \
{ \
    .id = npcID, \
    .settings = &N(NpcSettings_FrostClubba_Hitbox), \
    .pos = { NPC_DISPOSE_LOCATION }, \
    .yaw = 0, \
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DROPS, \
    .drops = NO_DROPS, \
    .animations = FROST_CLUBBA_ANIMS, \
    .extraAnimations = N(ExtraAnims_FrostClubba_Hitbox), \
}
