#include "kkj_15.h"
#include "sprite/player.h"

API_CALLABLE(N(SetPeachDepressed)) {
    gGameStatusPtr->peachFlags |= PEACH_FLAG_DEPRESSED;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ClearPeachDepressed)) {
    gGameStatusPtr->peachFlags &= ~PEACH_FLAG_DEPRESSED;
    return ApiStatus_DONE2;
}

Vec3f N(TwinkHideCh3Path)[] = {
    {  100.0,    50.0, -160.0 },
    {   30.0,   120.0, -120.0 },
    {   50.0,   200.0,  -80.0 },
};

Vec3f N(TwinkFollowCh3Path1)[] = {
    {   50.0,   200.0,  -70.0 },
    {   80.0,   110.0,  -70.0 },
    {  110.0,   120.0,  -70.0 },
    {  140.0,   110.0,  -70.0 },
    {  170.0,   120.0,  -70.0 },
    {  200.0,   110.0,  -70.0 },
    {  230.0,   120.0,  -70.0 },
};

Vec3f N(TwinkFollowCh3Path2)[] = {
    {  230.0,   120.0,  -70.0 },
    {  220.0,    60.0,  -70.0 },
    {  250.0,    40.0,  -70.0 },
};

EvtScript N(EVS_ApproachPeach_Ch3) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Sub(LVar0, 10)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetNpcVar, NPC_Koopatrol_03, 0, 1)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Sub(LVar0, 26)
        Sub(LVar2, 2)
        Call(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim06)
        Call(SetNpcSpeed, NPC_Koopatrol_03, Float(5.0))
        Call(NpcMoveTo, NPC_Koopatrol_03, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim01)
        Call(NpcFacePlayer, NPC_Koopatrol_03, 5)
        Call(SetNpcVar, NPC_Koopatrol_03, 0, 0)
    EndThread
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar0, 26)
        Add(LVar2, 2)
        Call(SetNpcAnimation, NPC_Koopatrol_04, ANIM_WorldKoopatrol_Anim06)
        Call(SetNpcSpeed, NPC_Koopatrol_04, Float(5.0))
        Call(NpcMoveTo, NPC_Koopatrol_04, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_Koopatrol_04, ANIM_WorldKoopatrol_Anim01)
        Call(NpcFacePlayer, NPC_Koopatrol_04, 5)
    EndThread
    Loop(0)
        Wait(1)
        Call(GetNpcVar, NPC_Koopatrol_03, 0, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(10)
    Return
    End
};

EvtScript N(EVS_PickUpPeach_Ch3) = {
    Thread
        Call(GetNpcPos, NPC_Koopatrol_03, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Call(NpcMoveTo, NPC_Koopatrol_03, LVar0, LVar2, 5)
        Call(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim12)
        Add(LVar0, 5)
        Call(NpcMoveTo, NPC_Koopatrol_03, LVar0, LVar2, 5)
    EndThread
    Thread
        Call(GetNpcPos, NPC_Koopatrol_04, LVar0, LVar1, LVar2)
        Sub(LVar0, 5)
        Call(NpcMoveTo, NPC_Koopatrol_04, LVar0, LVar2, 5)
        Call(SetNpcAnimation, NPC_Koopatrol_04, ANIM_WorldKoopatrol_Anim12)
        Sub(LVar0, 5)
        Call(NpcMoveTo, NPC_Koopatrol_04, LVar0, LVar2, 5)
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
    Sub(LVar0, 10)
    Loop(5)
        Add(LVar1, 4)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_CarryPeachAway_Ch3) = {
    Call(InterpNpcYaw, NPC_Koopatrol_04, 90, 3)
    Wait(10)
    Thread
        Loop(0)
            Call(GetNpcPos, NPC_Koopatrol_03, LVar0, LVar1, LVar2)
            Add(LVar0, 10)
            Add(LVar2, 2)
            Call(SetPlayerPos, LVar0, 30, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcVar, NPC_Koopatrol_03, 0, 1)
    Thread
        Call(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim14)
        Call(SetNpcSpeed, NPC_Koopatrol_03, Float(7.5))
        Call(NpcMoveTo, NPC_Koopatrol_03, 249, -72, 0)
        Call(SetNpcVar, NPC_Koopatrol_03, 0, 0)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Koopatrol_04, ANIM_WorldKoopatrol_Anim14)
        Call(SetNpcSpeed, NPC_Koopatrol_04, Float(7.5))
        Call(NpcMoveTo, NPC_Koopatrol_04, 281, -68, 0)
    EndThread
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
        Call(GetNpcVar, NPC_Koopatrol_03, 0, LVar0)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_Chapter3) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetMusic, 0, SONG_BOWSER_THEME, 0, VOL_LEVEL_FULL)
    Call(InterpPlayerYaw, 270, 0)
    Call(SetPlayerPos, 50, 10, -250)
    Call(SetNpcPos, NPC_PARTNER, 10, 50, -250)
    Call(SetNpcPos, NPC_Bowser, -50, 0, -20)
    Call(SetNpcPos, NPC_Kammy, -130, 0, -20)
    Call(SetNpcYaw, NPC_Bowser, 270)
    Call(SetNpcYaw, NPC_Kammy, 90)
    Call(UseSettingsFrom, CAM_DEFAULT, -50, 0, -20)
    Call(SetPanTarget, CAM_DEFAULT, -50, 0, -20)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(30 * DT)
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_AngryTalk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_0082)
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0 / DT))
    Call(SetCamDistance, CAM_DEFAULT, 400)
    Call(SetPanTarget, CAM_DEFAULT, -50, 0, -20)
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_0083)
    Thread
        ExecWait(N(EVS_AnimateRotatingWall_AlmostCaught))
        Call(SetPlayerAnimation, ANIM_Peach2_Gasp)
        Call(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        Call(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 30, EMOTER_PLAYER, 0, 0, 0, 0)
        Wait(30 * DT)
        Call(SetPlayerAnimation, ANIM_Peach2_LookAround)
    EndThread
    Thread
        Wait(360 * DT)
        Call(SetNpcPos, NPC_PARTNER, 100, 50, -160)
        Call(LoadPath, 30 * DT, Ref(N(TwinkHideCh3Path)), ARRAY_COUNT(N(TwinkHideCh3Path)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(EnableNpcShadow, NPC_PARTNER, FALSE)
    EndThread
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_AngryTalk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_0084)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Tantrum)
    Wait(60 * DT)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_ArmsCrossed)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_0085)
    Call(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_0086)
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_0087)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_ArmsCrossed)
    Wait(30 * DT)
    Call(InterpNpcYaw, NPC_Bowser, 90, 7 * DT)
    Wait(30 * DT)
    Call(InterpNpcYaw, NPC_Bowser, 270, 7 * DT)
    Wait(30 * DT)
    Call(InterpNpcYaw, NPC_Bowser, 90, 7 * DT)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Bowser, MSG_Peach_0088)
    Call(SetPlayerAnimation, ANIM_Peach2_Delighted)
    Wait(1)
    Call(PlaySoundAtNpc, NPC_Bowser, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_Bowser, EMOTE_EXCLAMATION, -45, 30, EMOTER_NPC, 0, 0, 0, 0)
    Call(PlaySoundAtNpc, NPC_Kammy, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_Kammy, EMOTE_EXCLAMATION, -45, 30, EMOTER_NPC, 0, 0, 0, 0)
    Wait(30 * DT)
    Call(SetNpcVar, NPC_Bowser, 0, 1)
    Thread
        Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Shock)
        Call(NpcJump0, NPC_Bowser, -50, 0, -20, 10)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim05)
        Call(NpcJump0, NPC_Kammy, -130, 0, -20, 10)
    EndThread
    Thread
        Call(SetPlayerAnimation, ANIM_Peach2_Gasp)
        Wait(30 * DT)
        Call(SetPlayerAnimation, ANIM_Peach2_LookAround)
        Wait(60 * DT)
        Call(DisablePlayerPhysics, FALSE)
        Call(N(SetPeachDepressed))
        Call(SetPlayerAnimation, ANIM_Peach2_SadStill)
        Call(func_802D1270, 30, -10, Float(2.0 / DT))
        Call(DisablePlayerPhysics, TRUE)
        Call(N(ClearPeachDepressed))
        Call(SetNpcVar, NPC_Bowser, 0, 0)
    EndThread
    Call(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_Shock, ANIM_WorldBowser_Shock, 0, MSG_Peach_0089)
    Wait(20 * DT)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    Call(ContinueSpeech, NPC_Bowser, ANIM_WorldBowser_AngryTalk, ANIM_WorldBowser_Idle, 0, MSG_Peach_008A)
    Loop(0)
        Wait(1)
        Call(GetNpcVar, NPC_Bowser, 0, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_ArmsCrossed)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    Call(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_Peach_008B)
    Call(ShowChoice, MSG_Choice_0026)
    Set(GB_OMO_PeachChoice1, LVar0)
    IfNe(LVar0, 2)
        Set(AF_KKJ_08, TRUE)
    EndIf
    Call(ContinueSpeech, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_Peach_008C)
    Call(ShowChoice, MSG_Choice_0027)
    Set(GB_OMO_PeachChoice2, LVar0)
    IfNe(LVar0, 2)
        Set(AF_KKJ_08, TRUE)
    EndIf
    Call(ContinueSpeech, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_Peach_008D)
    Call(ShowChoice, MSG_Choice_0028)
    Set(GB_OMO_PeachChoice3, LVar0)
    IfNe(LVar0, 2)
        Set(AF_KKJ_08, TRUE)
    EndIf
    Call(ContinueSpeech, NPC_Bowser, ANIM_WorldBowser_TalkEyesClosed, ANIM_WorldBowser_Idle, 0, MSG_Peach_008E)
    Call(InterpNpcYaw, NPC_Bowser, 270, 7)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5, MSG_Peach_008F)
    IfEq(AF_KKJ_08, FALSE)
        Call(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_0090)
    Else
        Call(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_0091)
    EndIf
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_TalkEyesClosed, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_0092)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    Call(InterpNpcYaw, NPC_Bowser, 90, 7 * DT)
    Wait(10 * DT)
    Call(ContinueSpeech, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5, MSG_Peach_0093)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    Call(InterpNpcYaw, NPC_Bowser, 90, 7 * DT)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 5, MSG_Peach_0094)
    Call(RotateModel, MODEL_o2, 120, 0, 1, 0)
    Call(SetNpcPos, NPC_Koopatrol_03, 249, 0, -70)
    Call(SetNpcPos, NPC_Koopatrol_04, 281, 0, -70)
    Call(SpeakToNpc, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, NPC_Bowser, MSG_Peach_0095)
    Call(InterpPlayerYaw, 90, 0)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    ExecWait(N(EVS_ApproachPeach_Ch3))
    ExecWait(N(EVS_PickUpPeach_Ch3))
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Carried, ANIM_Peach2_Carried, 5, MSG_Peach_0096)
    ExecWait(N(EVS_CarryPeachAway_Ch3))
    Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Cringe)
    Call(EnableNpcShadow, NPC_PARTNER, TRUE)
    Call(LoadPath, 80 * DT, Ref(N(TwinkFollowCh3Path1)), ARRAY_COUNT(N(TwinkFollowCh3Path1)), EASING_LINEAR)
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
    Call(InterpNpcYaw, NPC_PARTNER, 270, 7)
    Wait(15 * DT)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 7 * DT)
    Call(LoadPath, 15 * DT, Ref(N(TwinkFollowCh3Path2)), ARRAY_COUNT(N(TwinkFollowCh3Path2)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(30 * DT)
    Call(FadeOutMusic, 0, 1000 * DT)
    ExecWait(N(EVS_EndPeachChapter3))
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Call(EnablePartnerAI)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
