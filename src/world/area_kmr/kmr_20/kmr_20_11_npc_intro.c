#include "kmr_20.h"
#include "model.h"
#include "sprite/player.h"

#define NAME_SUFFIX _Intro
#include "world/common/entity/Pipe.inc.c"
#include "common/foliage.inc.c"
#define NAME_SUFFIX

API_CALLABLE(N(func_80241C9C_8EDABC)) {
    mdl_group_set_custom_gfx(MODEL_g62, CUSTOM_GFX_NONE, ENV_TINT_SHROUD, TRUE);
    mdl_set_shroud_tint_params(0, 0, 0, 255);

    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80241CF0_8EDB10)) {
    Bytecode* args = script->ptrReadPos;

    gCameras[CAM_DEFAULT].moveSpeed = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetAmbienceVolumeHalf_Intro)) {
    snd_ambient_set_volume(0, 1000, 63);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Luigi_PlayWalkSounds_Intro) = {
    EVT_CALL(GetNpcAnimation, NPC_Scene_Luigi, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ANIM_Luigi_Walk)
        EVT_CASE_OR_EQ(ANIM_Luigi_WalkLetter)
        EVT_CASE_OR_EQ(ANIM_Luigi_WalkBack)
            EVT_SET(LVar1, 10)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(ANIM_Luigi_Run)
        EVT_CASE_OR_EQ(ANIM_Luigi_RunLetter)
        EVT_CASE_OR_EQ(ANIM_Luigi_RunBack)
            EVT_SET(LVar1, 5)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(PlaySoundAtNpc, NPC_Scene_Luigi, SOUND_SEQ_LUIGI_STEP, SOUND_SPACE_DEFAULT)
            EVT_WAIT(LVar1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Player_EnterPipe_Intro) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_SET(LVar0, kmr_20_ENTRY_4)
    EVT_CALL(N(Pipe_GetEntryPos_Intro))
    EVT_CALL(PlayerMoveTo, LVar1, LVar3, 3)
    EVT_SET(LVar0, kmr_20_ENTRY_4)
    EVT_CALL(N(Pipe_GetEntryPos_Intro))
    EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
    EVT_WAIT(2)
    EVT_CALL(PlaySoundAtPlayer, SOUND_ENTER_PIPE, SOUND_SPACE_DEFAULT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_LOOP(40)
            EVT_SUB(LVar1, 1)
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_VERTICAL_PIPE_CURL, 1, 1, 0)
    EVT_WAIT(25)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Luigi_EnterPipe_Intro) = {
    EVT_CALL(SetNpcFlagBits, NPC_Scene_Luigi, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Scene_Luigi, NPC_FLAG_FLYING, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_Scene_Luigi, FALSE)
    EVT_SET(LVar0, kmr_20_ENTRY_4)
    EVT_CALL(N(Pipe_GetEntryPos_Intro))
    EVT_CALL(NpcMoveTo, NPC_Scene_Luigi, LVar1, LVar3, 3)
    EVT_SET(LVar0, kmr_20_ENTRY_4)
    EVT_CALL(N(Pipe_GetEntryPos_Intro))
    EVT_CALL(SetNpcPos, NPC_Scene_Luigi, LVar1, LVar2, LVar3)
    EVT_WAIT(2)
    EVT_CALL(PlaySoundAtNpc, NPC_Scene_Luigi, SOUND_ENTER_PIPE, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_Still)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Scene_Luigi, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 7)
        EVT_CALL(SetNpcPos, NPC_Scene_Luigi, LVar0, LVar1, LVar2)
        EVT_LOOP(40)
            EVT_SUB(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_Scene_Luigi, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcImgFXFlags, NPC_Scene_Luigi, IMGFX_FLAG_800)
    EVT_CALL(SetNpcImgFXParams, NPC_Scene_Luigi, IMGFX_SET_ANIM, IMGFX_ANIM_VERTICAL_PIPE_CURL, 1, 1, 0)
    EVT_WAIT(25)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCam_Unused) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 250, 30, -80)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(N(func_80241CF0_8EDB10), EVT_FLOAT(1.8))
    EVT_CALL(InterpCamTargetPos, 0, 1, 250, 30, -80, 10)
    EVT_CALL(N(func_80241CF0_8EDB10), 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TetherCamToLuigi) = {
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetNpcVar, NPC_Scene_Luigi, 0, 1)
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_Scene_Luigi, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 20)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(GetNpcVar, NPC_Scene_Luigi, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenAndCloseDoor_Intro_Impl) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o246, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 80, 14, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g14, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(30)
    EVT_CALL(MakeLerp, 80, 0, 8, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g14, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o246, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenAndCloseDoor_Intro) = {
    EVT_CALL(EnableGroup, MODEL_g72, TRUE)
    EVT_EXEC_WAIT(N(EVS_OpenAndCloseDoor_Intro_Impl))
    EVT_CALL(EnableGroup, MODEL_g72, FALSE)
    EVT_RETURN
    EVT_END
};

s32 N(D_8024FD28_8FBB48)[] = {
    3,
    34, 35, 36,
};

s32 N(D_8024FD38_8FBB58)[] = {
    3,
    422, 37, -195,
    422, 48, -195,
    422, 12, -195,
};

s32* N(UnknownLists)[] = {
    N(D_8024FD28_8FBB48), 0,
    N(D_8024FD38_8FBB58), 0,
};

EvtScript N(EVS_Scene_BeginGame) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_WAIT(5 * DT)
        EVT_CALL(SetMusicTrack, 0, SONG_MAIL_CALL, 0, 8)
    EVT_END_THREAD
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetPlayerPos, -50, 30, -80)
    EVT_CALL(SetNpcPos, NPC_Scene_Luigi, 220, 30, -80)
    EVT_CALL(SetNpcPos, NPC_Scene_Parakarry, 720, 220, -150)
    EVT_CALL(SetNpcYaw, NPC_Scene_Parakarry, 270)
    EVT_CALL(EnableGroup, MODEL_g94, FALSE)
    EVT_CALL(EnableGroup, MODEL_g100, TRUE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 550, 0, 20)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 550, 0, 20)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 550)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-14.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.7))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(MakeLerp, 0, 70, 60 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_g108, LVar0, 0, 0)
            EVT_SETF(LVar2, 0)
            EVT_SUBF(LVar2, LVar0)
            EVT_CALL(TranslateGroup, MODEL_g106, LVar2, 0, 0)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(30 * DT)
        EVT_CALL(MakeLerp, 0, 50, 40 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_g109, LVar0, 0, 0)
            EVT_SETF(LVar2, 0)
            EVT_SUBF(LVar2, LVar0)
            EVT_CALL(TranslateGroup, MODEL_g107, LVar2, 0, 0)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(50 * DT)
        EVT_CALL(MakeLerp, 0, 50, 40 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_g105, LVar0, 0, 0)
            EVT_CALL(TranslateGroup, MODEL_g102, LVar0, 0, 0)
            EVT_SETF(LVar2, 0)
            EVT_SUBF(LVar2, LVar0)
            EVT_CALL(TranslateGroup, MODEL_g103, LVar2, 0, 0)
            EVT_CALL(TranslateGroup, MODEL_g104, LVar2, 0, 0)
            EVT_CALL(TranslateGroup, MODEL_g101, LVar2, 0, 0)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(120 * DT)
    EVT_CALL(NpcFlyTo, NPC_Scene_Parakarry, 430, 20, -165, 60 * DT, -10, EASING_LINEAR)
    EVT_CALL(InterpNpcYaw, NPC_Scene_Parakarry, 45, 10)
    EVT_WAIT(20 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_Scene_Parakarry, SOUNC_CHECK_MAILBOX, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_CALL(TranslateModel, MODEL_o222, 2, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o223, 2, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o224, 2, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, MODEL_o222, -3, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o223, -3, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o224, -3, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, MODEL_o222, 2, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o223, 2, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o224, 2, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, MODEL_o222, -3, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o223, -3, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o224, -3, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, MODEL_o222, 0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o223, 0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o224, 0, 0, 0)
    EVT_END_THREAD
    EVT_WAIT(35 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Scene_Parakarry, 220, 5)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Scene_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, MSG_Intro_001E)
    EVT_WAIT(10 * DT)
    EVT_CALL(NpcFlyTo, NPC_Scene_Parakarry, 360, 260, 60, 60 * DT, -10, EASING_LINEAR)
    EVT_WAIT(30 * DT)
    EVT_EXEC(N(EVS_OpenAndCloseDoor_Intro))
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_Run)
    EVT_EXEC_GET_TID(N(EVS_Luigi_PlayWalkSounds_Intro), LVarA)
    EVT_CALL(SetNpcSpeed, NPC_Scene_Luigi, EVT_FLOAT(4.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_Scene_Luigi, 450, -80, 0)
    EVT_CALL(NpcMoveTo, NPC_Scene_Luigi, 430, -165, 0)
    EVT_CALL(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_Idle)
    EVT_KILL_THREAD(LVarA)
    EVT_WAIT(20 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_Scene_Luigi, SOUNC_CHECK_MAILBOX, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_CALL(TranslateModel, MODEL_o222, 1, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o223, 1, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o224, 1, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, MODEL_o222, -2, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o223, -2, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o224, -2, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, MODEL_o222, 1, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o223, 1, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o224, 1, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, MODEL_o222, -2, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o223, -2, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o224, -2, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateModel, MODEL_o222, 0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o223, 0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o224, 0, 0, 0)
    EVT_END_THREAD
    EVT_WAIT(2)
    EVT_CALL(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_IdleLetter)
    EVT_WAIT(40 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Scene_Luigi, 270, 5)
    EVT_CALL(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_RunLetter)
    EVT_EXEC_GET_TID(N(EVS_Luigi_PlayWalkSounds_Intro), LVarA)
    EVT_CALL(NpcMoveTo, NPC_Scene_Luigi, 450, -80, 0)
    EVT_CALL(NpcMoveTo, NPC_Scene_Luigi, 290, -70, 0)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(EnableGroup, MODEL_g20, TRUE)
    EVT_CALL(EnableGroup, MODEL_g21, TRUE)
    EVT_CALL(EnableGroup, MODEL_g49, TRUE)
    EVT_CALL(EnableModel, MODEL_g56, TRUE)
    EVT_CALL(N(func_80241C9C_8EDABC))
    EVT_CALL(RotateGroup, MODEL_g60, 90, 1, 0, 0)
    EVT_CALL(RotateGroup, MODEL_g34, 90, -1, 0, 0)
    EVT_CALL(EnableGroup, MODEL_g60, FALSE)
    EVT_CALL(EnableGroup, MODEL_g34, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 250, 30, -80)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 250, 30, -80)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(N(SetAmbienceVolumeHalf_Intro))
    EVT_EXEC(N(EVS_OpenAndCloseDoor_Intro_Impl))
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_WalkLetter)
    EVT_EXEC_GET_TID(N(EVS_Luigi_PlayWalkSounds_Intro), LVarA)
    EVT_CALL(SetNpcSpeed, NPC_Scene_Luigi, EVT_FLOAT(2.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_Scene_Luigi, 240, -80, 0)
    EVT_CALL(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_IdleLetter)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SpeakToPlayer, NPC_Scene_Luigi, ANIM_Luigi_TalkLetter, ANIM_Luigi_IdleLetter, 0, MSG_Intro_001F)
    EVT_WAIT(10 * DT)
    EVT_EXEC(N(EVS_TetherCamToLuigi))
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_WalkLetter)
        EVT_EXEC_GET_TID(N(EVS_Luigi_PlayWalkSounds_Intro), LVarA)
        EVT_CALL(NpcMoveTo, NPC_Scene_Luigi, 230, -130, 0)
        EVT_CALL(NpcMoveTo, NPC_Scene_Luigi, 110, -110, 0)
        EVT_CALL(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_IdleLetter)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(SetNpcVar, NPC_Scene_Luigi, 0, 0)
    EVT_END_THREAD
    EVT_WAIT(20 * DT)
    EVT_CALL(func_802D1270, 70, -80, EVT_FLOAT(2.0 / DT))
    EVT_CALL(func_802D1270, 70, -110, EVT_FLOAT(2.0 / DT))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Scene_Luigi, ANIM_Luigi_TalkLetter, ANIM_Luigi_IdleLetter, 0, MSG_Intro_0020)
    EVT_CALL(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_OpenLetter)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_IdleRead)
    EVT_CALL(SpeakToPlayer, NPC_Scene_Luigi, ANIM_Luigi_TalkRead, ANIM_Luigi_IdleRead, 0, MSG_Intro_0021)
    EVT_CALL(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_ReadLetter)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetMusicTrack, 0, SONG_PRISONER_PEACH_THEME, 0, 8)
    EVT_WAIT(5 * DT)
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_CALL(GotoMapSpecial, EVT_PTR("osr_00"), osr_00_ENTRY_3, TRANSITION_SLOW_FADE_TO_WHITE)
    EVT_WAIT(15 * DT)
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_WAIT(100 * DT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_SettingOff) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcPos, NPC_Scene_Luigi, 220, 30, -70)
    EVT_CALL(SetNpcYaw, NPC_Scene_Luigi, 90)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 320, 30, -70)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 320, 30, -70)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(60 * DT)
    EVT_CALL(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 8)
    EVT_EXEC(N(EVS_OpenAndCloseDoor_Intro))
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcSpeed, NPC_Scene_Luigi, EVT_FLOAT(3.0 / DT))
        EVT_CALL(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_Run)
        EVT_EXEC_GET_TID(N(EVS_Luigi_PlayWalkSounds_Intro), LVarA)
        EVT_CALL(NpcMoveTo, NPC_Scene_Luigi, 320, -70, 0)
        EVT_CALL(NpcMoveTo, NPC_Scene_Luigi, 460, -70, 0)
        EVT_CALL(NpcMoveTo, NPC_Scene_Luigi, 570, -170, 0)
        EVT_CALL(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_Idle)
        EVT_KILL_THREAD(LVarA)
    EVT_END_THREAD
    EVT_CALL(func_802D1270, 320, -70, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(func_802D1270, 460, -70, EVT_FLOAT(3.0 / DT))
    EVT_CALL(func_802D1270, 570, -170, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_CALL(PlayerJump, 594, 30, -216, 15 * DT)
    EVT_EXEC_WAIT(N(EVS_Player_EnterPipe_Intro))
    EVT_CALL(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_JumpStance)
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_Jump)
        EVT_CALL(PlaySoundAtNpc, NPC_Scene_Luigi, SOUND_QUICK_PLAYER_JUMP, SOUND_SPACE_DEFAULT)
        EVT_WAIT(7 * DT)
        EVT_WAIT(7 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_Idle)
        EVT_CALL(PlaySoundAtNpc, NPC_Scene_Luigi, SOUND_LAND_SOFTLY, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_Scene_Luigi, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_Scene_Luigi, 594, 30, -216, 15 * DT)
    EVT_EXEC_WAIT(N(EVS_Luigi_EnterPipe_Intro))
    EVT_EXEC(N(EVS_FadeOutAmbientSounds))
    EVT_CALL(GotoMap, EVT_PTR("mac_00"), mac_00_ENTRY_5)
    EVT_WAIT(100)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
