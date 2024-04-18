#include "flo_15.h"
#include "sprite/player.h"

#include "world/common/npc/Sun.inc.c"

EvtScript N(EVS_Sun_AnimateBobbing) = {
    IfLt(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        Set(LVar3, 7)
        Set(LVar4, 5)
    Else
        Set(LVar3, 15)
        Set(LVar4, 1)
    EndIf
    Loop(0)
        Set(LVar5, LVar3)
        Loop(LVar5)
            Call(GetNpcPos, NPC_Sun_01, LVar0, LVar1, LVar2)
            Add(LVar1, 1)
            Call(SetNpcPos, NPC_Sun_01, LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_Sun_02, LVar0, LVar1, LVar2)
            Wait(LVar4)
        EndLoop
        Set(LVar5, LVar3)
        Loop(LVar5)
            Call(GetNpcPos, NPC_Sun_01, LVar0, LVar1, LVar2)
            Add(LVar1, -1)
            Call(SetNpcPos, NPC_Sun_01, LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_Sun_02, LVar0, LVar1, LVar2)
            Wait(LVar4)
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_SunReturns) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetNpcPos, NPC_Sun_01, 0, 270, 0)
    Call(SetNpcPos, NPC_Sun_02, NPC_DISPOSE_LOCATION)
    Wait(1)
    Call(GetNpcPos, NPC_Sun_01, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 1050)
    Call(SetCamPitch, CAM_DEFAULT, Float(10.0), Float(4.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-10.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(6.5))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Sun_01, ANIM_Sun_TalkJoy, ANIM_Sun_TalkJoy, SPEECH_FLAG_200 | 5, MSG_CH6_00C3)
    Call(SetNpcAnimation, NPC_Sun_01, ANIM_Sun_TalkJoy)
    Thread
        Call(SetCamDistance, CAM_DEFAULT, 1000)
        Call(SetCamSpeed, CAM_DEFAULT, Float(5.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    EndThread
    Wait(15)
    Call(SetNpcJumpscale, NPC_Sun_01, Float(0.0))
    Call(GetNpcPos, NPC_Sun_01, LVar0, LVar1, LVar2)
    Add(LVar1, 400)
    Call(NpcJump0, NPC_Sun_01, LVar0, LVar1, LVar2, 40)
    Call(GotoMap, Ref("flo_00"), flo_00_ENTRY_9)
    Wait(70)
    Return
    End
};

EvtScript N(EVS_NpcAux_Sun_02) = {
    Call(SetNpcRotationPivot, NPC_Sun_02, 48)
    Loop(0)
        Call(MakeLerp, -30, 30, 20, EASING_SIN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_Sun_02, 0, 0, LVar0)
            Call(GetNpcPos, NPC_Sun_01, LVar2, LVar3, LVar4)
            Call(SetNpcPos, NPC_Sun_02, LVar2, LVar3, LVar4)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, 30, -30, 20, EASING_SIN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_Sun_02, 0, 0, LVar0)
            Call(GetNpcPos, NPC_Sun_01, LVar2, LVar3, LVar4)
            Call(SetNpcPos, NPC_Sun_02, LVar2, LVar3, LVar4)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_Sun_DescendFromSky) = {
    Loop(0)
        Wait(1)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfGt(LVar1, 220)
            BreakLoop
        EndIf
    EndLoop
    Thread
        Wait(15)
        Call(PlayerFaceNpc, NPC_Sun_01, FALSE)
    EndThread
    Call(SetNpcJumpscale, NPC_Sun_01, Float(0.0))
    Call(GetNpcPos, NPC_Sun_01, LVar0, LVar1, LVar2)
    Sub(LVar1, 400)
    Call(NpcJump0, NPC_Sun_01, LVar0, 275, LVar2, 30)
    ExecGetTID(N(EVS_Sun_AnimateBobbing), LVar9)
    Loop(0)
        Wait(1)
        IfEq(AF_FLO_MetTheSun, TRUE)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Wait(10)
    KillThread(LVar9)
    Call(SetNpcFlagBits, NPC_Sun_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(GetNpcPos, NPC_Sun_01, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_Sun_01, LVar0, 450, LVar2, 30)
    Call(DisablePlayerInput, FALSE)
    Unbind
    Return
    End
};

EvtScript N(EVS_NpcInteract_Sun_01) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_SPOKE_WITH_THE_SUN)
            Call(SpeakToPlayer, NPC_Sun_01, ANIM_Sun_TalkSad, ANIM_Sun_Idle, 517, MSG_CH6_009A)
            Call(SetPlayerAnimation, ANIM_Mario1_Thinking)
            Wait(20)
            Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
            Wait(20)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
            Call(SpeakToPlayer, NPC_Sun_01, ANIM_Sun_TalkSad, ANIM_Sun_Idle, 517, MSG_CH6_009B)
            Set(GB_StoryProgress, STORY_CH6_SPOKE_WITH_THE_SUN)
        CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            Call(SpeakToPlayer, NPC_Sun_01, ANIM_Sun_TalkSad, ANIM_Sun_Idle, 517, MSG_CH6_009C)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            IfEq(GF_FLO15_SunThankedPlayer, FALSE)
                Call(SpeakToPlayer, NPC_Sun_01, ANIM_Sun_TalkSad, ANIM_Sun_Idle, 517, MSG_CH6_009D)
                Set(GF_FLO15_SunThankedPlayer, TRUE)
            Else
                Call(SpeakToPlayer, NPC_Sun_01, ANIM_Sun_TalkSad, ANIM_Sun_Idle, 517, MSG_CH6_009E)
            EndIf
        CaseDefault
            Call(SpeakToPlayer, NPC_Sun_01, ANIM_Sun_TalkSad, ANIM_Sun_Idle, 517, MSG_CH6_009F)
    EndSwitch
    Set(AF_FLO_MetTheSun, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Sun_01) = {
    Call(SetNpcCollisionSize, NPC_Sun_01, 64, 40)
    Call(EnableNpcShadow, NPC_Sun_01, FALSE)
    IfLt(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        Call(SetNpcPos, NPC_Sun_01, 0, 270, 0)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Sun_01)))
        Exec(N(EVS_Sun_AnimateBobbing))
    Else
        Call(SetNpcPos, NPC_Sun_01, 0, 450, 0)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Sun_01)))
        Set(AF_FLO_MetTheSun, FALSE)
        Exec(N(EVS_Sun_DescendFromSky))
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Sun_02) = {
    Call(EnableNpcShadow, NPC_Sun_02, FALSE)
    Call(SetNpcAnimation, NPC_Sun_02, ANIM_Sun_FireIdle)
    Call(SetNpcPaletteSwapMode, NPC_Sun_01, NPC_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
    Call(SetNpcPaletteSwapMode, NPC_Sun_02, NPC_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
    Call(SetNpcPaletteSwapping, NPC_Sun_01, 0, 1, 5, 5, 13, 5, 0, 0)
    Call(SetNpcPaletteSwapping, NPC_Sun_02, 0, 1, 5, 5, 13, 5, 0, 0)
    IfLt(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        Call(SetNpcPos, NPC_Sun_02, 0, 270, -5)
    Else
        Call(SetNpcPos, NPC_Sun_02, 0, 450, -5)
        Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Sun_02)))
    EndIf
    Return
    End
};

NpcData N(NpcData_Sun)[] = {
    {
        .id = NPC_Sun_01,
        .pos = { 0.0f, 250.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Sun_01),
        .settings = &N(NpcSettings_Sun),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = SUN_ANIMS,
        .tattle = MSG_NpcTattle_TheSun,
    },
    {
        .id = NPC_Sun_02,
        .pos = { 0.0f, 250.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Sun_02),
        .settings = &N(NpcSettings_Sun),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_8000,
        .drops = NO_DROPS,
        .animations = SUN_ANIMS,
        .tattle = MSG_NpcTattle_TheSun,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Sun)),
    {}
};
