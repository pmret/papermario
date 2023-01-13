#include "dgb_07.h"

#define INCLUDE_CLUBBA_NAPPING
#include "world/common/enemy/complete/Clubba_Multi.inc.c"

StaticNpc N(NpcData_Clubba_01)[] = {
    {
        .id = NPC_Clubba_01,
        .settings = &N(NpcSettings_Clubba_Napping),
        .pos = { -500.0f, 0.0f, -240.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_800,
        .drops = CLUBBA_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -500, 0, -240 },
                .wanderSize = { 40 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -500, 0, -240 },
                .detectSize = { 200 },
            }
        },
        .animations = CLUBBA_ANIMS,
        .extraAnimations = N(ExtraAnims_Clubba),
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    CLUBBA_MACE_HITBOX(NPC_Clubba_01_Hitbox),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Clubba_01), BTL_DGB_FORMATION_01, BTL_DGB_STAGE_02),
    {}
};
