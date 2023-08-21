#include "trd_07.h"

extern EvtScript N(EVS_RestoreMagicDoors);

#include "world/common/enemy/KoopaTroopa_Wander.inc.c"
#include "world/common/enemy/Paratroopa.inc.c"

#include "world/common/util/GetDefeatedEnemyCount.inc.c"

EvtScript N(EVS_NpcDefeat_KoopaTroopa) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(N(GetDefeatedEnemyCount), LVar0)
            EVT_IF_EQ(LVar0, 1) // ???
                EVT_SET(GF_TRD07_Defeated_DungeonAmbush, TRUE)
                EVT_EXEC(N(EVS_RestoreMagicDoors))
            EVT_END_IF
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(OnPlayerFled, 0)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaTroopa) = {
    EVT_CALL(SetSelfEnemyFlags, ENEMY_FLAG_NO_DROPS)
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_KoopaTroopa)))
    EVT_IF_EQ(GF_TRD07_Defeated_DungeonAmbush, TRUE)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_KoopaTroopa) = {
    .id = NPC_KoopaTroopa,
    .pos = { -75.0f, 0.0f, -30.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -75, 0, -30 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 1000 },
        }
    },
    .init = &N(EVS_NpcInit_KoopaTroopa),
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
    .drops = KOOPA_TROOPA_TRD_DROPS,
    .animations = KOOPA_TROOPA_ANIMS,
};

NpcData N(NpcData_ParaTroopa_01) = {
    .id = NPC_ParaTroopa_01,
    .pos = { 0.0f, 50.0f, 30.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 50, 30 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 50, 30 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_KoopaTroopa),
    .settings = &N(NpcSettings_ParaTroopa),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
    .drops = PARATROOPA_DROPS,
    .animations = PARATROOPA_ANIMS,
};

NpcData N(NpcData_ParaTroopa_02) = {
    .id = NPC_ParaTroopa_02,
    .pos = { 75.0f, 50.0f, -30.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 75, 50, -30 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 75, 50, -30 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_KoopaTroopa),
    .settings = &N(NpcSettings_ParaTroopa),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
    .drops = PARATROOPA_DROPS,
    .animations = PARATROOPA_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_KoopaTroopa), BTL_TRD_1_FORMATION_01, BTL_TRD_1_STAGE_03),
    NPC_GROUP(N(NpcData_ParaTroopa_01), BTL_TRD_1_FORMATION_08, BTL_TRD_1_STAGE_03),
    NPC_GROUP(N(NpcData_ParaTroopa_02), BTL_TRD_1_FORMATION_0A, BTL_TRD_1_STAGE_03),
    {}
};
