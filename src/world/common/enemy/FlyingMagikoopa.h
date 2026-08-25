#include "common.h"
#include "sprite/npc/Magikoopa.h"
#include "sprite/npc/FlyingMagikoopa.h"

#define FLYING_MAGINO_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_SUPER_SHROOM, 5, 0 }, \
        { ITEM_MAPLE_SYRUP, 5, 0 }, \
        { ITEM_THUNDER_RAGE, 5, 0 }, \
        { ITEM_STOP_WATCH, 5, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(5), \
    .minCoinBonus = 1, \
    .maxCoinBonus = 3, \
}

#define FLYING_MAGIKOOPA_ANIMS \
{ \
    .idle   = ANIM_FlyingMagikoopa_Still, \
    .walk   = ANIM_FlyingMagikoopa_Idle, \
    .run    = ANIM_FlyingMagikoopa_Idle, \
    .chase  = ANIM_FlyingMagikoopa_Idle, \
    .anim_4 = ANIM_FlyingMagikoopa_Idle, \
    .anim_5 = ANIM_FlyingMagikoopa_Idle, \
    .death  = ANIM_FlyingMagikoopa_Hurt, \
    .hit    = ANIM_FlyingMagikoopa_Hurt, \
    .anim_8 = ANIM_FlyingMagikoopa_Shout, \
    .anim_9 = ANIM_FlyingMagikoopa_CastSpell, \
    .anim_A = ANIM_FlyingMagikoopa_Idle, \
    .anim_B = ANIM_FlyingMagikoopa_Idle, \
    .anim_C = ANIM_FlyingMagikoopa_Idle, \
    .anim_D = ANIM_FlyingMagikoopa_Idle, \
    .anim_E = ANIM_FlyingMagikoopa_Idle, \
    .anim_F = ANIM_FlyingMagikoopa_Idle, \
}

#define FLYING_MAGIKOOPA_SPELL_HITBOX(npcID) \
{ \
    .id = npcID, \
    .settings = &N(NpcSettings_FlyingMagikoopa_Hitbox), \
    .pos = { NPC_DISPOSE_LOCATION }, \
    .yaw = 90, \
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DROPS, \
    .drops = NO_DROPS, \
    .animations = { \
        .idle   = ANIM_FlyingMagikoopa_Still, \
        .walk   = ANIM_FlyingMagikoopa_Still, \
        .run    = ANIM_FlyingMagikoopa_Still, \
        .chase  = ANIM_FlyingMagikoopa_Still, \
        .anim_4 = ANIM_FlyingMagikoopa_Still, \
        .anim_5 = ANIM_FlyingMagikoopa_Still, \
        .death  = ANIM_FlyingMagikoopa_Still, \
        .hit    = ANIM_FlyingMagikoopa_Still, \
        .anim_8 = ANIM_FlyingMagikoopa_Still, \
        .anim_9 = ANIM_FlyingMagikoopa_Still, \
        .anim_A = ANIM_FlyingMagikoopa_Still, \
        .anim_B = ANIM_FlyingMagikoopa_Still, \
        .anim_C = ANIM_FlyingMagikoopa_Still, \
        .anim_D = ANIM_FlyingMagikoopa_Still, \
        .anim_E = ANIM_FlyingMagikoopa_Still, \
        .anim_F = ANIM_FlyingMagikoopa_Still, \
    }, \
}
