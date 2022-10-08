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
            .centerPos  = { -75, 0, -30 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 1000 },
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
};

StaticNpc N(NpcData_ParaTroopa_01) = {
    .id = NPC_ParaTroopa_01,
    .settings = &N(NpcSettings_ParaTroopa),
    .pos = { 0.0f, 50.0f, 30.0f },
    .yaw = 270,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_40000,
    .init = &N(EVS_NpcInit_KoopaTroopa),
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
};

StaticNpc N(NpcData_ParaTroopa_02) = {
    .id = NPC_ParaTroopa_02,
    .settings = &N(NpcSettings_ParaTroopa),
    .pos = { 75.0f, 50.0f, -30.0f },
    .yaw = 270,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_40000,
    .init = &N(EVS_NpcInit_KoopaTroopa),
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
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_KoopaTroopa), BTL_TRD_PART_1_FORMATION_01, BTL_TRD_PART_1_STAGE_03),
    NPC_GROUP(N(NpcData_ParaTroopa_01), BTL_TRD_PART_1_FORMATION_08, BTL_TRD_PART_1_STAGE_03),
    NPC_GROUP(N(NpcData_ParaTroopa_02), BTL_TRD_PART_1_FORMATION_0A, BTL_TRD_PART_1_STAGE_03),
    {}
};
