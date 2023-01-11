#include "kpa_08.h"

#include "world/common/enemy/complete/Magikoopa.inc.c"

StaticNpc N(NpcData_Magikoopa)[] = {
    {
        .id = NPC_Magikoopa,
        .settings = &N(NpcSettings_Magikoopa),
        .pos = { -210.0f, 0.0f, 25.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .drops = MAGIKOOPA_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { -210, 0, 25 },
                .wanderSize = { 30, 10 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -210, 0, 25 },
                .detectSize = { 200 },
            }
        },
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
