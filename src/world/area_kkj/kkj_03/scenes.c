#include "kkj_03.h"
#include "sprite/player.h"

EvtScript N(EVS_Scene_MeetingPeach) = {
    Loop(0)
        Wait(1)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfGe(LVar0, 525)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Call(FadeOutMusic, 0, 666)
    Wait(20 * DT)
    Call(SetMusicTrack, 0, SONG_PRISONER_PEACH_THEME, 0, 8)
    Call(PlayerFaceNpc, NPC_Peach, FALSE)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Walk)
    Call(SetNpcSpeed, NPC_Peach, Float(2.0 / DT))
    Call(NpcMoveTo, NPC_Peach, 625, 0, 0)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Idle)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach2_RaiseArms)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_Peach, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_Intro_004B)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach2_LowerArms)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Idle)
    Thread
        Call(SetCamProperties, CAM_DEFAULT, Float(5.0 / DT), 600, 0, -12, Float(325.0), Float(17.0), Float(-9.0))
    EndThread
    Call(PlayerMoveTo, 575, 0, 20 * DT)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach2_RaiseArms)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_Peach, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_Intro_004C)
    Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Peach, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_Intro_004D)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach2_LowerArms)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Idle)
    Wait(10 * DT)
    Call(FadeOutMusic, 0, 1000)
    Thread
        Wait(10 * DT)
        Call(PlayerMoveTo, 590, 0, 10 * DT)
        Wait(5 * DT)
        Call(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        Call(ShowEmote, 0, EMOTE_EXCLAMATION, -45, 20, EMOTER_PLAYER, 0, 0, 0, 0)
    EndThread
    Thread
        Call(InterpNpcYaw, NPC_Peach, 90, 7 * DT)
        Call(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Walk)
        Call(NpcMoveTo, NPC_Peach, 640, 0, 10 * DT)
        Call(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Idle)
        Call(PlaySoundAtNpc, NPC_Peach, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        Call(ShowEmote, NPC_Peach, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
        Wait(20 * DT)
        Call(SetNpcAnimation, NPC_Peach, ANIM_Peach2_LookAround)
        Wait(60 * DT)
        Call(InterpNpcYaw, NPC_Peach, 270, 7 * DT)
    EndThread
    Wait(17 * DT)
    Thread
        Call(PlaySound, SOUND_LOOP_KKJ_RUMBLING)
        Call(ShakeCam, CAM_DEFAULT, 0, 200 * DT, Float(1.0))
    EndThread
    Wait(60 * DT)
    Call(GotoMap, Ref("osr_04"), osr_04_ENTRY_0)
    Wait(100 * DT)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_TexPan_Clouds) = {
    Call(EnableTexPanning, MODEL_o718, TRUE)
    Set(LVar0, 0)
    Loop(0)
        Add(LVar0, -200)
        Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, LVar0, 0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_MoveClouds) = {
    Set(LVar0, 0)
    Loop(0)
        Call(TranslateGroup, MODEL_g159, 0, LVar0, 0)
        Add(LVar0, -2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_Ascending) = {
    Call(DisablePlayerInput, TRUE)
    Call(SetNpcPos, NPC_Peach, 680, 0, -15)
    Call(EnableGroup, MODEL_g156, TRUE)
    Exec(N(EVS_TexPan_Clouds))
    Exec(N(EVS_MoveClouds))
    Call(UseSettingsFrom, CAM_DEFAULT, 600, 0, -15)
    Call(SetPanTarget, CAM_DEFAULT, 600, 0, -15)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Thread
        Call(SetPlayerJumpscale, 0)
        Loop(0)
            Call(InterpPlayerYaw, 270, 0)
            Call(PlayerJump1, 550, 0, 0, 20 * DT)
            Call(InterpPlayerYaw, 90, 0)
            Call(PlayerJump1, 630, 0, 0, 20 * DT)
        EndLoop
    EndThread
    Thread
        Loop(0)
            Call(SetPlayerAnimation, ANIM_Mario1_Run)
            Wait(15 * DT)
            Call(SetPlayerAnimation, ANIM_MarioW1_CarryAboveRun)
            Wait(15 * DT)
        EndLoop
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Peach, ANIM_Peach1_RunLiftDress)
        Loop(0)
            Call(NpcMoveTo, NPC_Peach, 600, 0, 20 * DT)
            Call(NpcMoveTo, NPC_Peach, 680, 0, 20 * DT)
        EndLoop
    EndThread
    Thread
        Call(PlaySound, SOUND_LOOP_KKJ_RUMBLING)
        Call(ShakeCam, CAM_DEFAULT, 0, 200, Float(1.0))
    EndThread
    Wait(100 * DT)
    Call(GotoMap, Ref("osr_03"), osr_03_ENTRY_1)
    Wait(100 * DT)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
