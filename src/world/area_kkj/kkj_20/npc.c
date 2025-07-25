#include "kkj_20.h"
#include "sprite/player.h"

#include "world/common/npc/Toad_Stationary.inc.c"

#include "world/common/complete/ToadHouseBlanketAnim.inc.c"
#include "world/common/atomic/ToadHouse.inc.c"
#include "world/common/atomic/ToadHouse.data.inc.c"

#include "world/common/todo/GetPeachDisguise.inc.c"

EvtScript N(EVS_OpenDresserDoors) = {
    Call(PlaySoundAtCollider, COLLIDER_o80, SOUND_WOODEN_DOOR_OPEN, 0)
    Call(MakeLerp, 0, 80, 14, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_g16, LVar0, 0, 1, 0)
        Call(RotateGroup, MODEL_g15, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_CloseDresserDoors) = {
    Call(MakeLerp, 80, 0, 14, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_g16, LVar0, 0, 1, 0)
        Call(RotateGroup, MODEL_g15, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_o80, SOUND_WOODEN_DOOR_CLOSE, 0)
    Return
    End
};

EvtScript N(EVS_ShakeDresser) = {
    Loop(0)
        Call(TranslateGroup, MODEL_g9, 1, 0, 0)
        Wait(1)
        Call(TranslateGroup, MODEL_g9, -1, 0, 0)
        Wait(1)
        Call(TranslateGroup, MODEL_g9, 0, 0, 0)
        Wait(30)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_Inspect_Dresser_Peach) = {
    Call(N(GetPeachDisguise), LVar0)
    IfNe(LVar0, PEACH_DISGUISE_NONE)
        Call(DisablePlayerInput, true)
        Call(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_Peach_0185)
        Call(DisablePlayerInput, false)
        Return
    EndIf
    IfNe(GF_KKJ20_PeachMet_ToadInHiding, false)
        Call(DisablePlayerInput, true)
        Call(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_Peach_0185)
        Call(DisablePlayerInput, false)
        Return
    EndIf
    Call(SetNpcVar, NPC_Toad, 0, 0)
    Call(DisablePlayerInput, true)
    Call(SetCamProperties, CAM_DEFAULT, Float(4.0), -10, 0, 80, Float(300.0), Float(17.0), Float(-10.0))
    Thread
        Call(SetPlayerSpeed, Float(2.0))
        Call(PlayerMoveTo, -50, 0, 0)
        Call(InterpPlayerYaw, 90, 5)
        Call(func_802CF56C, 2)
    EndThread
    Wait(10)
    Exec(N(EVS_OpenDresserDoors))
    Wait(30)
    Call(SetNpcJumpscale, NPC_Toad, Float(1.0))
    Call(NpcJump0, NPC_Toad, -10, 0, -40, 15)
    Call(SetNpcAnimation, NPC_Toad, ANIM_Toad_Red_Walk)
    Call(NpcMoveTo, NPC_Toad, 30, 0, 20)
    Call(SetNpcAnimation, NPC_Toad, ANIM_Toad_Red_Idle)
    Call(InterpNpcYaw, NPC_Toad, 270, 5)
    Wait(10)
    Call(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_Peach_0182)
    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    Wait(10)
    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0183)
    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    Wait(10)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_Peach_0184)
    Call(SetNpcAnimation, NPC_Toad, ANIM_Toad_Red_Walk)
    Call(SetNpcSpeed, NPC_Toad, Float(3.0))
    Call(NpcMoveTo, NPC_Toad, -10, -60, 0)
    Call(SetNpcAnimation, NPC_Toad, ANIM_Toad_Red_Idle)
    Wait(10)
    Call(NpcJump0, NPC_Toad, -10, 30, -132, 10)
    Exec(N(EVS_CloseDresserDoors))
    Wait(30)
    Set(GF_KKJ20_PeachMet_ToadInHiding, true)
    Call(ResetCam, CAM_DEFAULT, Float(4.0))
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    IfEq(GF_KKJ20_Met_ToadInHiding, false)
        Set(LVar0, MSG_Peach_0187)
        Set(LVar8, MSG_Peach_0188)
        Set(GF_KKJ20_Met_ToadInHiding, true)
    Else
        Set(LVar0, MSG_Peach_0189)
        Set(LVar8, MSG_Peach_018A)
    EndIf
    Set(LVar1, MSG_Peach_018B)
    Set(LVar2, MSG_Peach_018C)
    Set(LVar3, MSG_Peach_018D)
    Return
    End
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    Exec(N(EVS_PlayRestingSong))
    Call(SetPlayerSpeed, Float(3.0))
    Call(PlayerMoveTo, 50, -40, 0)
    Thread
        Wait(20)
        Call(N(ToadHouse_CamSetFOV), 0, 40)
        Call(SetCamType, CAM_DEFAULT, 4, false)
        Call(SetCamDistance, CAM_DEFAULT, Float(200.0))
        Call(SetCamPitch, CAM_DEFAULT, Float(70.0), Float(-30.0))
        Call(SetCamPosA, CAM_DEFAULT, Float(-260.0), Float(270.0))
        Call(SetCamPosB, CAM_DEFAULT, Float(30.0), Float(-85.0))
        Call(SetCamPosC, CAM_DEFAULT, 0, Float(-50.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
    EndThread
    Call(PlayerMoveTo, 95, -87, 0)
    Call(InterpPlayerYaw, 229, 1)
    Call(HidePlayerShadow, true)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_GET_IN_BED, 1, 1, 0)
    Thread
        Wait(60)
        Call(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    EndThread
    Wait(20)
    Thread
        Wait(65)
        Call(N(ToadHouse_CamSetFOV), 0, 25)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Wait(1)
    EndThread
    Return
    End
};

EvtScript N(EVS_ToadHouse_ReturnFromRest) = {
    Call(HidePlayerShadow, false)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetPlayerPos, 85, 0, -85)
    Call(SetPlayerSpeed, Float(3.0))
    Call(PlayerMoveTo, 60, -50, 0)
    Exec(N(EVS_PlayBowserSong))
    Return
    End
};

EvtScript N(EVS_MeetToadHouseKeeper) = {
    Call(N(ToadHouse_InitScreenOverlay), 0, 0, 0)
    ExecWait(N(EVS_ToadHouse_SetDialogue))
    Set(LVar9, LVar1)
    Set(LVarA, LVar2)
    Set(LVarB, LVar3)
    Call(N(ToadHouse_DoesPlayerNeedSleep))
    IfEq(LVar1, 0)
        Set(LVar8, LVar0)
    EndIf
    Call(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar8)
    Call(ShowChoice, MSG_Choice_0006)
    Wait(10)
    IfEq(LVar0, 1)
        Call(ContinueSpeech, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar9)
        Return
    EndIf
    Call(ContinueSpeech, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVarA)
    Call(SetPlayerJumpscale, 1)
    Call(DisablePlayerPhysics, true)
    Call(SetNpcFlagBits, NPC_Toad, NPC_FLAG_IGNORE_PLAYER_COLLISION, true)
    Call(N(ToadHouse_DisableStatusBar))
    IfNe(LVar4, 0)
        Exec(N(EVS_ToadHouse_Unk2))
    EndIf
    Call(N(ToadHouse_PutPartnerAway), LVarA)
    Wait(20)
    ExecGetTID(N(EVS_ToadHouse_GetInBed), LVar9)
    Call(N(ToadHouse_AwaitScriptComplete), LVar9)
    Thread
        Call(MakeLerp, 0, 255, 60, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(N(ToadHouse_UpdateScreenOverlay), 3, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(FullyRestoreHPandFP)
        Call(FullyRestoreSP)
        IfNe(LVar4, 0)
            Exec(N(EVS_ToadHouse_Unk1))
        EndIf
        Call(N(ToadHouse_GetPartnerBackOut), LVarA)
        Wait(30)
        Call(MakeLerp, 255, 0, 30, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(N(ToadHouse_UpdateScreenOverlay), 0, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(90)
    ExecGetTID(N(EVS_ToadHouse_ReturnFromRest), LVar9)
    Call(N(ToadHouse_AwaitScriptComplete), LVar9)
    Call(DisablePlayerPhysics, false)
    Call(SetNpcFlagBits, NPC_Toad, NPC_FLAG_IGNORE_PLAYER_COLLISION, false)
    Call(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVarB)
    Call(N(ToadHouse_ShowWorldStatusBar))
    Return
    End
};

EvtScript N(EVS_Inspect_Dresser_Mario) = {
    Call(SetNpcVar, NPC_Toad, 0, 0)
    Call(DisablePlayerInput, true)
    Exec(N(EVS_OpenDresserDoors))
    Wait(30)
    Call(SetNpcJumpscale, NPC_Toad, Float(1.0))
    Call(NpcJump0, NPC_Toad, -10, 0, -40, 15)
    Call(PlayerFaceNpc, NPC_Toad, false)
    Call(NpcFaceNpc, NPC_PARTNER, NPC_Toad, 0)
    Exec(N(EVS_CloseDresserDoors))
    Call(SetNpcAnimation, NPC_Toad, ANIM_Toad_Red_Walk)
    Call(NpcMoveTo, NPC_Toad, 30, 0, 20)
    Call(SetNpcAnimation, NPC_Toad, ANIM_Toad_Red_Idle)
    Call(InterpNpcYaw, NPC_Toad, 270, 5)
    Wait(10)
    Call(UseSettingsFrom, CAM_DEFAULT, -10, 0, 80)
    Call(SetPanTarget, CAM_DEFAULT, -10, 0, 80)
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Call(SetCamPitch, CAM_DEFAULT, Float(18.0), Float(-11.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(func_802D1270, -50, 0, Float(2.5))
    Call(InterpPlayerYaw, 90, 5)
    Call(func_802CF56C, 2)
    Wait(10)
    Call(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_Peach_0186)
    Call(GetNpcPos, NPC_Toad, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_Toad, LVar0, LVar1, LVar2, 10)
    ExecWait(N(EVS_MeetToadHouseKeeper))
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Call(DisablePlayerInput, false)
    Unbind
    Return
    End
};

EvtScript N(EVS_NpcIdle_Toad) = {
    Call(WaitForPlayerInputEnabled)
    Call(DisablePlayerInput, true)
    Call(DisablePartnerAI, 1)
    Call(SetNpcJumpscale, NPC_PARTNER, Float(0.5))
    Call(NpcJump0, NPC_PARTNER, -86, 40, -25, 15)
    Wait(10)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_Peach_0181)
    Call(NpcFlyTo, NPC_PARTNER, -165, 55, -25, 20, -5, EASING_LINEAR)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad) = {
    ExecWait(N(EVS_NpcInteract_ToadHouseKeeper))
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad) = {
    Switch(GB_StoryProgress)
        CaseOrEq(STORY_CH4_BEGAN_PEACH_MISSION)
        CaseOrEq(STORY_CH5_BEGAN_PEACH_MISSION)
        CaseOrEq(STORY_CH6_BEGAN_PEACH_MISSION)
            Call(SetNpcPos, NPC_SELF, -10, 30, -132)
            Call(SetNpcYaw, NPC_SELF, 270)
            IfEq(GF_KKJ20_PeachMet_ToadInHiding, false)
                Call(SetSelfVar, 0, 1)
                Exec(N(EVS_ShakeDresser))
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Toad)))
            EndIf
            BindTrigger(Ref(N(EVS_Inspect_Dresser_Peach)), TRIGGER_WALL_PRESS_A, COLLIDER_o80, 1, 0)
        EndCaseGroup
        CaseDefault
            IfEq(GF_KKJ20_Met_ToadInHiding, false)
                Call(SetNpcPos, NPC_SELF, -10, 30, -132)
                Call(SetSelfVar, 0, 1)
                Exec(N(EVS_ShakeDresser))
                BindTrigger(Ref(N(EVS_Inspect_Dresser_Mario)), TRIGGER_WALL_PRESS_A, COLLIDER_o80, 1, 0)
            Else
                Call(SetNpcPos, NPC_SELF, 30, 0, 0)
            EndIf
            Call(SetNpcYaw, NPC_SELF, 270)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad)))
    EndSwitch
    Return
    End
};

NpcData N(NpcData_Toad) = {
    .id = NPC_Toad,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Toad),
    .settings = &N(NpcSettings_Toad_Stationary),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = TOAD_RED_ANIMS,
    .tattle = MSG_NpcTattle_KKJ_ToadHouseToad,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Toad)),
    {}
};
