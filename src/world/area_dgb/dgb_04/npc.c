#include "dgb_04.h"

#define AI_SENTINEL_FIRST_NPC NPC_Sentinel
#define AI_SENTINEL_LAST_NPC  NPC_Sentinel
#include "world/common/enemy/Sentinel.inc.c"

NpcData N(NpcData_Sentinel) = {
    .id = NPC_Sentinel,
    .pos = { 70.0f, -220.0f, 186.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 70, -220, 186 },
            .wanderSize = { 15, 40 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 80, -220, 170 },
            .detectSize = { 80, 150 },
        }
    },
    .settings = &N(NpcSettings_Sentinel),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = SENTINEL_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Sentinel)),
    {}
};
