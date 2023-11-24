#include "kmr_20.h"
#include "model.h"
#include "sprite/player.h"

#define NAME_SUFFIX _Epilogue
#include "world/common/entity/Pipe.inc.c"
#define NAME_SUFFIX

API_CALLABLE(N(func_80242030_8EDE50)) {
    mdl_group_set_custom_gfx(MODEL_g62, CUSTOM_GFX_NONE, ENV_TINT_NONE, TRUE);
    mdl_set_shroud_tint_params(0, 0, 0, 0);

    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80242084_8EDEA4)) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
    }

    script->functionTemp[1] += 16;

    if (script->functionTemp[1] > 255) {
        script->functionTemp[1] = 255;
    }

    set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, script->functionTemp[1]);

    if (script->functionTemp[1] == 255) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_802420EC_8EDF0C)) {
    if (isInitialCall) {
        script->functionTemp[1] = 255;
    }

    script->functionTemp[1] -= 16;
    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = 0;
        return ApiStatus_DONE2;
    }

    set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, script->functionTemp[1]);
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(SetAmbienceVolumeHalf_Epilogue)) {
    snd_ambient_set_volume(0, 1000, 63);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetAmbienceVolumeFull_Epilogue)) {
    snd_ambient_set_volume(0, 1000, 127);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Luigi_PlayWalkSounds_Epilogue) = {
    EVT_CALL(GetNpcAnimation, NPC_Luigi_1, LVar0)
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
            EVT_CALL(PlaySoundAtNpc, NPC_Luigi_1, SOUND_SEQ_LUIGI_STEP, SOUND_SPACE_DEFAULT)
            EVT_WAIT(LVar1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenFrontDoor) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o246, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 90, 10, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g14, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CloseFrontDoor) = {
    EVT_CALL(MakeLerp, 90, 0, 10, EASING_QUADRATIC_IN)
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

EvtScript N(EVS_OpenAndCloseDoor_Epilogue) = {
    EVT_CALL(EnableGroup, MODEL_g72, TRUE)
    EVT_EXEC_WAIT(N(EVS_OpenFrontDoor))
    EVT_WAIT(30)
    EVT_EXEC_WAIT(N(EVS_CloseFrontDoor))
    EVT_CALL(EnableGroup, MODEL_g72, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Player_EnterPipe_Epilogue) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_SET(LVar0, 4)
    EVT_CALL(N(Pipe_GetEntryPos_Epilogue))
    EVT_CALL(PlayerMoveTo, LVar1, LVar3, 3)
    EVT_SET(LVar0, 4)
    EVT_CALL(N(Pipe_GetEntryPos_Epilogue))
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

EvtScript N(EVS_Luigi_EnterPipe_Epilogue) = {
    EVT_CALL(SetNpcFlagBits, NPC_Luigi_1, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Luigi_1, NPC_FLAG_FLYING, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_Luigi_1, FALSE)
    EVT_SET(LVar0, 4)
    EVT_CALL(N(Pipe_GetEntryPos_Epilogue))
    EVT_CALL(NpcMoveTo, NPC_Luigi_1, LVar1, LVar3, 3)
    EVT_SET(LVar0, 4)
    EVT_CALL(N(Pipe_GetEntryPos_Epilogue))
    EVT_CALL(SetNpcPos, NPC_Luigi_1, LVar1, LVar2, LVar3)
    EVT_WAIT(2)
    EVT_CALL(PlaySoundAtNpc, NPC_Luigi_1, SOUND_ENTER_PIPE, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Still)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Luigi_1, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 7)
        EVT_CALL(SetNpcPos, NPC_Luigi_1, LVar0, LVar1, LVar2)
        EVT_LOOP(40)
            EVT_SUB(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_Luigi_1, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcImgFXFlags, NPC_Luigi_1, IMGFX_FLAG_800)
    EVT_CALL(SetNpcImgFXParams, NPC_Luigi_1, IMGFX_SET_ANIM, IMGFX_ANIM_VERTICAL_PIPE_CURL, 1, 1, 0)
    EVT_WAIT(25)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_BeginEpilogue) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(SetAmbienceVolumeHalf_Epilogue))
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SitIdle)
    EVT_CALL(SetPlayerPos, 95, 44, -40)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 150, 44, -40)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 150, 44, -40)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-6.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(30)
    EVT_CALL(SpeakToPlayer, NPC_Luigi_1, ANIM_Luigi_TalkSit, ANIM_Luigi_IdleSit, 0, MSG_Outro_000D)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SitNodYes)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_Luigi_1, ANIM_Luigi_TalkSit, ANIM_Luigi_IdleSit, 0, MSG_Outro_000E)
    EVT_WAIT(30)
    EVT_CALL(GotoMap, EVT_PTR("kmr_02"), kmr_02_ENTRY_4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_EpilogueGetLetter) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(SetAmbienceVolumeHalf_Epilogue))
    EVT_CALL(SetPlayerPos, 95, 44, -40)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SitIdle)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 150, 44, -40)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 150, 44, -40)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-6.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(35)
    EVT_CALL(PlaySoundAt, SOUNC_CHECK_MAILBOX, SOUND_SPACE_DEFAULT, 430, 0, -185)
    EVT_WAIT(25)
    EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, 0, EMOTE_QUESTION, 0, 20, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_Luigi_1, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_Luigi_1, EMOTE_QUESTION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(30)
    EVT_CALL(SpeakToPlayer, NPC_Luigi_1, ANIM_Luigi_TalkSit, ANIM_Luigi_IdleSit, 0, MSG_Outro_0021)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_Luigi_1, EVT_FLOAT(1.0))
        EVT_CALL(NpcJump0, NPC_Luigi_1, 180, 30, -20, 10)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Jump)
    EVT_CALL(PlaySoundAtNpc, NPC_Luigi_1, SOUND_QUICK_PLAYER_JUMP, SOUND_SPACE_DEFAULT)
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Fall)
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Land)
    EVT_CALL(PlaySoundAtNpc, NPC_Luigi_1, SOUND_LAND_SOFTLY, SOUND_SPACE_DEFAULT)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Walk)
    EVT_EXEC_GET_TID(N(EVS_Luigi_PlayWalkSounds_Epilogue), LVarA)
    EVT_CALL(NpcMoveTo, NPC_Luigi_1, 240, -20, 30)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_WalkBack)
    EVT_CALL(NpcMoveTo, NPC_Luigi_1, 240, -80, 30)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
    EVT_KILL_THREAD(LVarA)
    EVT_WAIT(10)
    EVT_EXEC(N(EVS_OpenFrontDoor))
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Walk)
    EVT_EXEC_GET_TID(N(EVS_Luigi_PlayWalkSounds_Epilogue), LVarA)
    EVT_CALL(NpcMoveTo, NPC_Luigi_1, 300, -80, 30)
    EVT_EXEC_WAIT(N(EVS_CloseFrontDoor))
    EVT_KILL_THREAD(LVarA)
    EVT_WAIT(90)
    EVT_CALL(SetNpcYaw, NPC_Luigi_1, 270)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_WalkLetter)
    EVT_EXEC_GET_TID(N(EVS_Luigi_PlayWalkSounds_Epilogue), LVarA)
    EVT_EXEC(N(EVS_OpenFrontDoor))
    EVT_CALL(NpcMoveTo, NPC_Luigi_1, 240, -80, 30)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_IdleLetter)
    EVT_KILL_THREAD(LVarA)
    EVT_EXEC_WAIT(N(EVS_CloseFrontDoor))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Luigi_1, ANIM_Luigi_TalkLetter, ANIM_Luigi_IdleLetter, 0, MSG_Outro_0022)
    EVT_WAIT(30)
    EVT_CALL(N(func_80242084_8EDEA4))
    EVT_CALL(EnableGroup, MODEL_g20, FALSE)
    EVT_CALL(EnableGroup, MODEL_g21, FALSE)
    EVT_CALL(EnableGroup, MODEL_g49, FALSE)
    EVT_CALL(EnableModel, MODEL_g56, FALSE)
    EVT_CALL(N(func_80242030_8EDE50))
    EVT_CALL(RotateGroup, MODEL_g60, 0, 1, 0, 0)
    EVT_CALL(RotateGroup, MODEL_g34, 0, -1, 0, 0)
    EVT_CALL(EnableGroup, MODEL_g60, TRUE)
    EVT_CALL(EnableGroup, MODEL_g34, TRUE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 340, 30, -70)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 340, 30, -70)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetPlayerPos, 240, 30, -75)
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
    EVT_CALL(SetNpcPos, NPC_Luigi_1, 200, 30, -75)
    EVT_WAIT(30)
    EVT_CALL(N(func_802420EC_8EDF0C))
    EVT_CALL(N(SetAmbienceVolumeFull_Epilogue))
    EVT_WAIT(30)
    EVT_CALL(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 0, 8)
    EVT_EXEC(N(EVS_OpenAndCloseDoor_Epilogue))
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetNpcSpeed, NPC_Luigi_1, EVT_FLOAT(3.0))
        EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Run)
        EVT_EXEC_GET_TID(N(EVS_Luigi_PlayWalkSounds_Epilogue), LVarA)
        EVT_CALL(NpcMoveTo, NPC_Luigi_1, 320, -70, 0)
        EVT_CALL(NpcMoveTo, NPC_Luigi_1, 460, -70, 0)
        EVT_CALL(NpcMoveTo, NPC_Luigi_1, 570, -170, 0)
        EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
        EVT_KILL_THREAD(LVarA)
    EVT_END_THREAD
    EVT_CALL(func_802D1270, 320, -70, EVT_FLOAT(3.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(func_802D1270, 460, -70, EVT_FLOAT(3.0))
    EVT_CALL(func_802D1270, 570, -170, EVT_FLOAT(3.0))
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_CALL(PlayerJump, 594, 30, -216, 15)
    EVT_EXEC_WAIT(N(EVS_Player_EnterPipe_Epilogue))
    EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_JumpStance)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Jump)
        EVT_CALL(PlaySoundAtNpc, NPC_Luigi_1, SOUND_QUICK_PLAYER_JUMP, SOUND_SPACE_DEFAULT)
        EVT_WAIT(7)
        EVT_WAIT(7)
        EVT_CALL(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
        EVT_CALL(PlaySoundAtNpc, NPC_Luigi_1, SOUND_LAND_SOFTLY, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_Luigi_1, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_Luigi_1, 594, 30, -216, 15)
    EVT_EXEC_WAIT(N(EVS_Luigi_EnterPipe_Epilogue))
    EVT_EXEC(N(EVS_FadeOutAmbientSounds))
    EVT_CALL(GotoMap, EVT_PTR("mac_00"), mac_00_ENTRY_7)
    EVT_WAIT(100)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

MAP_RODATA_PAD(1,unk);
