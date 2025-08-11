#include "kmr_20.h"
#include "model.h"
#include "sprite/player.h"

#define NAME_SUFFIX _Intro
#include "world/common/entity/Pipe.inc.c"
#include "common/foliage.inc.c"
#define NAME_SUFFIX

API_CALLABLE(N(func_80241C9C_8EDABC)) {
    mdl_group_set_custom_gfx(MODEL_g62, CUSTOM_GFX_NONE, ENV_TINT_SHROUD, true);
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
    Call(GetNpcAnimation, NPC_Scene_Luigi, LVar0)
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
            Call(PlaySoundAtNpc, NPC_Scene_Luigi, SOUND_SEQ_LUIGI_STEP, SOUND_SPACE_DEFAULT)
            Wait(LVar1)
        EndLoop
    EndChildThread
    Loop(0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Player_EnterPipe_Intro) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(HidePlayerShadow, true)
    Set(LVar0, kmr_20_ENTRY_4)
    Call(N(Pipe_GetEntryPos_Intro))
    Call(PlayerMoveTo, LVar1, LVar3, 3)
    Set(LVar0, kmr_20_ENTRY_4)
    Call(N(Pipe_GetEntryPos_Intro))
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

EvtScript N(EVS_Luigi_EnterPipe_Intro) = {
    Call(SetNpcFlagBits, NPC_Scene_Luigi, NPC_FLAG_GRAVITY, false)
    Call(SetNpcFlagBits, NPC_Scene_Luigi, NPC_FLAG_FLYING, true)
    Call(EnableNpcShadow, NPC_Scene_Luigi, false)
    Set(LVar0, kmr_20_ENTRY_4)
    Call(N(Pipe_GetEntryPos_Intro))
    Call(NpcMoveTo, NPC_Scene_Luigi, LVar1, LVar3, 3)
    Set(LVar0, kmr_20_ENTRY_4)
    Call(N(Pipe_GetEntryPos_Intro))
    Call(SetNpcPos, NPC_Scene_Luigi, LVar1, LVar2, LVar3)
    Wait(2)
    Call(PlaySoundAtNpc, NPC_Scene_Luigi, SOUND_ENTER_PIPE, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_Still)
    Thread
        Call(GetNpcPos, NPC_Scene_Luigi, LVar0, LVar1, LVar2)
        Add(LVar1, 7)
        Call(SetNpcPos, NPC_Scene_Luigi, LVar0, LVar1, LVar2)
        Loop(40)
            Sub(LVar1, 1)
            Call(SetNpcPos, NPC_Scene_Luigi, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcImgFXFlags, NPC_Scene_Luigi, IMGFX_FLAG_800)
    Call(SetNpcImgFXParams, NPC_Scene_Luigi, IMGFX_SET_ANIM, IMGFX_ANIM_VERTICAL_PIPE_CURL, 1, 1, 0)
    Wait(25)
    Return
    End
};

EvtScript N(EVS_FocusCam_Unused) = {
    Call(UseSettingsFrom, CAM_DEFAULT, 250, 30, -80)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(N(func_80241CF0_8EDB10), Float(1.8))
    Call(InterpCamTargetPos, 0, 1, 250, 30, -80, 10)
    Call(N(func_80241CF0_8EDB10), 1)
    Return
    End
};

EvtScript N(EVS_TetherCamToLuigi) = {
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetNpcVar, NPC_Scene_Luigi, 0, 1)
    Loop(0)
        Call(GetNpcPos, NPC_Scene_Luigi, LVar0, LVar1, LVar2)
        Sub(LVar0, 20)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Call(GetNpcVar, NPC_Scene_Luigi, 0, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_OpenAndCloseDoor_Intro_Impl) = {
    Call(PlaySoundAtCollider, COLLIDER_o246, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 80, 14, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_g14, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(30)
    Call(MakeLerp, 80, 0, 8, EASING_QUADRATIC_OUT)
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

EvtScript N(EVS_OpenAndCloseDoor_Intro) = {
    Call(EnableGroup, MODEL_g72, true)
    ExecWait(N(EVS_OpenAndCloseDoor_Intro_Impl))
    Call(EnableGroup, MODEL_g72, false)
    Return
    End
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
    Call(DisablePlayerInput, true)
    Thread
        Wait(5 * DT)
        Call(SetMusic, 0, SONG_MAIL_CALL, 0, VOL_LEVEL_FULL)
    EndThread
    Call(InterpPlayerYaw, 90, 0)
    Call(SetPlayerPos, -50, 30, -80)
    Call(SetNpcPos, NPC_Scene_Luigi, 220, 30, -80)
    Call(SetNpcPos, NPC_Scene_Parakarry, 720, 220, -150)
    Call(SetNpcYaw, NPC_Scene_Parakarry, 270)
    Call(EnableGroup, MODEL_g94, false)
    Call(EnableGroup, MODEL_g100, true)
    Call(UseSettingsFrom, CAM_DEFAULT, 550, 0, 20)
    Call(SetPanTarget, CAM_DEFAULT, 550, 0, 20)
    Call(SetCamDistance, CAM_DEFAULT, 550)
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-14.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Wait(1)
    Call(SetCamDistance, CAM_DEFAULT, 450)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.7))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Thread
        Wait(10 * DT)
        Call(MakeLerp, 0, 70, 60 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_g108, LVar0, 0, 0)
            SetF(LVar2, 0)
            SubF(LVar2, LVar0)
            Call(TranslateGroup, MODEL_g106, LVar2, 0, 0)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
    EndThread
    Thread
        Wait(30 * DT)
        Call(MakeLerp, 0, 50, 40 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_g109, LVar0, 0, 0)
            SetF(LVar2, 0)
            SubF(LVar2, LVar0)
            Call(TranslateGroup, MODEL_g107, LVar2, 0, 0)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
    EndThread
    Thread
        Wait(50 * DT)
        Call(MakeLerp, 0, 50, 40 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_g105, LVar0, 0, 0)
            Call(TranslateGroup, MODEL_g102, LVar0, 0, 0)
            SetF(LVar2, 0)
            SubF(LVar2, LVar0)
            Call(TranslateGroup, MODEL_g103, LVar2, 0, 0)
            Call(TranslateGroup, MODEL_g104, LVar2, 0, 0)
            Call(TranslateGroup, MODEL_g101, LVar2, 0, 0)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
    EndThread
    Wait(120 * DT)
    Call(NpcFlyTo, NPC_Scene_Parakarry, 430, 20, -165, 60 * DT, -10, EASING_LINEAR)
    Call(InterpNpcYaw, NPC_Scene_Parakarry, 45, 10)
    Wait(20 * DT)
    Call(PlaySoundAtNpc, NPC_Scene_Parakarry, SOUNC_CHECK_MAILBOX, SOUND_SPACE_DEFAULT)
    Thread
        Call(TranslateModel, MODEL_o222, 2, 0, 0)
        Call(TranslateModel, MODEL_o223, 2, 0, 0)
        Call(TranslateModel, MODEL_o224, 2, 0, 0)
        Wait(1)
        Call(TranslateModel, MODEL_o222, -3, 0, 0)
        Call(TranslateModel, MODEL_o223, -3, 0, 0)
        Call(TranslateModel, MODEL_o224, -3, 0, 0)
        Wait(1)
        Call(TranslateModel, MODEL_o222, 2, 0, 0)
        Call(TranslateModel, MODEL_o223, 2, 0, 0)
        Call(TranslateModel, MODEL_o224, 2, 0, 0)
        Wait(1)
        Call(TranslateModel, MODEL_o222, -3, 0, 0)
        Call(TranslateModel, MODEL_o223, -3, 0, 0)
        Call(TranslateModel, MODEL_o224, -3, 0, 0)
        Wait(1)
        Call(TranslateModel, MODEL_o222, 0, 0, 0)
        Call(TranslateModel, MODEL_o223, 0, 0, 0)
        Call(TranslateModel, MODEL_o224, 0, 0, 0)
    EndThread
    Wait(35 * DT)
    Call(InterpNpcYaw, NPC_Scene_Parakarry, 220, 5)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Scene_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, MSG_Intro_001E)
    Wait(10 * DT)
    Call(NpcFlyTo, NPC_Scene_Parakarry, 360, 260, 60, 60 * DT, -10, EASING_LINEAR)
    Wait(30 * DT)
    Exec(N(EVS_OpenAndCloseDoor_Intro))
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_Run)
    ExecGetTID(N(EVS_Luigi_PlayWalkSounds_Intro), LVarA)
    Call(SetNpcSpeed, NPC_Scene_Luigi, Float(4.0 / DT))
    Call(NpcMoveTo, NPC_Scene_Luigi, 450, -80, 0)
    Call(NpcMoveTo, NPC_Scene_Luigi, 430, -165, 0)
    Call(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_Idle)
    KillThread(LVarA)
    Wait(20 * DT)
    Call(PlaySoundAtNpc, NPC_Scene_Luigi, SOUNC_CHECK_MAILBOX, SOUND_SPACE_DEFAULT)
    Thread
        Call(TranslateModel, MODEL_o222, 1, 0, 0)
        Call(TranslateModel, MODEL_o223, 1, 0, 0)
        Call(TranslateModel, MODEL_o224, 1, 0, 0)
        Wait(1)
        Call(TranslateModel, MODEL_o222, -2, 0, 0)
        Call(TranslateModel, MODEL_o223, -2, 0, 0)
        Call(TranslateModel, MODEL_o224, -2, 0, 0)
        Wait(1)
        Call(TranslateModel, MODEL_o222, 1, 0, 0)
        Call(TranslateModel, MODEL_o223, 1, 0, 0)
        Call(TranslateModel, MODEL_o224, 1, 0, 0)
        Wait(1)
        Call(TranslateModel, MODEL_o222, -2, 0, 0)
        Call(TranslateModel, MODEL_o223, -2, 0, 0)
        Call(TranslateModel, MODEL_o224, -2, 0, 0)
        Wait(1)
        Call(TranslateModel, MODEL_o222, 0, 0, 0)
        Call(TranslateModel, MODEL_o223, 0, 0, 0)
        Call(TranslateModel, MODEL_o224, 0, 0, 0)
    EndThread
    Wait(2)
    Call(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_IdleLetter)
    Wait(40 * DT)
    Call(InterpNpcYaw, NPC_Scene_Luigi, 270, 5)
    Call(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_RunLetter)
    ExecGetTID(N(EVS_Luigi_PlayWalkSounds_Intro), LVarA)
    Call(NpcMoveTo, NPC_Scene_Luigi, 450, -80, 0)
    Call(NpcMoveTo, NPC_Scene_Luigi, 290, -70, 0)
    KillThread(LVarA)
    Call(EnableGroup, MODEL_g20, true)
    Call(EnableGroup, MODEL_g21, true)
    Call(EnableGroup, MODEL_g49, true)
    Call(EnableModel, MODEL_g56, true)
    Call(N(func_80241C9C_8EDABC))
    Call(RotateGroup, MODEL_g60, 90, 1, 0, 0)
    Call(RotateGroup, MODEL_g34, 90, -1, 0, 0)
    Call(EnableGroup, MODEL_g60, false)
    Call(EnableGroup, MODEL_g34, false)
    Call(UseSettingsFrom, CAM_DEFAULT, 250, 30, -80)
    Call(SetPanTarget, CAM_DEFAULT, 250, 30, -80)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(N(SetAmbienceVolumeHalf_Intro))
    Exec(N(EVS_OpenAndCloseDoor_Intro_Impl))
    Wait(10)
    Call(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_WalkLetter)
    ExecGetTID(N(EVS_Luigi_PlayWalkSounds_Intro), LVarA)
    Call(SetNpcSpeed, NPC_Scene_Luigi, Float(2.0 / DT))
    Call(NpcMoveTo, NPC_Scene_Luigi, 240, -80, 0)
    Call(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_IdleLetter)
    KillThread(LVarA)
    Call(SpeakToPlayer, NPC_Scene_Luigi, ANIM_Luigi_TalkLetter, ANIM_Luigi_IdleLetter, 0, MSG_Intro_001F)
    Wait(10 * DT)
    Exec(N(EVS_TetherCamToLuigi))
    Thread
        Call(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_WalkLetter)
        ExecGetTID(N(EVS_Luigi_PlayWalkSounds_Intro), LVarA)
        Call(NpcMoveTo, NPC_Scene_Luigi, 230, -130, 0)
        Call(NpcMoveTo, NPC_Scene_Luigi, 110, -110, 0)
        Call(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_IdleLetter)
        KillThread(LVarA)
        Call(SetNpcVar, NPC_Scene_Luigi, 0, 0)
    EndThread
    Wait(20 * DT)
    Call(func_802D1270, 70, -80, Float(2.0 / DT))
    Call(func_802D1270, 70, -110, Float(2.0 / DT))
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Scene_Luigi, ANIM_Luigi_TalkLetter, ANIM_Luigi_IdleLetter, 0, MSG_Intro_0020)
    Call(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_OpenLetter)
    Wait(20 * DT)
    Call(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_IdleRead)
    Call(SpeakToPlayer, NPC_Scene_Luigi, ANIM_Luigi_TalkRead, ANIM_Luigi_IdleRead, 0, MSG_Intro_0021)
    Call(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_ReadLetter)
    Wait(10 * DT)
    Call(SetMusic, 0, SONG_PRISONER_PEACH_THEME, 0, VOL_LEVEL_FULL)
    Wait(5 * DT)
    Call(ClearAmbientSounds, 250)
    Call(GotoMapSpecial, Ref("osr_00"), osr_00_ENTRY_3, TRANSITION_SLOW_FADE_TO_WHITE)
    Wait(15 * DT)
    Call(ClearAmbientSounds, 250)
    Wait(100 * DT)
    Return
    End
};

EvtScript N(EVS_Scene_SettingOff) = {
    Call(DisablePlayerInput, true)
    Call(SetNpcPos, NPC_Scene_Luigi, 220, 30, -70)
    Call(SetNpcYaw, NPC_Scene_Luigi, 90)
    Call(UseSettingsFrom, CAM_DEFAULT, 320, 30, -70)
    Call(SetPanTarget, CAM_DEFAULT, 320, 30, -70)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Wait(60 * DT)
    Call(SetMusic, 0, SONG_PEACHS_CASTLE_PARTY, BGM_VARIATION_1, VOL_LEVEL_FULL)
    Exec(N(EVS_OpenAndCloseDoor_Intro))
    Thread
        Wait(10 * DT)
        Call(SetNpcSpeed, NPC_Scene_Luigi, Float(3.0 / DT))
        Call(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_Run)
        ExecGetTID(N(EVS_Luigi_PlayWalkSounds_Intro), LVarA)
        Call(NpcMoveTo, NPC_Scene_Luigi, 320, -70, 0)
        Call(NpcMoveTo, NPC_Scene_Luigi, 460, -70, 0)
        Call(NpcMoveTo, NPC_Scene_Luigi, 570, -170, 0)
        Call(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_Idle)
        KillThread(LVarA)
    EndThread
    Call(func_802D1270, 320, -70, Float(3.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Call(func_802D1270, 460, -70, Float(3.0 / DT))
    Call(func_802D1270, 570, -170, Float(3.0 / DT))
    Call(SetPlayerJumpscale, Float(1.0))
    Call(PlayerJump, 594, 30, -216, 15 * DT)
    ExecWait(N(EVS_Player_EnterPipe_Intro))
    Call(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_JumpStance)
    Wait(10 * DT)
    Thread
        Call(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_Jump)
        Call(PlaySoundAtNpc, NPC_Scene_Luigi, SOUND_QUICK_PLAYER_JUMP, SOUND_SPACE_DEFAULT)
        Wait(7 * DT)
        Wait(7 * DT)
        Call(SetNpcAnimation, NPC_Scene_Luigi, ANIM_Luigi_Idle)
        Call(PlaySoundAtNpc, NPC_Scene_Luigi, SOUND_LAND_SOFTLY, SOUND_SPACE_DEFAULT)
    EndThread
    Call(SetNpcJumpscale, NPC_Scene_Luigi, Float(1.0))
    Call(NpcJump0, NPC_Scene_Luigi, 594, 30, -216, 15 * DT)
    ExecWait(N(EVS_Luigi_EnterPipe_Intro))
    Exec(N(EVS_FadeOutAmbientSounds))
    Call(GotoMap, Ref("mac_00"), mac_00_ENTRY_5)
    Wait(100)
    Call(DisablePlayerInput, false)
    Return
    End
};
