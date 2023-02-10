#include "jan_06.h"

#include "world/common/enemy/complete/JungleFuzzy_Wander.inc.c"
#include "world/common/enemy/complete/HeartPlant.inc.c"
#include "world/common/enemy/complete/HurtPlant.inc.c"
#include "world/common/enemy/complete/SpearGuy_Wander.inc.c"

s32 N(ExtraAnims_JungleFuzzy)[] = {
    ANIM_Fuzzy_Blue_Idle,
    ANIM_Fuzzy_Blue_Walk,
    ANIM_Fuzzy_Blue_Run,
    ANIM_Fuzzy_Blue_Hurt,
    -1
};

StaticNpc N(NpcData_JungleFuzzy) = {
    .id = NPC_JungleFuzzy,
    .settings = &N(NpcSettings_JungleFuzzy_Wander),
    .pos = { 310.0f, 24.0f, 35.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_400000,
    .drops = JUNGLE_FUZZY_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 310, 24, 35 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 310, 24, 35 },
            .detectSize = { 150 },
        }
    },
    .animations = JUNGLE_FUZZY_ANIMS,
    .extraAnimations = N(ExtraAnims_JungleFuzzy),
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

s32 N(ExtraAnims_SpearGuy_Custom)[] = {
    ANIM_SpearGuy_Anim03,
    ANIM_SpearGuy_Anim04,
    ANIM_SpearGuy_Anim05,
    ANIM_SpearGuy_Anim06,
    ANIM_SpearGuy_Anim0F,
    ANIM_SpearGuy_Anim10,
    ANIM_SpearGuy_Anim07,
    ANIM_SpearGuy_Anim08,
    ANIM_SpearGuy_Anim09,
    ANIM_SpearGuy_Anim0D,
    ANIM_SpearGuy_Anim1A,
    ANIM_SpearGuy_Anim1B,
    -1
};

StaticNpc N(NpcData_SpearGuy)[] = {
    {
        .id = NPC_SpearGuy,
        .pos = { -298.0f, 35.0f, 37.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -298, 0, 37 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -298, 0, 37 },
                .detectSize = { 150 },
            }
        },
        .settings = &N(NpcSettings_SpearGuy_Wander),
        .flags = ENEMY_FLAG_400 | ENEMY_FLAG_400000,
        .drops = SPEAR_GUY_DROPS,
        .animations = SPEAR_GUY_ANIMS,
        .extraAnimations = N(ExtraAnims_SpearGuy_Custom),
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    SPEAR_GUY_HITBOX(NPC_SpearGuy_Hitbox),
};

StaticNpc N(NpcData_HeartPlant) = {
    .id = NPC_HeartPlant,
    .pos = { 410.0f, 0.0f, -30.0f },
    .yaw = 270,
    .settings = &N(NpcSettings_HeartPlant),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_8000 | ENEMY_FLAG_400000,
    .drops = NPC_NO_DROPS,
    .animations = HEART_PLANT_ANIMS,
    .tattle = MSG_NpcTattle_HeartPlant,
};

StaticNpc N(NpcData_HurtPlant_01) = {
    .id = NPC_HurtPlant_01,
    .pos = { 110.0f, 0.0f, 55.0f },
    .yaw = 90,
    .settings = &N(NpcSettings_HurtPlant),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_8000 | ENEMY_FLAG_400000,
    .drops = HURT_PLANT_DROPS,
    .animations = HURT_PLANT_ANIMS,
    .tattle = MSG_NpcTattle_HeartPlant,
};

StaticNpc N(NpcData_HurtPlant_02) = {
    .id = NPC_HurtPlant_02,
    .pos = { -430.0f, 0.0f, -80.0f },
    .yaw = 90,
    .settings = &N(NpcSettings_HurtPlant),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_8000 | ENEMY_FLAG_400000,
    .drops = HURT_PLANT_DROPS,
    .animations = HURT_PLANT_ANIMS,
    .tattle = MSG_NpcTattle_HeartPlant,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_JungleFuzzy), BTL_JAN_FORMATION_0D, BTL_JAN_STAGE_01),
    NPC_GROUP(N(NpcData_SpearGuy), BTL_JAN_FORMATION_02, BTL_JAN_STAGE_01),
    NPC_GROUP(N(NpcData_HeartPlant)),
    NPC_GROUP(N(NpcData_HurtPlant_01), BTL_JAN_FORMATION_08, BTL_JAN_STAGE_01),
    NPC_GROUP(N(NpcData_HurtPlant_02), BTL_JAN_FORMATION_08, BTL_JAN_STAGE_01),
    {}
};
