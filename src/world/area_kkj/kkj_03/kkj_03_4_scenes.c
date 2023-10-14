#include "kkj_03.h"
#include "sprite/player.h"

EvtScript N(EVS_Scene_MeetingPeach) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GE(LVar0, 525)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(FadeOutMusic, 0, 666)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetMusicTrack, 0, SONG_PRISONER_PEACH_THEME, 0, 8)
    EVT_CALL(PlayerFaceNpc, NPC_Peach, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Walk)
    EVT_CALL(SetNpcSpeed, NPC_Peach, EVT_FLOAT(2.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_Peach, 625, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_Peach, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_Intro_004B)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach2_LowerArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Idle)
    EVT_THREAD
        EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(5.0 / DT), 600, 0, -12, EVT_FLOAT(325.0), EVT_FLOAT(17.0), EVT_FLOAT(-9.0))
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, 575, 0, 20 * DT)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_Peach, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_Intro_004C)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Peach, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_Intro_004D)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach2_LowerArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(FadeOutMusic, 0, 1000)
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(PlayerMoveTo, 590, 0, 10 * DT)
        EVT_WAIT(5 * DT)
        EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        EVT_CALL(ShowEmote, 0, EMOTE_EXCLAMATION, -45, 20, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(InterpNpcYaw, NPC_Peach, 90, 7 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Walk)
        EVT_CALL(NpcMoveTo, NPC_Peach, 640, 0, 10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Idle)
        EVT_CALL(PlaySoundAtNpc, NPC_Peach, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        EVT_CALL(ShowEmote, NPC_Peach, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
        EVT_WAIT(20 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach2_LookAround)
        EVT_WAIT(60 * DT)
        EVT_CALL(InterpNpcYaw, NPC_Peach, 270, 7 * DT)
    EVT_END_THREAD
    EVT_WAIT(17 * DT)
    EVT_THREAD
        EVT_CALL(PlaySound, SOUND_LOOP_KKJ_RUMBLING)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 200 * DT, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_WAIT(60 * DT)
    EVT_CALL(GotoMap, EVT_PTR("osr_04"), osr_04_ENTRY_0)
    EVT_WAIT(100 * DT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Clouds) = {
    EVT_CALL(EnableTexPanning, MODEL_o718, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, -200)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MoveClouds) = {
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_CALL(TranslateGroup, MODEL_g159, 0, LVar0, 0)
        EVT_ADD(LVar0, -2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_Ascending) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcPos, NPC_Peach, 680, 0, -15)
    EVT_CALL(EnableGroup, MODEL_g156, TRUE)
    EVT_EXEC(N(EVS_TexPan_Clouds))
    EVT_EXEC(N(EVS_MoveClouds))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 600, 0, -15)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 600, 0, -15)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_CALL(SetPlayerJumpscale, 0)
        EVT_LOOP(0)
            EVT_CALL(InterpPlayerYaw, 270, 0)
            EVT_CALL(PlayerJump1, 550, 0, 0, 20 * DT)
            EVT_CALL(InterpPlayerYaw, 90, 0)
            EVT_CALL(PlayerJump1, 630, 0, 0, 20 * DT)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Run)
            EVT_WAIT(15 * DT)
            EVT_CALL(SetPlayerAnimation, ANIM_MarioW1_CarryAboveRun)
            EVT_WAIT(15 * DT)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach1_RunLiftDress)
        EVT_LOOP(0)
            EVT_CALL(NpcMoveTo, NPC_Peach, 600, 0, 20 * DT)
            EVT_CALL(NpcMoveTo, NPC_Peach, 680, 0, 20 * DT)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(PlaySound, SOUND_LOOP_KKJ_RUMBLING)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 200, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_WAIT(100 * DT)
    EVT_CALL(GotoMap, EVT_PTR("osr_03"), osr_03_ENTRY_1)
    EVT_WAIT(100 * DT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
