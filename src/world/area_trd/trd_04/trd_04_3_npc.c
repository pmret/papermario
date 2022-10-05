#include "trd_04.h"

extern EvtScript N(EVS_80245198);

#include "world/common/enemy/complete/KoopaTroopa_Wander.inc.c"
#include "world/common/enemy/complete/KoopaTroopa_Patrol.inc.c"
#include "world/common/enemy/complete/Paratroopa.inc.c"

EvtScript N(EVS_NpcDefeat_KoopaTroopa) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(GB_StoryProgress, STORY_CH1_DEFEATED_BASEMENT_GUARD)
            EVT_THREAD
                EVT_CALL(DoNpcDefeat)
            EVT_END_THREAD
            EVT_EXEC_WAIT(N(EVS_80245198))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaTroopa) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_DEFEATED_BASEMENT_GUARD)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_KoopaTroopa)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_KoopaTroopa_Wander) = {
    .id = NPC_KoopaTroopa,
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .pos = { 0.0f, 0.0f, 125.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_MUSHROOM, 5, 0 },
            { ITEM_P_O_W_BLOCK, 5, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 1,
        .maxCoinBonus = 1,
    },
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 125 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 125 },
            .detectSize = { 200 },
        }
    },
    .animations = {
        .idle   = ANIM_KoopaTroopa_Anim01,
        .walk   = ANIM_KoopaTroopa_Anim03,
        .run    = ANIM_KoopaTroopa_Anim04,
        .chase  = ANIM_KoopaTroopa_Anim04,
        .anim_4 = ANIM_KoopaTroopa_Anim01,
        .anim_5 = ANIM_KoopaTroopa_Anim01,
        .death  = ANIM_KoopaTroopa_Anim0B,
        .hit    = ANIM_KoopaTroopa_Anim0B,
        .anim_8 = ANIM_KoopaTroopa_Anim07,
        .anim_9 = ANIM_KoopaTroopa_Anim06,
        .anim_A = ANIM_KoopaTroopa_Anim08,
        .anim_B = ANIM_KoopaTroopa_Anim04,
        .anim_C = ANIM_KoopaTroopa_Anim04,
        .anim_D = ANIM_KoopaTroopa_Anim04,
        .anim_E = ANIM_KoopaTroopa_Anim04,
        .anim_F = ANIM_KoopaTroopa_Anim04,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_KoopaTroopa_Patrol) = {
    .id = NPC_KoopaTroopa,
    .settings = &N(NpcSettings_KoopaTroopa_Patrol),
    .pos = { 220.0f, 0.0f, 30.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_NO_DROPS,
    .init = &N(EVS_NpcInit_KoopaTroopa),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .territory = {
        .patrol = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 2,
            .points  = {
                { 220, 0, 30 },
                { 240, 0, 160 },
            },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 220, 0, 30 },
            .detectSize = { 200 },
        }
    },
    .animations = {
        .idle   = ANIM_KoopaTroopa_Anim01,
        .walk   = ANIM_KoopaTroopa_Anim03,
        .run    = ANIM_KoopaTroopa_Anim04,
        .chase  = ANIM_KoopaTroopa_Anim04,
        .anim_4 = ANIM_KoopaTroopa_Anim01,
        .anim_5 = ANIM_KoopaTroopa_Anim01,
        .death  = ANIM_KoopaTroopa_Anim0B,
        .hit    = ANIM_KoopaTroopa_Anim0B,
        .anim_8 = ANIM_KoopaTroopa_Anim07,
        .anim_9 = ANIM_KoopaTroopa_Anim06,
        .anim_A = ANIM_KoopaTroopa_Anim08,
        .anim_B = ANIM_KoopaTroopa_Anim04,
        .anim_C = ANIM_KoopaTroopa_Anim04,
        .anim_D = ANIM_KoopaTroopa_Anim04,
        .anim_E = ANIM_KoopaTroopa_Anim04,
        .anim_F = ANIM_KoopaTroopa_Anim04,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_ParaTroopa) = {
    .id = NPC_ParaTroopa,
    .settings = &N(NpcSettings_ParaTroopa),
    .pos = { -5.0f, 237.0f, 157.0f },
    .yaw = 270,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_P_O_W_BLOCK, 10, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 1,
        .maxCoinBonus = 1,
    },
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -5, 237, 157 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -5, 237, 157 },
            .detectSize = { 200 },
        }
    },
    .animations = {
        .idle   = ANIM_ParaTroopa_Anim01,
        .walk   = ANIM_ParaTroopa_Anim02,
        .run    = ANIM_ParaTroopa_Anim03,
        .chase  = ANIM_ParaTroopa_Anim03,
        .anim_4 = ANIM_ParaTroopa_Anim01,
        .anim_5 = ANIM_ParaTroopa_Anim01,
        .death  = ANIM_ParaTroopa_Anim06,
        .hit    = ANIM_ParaTroopa_Anim06,
        .anim_8 = ANIM_ParaTroopa_Anim04,
        .anim_9 = ANIM_ParaTroopa_Anim0C,
        .anim_A = ANIM_ParaTroopa_Anim0A,
        .anim_B = ANIM_ParaTroopa_Anim0E,
        .anim_C = ANIM_ParaTroopa_Anim03,
        .anim_D = ANIM_ParaTroopa_Anim03,
        .anim_E = ANIM_ParaTroopa_Anim03,
        .anim_F = ANIM_ParaTroopa_Anim03,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(NpcGroupAfter) = {
    NPC_GROUP(N(NpcData_KoopaTroopa_Wander), BTL_TRD_PART_1_FORMATION_05, BTL_TRD_PART_1_STAGE_0C),
    NPC_GROUP(N(NpcData_ParaTroopa), BTL_TRD_PART_1_FORMATION_0D, BTL_TRD_PART_1_STAGE_05),
    {}
};

NpcGroupList N(NpcGroupBefore) = {
    NPC_GROUP(N(NpcData_KoopaTroopa_Patrol), BTL_TRD_PART_1_FORMATION_05, BTL_TRD_PART_1_STAGE_0C),
    NPC_GROUP(N(NpcData_ParaTroopa), BTL_TRD_PART_1_FORMATION_0D, BTL_TRD_PART_1_STAGE_05),
    {}
};
