#include "kpa_08.h"

#include "world/common/enemy/Magikoopa.inc.c"

NpcData N(NpcData_Magikoopa)[] = {
    {
        .id = NPC_Magikoopa,
        .pos = { -210.0f, 0.0f, 25.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = true,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { -210, 0, 25 },
                .wanderSize = { 30, 10 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -210, 0, 25 },
                .detectSize = { 200 },
            }
        },
        .settings = &N(NpcSettings_Magikoopa),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = MAGINO_DROPS,
        .animations = MAGIKOOPA_ANIMS,
        .extraAnimations = N(ExtraAnims_Magikoopa),
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    MAGIKOOPA_SPELL_HITBOX(NPC_Magikoopa_Spell)
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Magikoopa), BTL_KPA_FORMATION_2B, BTL_KPA_STAGE_01),
    {}
};
