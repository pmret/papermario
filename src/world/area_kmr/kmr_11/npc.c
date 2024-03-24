#include "kmr_11.h"

#include "world/common/enemy/GoombaBros_Guard.inc.c"

EvtScript N(EVS_NpcIdle_GoombaBros_01) = {
    Return
    End
};

EvtScript N(EVS_NpcIdle_GoombaBros_02) = {
    Return
    End
};

EvtScript N(EVS_NpcIdle_GoombaKing) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_DEFEATED_GOOMBA_KING)
            IfEq(GF_KMR11_GoombaBrosFledToCastle, TRUE)
                Call(GetNpcPos, NPC_GoombaKing, LVar0, LVar1, LVar2)
                Call(AwaitPlayerApproach, LVar0, LVar2, 300)
                Call(DisablePlayerInput, TRUE)
                Call(SetPlayerSpeed, Float(3.0 / DT))
                Call(PlayerMoveTo, -564, -64, 0)
            Else
                Label(0)
                Call(GetSelfVar, 0, LVar0)
                IfEq(LVar0, 0)
                    Wait(1)
                    Goto(0)
                EndIf
            EndIf
        CaseGe(STORY_CH0_DEFEATED_GOOMBA_KING)
            Return
    EndSwitch
    Call(SetNpcJumpscale, NPC_RedGoombaBro, Float(0.8))
    Call(SetNpcJumpscale, NPC_BlueGoombaBro, Float(0.8))
    Call(SetNpcJumpscale, NPC_GoombaKing, Float(0.8))
    Thread
        Call(GetNpcPos, NPC_RedGoombaBro, LVar0, LVar1, LVar2)
        Call(GetAngleToPlayer, NPC_RedGoombaBro, LVar3)
        Call(AddVectorPolar, LVar0, LVar2, Float(100.0), LVar3)
        Call(PlaySoundAtNpc, NPC_RedGoombaBro, SOUND_ACTOR_HURT, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_RedGoombaBro, LVar0, 0, LVar2, 30 * DT)
    EndThread
    Thread
        Call(GetNpcPos, NPC_BlueGoombaBro, LVar0, LVar1, LVar2)
        Call(GetAngleToPlayer, NPC_BlueGoombaBro, LVar3)
        Call(AddVectorPolar, LVar0, LVar2, Float(100.0), LVar3)
        Call(PlaySoundAtNpc, NPC_BlueGoombaBro, SOUND_ACTOR_HURT, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_BlueGoombaBro, LVar0, 0, LVar2, 30 * DT)
    EndThread
    Thread
        Call(GetNpcPos, NPC_GoombaKing, LVar0, LVar1, LVar2)
        Call(GetAngleToPlayer, NPC_GoombaKing, LVar3)
        Call(AddVectorPolar, LVar0, LVar2, Float(100.0), LVar3)
        Call(PlaySoundAtNpc, NPC_GoombaKing, SOUND_LARGE_ACTOR_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_GoombaKing, LVar0, 0, LVar2, 30 * DT)
    EndThread
    Wait(15 * DT)
    Call(StartBossBattle, SONG_GOOMBA_KING_BATTLE)
    Return
    End
};

EvtScript N(EVS_Scene_BossDefeated) = {
    Call(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_2, TRUE)
    Call(N(SetupFog))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-8.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(N(SetCameraVFov), 25)
    Call(SpeakToPlayer, NPC_GoombaKing, ANIM_GoombaKing_Walk, ANIM_GoombaKing_Idle, 0, MSG_CH0_00D1)
    Call(SetNpcSpeed, NPC_BlueGoombaBro, Float(6.0 / DT))
    Call(SetNpcSpeed, NPC_RedGoombaBro, Float(6.0 / DT))
    Call(SetNpcSpeed, NPC_GoombaKing, Float(6.0 / DT))
    Call(SetNpcAnimation, NPC_BlueGoombaBro, ANIM_GoombaBros_Blue_Run)
    Call(SetNpcAnimation, NPC_RedGoombaBro, ANIM_GoombaBros_Red_Run)
    Call(SetNpcAnimation, NPC_GoombaKing, ANIM_GoombaKing_Run)
    Thread
        Call(NpcMoveTo, NPC_GoombaKing, -358, -107, 0)
    EndThread
    Thread
        Wait(20)
        Call(NpcMoveTo, NPC_BlueGoombaBro, -396, -121, 0)
    EndThread
    Thread
        Wait(20)
        Call(NpcMoveTo, NPC_RedGoombaBro, -396, -89, 0)
    EndThread
    Wait(2)
    Call(PlaySoundAtCollider, COLLIDER_tt, SOUND_METAL_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 90, 20, EASING_COS_IN_OUT)
    Label(0)
    Call(UpdateLerp)
    Call(RotateModel, MODEL_o416, LVar0, 0, -1, 0)
    Call(RotateModel, MODEL_o415, LVar0, 0, 1, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(0)
    EndIf
    Wait(5 * DT)
    Call(MakeLerp, 90, 0, 20, EASING_COS_IN_OUT)
    Label(1)
    Call(UpdateLerp)
    Call(RotateModel, MODEL_o416, LVar0, 0, -1, 0)
    Call(RotateModel, MODEL_o415, LVar0, 0, 1, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(1)
    EndIf
    Call(PlaySoundAtCollider, COLLIDER_tt, SOUND_METAL_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(2.0))
    Set(GB_StoryProgress, STORY_CH0_DEFEATED_GOOMBA_KING)
    Exec(N(EVS_SetupMusic))
    Call(AdjustCam, CAM_DEFAULT, Float(4.0 / DT), 0, Float(250.0), Float(15.0), Float(-7.5))
    Wait(10 * DT)
    Call(DisablePartnerAI, 0)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_00D2)
    Call(EnablePartnerAI)
    Wait(10 * DT)
    Call(DisablePlayerInput, TRUE)
    Thread
        Wait(40)
        Call(ResetCam, CAM_DEFAULT, Float(4.0 / DT))
        Call(DisablePlayerInput, FALSE)
    EndThread
    Call(SetNpcPos, NPC_BlueGoombaBro, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_RedGoombaBro, NPC_DISPOSE_LOCATION)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_GoombaKing) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            ExecWait(N(EVS_Scene_BossDefeated))
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(SetPlayerSpeed, Float(6.0))
            Call(PlayerMoveTo, -954, -50, 0)
    EndSwitch
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_GoombaBros_01) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcDefeat_GoombaBros_02) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcAuxAI_Kammy) = {
    IfGe(GB_StoryProgress, STORY_CH0_KAMMY_RETURNED_TO_BOWSER)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

#define KAMMY_NPC NPC_Kammy
#include "world/common/util/GetKammyBroomEmitterPos.inc.c"

EvtScript N(EVS_NpcAux_Kammy) = {
    Label(1)
        // wait to be activated
        Call(GetSelfVar, 0, LVar0)
        Wait(1)
        IfEq(LVar0, 0)
            Goto(1)
        EndIf
    Call(GetNpcPos, NPC_Kammy, LVar6, LVar7, LVar8)
    Label(0)
        Call(N(GetKammyBroomEmitterPos))
        Call(GetNpcPos, NPC_Kammy, LVar9, LVarA, LVarB)
        EVT_VEC3I_VSET(LVar3, LVar9)
        EVT_VEC3I_VSUB(LVar3, LVar6)
        EVT_VEC3I_VSET(LVar6, LVar9)
        IfEq(LVar3, 0)
            IfEq(LVar5, 0)
            Else
                PlayEffect(EFFECT_PURPLE_RING, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.0))
            EndIf
        Else
            PlayEffect(EFFECT_PURPLE_RING, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.0))
        EndIf
        Wait(3)
        Goto(0)
    Return
    End
};

s32 N(KammyFloatingOffsets)[] = {
     1,  2,  3,  2,  1,
    -1, -2, -3, -2, -1,
};

EvtScript N(EVS_NpcAI_Kammy) = {
    Label(0)
        UseBuf(Ref(N(KammyFloatingOffsets)))
        Loop(ARRAY_COUNT(N(KammyFloatingOffsets)))
            BufRead1(LVar1)
            Call(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
            Add(LVar3, LVar1)
            Call(SetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
            Wait(3)
        EndLoop
        Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcInit_GoombaBros_01) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_GoombaBros_01)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_GoombaBros_01)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_DEFEATED_GOOMBA_KING)
            IfEq(GF_KMR11_GoombaBrosFledToCastle, TRUE)
                Call(SetNpcPos, NPC_BlueGoombaBro, -432, 130, -146)
            EndIf
        CaseGe(STORY_CH0_DEFEATED_GOOMBA_KING)
            Call(SetNpcPos, NPC_BlueGoombaBro, NPC_DISPOSE_LOCATION)
            Call(SetNpcFlagBits, NPC_BlueGoombaBro, NPC_FLAG_GRAVITY, FALSE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_GoombaBros_02) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_GoombaBros_02)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_GoombaBros_02)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_DEFEATED_GOOMBA_KING)
            IfEq(GF_KMR11_GoombaBrosFledToCastle, TRUE)
                Call(SetNpcPos, NPC_RedGoombaBro, -412, 130, -35)
            EndIf
        CaseGe(STORY_CH0_DEFEATED_GOOMBA_KING)
            Call(SetNpcPos, NPC_RedGoombaBro, NPC_DISPOSE_LOCATION)
            Call(SetNpcFlagBits, NPC_RedGoombaBro, NPC_FLAG_GRAVITY, FALSE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_GoombaKing) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_GoombaKing)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_GoombaKing)))
    Call(SetNpcCollisionSize, NPC_SELF, 70, 50)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_DEFEATED_GOOMBA_KING)
            IfEq(GF_KMR11_GoombaBrosFledToCastle, TRUE)
                Call(SetNpcPos, NPC_GoombaKing, -419, 119, -91)
            EndIf
        CaseLt(STORY_CH0_HIT_GATEHOUSE_SWITCH)
            Call(SetNpcPos, NPC_GoombaKing, -358, 0, -107)
        CaseGe(STORY_CH0_HIT_GATEHOUSE_SWITCH)
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

NpcSettings N(NpcSettings_Kammy) = {
    .defaultAnim = ANIM_WorldKammy_Anim0A,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_Kammy),
    .ai = &N(EVS_NpcAI_Kammy),
    .aux = &N(EVS_NpcAux_Kammy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
};

NpcData N(NpcData_Enemies)[] = {
    {
        .id = NPC_BlueGoombaBro,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_GoombaBros_01),
        .settings = &N(NpcSettings_GoombaBros_Guard),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_GoombaBros_Blue_Idle,
            .walk   = ANIM_GoombaBros_Blue_Walk,
            .run    = ANIM_GoombaBros_Blue_Run,
            .chase  = ANIM_GoombaBros_Blue_Run,
            .anim_4 = ANIM_GoombaBros_Blue_Idle,
            .anim_5 = ANIM_GoombaBros_Blue_Idle,
            .death  = ANIM_GoombaBros_Blue_Hurt,
            .hit    = ANIM_GoombaBros_Blue_Hurt,
            .anim_8 = ANIM_GoombaBros_Blue_Run,
            .anim_9 = ANIM_GoombaBros_Blue_Run,
            .anim_A = ANIM_GoombaBros_Blue_Run,
            .anim_B = ANIM_GoombaBros_Blue_Run,
            .anim_C = ANIM_GoombaBros_Blue_Run,
            .anim_D = ANIM_GoombaBros_Blue_Run,
            .anim_E = ANIM_GoombaBros_Blue_Run,
            .anim_F = ANIM_GoombaBros_Blue_Run,
        },
    },
    {
        .id = NPC_RedGoombaBro,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_GoombaBros_02),
        .settings = &N(NpcSettings_GoombaBros_Guard),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_GoombaBros_Red_Idle,
            .walk   = ANIM_GoombaBros_Red_Walk,
            .run    = ANIM_GoombaBros_Red_Run,
            .chase  = ANIM_GoombaBros_Red_Run,
            .anim_4 = ANIM_GoombaBros_Red_Idle,
            .anim_5 = ANIM_GoombaBros_Red_Idle,
            .death  = ANIM_GoombaBros_Red_Hurt,
            .hit    = ANIM_GoombaBros_Red_Hurt,
            .anim_8 = ANIM_GoombaBros_Red_Run,
            .anim_9 = ANIM_GoombaBros_Red_Run,
            .anim_A = ANIM_GoombaBros_Red_Run,
            .anim_B = ANIM_GoombaBros_Red_Run,
            .anim_C = ANIM_GoombaBros_Red_Run,
            .anim_D = ANIM_GoombaBros_Red_Run,
            .anim_E = ANIM_GoombaBros_Red_Run,
            .anim_F = ANIM_GoombaBros_Red_Run,
        },
    },
    {
        .id = NPC_GoombaKing,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_GoombaKing),
        .settings = &N(NpcSettings_GoombaBros_Guard),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_GoombaKing_Idle,
            .walk   = ANIM_GoombaKing_Walk,
            .run    = ANIM_GoombaKing_Run,
            .chase  = ANIM_GoombaKing_Run,
            .anim_4 = ANIM_GoombaKing_Idle,
            .anim_5 = ANIM_GoombaKing_Idle,
            .death  = ANIM_GoombaKing_Dead,
            .hit    = ANIM_GoombaKing_Dead,
            .anim_8 = ANIM_GoombaKing_Run,
            .anim_9 = ANIM_GoombaKing_Run,
            .anim_A = ANIM_GoombaKing_Run,
            .anim_B = ANIM_GoombaKing_Run,
            .anim_C = ANIM_GoombaKing_Run,
            .anim_D = ANIM_GoombaKing_Run,
            .anim_E = ANIM_GoombaKing_Run,
            .anim_F = ANIM_GoombaKing_Run,
        },
    },
};

NpcData N(NpcData_Kammy) = {
    .id = NPC_Kammy,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 100,
    .initVarCount = 1,
    .initVar = { .value = 0 },
    .settings = &N(NpcSettings_Kammy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .animations = {},
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Enemies), BTL_KMR_2_FORMATION_01),
    NPC_GROUP(N(NpcData_Kammy)),
    {}
};
