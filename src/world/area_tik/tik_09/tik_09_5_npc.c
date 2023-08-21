#include "tik_09.h"

#include "world/common/enemy/DarkTroopa_Wander.inc.c"

#include "world/common/util/GetDefeatedEnemyCount.inc.c"

EvtScript N(EVS_OpenGates) = {
    EVT_CALL(MakeLerp, 0, 60, 25, EASING_COS_IN_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_ew_kousi, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_ee_kousi, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o58, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o59, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_DarkTroopa) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(N(GetDefeatedEnemyCount), LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET(GF_TIK09_Defeated_Ambush, TRUE)
                EVT_EXEC(N(EVS_SpawnSwitch))
                EVT_EXEC(N(EVS_OpenGates))
            EVT_END_IF
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_DarkTroopa) = {
    EVT_IF_EQ(GF_TIK09_Defeated_Ambush, FALSE)
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_DarkTroopa)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_KoopaTroopa_01) = {
    .id = NPC_KoopaTroopa_01,
    .pos = { -80.0f, -10.0f, 0.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -80, -10, 0 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -80, -10, 0 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_DarkTroopa),
    .settings = &N(NpcSettings_DarkTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
    .drops = DARK_TROOPA_DROPS,
    .animations = DARK_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_KoopaTroopa_02) = {
    .id = NPC_KoopaTroopa_02,
    .pos = { 60.0f, -10.0f, 0.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 60, -10, 0 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 60, -10, 0 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_DarkTroopa),
    .settings = &N(NpcSettings_DarkTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
    .drops = DARK_TROOPA_DROPS,
    .animations = DARK_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_KoopaTroopa_03) = {
    .id = NPC_KoopaTroopa_03,
    .pos = { 180.0f, -10.0f, 0.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 180, -10, 0 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 180, -10, 0 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_DarkTroopa),
    .settings = &N(NpcSettings_DarkTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
    .drops = DARK_TROOPA_DROPS,
    .animations = DARK_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_KoopaTroopa_01), BTL_TIK_FORMATION_02, BTL_TIK_STAGE_03),
    NPC_GROUP(N(NpcData_KoopaTroopa_02), BTL_TIK_FORMATION_01, BTL_TIK_STAGE_03),
    NPC_GROUP(N(NpcData_KoopaTroopa_03), BTL_TIK_FORMATION_00, BTL_TIK_STAGE_03),
    {}
};
