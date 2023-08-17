#include "mim_07.h"

#include "world/common/enemy/ForestFuzzy_Wander.inc.c"

NpcSettings N(NpcSettings_JrTroopa) = {
    .height = 32,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

s32 N(D_80242944_BACA84)[] = {
    0, -350,
};

s32 N(D_8024294C_BACA8C)[] = {
    0, 350,
};

s32 N(D_80242954_BACA94)[] = {
    350, 0,
};

s32 N(D_8024295C_BACA9C)[] = {
    -270, -245, -150, -310,
};

s32 N(D_8024296C_BACAAC)[] = {
    270, -245, 150, -310,
};

s32 N(D_8024297C_BACABC)[] = {
    -270, 245, -150, 310,
};

s32 N(D_8024298C_BACACC)[] = {
    270, 245, 150, 310,
};

s32 N(D_8024299C_BACADC)[] = {
    245, -270, 310, -150,
};

s32 N(D_802429AC_BACAEC)[] = {
    245, 270, 310, 150,
};

EvtScript N(EVS_NpcIdle_JrTroopa) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(mim_07_ENTRY_0)
            EVT_USE_BUF(EVT_PTR(N(D_80242944_BACA84)))
        EVT_CASE_EQ(mim_07_ENTRY_1)
            EVT_USE_BUF(EVT_PTR(N(D_80242944_BACA84)))
        EVT_CASE_EQ(mim_07_ENTRY_2)
            EVT_USE_BUF(EVT_PTR(N(D_8024294C_BACA8C)))
        EVT_CASE_EQ(mim_07_ENTRY_3)
            EVT_USE_BUF(EVT_PTR(N(D_80242954_BACA94)))
    EVT_END_SWITCH
    EVT_BUF_READ2(LVar1, LVar2)
    EVT_CALL(AwaitPlayerApproach, LVar1, LVar2, 80)
    EVT_LABEL(10)
    EVT_WAIT(1)
    EVT_CALL(AwaitPlayerLeave, LVar1, LVar2, 100)
    EVT_CALL(IsPlayerWithin, 0, 0, 410, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(InterruptUsePartner)
        EVT_WAIT(20)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_JrTroopaMusic))
    EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(mim_07_ENTRY_0)
            EVT_IF_LT(LVar1, 0)
                EVT_USE_BUF(EVT_PTR(N(D_8024295C_BACA9C)))
            EVT_ELSE
                EVT_USE_BUF(EVT_PTR(N(D_8024296C_BACAAC)))
            EVT_END_IF
        EVT_CASE_EQ(mim_07_ENTRY_2)
            EVT_IF_LT(LVar1, 0)
                EVT_USE_BUF(EVT_PTR(N(D_8024297C_BACABC)))
            EVT_ELSE
                EVT_USE_BUF(EVT_PTR(N(D_8024298C_BACACC)))
            EVT_END_IF
        EVT_CASE_EQ(mim_07_ENTRY_3)
            EVT_IF_LT(LVar3, 0)
                EVT_USE_BUF(EVT_PTR(N(D_8024299C_BACADC)))
            EVT_ELSE
                EVT_USE_BUF(EVT_PTR(N(D_802429AC_BACAEC)))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_BUF_READ4(LVar2, LVar3, LVar4, LVar5)
    EVT_CALL(SetSelfVar, 0, LVar2)
    EVT_CALL(SetSelfVar, 1, LVar3)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar2, 0, LVar3)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle, 0, MSG_CH3_0018)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, LVar4)
        EVT_ADD(LVar2, LVar5)
        EVT_DIV(LVar0, 2)
        EVT_DIV(LVar2, 2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(20.0), EVT_FLOAT(-6.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Run)
    EVT_CALL(NpcMoveTo, NPC_SELF, LVar4, LVar5, 30)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Idle)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle, 0, MSG_CH3_0019)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PARTNER_GOOMBARIO)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_CH3_001A)
        EVT_CASE_EQ(PARTNER_KOOPER)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 5, MSG_CH3_001B)
        EVT_CASE_EQ(PARTNER_BOMBETTE)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 5, MSG_CH3_001C)
        EVT_CASE_EQ(PARTNER_PARAKARRY)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, MSG_CH3_001D)
        EVT_CASE_EQ(PARTNER_BOW)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 5, MSG_CH3_001E)
    EVT_END_SWITCH
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle, 0, MSG_CH3_001F)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_ChargeArmsUp)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(StartBossBattle, SONG_JR_TROOPA_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_JrTroopa) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle, 0, MSG_CH3_0022)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_CALL(GetSelfVar, 1, LVar1)
    EVT_IF_GE(LVar1, 0)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 200, 0)
    EVT_ELSE
        EVT_CALL(InterpNpcYaw, NPC_SELF, 330, 0)
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_ChargeArmsUp)
    EVT_WAIT(10 * DT)
    EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar1, 15)
    EVT_SET(GF_MIM10_Defeated_JrTroopa, TRUE)
    EVT_EXEC_WAIT(N(EVS_PlayForestMusic))
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_JrTroopa) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_IF_EQ(GF_MIM10_Defeated_JrTroopa, FALSE)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_JrTroopa)))
            EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_JrTroopa)))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Fuzzy) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_IF_EQ(GF_MIM10_Defeated_JrTroopa, FALSE)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Fuzzy_01) = {
    .id = NPC_Fuzzy_01,
    .pos = { -240.0f, 0.0f, -240.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 400 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 400 },
        }
    },
    .init = &N(EVS_NpcInit_Fuzzy),
    .settings = &N(NpcSettings_ForestFuzzy_Wander),
    .flags = 0,
    .drops = FOREST_FUZZY_DROPS,
    .animations = FOREST_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_Fuzzy_02) = {
    .id = NPC_Fuzzy_02,
    .pos = { 270.0f, 0.0f, 200.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 400 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 400 },
        }
    },
    .init = &N(EVS_NpcInit_Fuzzy),
    .settings = &N(NpcSettings_ForestFuzzy_Wander),
    .flags = 0,
    .drops = FOREST_FUZZY_DROPS,
    .animations = FOREST_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_JrTroopa) = {
    .id = NPC_JrTroopa,
    .pos = { -338.0f, 0.0f, 0.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_JrTroopa),
    .settings = &N(NpcSettings_JrTroopa),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_JrTroopa_Idle,
        .walk   = ANIM_JrTroopa_Walk,
        .run    = ANIM_JrTroopa_Walk,
        .chase  = ANIM_JrTroopa_Walk,
        .anim_4 = ANIM_JrTroopa_Idle,
        .anim_5 = ANIM_JrTroopa_Idle,
        .death  = ANIM_JrTroopa_Idle,
        .hit    = ANIM_JrTroopa_Idle,
        .anim_8 = ANIM_JrTroopa_Idle,
        .anim_9 = ANIM_JrTroopa_Idle,
        .anim_A = ANIM_JrTroopa_Idle,
        .anim_B = ANIM_JrTroopa_Idle,
        .anim_C = ANIM_JrTroopa_Idle,
        .anim_D = ANIM_JrTroopa_Idle,
        .anim_E = ANIM_JrTroopa_Idle,
        .anim_F = ANIM_JrTroopa_Idle,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Fuzzy_01), BTL_MIM_FORMATION_02, BTL_MIM_STAGE_00),
    NPC_GROUP(N(NpcData_Fuzzy_02), BTL_MIM_FORMATION_06, BTL_MIM_STAGE_00),
    NPC_GROUP(N(NpcData_JrTroopa), BTL_KMR_3_FORMATION_04),
    {}
};
