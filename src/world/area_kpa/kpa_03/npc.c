#include "kpa_03.h"

#include "world/common/enemy/Koopatrol_Wander.inc.c"
#include "world/common/enemy/SpikeTop.inc.c"
#include "world/common/enemy/Magikoopa.inc.c"

AnimID N(ExtraAnims_Koopatrol)[] = {
    ANIM_WorldKoopatrol_Anim01,
    ANIM_WorldKoopatrol_Anim04,
    ANIM_WorldKoopatrol_Anim06,
    ANIM_WorldKoopatrol_Anim10,
    ANIM_WorldKoopatrol_Anim0B,
    ANIM_LIST_END
};

NpcData N(NpcData_Koopatrol_01) = {
    .id = NPC_Koopatrol_01,
    .pos = { 1045.0f, -255.0f, -194.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 1045, -255, -194 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 1045, -255, -194 },
            .detectSize = { 300 },
        }
    },
    .settings = &N(NpcSettings_Koopatrol_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = KOOPATROL_DROPS,
    .animations = KOOPATROL_ANIMS,
    .extraAnimations = N(ExtraAnims_Koopatrol),
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Koopatrol_02) = {
    .id = NPC_Koopatrol_02,
    .pos = { 950.0f, -265.0f, 0.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 950, -265, 0 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 950, -265, 0 },
            .detectSize = { 300 },
        }
    },
    .settings = &N(NpcSettings_Koopatrol_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = KOOPATROL_DROPS,
    .animations = KOOPATROL_ANIMS,
    .extraAnimations = N(ExtraAnims_Koopatrol),
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_BonyBeetle_01) = {
    .id = NPC_BonyBeetle_01,
    .pos = { -940.0f, 140.0f, -145.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -940, 140, -145 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -940, 140, -145 },
            .detectSize = { 300 },
        }
    },
    .settings = &N(NpcSettings_BonyBeetle),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = BONY_BEETLE_DROPS_ALT,
    .animations = BONY_BEETLE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_BonyBeetle_02) = {
    .id = NPC_BonyBeetle_02,
    .pos = { 175.0f, -130.0f, 0.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 175, -130, 0 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 175, -130, 0 },
            .detectSize = { 300 },
        }
    },
    .settings = &N(NpcSettings_BonyBeetle),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = BONY_BEETLE_DROPS,
    .animations = BONY_BEETLE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Magikoopa_01)[] = {
    {
        .id = NPC_Magikoopa_01,
        .pos = { -1000.0f, -160.0f, -150.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = false,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -1000, -160, -150 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -1000, -160, -150 },
                .detectSize = { 200 },
            }
        },
        .settings = &N(NpcSettings_Magikoopa),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = MAGINO_DROPS,
        .animations = MAGIKOOPA_ANIMS,
        .extraAnimations = N(ExtraAnims_Magikoopa),
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    MAGIKOOPA_SPELL_HITBOX(NPC_Magikoopa_01_Spell),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Koopatrol_01), BTL_KPA_FORMATION_20, BTL_KPA_STAGE_03),
    NPC_GROUP(N(NpcData_Koopatrol_02), BTL_KPA_FORMATION_1F, BTL_KPA_STAGE_03),
    NPC_GROUP(N(NpcData_BonyBeetle_01), BTL_KPA_FORMATION_01, BTL_KPA_STAGE_03),
    NPC_GROUP(N(NpcData_BonyBeetle_02), BTL_KPA_FORMATION_04, BTL_KPA_STAGE_03),
    NPC_GROUP(N(NpcData_Magikoopa_01), BTL_KPA_FORMATION_2F, BTL_KPA_STAGE_03),
    {}
};
