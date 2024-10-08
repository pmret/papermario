#include "tik_09.h"

#include "world/common/enemy/DarkTroopa_Wander.inc.c"

#include "world/common/util/GetDefeatedEnemyCount.inc.c"

EvtScript N(EVS_OpenGates) = {
    Call(MakeLerp, 0, 60, 25, EASING_COS_IN_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_ew_kousi, 0, LVar0, 0)
        Call(TranslateModel, MODEL_ee_kousi, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o58, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o59, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_DarkTroopa) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(N(GetDefeatedEnemyCount), LVar0)
            IfEq(LVar0, 1)
                Set(GF_TIK09_Defeated_Ambush, TRUE)
                Exec(N(EVS_SpawnSwitch))
                Exec(N(EVS_OpenGates))
            EndIf
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_DarkTroopa) = {
    IfEq(GF_TIK09_Defeated_Ambush, FALSE)
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_DarkTroopa)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
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
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DELAY_AFTER_FLEE,
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
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DELAY_AFTER_FLEE,
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
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DELAY_AFTER_FLEE,
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
