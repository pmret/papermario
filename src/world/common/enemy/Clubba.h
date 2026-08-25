#include "common.h"
#include "sprite/npc/WorldClubba.h"

#define CLUBBA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_SUPER_SHROOM, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(3), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 2, \
    .maxCoinBonus = 3, \
}

#define CLUBBA_ANIMS \
{ \
    .idle   = ANIM_WorldClubba_Idle, \
    .walk   = ANIM_WorldClubba_Walk, \
    .run    = ANIM_WorldClubba_Run, \
    .chase  = ANIM_WorldClubba_Run, \
    .anim_4 = ANIM_WorldClubba_Idle, \
    .anim_5 = ANIM_WorldClubba_Idle, \
    .death  = ANIM_WorldClubba_Hurt, \
    .hit    = ANIM_WorldClubba_Hurt, \
    .anim_8 = ANIM_WorldClubba_RaiseClub, \
    .anim_9 = ANIM_WorldClubba_SwingClub, \
    .anim_A = ANIM_WorldClubba_Sleep, \
    .anim_B = ANIM_WorldClubba_WakeUp, \
    .anim_C = ANIM_WorldClubba_StillSleep, \
    .anim_D = ANIM_WorldClubba_Idle, \
    .anim_E = ANIM_WorldClubba_Idle, \
    .anim_F = ANIM_WorldClubba_Idle, \
}

// used in omo_04, anim_C is different
#define CLUBBA_ANIMS_ALT \
{ \
    .idle   = ANIM_WorldClubba_Idle, \
    .walk   = ANIM_WorldClubba_Walk, \
    .run    = ANIM_WorldClubba_Run, \
    .chase  = ANIM_WorldClubba_Run, \
    .anim_4 = ANIM_WorldClubba_Idle, \
    .anim_5 = ANIM_WorldClubba_Idle, \
    .death  = ANIM_WorldClubba_Hurt, \
    .hit    = ANIM_WorldClubba_Hurt, \
    .anim_8 = ANIM_WorldClubba_RaiseClub, \
    .anim_9 = ANIM_WorldClubba_SwingClub, \
    .anim_A = ANIM_WorldClubba_Sleep, \
    .anim_B = ANIM_WorldClubba_WakeUp, \
    .anim_C = ANIM_WorldClubba_Idle, \
    .anim_D = ANIM_WorldClubba_Idle, \
    .anim_E = ANIM_WorldClubba_Idle, \
    .anim_F = ANIM_WorldClubba_Idle, \
}

#define CLUBBA_MACE_HITBOX(npcID) \
{ \
    .id = npcID, \
    .settings = &N(NpcSettings_Clubba_Hitbox), \
    .pos = { NPC_DISPOSE_LOCATION }, \
    .yaw = 0, \
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DROPS, \
    .drops = NO_DROPS, \
    .animations = CLUBBA_ANIMS, \
    .extraAnimations = N(ExtraAnims_Clubba_Hitbox), \
}
