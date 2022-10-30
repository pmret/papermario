#include "flo_09.h"

#include "world/common/enemy/complete/CrazyDayzee.inc.c"

#include "world/common/enemy/complete/Bzzap.inc.c"

NpcSettings N(NpcSettings_Bzzap_02) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

EvtScript N(EVS_NpcAI_Bzzap_02) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                EVT_IF_GT(LVar1, 0)
                    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                    EVT_CALL(SetNpcJumpscale, NPC_SELF, 0)
                    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 50, LVar2, 15)
                    EVT_CALL(SetSelfVar, 0, 1)
                    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Bzzap)))
                EVT_END_IF
            EVT_CASE_EQ(2)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_WAIT(25)
                EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_2, FALSE)
                EVT_CALL(SetSelfVar, 0, 0)
                EVT_CALL(DisablePlayerInput, FALSE)
        EVT_END_SWITCH
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Bzzap_02) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetSelfVar, 0, 2)
            EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Bzzap_02)))
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bzzap_02) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Bzzap_02)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Bzzap_02)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Dayzee_01) = {
    .id = NPC_Dayzee_01,
    .settings = &N(NpcSettings_CrazyDayzee),
    .pos = { -350.0f, 0.0f, 40.0f },
    .yaw = 90,
    .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .drops = CRAZY_DAYZEE_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -350, 0, 40 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -350, 0, 40 },
            .detectSize = { 200 },
        }
    },
    .animations = CRAZY_DAYZEE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_Dayzee_02) = {
    .id = NPC_Dayzee_02,
    .settings = &N(NpcSettings_CrazyDayzee),
    .pos = { 260.0f, 0.0f, 75.0f },
    .yaw = 270,
    .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .drops = CRAZY_DAYZEE_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 260, 0, 75 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 260, 0, 75 },
            .detectSize = { 200 },
        }
    },
    .animations = CRAZY_DAYZEE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_Bzzap_01) = {
    .id = NPC_Bzzap_01,
    .settings = &N(NpcSettings_Bzzap),
    .pos = { -50.0f, 55.0f, 90.0f },
    .yaw = 90,
    .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .drops = BZZAP_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -50, 55, 90 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -50, 50, 90 },
            .detectSize = { 250 },
        }
    },
    .animations = BZZAP_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_Bzzap_02) = {
    .id = NPC_Bzzap_02,
    .settings = &N(NpcSettings_Bzzap_02),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .flags = NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .init = &N(EVS_NpcInit_Bzzap_02),
    .drops = BZZAP_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -50, 55, 90 },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -50, 50, 90 },
            .detectSize = { 250 },
        }
    },
    .animations = BZZAP_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Dayzee_01), BTL_FLO_FORMATION_10, BTL_FLO_STAGE_04),
    NPC_GROUP(N(NpcData_Dayzee_02), BTL_FLO_FORMATION_15, BTL_FLO_STAGE_04),
    NPC_GROUP(N(NpcData_Bzzap_01), BTL_FLO_FORMATION_17, BTL_FLO_STAGE_01),
    NPC_GROUP(N(NpcData_Bzzap_02), BTL_FLO_FORMATION_17, BTL_FLO_STAGE_01),
    {}
};
