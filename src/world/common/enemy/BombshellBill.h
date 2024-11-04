#include "common.h"
#include "sprite/npc/BulletBill.h"

#define BOMBSHELL_BLASTER_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .heartDrops  = STANDARD_HEART_DROPS(4), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 1, \
    .maxCoinBonus = 3, \
}

#define BOMBSHELL_BLASTER_ANIMS \
{ \
    .idle   = ANIM_BillBlaster_Gold_Idle, \
    .walk   = ANIM_BillBlaster_Gold_Idle, \
    .run    = ANIM_BillBlaster_Gold_Idle, \
    .chase  = ANIM_BillBlaster_Gold_Idle, \
    .anim_4 = ANIM_BillBlaster_Gold_Idle, \
    .anim_5 = ANIM_BillBlaster_Gold_Idle, \
    .death  = ANIM_BillBlaster_Gold_Hurt, \
    .hit    = ANIM_BillBlaster_Gold_Hurt, \
    .anim_8 = ANIM_BillBlaster_Gold_Fire, \
    .anim_9 = ANIM_BillBlaster_Gold_Idle, \
    .anim_A = ANIM_BillBlaster_Gold_Idle, \
    .anim_B = ANIM_BillBlaster_Gold_Idle, \
    .anim_C = ANIM_BillBlaster_Gold_Idle, \
    .anim_D = ANIM_BillBlaster_Gold_Idle, \
    .anim_E = ANIM_BillBlaster_Gold_Idle, \
    .anim_F = ANIM_BillBlaster_Gold_Idle, \
}

#define BOMBSHELL_BILL_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 3, \
    .itemDrops = { \
        { ITEM_SUPER_SHROOM, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(3), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 1, \
    .maxCoinBonus = 3, \
}

#define BOMBSHELL_BILL_ANIMS \
{ \
    .idle   = ANIM_BulletBill_Gold_Still, \
    .walk   = ANIM_BulletBill_Gold_TenseCopy, \
    .run    = ANIM_BulletBill_Gold_Tense, \
    .chase  = ANIM_BulletBill_Gold_Tense, \
    .anim_4 = ANIM_BulletBill_Gold_Still, \
    .anim_5 = ANIM_BulletBill_Gold_Fire, \
    .death  = ANIM_BulletBill_Gold_Hurt, \
    .hit    = ANIM_BulletBill_Gold_Hurt, \
    .anim_8 = ANIM_BulletBill_Gold_Still, \
    .anim_9 = ANIM_BulletBill_Gold_Still, \
    .anim_A = ANIM_BulletBill_Gold_Still, \
    .anim_B = ANIM_BulletBill_Gold_Still, \
    .anim_C = ANIM_BulletBill_Gold_Still, \
    .anim_D = ANIM_BulletBill_Gold_Still, \
    .anim_E = ANIM_BulletBill_Gold_Still, \
    .anim_F = ANIM_BulletBill_Gold_Still, \
}

#define BOMBSHELL_BILL_NPC(npcID) \
{ \
    .id = npcID, \
    .settings = &N(NpcSettings_BombshellBill), \
    .pos = { NPC_DISPOSE_LOCATION }, \
    .yaw = 0, \
    .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_DONT_SUSPEND_SCRIPTS | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN, \
    .drops = BOMBSHELL_BILL_DROPS, \
    .territory = { \
        .wander = { \
            .isFlying = TRUE, \
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED, \
            .wanderShape = SHAPE_CYLINDER, \
            .centerPos  = { 0, 0, 0 }, \
            .wanderSize = { 0 }, \
            .detectShape = SHAPE_CYLINDER, \
            .detectPos  = { 0, 0, 0 }, \
            .detectSize = { 0 }, \
        } \
    }, \
    .animations = BOMBSHELL_BILL_ANIMS, \
}
