#include "kkj_14.h"
#include "sprite/player.h"

API_CALLABLE(N(SetPeachDepressed)) {
    gGameStatusPtr->peachFlags |= PEACH_FLAG_DEPRESSED;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ClearPeachDepressed)) {
    gGameStatusPtr->peachFlags &= ~PEACH_FLAG_DEPRESSED;
    return ApiStatus_DONE2;
}

Vec3f N(TwinkEnterPath)[] = {
    {  520.0,    70.0,  -62.0 },
    {  400.0,    57.0,   47.0 },
    {  300.0,    50.0,   40.0 },
    {  300.0,    50.0,  -10.0 },
    {  320.0,    65.0,    0.0 },
};

Vec3f N(TwinkExitPath)[] = {
    {  352.0,    50.0,   -2.0 },
    {  300.0,    85.0,    0.0 },
    {  350.0,   120.0,    0.0 },
    {  400.0,   105.0,   -7.0 },
    {  430.0,    90.0,  -15.0 },
};

EvtScript N(EVS_OpenDoor_Ch0) = {
    Call(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_OPEN, 0)
    Call(MakeLerp, 0, 120, 14, EASING_COS_FAST_OVERSHOOT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o4, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_CloseDoor_Ch0) = {
    Call(MakeLerp, 120, 0, 8, EASING_COS_FAST_OVERSHOOT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o4, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_CLOSE, 0)
    Return
    End
};

EvtScript N(EVS_TwinkTappingOnGlassDoor) = {
    Loop(0)
        Call(NpcFlyTo, NPC_PARTNER, 520, 70, -60, 30 * DT, -10, EASING_LINEAR)
        Call(NpcFlyTo, NPC_PARTNER, 520, 70, -61, 10 * DT, -5, EASING_LINEAR)
        Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_KKJ_WINDOW_TAP, SOUND_SPACE_DEFAULT)
        Call(NpcFlyTo, NPC_PARTNER, 520, 70, -62, 10 * DT, -5, EASING_LINEAR)
        Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_KKJ_WINDOW_TAP, SOUND_SPACE_DEFAULT)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_Chapter0) = {
    Call(DisablePlayerInput, TRUE)
    Call(N(SetPeachDepressed))
    Call(SetPlayerAnimation, ANIM_Peach2_SadStill)
    Call(InterpPlayerYaw, 270, 0)
    Call(DisablePartnerAI, 0)
    Call(SetNpcPos, NPC_PARTNER, 520, 60, -35)
    Call(SetNpcPos, NPC_Bowser, -450, 0, -20)
    Call(SetNpcPos, NPC_Kammy, -510, 0, -20)
    Call(SetNpcYaw, NPC_Bowser, 90)
    Call(SetNpcYaw, NPC_Kammy, 90)
    Call(AdjustCam, CAM_DEFAULT, Float(90.0), 20, 250, Float(17.0), Float(-11.0))
    Wait(30 * DT)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_SadTalk, ANIM_Peach2_SadStill, 5, MSG_Peach_0016)
    Wait(5 * DT)
    Call(InterpPlayerYaw, 90, 5)
    Call(PlayerMoveTo, 20, 30, 30 * DT)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_SadTalk, ANIM_Peach2_SadStill, 5, MSG_Peach_0017)
    Wait(5 * DT)
    Call(InterpPlayerYaw, 270, 5)
    Call(PlayerMoveTo, -20, 30, 30 * DT)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_SadTalk, ANIM_Peach2_SadStill, 5, MSG_Peach_0018)
    Wait(5 * DT)
    Call(InterpPlayerYaw, 90, 5)
    Call(PlayerMoveTo, 20, 30, 30 * DT)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_SadTalk, ANIM_Peach2_SadStill, 5, MSG_Peach_0019)
    Wait(30 * DT)
    Call(N(ClearPeachDepressed))
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_EXCLAMATION, -45, 30, EMOTER_PLAYER, 0, 0, 0, 0)
    Wait(10 * DT)
    Call(InterpPlayerYaw, 270, 3)
    Wait(15 * DT)
    Call(SetMusicTrack, 0, SONG_BOWSER_THEME, 0, 8)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
    Call(SetPanTarget, CAM_DEFAULT, -330, 0, 0)
    Call(SetCamPosA, CAM_DEFAULT, -330, 32)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(3 * DT)
    Exec(N(EVS_OpenDoor_Ch0))
    Wait(10 * DT)
    Call(SetNpcVar, NPC_Bowser, 0, 1)
    Thread
        Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Walk)
        Call(SetNpcSpeed, NPC_Bowser, Float(3.0 / DT))
        Call(NpcMoveTo, NPC_Bowser, -300, -20, 0)
        Call(NpcMoveTo, NPC_Bowser, -50, 30, 0)
        Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
        Call(SetNpcVar, NPC_Bowser, 0, 0)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
        Call(SetNpcSpeed, NPC_Kammy, Float(3.0 / DT))
        Call(NpcMoveTo, NPC_Kammy, -110, 30, 0)
        Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    EndThread
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Thread
        Wait(40 * DT)
        Call(MakeLerp, 250, 300, 80 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetCamDistance, CAM_DEFAULT, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Loop(0)
        Call(GetNpcPos, NPC_Bowser, LVar0, LVar1, LVar2)
        Add(LVar0, 10)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Call(GetNpcVar, NPC_Bowser, 0, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(20 * DT)
    Call(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_TalkEyesClosed, ANIM_WorldBowser_TalkEyesClosed, 0, MSG_Peach_001A)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    Wait(1)
    Call(EndSpeech, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0)
    Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, MSG_Peach_001B)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Brandish)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_BrandishTalk, ANIM_WorldBowser_BrandishIdle, 0, MSG_Peach_001C)
    Call(SetPlayerAnimation, ANIM_Peach2_Startle)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    Call(EndSpeech, NPC_Bowser, ANIM_WorldBowser_BrandishTalk, ANIM_WorldBowser_BrandishIdle, 0)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, MSG_Peach_001D)
    Call(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_Peach_001E)
    Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, MSG_Peach_001F)
    Wait(15 * DT)
    Thread
        Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Walk)
        Call(NpcMoveTo, NPC_Bowser, -450, 30, 0)
    EndThread
    Thread
        Call(InterpNpcYaw, NPC_Kammy, 270, 5)
        Wait(60 * DT)
        Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
        Call(NpcMoveTo, NPC_Kammy, -510, 30, 0)
        Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    EndThread
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.5 / DT))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(FadeOutMusic, 0, 2000 * DT)
    Wait(60 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0020)
    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Wait(20 * DT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 150)
    Call(PlaySoundAt, SOUND_KKJ_WINDOW_TAP, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    Wait(10 * DT)
    Call(PlaySoundAt, SOUND_KKJ_WINDOW_TAP, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    Wait(10 * DT)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_QUESTION, -45, 20, EMOTER_PLAYER, 0, 0, 0, 0)
    Wait(20 * DT)
    Call(InterpPlayerYaw, 135, 5)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    Wait(10)
    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0021)
    Set(AF_KKJ_03, FALSE)
    ExecGetTID(N(EVS_TwinkTappingOnGlassDoor), LVarA)
    Thread
        Call(UseSettingsFrom, CAM_DEFAULT, 413, 0, -66)
        Call(SetCamType, CAM_DEFAULT, 4, FALSE)
        Call(SetCamPosA, CAM_DEFAULT, 338, 44)
        Call(SetCamPosB, CAM_DEFAULT, 413, -66)
        Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    EndThread
    Wait(10 * DT)
    Call(SetPlayerSpeed, Float(3.0 / DT))
    Call(PlayerMoveTo, 179, -4, 0)
    Call(PlayerMoveTo, 439, -16, 0)
    Set(AF_KKJ_03, TRUE)
    KillThread(LVarA)
    Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
    Wait(15 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_OpenDoors)
    Call(PlaySoundAtCollider, COLLIDER_tte, SOUND_WINDOW_OPEN_A, 0)
    Call(MakeLerp, 0, 80, 14, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o83, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o85, LVar0, 0, -1, 0)
        Call(RotateModel, MODEL_o84, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o86, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetMusicTrack, 0, SONG_TWINK_THEME, 0, 8)
    Thread
        Call(LoadPath, 100 * DT, Ref(N(TwinkEnterPath)), ARRAY_COUNT(N(TwinkEnterPath)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
        Set(AF_KKJ_03, FALSE)
    EndThread
    Thread
        Loop(0)
            Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            IfLt(LVar0, 310)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EndThread
    Loop(0)
        Wait(1)
        Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        IfLt(LVar0, 430)
            BreakLoop
        EndIf
    EndLoop
    Call(InterpPlayerYaw, 220, 5)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Thread
        Wait(40 * DT)
        Call(func_802D1270, 420, 0, Float(2.0 / DT))
    EndThread
    Wait(10 * DT)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Wait(30 * DT)
    Call(UseSettingsFrom, CAM_DEFAULT, 370, 30, 0)
    Call(SetPanTarget, CAM_DEFAULT, 370, 30, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(370.0), Float(32.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Loop(0)
        Wait(1)
        IfEq(AF_KKJ_03, FALSE)
            BreakLoop
        EndIf
    EndLoop
    Call(SetPanTarget, CAM_DEFAULT, 320, 30, 17)
    Call(SetCamDistance, CAM_DEFAULT, Float(200.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-16.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0022)
    Call(SetPanTarget, CAM_DEFAULT, 370, 30, 17)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-10.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_0023)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0024)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.4 / DT))
    Call(SetPanTarget, CAM_DEFAULT, 350, 30, 17)
    Call(PlayerMoveTo, 380, 0, 30)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_0025)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0026)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(SetCamDistance, CAM_DEFAULT, 200)
    Call(SetCamPitch, CAM_DEFAULT, 17, -14)
    Call(SetPanTarget, CAM_DEFAULT, 380, 30, 17)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0027)
    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_TalkSad)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Call(SetCamPitch, CAM_DEFAULT, 17, -16)
    Call(SetPanTarget, CAM_DEFAULT, 320, 30, 17)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_TalkSad, ANIM_Twink_TalkSad, 0, MSG_Peach_0028)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPitch, CAM_DEFAULT, 17, -10)
    Call(SetPanTarget, CAM_DEFAULT, 350, 30, 17)
    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0029)
    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_TalkSad, ANIM_Twink_TalkSad, 0, MSG_Peach_002A)
    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_002B)
    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_Startle)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_EXCLAMATION, -45, 30, EMOTER_PLAYER, 0, 0, 0, 0)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_002C)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Idle)
    Call(EndSpeech, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5)
    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_GiveItem)
    Wait(12 * DT)
    Call(GetPlayerPos, LVar2, LVar3, LVar4)
    Sub(LVar2, 10)
    Add(LVar3, 20)
    Add(LVar4, 2)
    Call(MakeItemEntity, ITEM_LUCKY_STAR, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(LVar9, LVar0)
    Wait(10 * DT)
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0 / DT))
    Call(SetCamDistance, CAM_DEFAULT, Float(200.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-12.5))
    Call(SetPanTarget, CAM_DEFAULT, 365, 30, 17)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Thread
        Call(NpcFlyTo, NPC_PARTNER, 350, 50, -2, 30 * DT, -5, EASING_LINEAR)
    EndThread
    Wait(40 * DT)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Wink)
    Call(MakeLerp, 50, 70, 10 * DT, EASING_QUADRATIC_OUT)
    Loop(0)
        Add(LVar2, -2)
        Call(UpdateLerp)
        Call(SetItemPos, LVar9, LVar2, LVar0, LVar4)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(10)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_TalkWink)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_TalkWink, ANIM_Twink_TalkWink, 0, MSG_Peach_002D)
    Set(LVar3, LVar0)
    Loop(10)
        Add(LVar3, -1)
        Call(SetItemPos, LVar9, LVar2, LVar3, LVar4)
        Wait(1)
    EndLoop
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Tense)
    Call(RemoveItemEntity, LVar9)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Idle)
    Wait(20 * DT)
    Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    Wait(10 * DT)
    Call(SetCamDistance, CAM_DEFAULT, 400)
    Call(SetCamPitch, CAM_DEFAULT, 17, -10)
    Call(SetPanTarget, CAM_DEFAULT, 355, 30, 17)
    Thread
        Loop(0)
            Wait(1)
            Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            IfGt(LVar0, 380)
                BreakLoop
            EndIf
        EndLoop
        Call(InterpPlayerYaw, 90, 5)
        Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
        Wait(10 * DT)
        Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
        Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_002E)
        Set(AF_KKJ_03, TRUE)
    EndThread
    Thread
        Loop(0)
            Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            IfLt(LVar0, 310)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EndThread
    Call(LoadPath, 60 * DT, Ref(N(TwinkExitPath)), ARRAY_COUNT(N(TwinkExitPath)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Idle)
    Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
    Loop(0)
        Wait(1)
        IfEq(AF_KKJ_03, TRUE)
            BreakLoop
        EndIf
    EndLoop
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Call(SetCamPitch, CAM_DEFAULT, 17, -13)
    Call(SetPanTarget, CAM_DEFAULT, 405, 30, 17)
    Call(SetCamPosB, CAM_DEFAULT, Float(400.0), Float(32.0))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_002F)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    Call(NpcFlyTo, NPC_PARTNER, 420, 60, 0, 20 * DT, 0, EASING_LINEAR)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Idle)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0030)
    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Thread
        Call(MakeLerp, 0, 360, 10 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_PARTNER, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0031)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Fly)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 5)
    Wait(10 * DT)
    Call(FadeOutMusic, 0, 2000 * DT)
    Call(NpcFlyTo, NPC_PARTNER, 600, 100, -80, 40, 0, EASING_LINEAR)
    Wait(30 * DT)
    Call(GotoMap, Ref("kkj_26"), kkj_26_ENTRY_2)
    Wait(100 * DT)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
