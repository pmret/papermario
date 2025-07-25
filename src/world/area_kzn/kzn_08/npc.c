#include "kzn_08.h"

#include "world/common/enemy/LavaBubble.inc.c"
#include "world/common/enemy/PutridPiranha.inc.c"

NpcData N(NpcData_PutridPiranha)[] = {
    {
        .id = NPC_PutridPiranha,
        .pos = { 80.0f, 0.0f, 135.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = false,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 80, 0, 135 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 90, 0, 130 },
                .detectSize = { 130, 60 },
            }
        },
        .settings = &N(NpcSettings_PutridPiranha),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = PUTRID_PIRANHA_DROPS,
        .animations = PUTRID_PIRANHA_ANIMS,
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    PUTRID_PIRANHA_HITBOX(NPC_Piranha_Hitbox),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_PutridPiranha), BTL_KZN_FORMATION_11, BTL_KZN_STAGE_04),
    {}
};
