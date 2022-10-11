#include "trd_07.h"

extern EvtScript N(EVS_RestoreMagicDoors);

#include "world/common/enemy/complete/KoopaTroopa_Wander.inc.c"
#include "world/common/enemy/complete/Paratroopa.inc.c"

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
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAGS_10, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaTroopa) = {
    EVT_CALL(SetSelfEnemyFlags, ENEMY_FLAGS_800000)
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_KoopaTroopa)))
    EVT_IF_EQ(GF_TRD07_Defeated_DungeonAmbush, TRUE)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_KoopaTroopa) = {
    .id = NPC_KoopaTroopa,
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .pos = { -75.0f, 0.0f, -30.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_40000,
    .init = &N(EVS_NpcInit_KoopaTroopa),
    .drops = KOOPA_TROOPA_DROPS,
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
    .animations = KOOPA_TROOPA_ANIMS,
};

StaticNpc N(NpcData_ParaTroopa_01) = {
    .id = NPC_ParaTroopa_01,
    .settings = &N(NpcSettings_ParaTroopa),
    .pos = { 0.0f, 50.0f, 30.0f },
    .yaw = 270,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_40000,
    .init = &N(EVS_NpcInit_KoopaTroopa),
    .drops = PARATROOPA_DROPS,
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
    .animations = PARATROOPA_ANIMS,
};

StaticNpc N(NpcData_ParaTroopa_02) = {
    .id = NPC_ParaTroopa_02,
    .settings = &N(NpcSettings_ParaTroopa),
    .pos = { 75.0f, 50.0f, -30.0f },
    .yaw = 270,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_40000,
    .init = &N(EVS_NpcInit_KoopaTroopa),
    .drops = PARATROOPA_DROPS,
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
    .animations = PARATROOPA_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_KoopaTroopa), BTL_TRD_PART_1_FORMATION_01, BTL_TRD_PART_1_STAGE_03),
    NPC_GROUP(N(NpcData_ParaTroopa_01), BTL_TRD_PART_1_FORMATION_08, BTL_TRD_PART_1_STAGE_03),
    NPC_GROUP(N(NpcData_ParaTroopa_02), BTL_TRD_PART_1_FORMATION_0A, BTL_TRD_PART_1_STAGE_03),
    {}
};
