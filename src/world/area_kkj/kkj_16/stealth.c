#include "kkj_16.h"
#include "sprite/player.h"

Vec3f N(TwinkHide1)[] = {
    { -752.0,    60.0,  -55.0 },
    { -755.0,   120.0,  -60.0 },
    { -770.0,   140.0, -130.0 },
};

Vec3f N(TwinkFollowPath1)[] = {
    { -770.0,   140.0, -130.0 },
    { -755.0,   135.0,  -90.0 },
    { -670.0,   110.0,  -80.0 },
};

Vec3f N(TwinkFollowPath2)[] = {
    { -670.0,   110.0,  -80.0 },
    { -630.0,   100.0,  -80.0 },
    { -470.0,    90.0,  -80.0 },
};

EvtScript N(EVS_ApproachPeach) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Sub(LVar0, 10)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetNpcVar, NPC_HammerBros, 0, 1)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Sub(LVar0, 26)
        Sub(LVar2, 2)
        Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim07)
        Call(SetNpcSpeed, NPC_HammerBros, Float(5.0))
        Call(NpcMoveTo, NPC_HammerBros, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim02)
        Call(NpcFacePlayer, NPC_HammerBros, 5)
        Call(SetNpcVar, NPC_HammerBros, 0, 0)
    EndThread
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar0, 26)
        Add(LVar2, 2)
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim06)
        Call(SetNpcSpeed, NPC_Koopatrol_01, Float(5.0))
        Call(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
        Call(NpcFacePlayer, NPC_Koopatrol_01, 5)
    EndThread
    Loop(0)
        Wait(1)
        Call(GetNpcVar, NPC_HammerBros, 0, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(10)
    Return
    End
};

EvtScript N(EVS_PickUpPeach) = {
    Thread
        Call(GetNpcPos, NPC_HammerBros, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Call(NpcMoveTo, NPC_HammerBros, LVar0, LVar2, 5)
        Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim13)
        Add(LVar0, 5)
        Call(NpcMoveTo, NPC_HammerBros, LVar0, LVar2, 5)
    EndThread
    Thread
        Call(GetNpcPos, NPC_Koopatrol_01, LVar0, LVar1, LVar2)
        Sub(LVar0, 5)
        Call(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 5)
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim12)
        Sub(LVar0, 5)
        Call(NpcMoveTo, NPC_Koopatrol_01, LVar0, LVar2, 5)
    EndThread
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPlayerAnimation, ANIM_Peach2_Gasp)
    Wait(1)
    Loop(4)
        Add(LVar1, 2)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(SetPlayerAnimation, ANIM_Peach2_Carried)
    Add(LVar0, 10)
    Loop(5)
        Add(LVar1, 4)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_CarryPeachAway) = {
    Call(InterpNpcYaw, NPC_Koopatrol_01, 90, 3)
    Wait(10)
    Thread
        Loop(0)
            Call(GetNpcPos, NPC_HammerBros, LVar0, LVar1, LVar2)
            Add(LVar0, 32)
            Add(LVar2, 2)
            Call(SetPlayerPos, LVar0, 30, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcVar, NPC_HammerBros, 0, 1)
    Thread
        Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim08)
        Call(SetNpcSpeed, NPC_HammerBros, Float(5.0))
        Call(NpcMoveTo, NPC_HammerBros, -606, -57, 0)
        Call(SetNpcPos, NPC_HammerBros, 354, 0, 0)
        Call(SetNpcVar, NPC_HammerBros, 0, 0)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim14)
        Call(SetNpcSpeed, NPC_Koopatrol_01, Float(5.0))
        Call(NpcMoveTo, NPC_Koopatrol_01, -574, -53, 0)
        Call(SetNpcPos, NPC_Koopatrol_01, 386, 0, 0)
    EndThread
    Loop(0)
        Wait(1)
        Call(GetNpcVar, NPC_HammerBros, 0, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_ManageSneakingScenes) = {
    IfEq(AF_KKJ_07, FALSE)
        Call(DisablePlayerInput, TRUE)
        Call(DisablePartnerAI, 1)
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_006C)
        Set(AF_KKJ_07, TRUE)
        Call(EnablePartnerAI)
        Call(DisablePlayerInput, FALSE)
    EndIf
    Loop(0)
        Wait(1)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLe(LVar0, -770)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    Thread
        Call(SetMusic, 0, SONG_PEACH_SNEAKING, 0, VOL_LEVEL_FULL)
        Wait(3)
        Call(SetMusic, 0, SONG_PEACH_SNEAKING, 0, VOL_LEVEL_7)
        Wait(3)
        Call(SetMusic, 0, SONG_PEACH_SNEAKING, 0, VOL_LEVEL_6)
        Wait(3)
        Call(SetMusic, 0, SONG_PEACH_SNEAKING, 0, VOL_LEVEL_5)
        Wait(3)
        Call(SetMusic, 0, SONG_PEACH_SNEAKING, 0, VOL_LEVEL_4)
    EndThread
    Call(SetPlayerAnimation, ANIM_Peach2_Startle)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 30, EMOTER_PLAYER, 0, 0, 0, 0)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Thread
        Call(NpcFlyTo, NPC_PARTNER, -776, 50, -65, 10 * DT, 0, EASING_LINEAR)
    EndThread
    Thread
        Call(PlayerMoveTo, -778, -55, 10 * DT)
        Call(InterpPlayerYaw, 185, 0)
    EndThread
    Call(SpeakToNpc, NPC_HammerBros, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, NPC_Koopatrol_01, MSG_Peach_006E)
    Call(SpeakToNpc, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, NPC_HammerBros, MSG_Peach_006F)
    Call(SpeakToNpc, NPC_HammerBros, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, NPC_Koopatrol_01, MSG_Peach_0070)
    Call(SpeakToNpc, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, NPC_HammerBros, MSG_Peach_0071)
    Call(SpeakToNpc, NPC_HammerBros, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, NPC_Koopatrol_01, MSG_Peach_0072)
    Call(SpeakToNpc, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, NPC_HammerBros, MSG_Peach_0073)
    Call(SpeakToNpc, NPC_HammerBros, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, NPC_Koopatrol_01, MSG_Peach_0074)
    Call(SpeakToNpc, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, NPC_HammerBros, MSG_Peach_0075)
    Call(SpeakToNpc, NPC_HammerBros, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, NPC_Koopatrol_01, MSG_Peach_0076)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-10.5))
    Call(SetCamPosA, CAM_DEFAULT, -775, -50)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_BattleBow_Talk, ANIM_Peach1_Idle, 5, MSG_Peach_0077)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 5, MSG_Peach_0078)
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Call(SpeakToNpc, NPC_HammerBros, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, NPC_Koopatrol_01, MSG_Peach_0079)
    Call(SpeakToNpc, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, NPC_HammerBros, MSG_Peach_007A)
    Thread
        Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim07)
        Call(NpcMoveTo, NPC_HammerBros, -820, 50, 30 * DT)
        Call(SetNpcAnimation, NPC_HammerBros, ANIM_HammerBros_Anim02)
        Call(NpcFacePlayer, NPC_HammerBros, 0)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim06)
        Call(NpcMoveTo, NPC_Koopatrol_01, -840, 10, 30 * DT)
        Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
        Call(NpcFacePlayer, NPC_Koopatrol_01, 0)
    EndThread
    Thread
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Cringe)
        Call(LoadPath, 20 * DT, Ref(N(TwinkHide1)), ARRAY_COUNT(N(TwinkHide1)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(NpcFacePlayer, NPC_PARTNER, 0)
    EndThread
    Thread
        Wait(10 * DT)
        Call(SetPlayerAnimation, ANIM_Peach2_Gasp)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetPlayerJumpscale, Float(1.0))
        Call(PlayerJump1, LVar0, LVar1, LVar2, 10 * DT)
    EndThread
    Wait(30 * DT)
    Call(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, MSG_Peach_007B)
    Call(SpeakToPlayer, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_Peach_007C)
    ExecWait(N(EVS_ApproachPeach))
    ExecWait(N(EVS_PickUpPeach))
    ExecWait(N(EVS_CarryPeachAway))
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Carried, ANIM_Peach2_Carried, 5, MSG_Peach_007D)
    Wait(10 * DT)
    Call(LoadPath, 40 * DT, Ref(N(TwinkFollowPath1)), ARRAY_COUNT(N(TwinkFollowPath1)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_TalkSad)
    Loop(2)
        Call(InterpNpcYaw, NPC_PARTNER, 270, 7 * DT)
        Wait(5 * DT)
        Call(InterpNpcYaw, NPC_PARTNER, 90, 7 * DT)
        Wait(5 * DT)
    EndLoop
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Idle)
    Thread
        Call(LoadPath, 30 * DT, Ref(N(TwinkFollowPath2)), ARRAY_COUNT(N(TwinkFollowPath2)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(15 * DT)
    Call(FadeOutMusic, 0, 1000 * DT)
    ExecWait(N(EVS_EndPeachChapter2))
    Call(EnablePartnerAI)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
