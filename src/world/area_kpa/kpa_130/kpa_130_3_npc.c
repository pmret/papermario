#include "kpa_130.h"

#include "world/common/enemy/complete/BombshellBill.h"

#include "world/common/enemy/ai/BulletBillAI.inc.c"

GuardAISettings N(D_80240B50_AA3870) = {
    .playerSearchInterval = 30,
};

EvtScript N(D_80240B74_AA3894) = {
    EVT_CALL(N(BillBlasterAI_Main), EVT_PTR(N(D_80240B50_AA3870)))
    EVT_RETURN
    EVT_END
};

MobileAISettings N(D_80240B94_AA38B4) = {
    .chaseSpeed = 3.0f,
    .unk_AI_2C = 1,
};

EvtScript N(D_80240BC4_AA38E4) = {
    EVT_CALL(SelfEnemyOverrideSyncPos, 1)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(N(BulletBillAI_Main), EVT_PTR(N(D_80240B94_AA38B4)))
    EVT_RETURN
    EVT_END
};

GuardAISettings N(AISettings_BillBlaster) = {
    .playerSearchInterval = 10,
};

EvtScript N(EVS_NpcAI_BillBlaster) = {
    EVT_CALL(N(BillBlasterAI_Main), EVT_PTR(N(AISettings_BillBlaster)))
    EVT_RETURN
    EVT_END
};

MobileAISettings N(AISettings_BulletBill) = {
    .chaseSpeed = 7.3f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_BulletBill) = {
    EVT_CALL(SelfEnemyOverrideSyncPos, 1)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(N(BulletBillAI_Main), EVT_PTR(N(AISettings_BulletBill)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_BillBlaster) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
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

EvtScript N(D_80240D94_AA3AB4) = {
    EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(DoNpcDefeat)
            EVT_CALL(SetSelfVar, 0, 0)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(D_80240BC4_AA38E4)))
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(OnPlayerFled, 0)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_BulletBill) = {
    EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetSelfVar, 0, 100)
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

NpcSettings N(missing_80240F50) = {
    .height = 26,
    .radius = 32,
    .level = 10,
    .ai = &N(D_80240B74_AA3894),
    .onHit = &EnemyNpcHit,
    .onDefeat = &N(EVS_NpcDefeat_BillBlaster),
};

NpcSettings N(missing_80240F7C) = {
    .height = 14,
    .radius = 31,
    .level = 5,
    .ai = &N(D_80240BC4_AA38E4),
    .onHit = &EnemyNpcHit,
    .onDefeat = &N(D_80240D94_AA3AB4),
};


NpcSettings N(NpcSettings_BillBlaster) = {
    .height = 26,
    .radius = 32,
    .level = 27,
    .ai = &N(EVS_NpcAI_BillBlaster),
    .onHit = &EnemyNpcHit,
    .onDefeat = &N(EVS_NpcDefeat_BillBlaster),
};

NpcSettings N(NpcSettings_BulletBill) = {
    .height = 14,
    .radius = 31,
    .level = 24,
    .ai = &N(EVS_NpcAI_BulletBill),
    .onHit = &EnemyNpcHit,
    .onDefeat = &N(EVS_NpcDefeat_BulletBill),
};

EvtScript N(EVS_NpcInit_BillBlaster) = {
    EVT_CALL(SetSelfVar, 1, -995)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_BillBlaster_03) = {
    EVT_CALL(SetSelfVar, 1, 30)
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_BillBlaster_01)[] = {
    {
        .id = NPC_BillBlaster_01,
        .settings = &N(NpcSettings_BillBlaster),
        .pos = { -288.0f, 120.0f, 120.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_BillBlaster),
        .drops = BOMBSHELL_BLASTER_NO_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = BOMBSHELL_BLASTER_ANIMS,
    },
    {
        .id = NPC_BillBlaster_02,
        .settings = &N(NpcSettings_BillBlaster),
        .pos = { -288.0f, 120.0f, 78.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_BillBlaster),
        .drops = BOMBSHELL_BLASTER_NO_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = BOMBSHELL_BLASTER_ANIMS,
    },
};

StaticNpc N(NpcData_BillBlaster_03)[] = {
    {
        .id = NPC_BillBlaster_03,
        .settings = &N(NpcSettings_BillBlaster),
        .pos = { -748.0f, 300.0f, -22.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_BillBlaster_03),
        .drops = BOMBSHELL_BLASTER_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = BOMBSHELL_BLASTER_ANIMS,
    },
    {
        .id = NPC_BillBlaster_04,
        .settings = &N(NpcSettings_BillBlaster),
        .pos = { -748.0f, 300.0f, 22.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_BillBlaster_03),
        .drops = BOMBSHELL_BLASTER_NO_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = BOMBSHELL_BLASTER_ANIMS,
    },
};

StaticNpc N(NpcData_BillBlaster_05)[] = {
    {
        .id = NPC_BillBlaster_05,
        .settings = &N(NpcSettings_BillBlaster),
        .pos = { 30.0f, 480.0f, -122.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_BillBlaster),
        .drops = BOMBSHELL_BLASTER_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = BOMBSHELL_BLASTER_ANIMS,
    },
    {
        .id = NPC_BillBlaster_06,
        .settings = &N(NpcSettings_BillBlaster),
        .pos = { 30.0f, 480.0f, -78.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_BillBlaster),
        .drops = BOMBSHELL_BLASTER_NO_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = BOMBSHELL_BLASTER_ANIMS,
    },
};

StaticNpc N(NpcData_BillBlaster_07)[] = {
    {
        .id = NPC_BillBlaster_07,
        .settings = &N(NpcSettings_BillBlaster),
        .pos = { 820.0f, 600.0f, -122.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_BillBlaster),
        .drops = BOMBSHELL_BLASTER_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = BOMBSHELL_BLASTER_ANIMS,
    },
    {
        .id = NPC_BillBlaster_08,
        .settings = &N(NpcSettings_BillBlaster),
        .pos = { 820.0f, 600.0f, -78.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_BillBlaster),
        .drops = BOMBSHELL_BLASTER_NO_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = BOMBSHELL_BLASTER_ANIMS,
    },
};

StaticNpc N(NpcData_BulletBill_01) = BOMBSHELL_BILL_NPC(NPC_BulletBill_01);
StaticNpc N(NpcData_BulletBill_02) = BOMBSHELL_BILL_NPC(NPC_BulletBill_02);
StaticNpc N(NpcData_BulletBill_03) = BOMBSHELL_BILL_NPC(NPC_BulletBill_03);
StaticNpc N(NpcData_BulletBill_04) = BOMBSHELL_BILL_NPC(NPC_BulletBill_04);
StaticNpc N(NpcData_BulletBill_05) = BOMBSHELL_BILL_NPC(NPC_BulletBill_05);
StaticNpc N(NpcData_BulletBill_06) = BOMBSHELL_BILL_NPC(NPC_BulletBill_06);
StaticNpc N(NpcData_BulletBill_07) = BOMBSHELL_BILL_NPC(NPC_BulletBill_07);
StaticNpc N(NpcData_BulletBill_08) = BOMBSHELL_BILL_NPC(NPC_BulletBill_08);
StaticNpc N(NpcData_BulletBill_09) = BOMBSHELL_BILL_NPC(NPC_BulletBill_09);
StaticNpc N(NpcData_BulletBill_10) = BOMBSHELL_BILL_NPC(NPC_BulletBill_10);

// the following NPCs are unused
StaticNpc N(NpcData_BulletBill_11) = BOMBSHELL_BILL_NPC(NPC_BulletBill_11);
StaticNpc N(NpcData_BulletBill_12) = BOMBSHELL_BILL_NPC(NPC_BulletBill_12);
StaticNpc N(NpcData_BulletBill_13) = BOMBSHELL_BILL_NPC(NPC_BulletBill_13);
StaticNpc N(NpcData_BulletBill_14) = BOMBSHELL_BILL_NPC(NPC_BulletBill_14);
StaticNpc N(NpcData_BulletBill_15) = BOMBSHELL_BILL_NPC(NPC_BulletBill_15);
StaticNpc N(NpcData_BulletBill_16) = BOMBSHELL_BILL_NPC(NPC_BulletBill_16);
StaticNpc N(NpcData_BulletBill_17) = BOMBSHELL_BILL_NPC(NPC_BulletBill_17);
StaticNpc N(NpcData_BulletBill_18) = BOMBSHELL_BILL_NPC(NPC_BulletBill_18);
StaticNpc N(NpcData_BulletBill_19) = BOMBSHELL_BILL_NPC(NPC_BulletBill_19);
StaticNpc N(NpcData_BulletBill_20) = BOMBSHELL_BILL_NPC(NPC_BulletBill_20);

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_BillBlaster_01), BTL_KPA4_FORMATION_02, BTL_KPA4_STAGE_04),
    NPC_GROUP(N(NpcData_BillBlaster_03), BTL_KPA4_FORMATION_02, BTL_KPA4_STAGE_05),
    NPC_GROUP(N(NpcData_BillBlaster_05), BTL_KPA4_FORMATION_03, BTL_KPA4_STAGE_05),
    NPC_GROUP(N(NpcData_BillBlaster_07), BTL_KPA4_FORMATION_04, BTL_KPA4_STAGE_05),
    NPC_GROUP(N(NpcData_BulletBill_01), BTL_KPA4_FORMATION_01, BTL_KPA4_STAGE_04),
    NPC_GROUP(N(NpcData_BulletBill_02), BTL_KPA4_FORMATION_01, BTL_KPA4_STAGE_04),
    NPC_GROUP(N(NpcData_BulletBill_03), BTL_KPA4_FORMATION_01, BTL_KPA4_STAGE_04),
    NPC_GROUP(N(NpcData_BulletBill_04), BTL_KPA4_FORMATION_01, BTL_KPA4_STAGE_04),
    NPC_GROUP(N(NpcData_BulletBill_05), BTL_KPA4_FORMATION_01, BTL_KPA4_STAGE_04),
    NPC_GROUP(N(NpcData_BulletBill_06), BTL_KPA4_FORMATION_01, BTL_KPA4_STAGE_04),
    NPC_GROUP(N(NpcData_BulletBill_07), BTL_KPA4_FORMATION_01, BTL_KPA4_STAGE_04),
    NPC_GROUP(N(NpcData_BulletBill_08), BTL_KPA4_FORMATION_01, BTL_KPA4_STAGE_04),
    NPC_GROUP(N(NpcData_BulletBill_09), BTL_KPA4_FORMATION_01, BTL_KPA4_STAGE_04),
    NPC_GROUP(N(NpcData_BulletBill_10), BTL_KPA4_FORMATION_01, BTL_KPA4_STAGE_04),
    {}
};
