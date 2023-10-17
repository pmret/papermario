#include "kpa_83.h"
#include "effects.h"
#include "sprite/player.h"

#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/npc/KoopaBros.h"

NpcSettings N(NpcSettings_KoopaBros) = {
    .height = 35,
    .radius = 24,
    .level = ACTOR_LEVEL_KOOPA_TROOPA,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(NpcSettings_JrTroopa) = {
    .height = 32,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

API_CALLABLE(N(SetPlayerSpriteFacingAngle)) {
    gPlayerStatus.spriteFacingAngle = script->varTable[0];
    return ApiStatus_DONE2;
}

EvtScript N(EVS_FocusCam_LookAtDoor) = {
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, LVar6)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(500.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(88.0), EVT_FLOAT(256.6))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(195.0), EVT_FLOAT(142.0))
    EVT_CALL(SetCamPosC, CAM_DEFAULT, EVT_FLOAT(0.0), EVT_FLOAT(0.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCam_AfterBattle) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, LVar6)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(22.5), EVT_FLOAT(-13.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCam_InFrontOfDoor) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, LVar6)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(22.5), EVT_FLOAT(-11.5))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCam_MidRoom) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, LVar6)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(22.5), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCam_JrTroopa) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, LVar6)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(22.5), EVT_FLOAT(-13.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(175.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KoopaBros_Hop) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(NPC_KoopaBrosRed)
            EVT_CALL(SetNpcJumpscale, NPC_KoopaBrosRed, EVT_FLOAT(1.0))
            EVT_CALL(GetNpcPos, NPC_KoopaBrosRed, LVar1, LVar2, LVar3)
            EVT_CALL(NpcJump0, NPC_KoopaBrosRed, LVar1, LVar2, LVar3, 10)
        EVT_CASE_EQ(NPC_KoopaBrosBlk)
            EVT_CALL(SetNpcJumpscale, NPC_KoopaBrosBlk, EVT_FLOAT(1.0))
            EVT_CALL(GetNpcPos, NPC_KoopaBrosBlk, LVar1, LVar2, LVar3)
            EVT_CALL(NpcJump0, NPC_KoopaBrosBlk, LVar1, LVar2, LVar3, 10)
        EVT_CASE_EQ(NPC_KoopaBrosYlw)
            EVT_CALL(SetNpcJumpscale, NPC_KoopaBrosYlw, EVT_FLOAT(1.0))
            EVT_CALL(GetNpcPos, NPC_KoopaBrosYlw, LVar1, LVar2, LVar3)
            EVT_CALL(NpcJump0, NPC_KoopaBrosYlw, LVar1, LVar2, LVar3, 10)
        EVT_CASE_EQ(NPC_KoopaBrosGrn)
            EVT_CALL(SetNpcJumpscale, NPC_KoopaBrosGrn, EVT_FLOAT(1.0))
            EVT_CALL(GetNpcPos, NPC_KoopaBrosGrn, LVar1, LVar2, LVar3)
            EVT_CALL(NpcJump0, NPC_KoopaBrosGrn, LVar1, LVar2, LVar3, 10)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KoopaBros_SpinAround) = {
    EVT_SET(LVarA, LVar0)
    EVT_CALL(MakeLerp, 0, 11 * 180, 50, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, LVarA, 0, LVar0, 0)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KoopaBros_FlingAway) = {
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, LVar0, SOUND_HIT_NORMAL, SOUND_SPACE_DEFAULT)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.6))
    EVT_END_THREAD
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(NPC_KoopaBrosRed)
            EVT_CALL(SetNpcAnimation, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_Shock)
            EVT_CALL(SetNpcJumpscale, NPC_KoopaBrosRed, EVT_FLOAT(0.7))
            EVT_CALL(NpcJump0, NPC_KoopaBrosRed, -50, 200, 170, 40)
            EVT_CALL(SetNpcFlagBits, NPC_KoopaBrosRed, NPC_FLAG_GRAVITY, FALSE)
            EVT_CALL(SetNpcPos, NPC_KoopaBrosRed, NPC_DISPOSE_LOCATION)
        EVT_CASE_EQ(NPC_KoopaBrosBlk)
            EVT_CALL(SetNpcAnimation, NPC_KoopaBrosBlk, ANIM_KoopaBros_Black_Shock)
            EVT_CALL(SetNpcJumpscale, NPC_KoopaBrosBlk, EVT_FLOAT(0.7))
            EVT_CALL(NpcJump0, NPC_KoopaBrosBlk, 0, 200, 127, 40)
            EVT_CALL(SetNpcFlagBits, NPC_KoopaBrosRed, NPC_FLAG_GRAVITY, FALSE)
            EVT_CALL(SetNpcPos, NPC_KoopaBrosBlk, NPC_DISPOSE_LOCATION)
        EVT_CASE_EQ(NPC_KoopaBrosYlw)
            EVT_CALL(SetNpcAnimation, NPC_KoopaBrosYlw, ANIM_KoopaBros_Yellow_Shock)
            EVT_CALL(SetNpcJumpscale, NPC_KoopaBrosYlw, EVT_FLOAT(0.7))
            EVT_CALL(NpcJump0, NPC_KoopaBrosYlw, 100, 200, 200, 40)
            EVT_CALL(SetNpcFlagBits, NPC_KoopaBrosYlw, NPC_FLAG_GRAVITY, FALSE)
            EVT_CALL(SetNpcPos, NPC_KoopaBrosYlw, NPC_DISPOSE_LOCATION)
        EVT_CASE_EQ(NPC_KoopaBrosGrn)
            EVT_CALL(SetNpcAnimation, NPC_KoopaBrosGrn, ANIM_KoopaBros_Green_Shock)
            EVT_CALL(SetNpcJumpscale, NPC_KoopaBrosGrn, EVT_FLOAT(0.7))
            EVT_CALL(NpcJump0, NPC_KoopaBrosGrn, 150, 200, 150, 40)
            EVT_CALL(SetNpcFlagBits, NPC_KoopaBrosGrn, NPC_FLAG_GRAVITY, FALSE)
            EVT_CALL(SetNpcPos, NPC_KoopaBrosGrn, NPC_DISPOSE_LOCATION)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Door) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PlayerMoveTo, -150, LVar2, 0)
    EVT_CALL(SetCamType, CAM_DEFAULT, 6, FALSE)
    EVT_SET(LVar6, EVT_FLOAT(3.0 / DT))
    EVT_EXEC_WAIT(N(EVS_FocusCam_LookAtDoor))
    EVT_SET(MF_DoneIntroMessage, FALSE)
    EVT_THREAD
        EVT_CALL(SetMusicTrack, 0, SONG_FINAL_BOWSER_BATTLE, 1, 8)
        EVT_WAIT(150)
        EVT_IF_NE(MF_DoneIntroMessage, FALSE)
            EVT_GOTO(5)
        EVT_END_IF
        EVT_CALL(FadeOutMusic, 0, 250)
        EVT_WAIT(15)
        EVT_IF_NE(MF_DoneIntroMessage, FALSE)
            EVT_GOTO(5)
        EVT_END_IF
        EVT_CALL(SetMusicTrack, 0, SONG_BOWSERS_CASTLE, 0, 8)
        EVT_WAIT(30)
        EVT_IF_NE(MF_DoneIntroMessage, FALSE)
            EVT_GOTO(5)
        EVT_END_IF
        EVT_CALL(SetMusicTrackVolumes, TRACK_VOLS_KPA_3)
        EVT_LABEL(5)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0053)
    EVT_SET(MF_DoneIntroMessage, TRUE)
    EVT_WAIT(2)
    EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_BROS_THEME, 2, 8)
    EVT_SET(LVar3, 65)
    EVT_SET(LVar4, 0)
    EVT_SET(LVar5, 150)
    EVT_SET(LVar6, EVT_FLOAT(90.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_InFrontOfDoor))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o166, COLLIDER_FLAGS_UPPER_MASK)
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_KoopaBrosRed, 220, 180, 160)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_Midair)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBrosRed, TRUE)
        EVT_CALL(SetNpcJumpscale, NPC_KoopaBrosRed, EVT_FLOAT(1.0))
        EVT_CALL(SetNpcFlagBits, NPC_KoopaBrosRed, NPC_FLAG_GRAVITY, TRUE)
        EVT_CALL(SetNpcFlagBits, NPC_KoopaBrosRed, NPC_FLAG_FLYING, FALSE)
        EVT_CALL(NpcMoveTo, NPC_KoopaBrosRed, 20, 160, 20)
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaBrosRed, SOUND_KOOPA_BROS_LAND, SOUND_SPACE_DEFAULT)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 20, 0, 160, 0)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBrosRed, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_IdleCrouch)
        EVT_CALL(SetNpcYaw, NPC_KoopaBrosRed, 270)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetNpcPos, NPC_KoopaBrosBlk, 248, 180, 185)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBrosBlk, ANIM_KoopaBros_Black_Midair)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBrosBlk, TRUE)
        EVT_CALL(SetNpcJumpscale, NPC_KoopaBrosBlk, EVT_FLOAT(1.0))
        EVT_CALL(SetNpcFlagBits, NPC_KoopaBrosBlk, NPC_FLAG_GRAVITY, TRUE)
        EVT_CALL(SetNpcFlagBits, NPC_KoopaBrosBlk, NPC_FLAG_FLYING, FALSE)
        EVT_CALL(NpcMoveTo, NPC_KoopaBrosBlk, 48, 185, 20)
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaBrosBlk, SOUND_KOOPA_BROS_LAND, SOUND_SPACE_DEFAULT)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 48, 0, 185, 0)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBrosBlk, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBrosBlk, ANIM_KoopaBros_Black_IdleCrouch)
        EVT_CALL(SetNpcYaw, NPC_KoopaBrosBlk, 270)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetNpcPos, NPC_KoopaBrosYlw, 260, 180, 110)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBrosYlw, ANIM_KoopaBros_Yellow_Midair)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBrosYlw, TRUE)
        EVT_CALL(SetNpcJumpscale, NPC_KoopaBrosYlw, EVT_FLOAT(1.0))
        EVT_CALL(SetNpcFlagBits, NPC_KoopaBrosYlw, NPC_FLAG_GRAVITY, TRUE)
        EVT_CALL(SetNpcFlagBits, NPC_KoopaBrosYlw, NPC_FLAG_FLYING, FALSE)
        EVT_CALL(NpcMoveTo, NPC_KoopaBrosYlw, 60, 110, 20)
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaBrosYlw, SOUND_KOOPA_BROS_LAND, SOUND_SPACE_DEFAULT)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 60, 0, 110, 0)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBrosYlw, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBrosYlw, ANIM_KoopaBros_Yellow_IdleCrouch)
        EVT_CALL(SetNpcYaw, NPC_KoopaBrosYlw, 270)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(SetNpcPos, NPC_KoopaBrosGrn, 288, 180, 155)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBrosGrn, ANIM_KoopaBros_Green_Midair)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBrosGrn, TRUE)
        EVT_CALL(SetNpcJumpscale, NPC_KoopaBrosGrn, EVT_FLOAT(1.0))
        EVT_CALL(SetNpcFlagBits, NPC_KoopaBrosGrn, NPC_FLAG_GRAVITY, TRUE)
        EVT_CALL(SetNpcFlagBits, NPC_KoopaBrosGrn, NPC_FLAG_FLYING, FALSE)
        EVT_CALL(NpcMoveTo, NPC_KoopaBrosGrn, 88, 155, 20)
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaBrosGrn, SOUND_KOOPA_BROS_LAND, SOUND_SPACE_DEFAULT)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 88, 0, 155, 0)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBrosGrn, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBrosGrn, ANIM_KoopaBros_Green_IdleCrouch)
        EVT_CALL(SetNpcYaw, NPC_KoopaBrosGrn, 270)
    EVT_END_THREAD
    EVT_WAIT(65)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o166, COLLIDER_FLAGS_UPPER_MASK)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_KoopaBrosRed, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_ADD(LVar1, 30)
        EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaBrosRed, SOUND_SMALL_LENS_FLARE, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_ThumbsUp)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(GetNpcPos, NPC_KoopaBrosBlk, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_ADD(LVar1, 30)
        EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaBrosBlk, SOUND_SMALL_LENS_FLARE, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBrosBlk, ANIM_KoopaBros_Black_ThumbsUp)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(GetNpcPos, NPC_KoopaBrosYlw, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_ADD(LVar1, 30)
        EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaBrosYlw, SOUND_SMALL_LENS_FLARE, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBrosYlw, ANIM_KoopaBros_Yellow_ThumbsUp)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(GetNpcPos, NPC_KoopaBrosGrn, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_ADD(LVar1, 30)
        EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaBrosGrn, SOUND_SMALL_LENS_FLARE, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBrosGrn, ANIM_KoopaBros_Green_ThumbsUp)
    EVT_END_THREAD
    EVT_WAIT(45)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_ThumbsUp)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBrosBlk, ANIM_KoopaBros_Black_ThumbsUp)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBrosYlw, ANIM_KoopaBros_Yellow_ThumbsUp)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBrosGrn, ANIM_KoopaBros_Green_ThumbsUp)
    EVT_THREAD
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
        EVT_CALL(PlayerMoveTo, -50, 150, 0)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_ThumbsUp, ANIM_KoopaBros_Red_ThumbsUp, 0, MSG_CH8_0054)
    EVT_SET(LVar3, 0)
    EVT_SET(LVar4, 0)
    EVT_SET(LVar5, 150)
    EVT_SET(LVar6, EVT_FLOAT(3.0 / DT))
    EVT_EXEC_WAIT(N(EVS_FocusCam_MidRoom))
    EVT_CALL(SetNpcAnimation, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_Idle)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBrosBlk, ANIM_KoopaBros_Black_Idle)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBrosYlw, ANIM_KoopaBros_Yellow_Idle)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBrosGrn, ANIM_KoopaBros_Green_Idle)
    EVT_CALL(SpeakToPlayer, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 0, MSG_CH8_0055)
    EVT_CALL(ShowChoice, MSG_Choice_0013)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ContinueSpeech, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 0, MSG_CH8_0056)
    EVT_ELSE
        EVT_CALL(ContinueSpeech, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 0, MSG_CH8_0057)
    EVT_END_IF
    EVT_SET(LVar6, EVT_FLOAT(3.0 / DT))
    EVT_EXEC_WAIT(N(EVS_FocusCam_LookAtDoor))
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0058)
    EVT_SET(LVar3, 0)
    EVT_SET(LVar4, 0)
    EVT_SET(LVar5, 150)
    EVT_SET(LVar6, EVT_FLOAT(90.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_MidRoom))
    EVT_CALL(SpeakToPlayer, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 0, MSG_CH8_0059)
    EVT_CALL(SetMusicTrack, 0, SONG_JR_TROOPA_THEME, 1, 8)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH8_005A, 0, 150)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcPos, NPC_JrTroopa, -150, 0, 140)
    EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_JrTroopa_ChargeArmsUp)
    EVT_CALL(SetNpcSpeed, NPC_JrTroopa, EVT_FLOAT(8.0))
    EVT_THREAD
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
        EVT_LOOP(0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(GetNpcPos, NPC_JrTroopa, LVar3, LVar4, LVar5)
            EVT_IF_LE(LVar0, LVar3)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_STATIC_COLLISION | PS_FLAG_ROTATION_LOCKED | PS_FLAG_FACE_FORWARD, TRUE)
        EVT_CALL(MakeLerp, 0, 11 * 180, 50, EASING_QUADRATIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(InterpPlayerYaw, LVar0, 0)
            EVT_CALL(N(SetPlayerSpriteFacingAngle))
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_STATIC_COLLISION | PS_FLAG_ROTATION_LOCKED | PS_FLAG_FACE_FORWARD, FALSE)
        EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_END_THREAD
    EVT_SET(LVar0, NPC_KoopaBrosRed)
    EVT_EXEC_GET_TID(N(EVS_KoopaBros_Hop), MV_KoopaBrosRed_HopScript)
    EVT_SET(LVar0, NPC_KoopaBrosBlk)
    EVT_EXEC_GET_TID(N(EVS_KoopaBros_Hop), MV_KoopaBrosBlk_HopScript)
    EVT_SET(LVar0, NPC_KoopaBrosYlw)
    EVT_EXEC_GET_TID(N(EVS_KoopaBros_Hop), MV_KoopaBrosYlw_HopScript)
    EVT_SET(LVar0, NPC_KoopaBrosGrn)
    EVT_EXEC_GET_TID(N(EVS_KoopaBros_Hop), MV_KoopaBrosGrn_HopScript)
    EVT_CALL(NpcMoveTo, NPC_JrTroopa, 22, 140, 0)
    EVT_SET(LVar0, NPC_KoopaBrosRed)
    EVT_EXEC(N(EVS_KoopaBros_SpinAround))
    EVT_CALL(NpcMoveTo, NPC_JrTroopa, 50, 140, 0)
    EVT_SET(LVar0, NPC_KoopaBrosBlk)
    EVT_EXEC(N(EVS_KoopaBros_SpinAround))
    EVT_CALL(NpcMoveTo, NPC_JrTroopa, 62, 140, 0)
    EVT_SET(LVar0, NPC_KoopaBrosYlw)
    EVT_EXEC(N(EVS_KoopaBros_SpinAround))
    EVT_CALL(NpcMoveTo, NPC_JrTroopa, 90, 140, 0)
    EVT_SET(LVar0, NPC_KoopaBrosGrn)
    EVT_EXEC(N(EVS_KoopaBros_SpinAround))
    EVT_CALL(NpcMoveTo, NPC_JrTroopa, 100, 140, 0)
    EVT_CALL(NpcMoveTo, NPC_JrTroopa, 98, 140, 0)
    EVT_KILL_THREAD(MV_KoopaBrosGrn_HopScript)
    EVT_SET(LVar0, NPC_KoopaBrosGrn)
    EVT_EXEC(N(EVS_KoopaBros_FlingAway))
    EVT_CALL(NpcMoveTo, NPC_JrTroopa, 25, 140, 0)
    EVT_CALL(NpcMoveTo, NPC_JrTroopa, 70, 140, 0)
    EVT_KILL_THREAD(MV_KoopaBrosYlw_HopScript)
    EVT_SET(LVar0, NPC_KoopaBrosYlw)
    EVT_EXEC(N(EVS_KoopaBros_FlingAway))
    EVT_CALL(NpcMoveTo, NPC_JrTroopa, 75, 140, 0)
    EVT_CALL(NpcMoveTo, NPC_JrTroopa, 30, 140, 0)
    EVT_KILL_THREAD(MV_KoopaBrosRed_HopScript)
    EVT_SET(LVar0, NPC_KoopaBrosRed)
    EVT_EXEC(N(EVS_KoopaBros_FlingAway))
    EVT_CALL(NpcMoveTo, NPC_JrTroopa, 25, 140, 0)
    EVT_CALL(NpcMoveTo, NPC_JrTroopa, 58, 140, 0)
    EVT_KILL_THREAD(MV_KoopaBrosBlk_HopScript)
    EVT_SET(LVar0, NPC_KoopaBrosBlk)
    EVT_EXEC(N(EVS_KoopaBros_FlingAway))
    EVT_CALL(NpcMoveTo, NPC_JrTroopa, 75, 140, 0)
    EVT_CALL(InterpNpcYaw, NPC_JrTroopa, 270, 0)
    EVT_WAIT(5)
    EVT_CALL(GetNpcPos, NPC_JrTroopa, LVar0, LVar1, LVar2)
    EVT_CALL(NpcMoveTo, NPC_JrTroopa, 100, 140, 0)
    EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_JrTroopa_Idle)
    EVT_CALL(SetNpcYaw, NPC_JrTroopa, 270)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH8_005B, 160, 40)
    EVT_WAIT(10)
    EVT_SET(LVar3, 100)
    EVT_SET(LVar4, 0)
    EVT_SET(LVar5, 150)
    EVT_SET(LVar6, EVT_FLOAT(3.0 / DT))
    EVT_EXEC_WAIT(N(EVS_FocusCam_JrTroopa))
    EVT_CALL(SpeakToPlayer, NPC_JrTroopa, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle, 0, MSG_CH8_005C)
    EVT_SET(LVar3, 0)
    EVT_SET(LVar4, 0)
    EVT_SET(LVar5, 150)
    EVT_SET(LVar6, EVT_FLOAT(3.0 / DT))
    EVT_EXEC_WAIT(N(EVS_FocusCam_AfterBattle))
    EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_JrTroopa_ChargeArmsUp)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetNpcSpeed, NPC_JrTroopa, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_JrTroopa, -30, 140, 0)
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 60)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(StartBossBattle, SONG_JR_TROOPA_BATTLE)
    EVT_CALL(SpeakToPlayer, NPC_JrTroopa, ANIM_JrTroopa_Dizzy, ANIM_JrTroopa_Dizzy, 0, MSG_CH8_0061)
    EVT_SET(MV_Sync_AfterBattleCamMovement, 0)
    EVT_THREAD
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 0)
        EVT_SET(LVar5, 150)
        EVT_SET(LVar6, EVT_FLOAT(3.0 / DT))
        EVT_EXEC_WAIT(N(EVS_FocusCam_AfterBattle))
        EVT_CALL(ShowMessageAtScreenPos, MSG_CH8_0062, 160, 40)
        EVT_SET(MV_Sync_AfterBattleCamMovement, 1)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_JrTroopa_ChargeArmsUp)
    EVT_CALL(SetNpcSpeed, NPC_JrTroopa, EVT_FLOAT(8.0))
    EVT_CALL(NpcMoveTo, NPC_JrTroopa, -50, 140, 0)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(NpcMoveTo, NPC_JrTroopa, -200, 140, 0)
    EVT_CALL(SetNpcPos, NPC_JrTroopa, NPC_DISPOSE_LOCATION)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_LOOP(0)
        EVT_IF_EQ(MV_Sync_AfterBattleCamMovement, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(LVar6, EVT_FLOAT(3.0 / DT))
    EVT_EXEC_WAIT(N(EVS_FocusCam_LookAtDoor))
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0063)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_SET(GB_KPA83_BowserDoorState, 1)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Door) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(LVar3, 100)
            EVT_SET(LVar4, 0)
            EVT_SET(LVar5, 150)
            EVT_SET(LVar6, EVT_FLOAT(90.0))
            EVT_EXEC_WAIT(N(EVS_FocusCam_JrTroopa))
            EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_JrTroopa_Dizzy)
            EVT_CALL(SetNpcPos, NPC_JrTroopa, 100, 0, 140)
            EVT_CALL(SetNpcPos, NPC_SELF, 184, 20, 150)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Door) = {
    EVT_IF_EQ(GB_KPA83_BowserDoorState, 0)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Door)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Door)))
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
        EVT_CALL(SetNpcPos, NPC_SELF, 184, 20, 150)
        EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaBros) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_JrTroopa) = {
    EVT_RETURN
    EVT_END
};

AnimID N(ExtraAnims_KoopaBros)[] = {
    ANIM_KoopaBros_Black_Shock,
    ANIM_KoopaBros_Black_Idle,
    ANIM_KoopaBros_Black_IdleCrouch,
    ANIM_KoopaBros_Black_Midair,
    ANIM_KoopaBros_Black_ThumbsUp,
    ANIM_KoopaBros_Black_Talk,
    ANIM_KoopaBros_Black_Leap,
    ANIM_KoopaBros_Black_Sleep,
    ANIM_LIST_END
};

NpcData N(NpcData_Enemies)[] = {
    {
        .id = NPC_KoopaBrosBlk,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_KoopaBros),
        .settings = &N(NpcSettings_KoopaBros),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = BLACK_KOOPA_BROS_ANIMS,
        .extraAnimations = N(ExtraAnims_KoopaBros),
    },
    {
        .id = NPC_KoopaBrosRed,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_KoopaBros),
        .settings = &N(NpcSettings_KoopaBros),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = RED_KOOPA_BROS_ANIMS,
        .extraAnimations = N(ExtraAnims_KoopaBros),
    },
    {
        .id = NPC_KoopaBrosYlw,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_KoopaBros),
        .settings = &N(NpcSettings_KoopaBros),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = YELLOW_KOOPA_BROS_ANIMS,
        .extraAnimations = N(ExtraAnims_KoopaBros),
    },
    {
        .id = NPC_KoopaBrosGrn,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_KoopaBros),
        .settings = &N(NpcSettings_KoopaBros),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = GREEN_KOOPA_BROS_ANIMS,
        .extraAnimations = N(ExtraAnims_KoopaBros),
    },
    {
        .id = NPC_JrTroopa,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_JrTroopa),
        .settings = &N(NpcSettings_JrTroopa),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
    },
    {
        .id = NPC_Door,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Door),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Enemies), BTL_KMR_3_FORMATION_07),
    {}
};
