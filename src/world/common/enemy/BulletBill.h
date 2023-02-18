#include "common.h"
#include "sprite/npc/BulletBill.h"

#define BILL_BLASTER_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 1, \
    .maxCoinBonus = 1, \
}

#define BILL_BLASTER_ANIMS \
{ \
    .idle   = ANIM_BillBlaster_Anim01, \
    .walk   = ANIM_BillBlaster_Anim01, \
    .run    = ANIM_BillBlaster_Anim01, \
    .chase  = ANIM_BillBlaster_Anim01, \
    .anim_4 = ANIM_BillBlaster_Anim01, \
    .anim_5 = ANIM_BillBlaster_Anim01, \
    .death  = ANIM_BillBlaster_Anim03, \
    .hit    = ANIM_BillBlaster_Anim03, \
    .anim_8 = ANIM_BillBlaster_Anim01, \
    .anim_9 = ANIM_BillBlaster_Anim01, \
    .anim_A = ANIM_BillBlaster_Anim01, \
    .anim_B = ANIM_BillBlaster_Anim01, \
    .anim_C = ANIM_BillBlaster_Anim01, \
    .anim_D = ANIM_BillBlaster_Anim01, \
    .anim_E = ANIM_BillBlaster_Anim01, \
    .anim_F = ANIM_BillBlaster_Anim01, \
}

#define BULLET_BILL_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAG_80, \
    .itemDropChance = 3, \
    .itemDrops = { \
        { ITEM_MUSHROOM, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
}

#define BULLET_BILL_ANIMS \
{ \
    .idle   = ANIM_BulletBill_Anim01, \
    .walk   = ANIM_BulletBill_Anim02, \
    .run    = ANIM_BulletBill_Anim03, \
    .chase  = ANIM_BulletBill_Anim03, \
    .anim_4 = ANIM_BulletBill_Anim01, \
    .anim_5 = ANIM_BulletBill_Anim04, \
    .death  = ANIM_BulletBill_Anim05, \
    .hit    = ANIM_BulletBill_Anim05, \
    .anim_8 = ANIM_BulletBill_Anim01, \
    .anim_9 = ANIM_BulletBill_Anim01, \
    .anim_A = ANIM_BulletBill_Anim01, \
    .anim_B = ANIM_BulletBill_Anim01, \
    .anim_C = ANIM_BulletBill_Anim01, \
    .anim_D = ANIM_BulletBill_Anim01, \
    .anim_E = ANIM_BulletBill_Anim01, \
    .anim_F = ANIM_BulletBill_Anim01, \
}

#define BULLET_BILL_NPC(npcID) \
{ \
    .id = npcID, \
    .settings = &N(NpcSettings_BulletBill), \
    .pos = { NPC_DISPOSE_LOCATION }, \
    .yaw = 270, \
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_80000, \
    .initVarCount = 1, \
    .initVar = { .value = 0 }, \
    .drops = BULLET_BILL_DROPS, \
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
    .animations = BULLET_BILL_ANIMS, \
}
