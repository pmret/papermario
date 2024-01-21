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
    Call(GetNpcAnimation, NPC_Luigi_1, LVar0)
    Switch(LVar0)
        CaseOrEq(ANIM_Luigi_Walk)
        CaseOrEq(ANIM_Luigi_WalkLetter)
        CaseOrEq(ANIM_Luigi_WalkBack)
            Set(LVar1, 10)
        EndCaseGroup
        CaseOrEq(ANIM_Luigi_Run)
        CaseOrEq(ANIM_Luigi_RunLetter)
        CaseOrEq(ANIM_Luigi_RunBack)
            Set(LVar1, 5)
        EndCaseGroup
    EndSwitch
    ChildThread
        Loop(0)
            Call(PlaySoundAtNpc, NPC_Luigi_1, SOUND_SEQ_LUIGI_STEP, SOUND_SPACE_DEFAULT)
            Wait(LVar1)
        EndLoop
    EndChildThread
    Loop(0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_OpenFrontDoor) = {
    Call(PlaySoundAtCollider, COLLIDER_o246, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 90, 10, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_g14, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_CloseFrontDoor) = {
    Call(MakeLerp, 90, 0, 10, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_g14, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_o246, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Return
    End
};

EvtScript N(EVS_OpenAndCloseDoor_Epilogue) = {
    Call(EnableGroup, MODEL_g72, TRUE)
    ExecWait(N(EVS_OpenFrontDoor))
    Wait(30)
    ExecWait(N(EVS_CloseFrontDoor))
    Call(EnableGroup, MODEL_g72, TRUE)
    Return
    End
};

EvtScript N(EVS_Player_EnterPipe_Epilogue) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(HidePlayerShadow, TRUE)
    Set(LVar0, 4)
    Call(N(Pipe_GetEntryPos_Epilogue))
    Call(PlayerMoveTo, LVar1, LVar3, 3)
    Set(LVar0, 4)
    Call(N(Pipe_GetEntryPos_Epilogue))
    Call(SetPlayerPos, LVar1, LVar2, LVar3)
    Wait(2)
    Call(PlaySoundAtPlayer, SOUND_ENTER_PIPE, SOUND_SPACE_DEFAULT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Thread
        Wait(4)
        Loop(40)
            Sub(LVar1, 1)
            Call(SetPlayerPos, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Call(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_VERTICAL_PIPE_CURL, 1, 1, 0)
    Wait(25)
    Return
    End
};

EvtScript N(EVS_Luigi_EnterPipe_Epilogue) = {
    Call(SetNpcFlagBits, NPC_Luigi_1, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_Luigi_1, NPC_FLAG_FLYING, TRUE)
    Call(EnableNpcShadow, NPC_Luigi_1, FALSE)
    Set(LVar0, 4)
    Call(N(Pipe_GetEntryPos_Epilogue))
    Call(NpcMoveTo, NPC_Luigi_1, LVar1, LVar3, 3)
    Set(LVar0, 4)
    Call(N(Pipe_GetEntryPos_Epilogue))
    Call(SetNpcPos, NPC_Luigi_1, LVar1, LVar2, LVar3)
    Wait(2)
    Call(PlaySoundAtNpc, NPC_Luigi_1, SOUND_ENTER_PIPE, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Still)
    Thread
        Call(GetNpcPos, NPC_Luigi_1, LVar0, LVar1, LVar2)
        Add(LVar1, 7)
        Call(SetNpcPos, NPC_Luigi_1, LVar0, LVar1, LVar2)
        Loop(40)
            Sub(LVar1, 1)
            Call(SetNpcPos, NPC_Luigi_1, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcImgFXFlags, NPC_Luigi_1, IMGFX_FLAG_800)
    Call(SetNpcImgFXParams, NPC_Luigi_1, IMGFX_SET_ANIM, IMGFX_ANIM_VERTICAL_PIPE_CURL, 1, 1, 0)
    Wait(25)
    Return
    End
};

EvtScript N(EVS_Scene_BeginEpilogue) = {
    Call(DisablePlayerInput, TRUE)
    Call(N(SetAmbienceVolumeHalf_Epilogue))
    Call(SetPlayerAnimation, ANIM_MarioW2_SitIdle)
    Call(SetPlayerPos, 95, 44, -40)
    Call(UseSettingsFrom, CAM_DEFAULT, 150, 44, -40)
    Call(SetPanTarget, CAM_DEFAULT, 150, 44, -40)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-6.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(30)
    Call(SpeakToPlayer, NPC_Luigi_1, ANIM_Luigi_TalkSit, ANIM_Luigi_IdleSit, 0, MSG_Outro_000D)
    Call(SetPlayerAnimation, ANIM_MarioW2_SitNodYes)
    Wait(20)
    Call(SpeakToPlayer, NPC_Luigi_1, ANIM_Luigi_TalkSit, ANIM_Luigi_IdleSit, 0, MSG_Outro_000E)
    Wait(30)
    Call(GotoMap, Ref("kmr_02"), kmr_02_ENTRY_4)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_Scene_EpilogueGetLetter) = {
    Call(DisablePlayerInput, TRUE)
    Call(N(SetAmbienceVolumeHalf_Epilogue))
    Call(SetPlayerPos, 95, 44, -40)
    Call(SetPlayerAnimation, ANIM_MarioW2_SitIdle)
    Call(UseSettingsFrom, CAM_DEFAULT, 150, 44, -40)
    Call(SetPanTarget, CAM_DEFAULT, 150, 44, -40)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-6.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(35)
    Call(PlaySoundAt, SOUNC_CHECK_MAILBOX, SOUND_SPACE_DEFAULT, 430, 0, -185)
    Wait(25)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_QUESTION, 0, 20, EMOTER_PLAYER, 0, 0, 0, 0)
    Call(PlaySoundAtNpc, NPC_Luigi_1, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_Luigi_1, EMOTE_QUESTION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    Wait(30)
    Call(SpeakToPlayer, NPC_Luigi_1, ANIM_Luigi_TalkSit, ANIM_Luigi_IdleSit, 0, MSG_Outro_0021)
    Wait(10)
    Thread
        Call(SetNpcJumpscale, NPC_Luigi_1, Float(1.0))
        Call(NpcJump0, NPC_Luigi_1, 180, 30, -20, 10)
    EndThread
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Jump)
    Call(PlaySoundAtNpc, NPC_Luigi_1, SOUND_QUICK_PLAYER_JUMP, SOUND_SPACE_DEFAULT)
    Wait(5)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Fall)
    Wait(5)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Land)
    Call(PlaySoundAtNpc, NPC_Luigi_1, SOUND_LAND_SOFTLY, SOUND_SPACE_DEFAULT)
    Wait(10)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Walk)
    ExecGetTID(N(EVS_Luigi_PlayWalkSounds_Epilogue), LVarA)
    Call(NpcMoveTo, NPC_Luigi_1, 240, -20, 30)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_WalkBack)
    Call(NpcMoveTo, NPC_Luigi_1, 240, -80, 30)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
    KillThread(LVarA)
    Wait(10)
    Exec(N(EVS_OpenFrontDoor))
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Walk)
    ExecGetTID(N(EVS_Luigi_PlayWalkSounds_Epilogue), LVarA)
    Call(NpcMoveTo, NPC_Luigi_1, 300, -80, 30)
    ExecWait(N(EVS_CloseFrontDoor))
    KillThread(LVarA)
    Wait(90)
    Call(SetNpcYaw, NPC_Luigi_1, 270)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_WalkLetter)
    ExecGetTID(N(EVS_Luigi_PlayWalkSounds_Epilogue), LVarA)
    Exec(N(EVS_OpenFrontDoor))
    Call(NpcMoveTo, NPC_Luigi_1, 240, -80, 30)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_IdleLetter)
    KillThread(LVarA)
    ExecWait(N(EVS_CloseFrontDoor))
    Wait(10)
    Call(SpeakToPlayer, NPC_Luigi_1, ANIM_Luigi_TalkLetter, ANIM_Luigi_IdleLetter, 0, MSG_Outro_0022)
    Wait(30)
    Call(N(func_80242084_8EDEA4))
    Call(EnableGroup, MODEL_g20, FALSE)
    Call(EnableGroup, MODEL_g21, FALSE)
    Call(EnableGroup, MODEL_g49, FALSE)
    Call(EnableModel, MODEL_g56, FALSE)
    Call(N(func_80242030_8EDE50))
    Call(RotateGroup, MODEL_g60, 0, 1, 0, 0)
    Call(RotateGroup, MODEL_g34, 0, -1, 0, 0)
    Call(EnableGroup, MODEL_g60, TRUE)
    Call(EnableGroup, MODEL_g34, TRUE)
    Call(UseSettingsFrom, CAM_DEFAULT, 340, 30, -70)
    Call(SetPanTarget, CAM_DEFAULT, 340, 30, -70)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetPlayerPos, 240, 30, -75)
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
    Call(SetNpcPos, NPC_Luigi_1, 200, 30, -75)
    Wait(30)
    Call(N(func_802420EC_8EDF0C))
    Call(N(SetAmbienceVolumeFull_Epilogue))
    Wait(30)
    Call(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 0, 8)
    Exec(N(EVS_OpenAndCloseDoor_Epilogue))
    Thread
        Wait(10)
        Call(SetNpcSpeed, NPC_Luigi_1, Float(3.0))
        Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Run)
        ExecGetTID(N(EVS_Luigi_PlayWalkSounds_Epilogue), LVarA)
        Call(NpcMoveTo, NPC_Luigi_1, 320, -70, 0)
        Call(NpcMoveTo, NPC_Luigi_1, 460, -70, 0)
        Call(NpcMoveTo, NPC_Luigi_1, 570, -170, 0)
        Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
        KillThread(LVarA)
    EndThread
    Call(func_802D1270, 320, -70, Float(3.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(func_802D1270, 460, -70, Float(3.0))
    Call(func_802D1270, 570, -170, Float(3.0))
    Call(SetPlayerJumpscale, Float(1.0))
    Call(PlayerJump, 594, 30, -216, 15)
    ExecWait(N(EVS_Player_EnterPipe_Epilogue))
    Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_JumpStance)
    Wait(10)
    Thread
        Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Jump)
        Call(PlaySoundAtNpc, NPC_Luigi_1, SOUND_QUICK_PLAYER_JUMP, SOUND_SPACE_DEFAULT)
        Wait(7)
        Wait(7)
        Call(SetNpcAnimation, NPC_Luigi_1, ANIM_Luigi_Idle)
        Call(PlaySoundAtNpc, NPC_Luigi_1, SOUND_LAND_SOFTLY, SOUND_SPACE_DEFAULT)
    EndThread
    Call(SetNpcJumpscale, NPC_Luigi_1, Float(1.0))
    Call(NpcJump0, NPC_Luigi_1, 594, 30, -216, 15)
    ExecWait(N(EVS_Luigi_EnterPipe_Epilogue))
    Exec(N(EVS_FadeOutAmbientSounds))
    Call(GotoMap, Ref("mac_00"), mac_00_ENTRY_7)
    Wait(100)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

MAP_RODATA_PAD(1,unk);
