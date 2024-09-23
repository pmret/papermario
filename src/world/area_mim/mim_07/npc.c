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
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(mim_07_ENTRY_0)
            UseBuf(Ref(N(D_80242944_BACA84)))
        CaseEq(mim_07_ENTRY_1)
            UseBuf(Ref(N(D_80242944_BACA84)))
        CaseEq(mim_07_ENTRY_2)
            UseBuf(Ref(N(D_8024294C_BACA8C)))
        CaseEq(mim_07_ENTRY_3)
            UseBuf(Ref(N(D_80242954_BACA94)))
    EndSwitch
    BufRead2(LVar1, LVar2)
    Call(AwaitPlayerApproach, LVar1, LVar2, 80)
    Label(10)
    Wait(1)
    Call(AwaitPlayerLeave, LVar1, LVar2, 100)
    Call(IsPlayerWithin, 0, 0, 410, LVar0)
    IfEq(LVar0, 0)
        Goto(10)
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        Call(InterruptUsePartner)
        Wait(20)
    EndIf
    ExecWait(N(EVS_JrTroopaMusic))
    Call(GetPlayerPos, LVar1, LVar2, LVar3)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(mim_07_ENTRY_0)
            IfLt(LVar1, 0)
                UseBuf(Ref(N(D_8024295C_BACA9C)))
            Else
                UseBuf(Ref(N(D_8024296C_BACAAC)))
            EndIf
        CaseEq(mim_07_ENTRY_2)
            IfLt(LVar1, 0)
                UseBuf(Ref(N(D_8024297C_BACABC)))
            Else
                UseBuf(Ref(N(D_8024298C_BACACC)))
            EndIf
        CaseEq(mim_07_ENTRY_3)
            IfLt(LVar3, 0)
                UseBuf(Ref(N(D_8024299C_BACADC)))
            Else
                UseBuf(Ref(N(D_802429AC_BACAEC)))
            EndIf
    EndSwitch
    BufRead4(LVar2, LVar3, LVar4, LVar5)
    Call(SetSelfVar, 0, LVar2)
    Call(SetSelfVar, 1, LVar3)
    Call(SetNpcPos, NPC_SELF, LVar2, 0, LVar3)
    Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle, 0, MSG_CH3_0018)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar0, LVar4)
        Add(LVar2, LVar5)
        Div(LVar0, 2)
        Div(LVar2, 2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
        Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
        Call(SetCamPitch, CAM_DEFAULT, Float(20.0), Float(-6.0))
        Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    EndThread
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Run)
    Call(NpcMoveTo, NPC_SELF, LVar4, LVar5, 30)
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Idle)
    Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle, 0, MSG_CH3_0019)
    Call(DisablePartnerAI, 0)
    Call(GetCurrentPartnerID, LVar0)
    Switch(LVar0)
        CaseEq(PARTNER_GOOMBARIO)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_CH3_001A)
        CaseEq(PARTNER_KOOPER)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 5, MSG_CH3_001B)
        CaseEq(PARTNER_BOMBETTE)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 5, MSG_CH3_001C)
        CaseEq(PARTNER_PARAKARRY)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, MSG_CH3_001D)
        CaseEq(PARTNER_BOW)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 5, MSG_CH3_001E)
    EndSwitch
    Call(EnablePartnerAI)
    Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle, 0, MSG_CH3_001F)
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_ChargeArmsUp)
    Call(DisablePlayerInput, FALSE)
    Call(StartBossBattle, SONG_JR_TROOPA_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_JrTroopa) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle, 0, MSG_CH3_0022)
    Call(GetSelfVar, 0, LVar0)
    Call(GetSelfVar, 1, LVar1)
    IfGe(LVar1, 0)
        Call(InterpNpcYaw, NPC_SELF, 200, 0)
    Else
        Call(InterpNpcYaw, NPC_SELF, 330, 0)
    EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_ChargeArmsUp)
    Wait(10 * DT)
    Call(NpcMoveTo, NPC_SELF, LVar0, LVar1, 15)
    Set(GF_MIM10_Defeated_JrTroopa, TRUE)
    ExecWait(N(EVS_PlayForestMusic))
    Call(ResetCam, CAM_DEFAULT, Float(4.0 / DT))
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_NpcInit_JrTroopa) = {
    IfGe(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        IfEq(GF_MIM10_Defeated_JrTroopa, FALSE)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_JrTroopa)))
            Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_JrTroopa)))
            Return
        EndIf
    EndIf
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_NpcInit_Fuzzy) = {
    IfGe(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        IfEq(GF_MIM10_Defeated_JrTroopa, FALSE)
            Call(RemoveNpc, NPC_SELF)
        EndIf
    EndIf
    Return
    End
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
