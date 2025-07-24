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
    Call(SetCamType, CAM_DEFAULT, 4, false)
    Call(SetCamSpeed, CAM_DEFAULT, LVar6)
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-10.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(500.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(88.0), Float(256.6))
    Call(SetCamPosB, CAM_DEFAULT, Float(195.0), Float(142.0))
    Call(SetCamPosC, CAM_DEFAULT, Float(0.0), Float(0.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_FocusCam_AfterBattle) = {
    Call(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(SetCamSpeed, CAM_DEFAULT, LVar6)
    Call(SetCamPitch, CAM_DEFAULT, Float(22.5), Float(-13.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_FocusCam_InFrontOfDoor) = {
    Call(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(SetCamSpeed, CAM_DEFAULT, LVar6)
    Call(SetCamPitch, CAM_DEFAULT, Float(22.5), Float(-11.5))
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_FocusCam_MidRoom) = {
    Call(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(SetCamSpeed, CAM_DEFAULT, LVar6)
    Call(SetCamPitch, CAM_DEFAULT, Float(22.5), Float(-10.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
    Call(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_FocusCam_JrTroopa) = {
    Call(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(SetCamSpeed, CAM_DEFAULT, LVar6)
    Call(SetCamPitch, CAM_DEFAULT, Float(22.5), Float(-13.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(175.0))
    Call(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_KoopaBros_Hop) = {
    Switch(LVar0)
        CaseEq(NPC_KoopaBrosRed)
            Call(SetNpcJumpscale, NPC_KoopaBrosRed, Float(1.0))
            Call(GetNpcPos, NPC_KoopaBrosRed, LVar1, LVar2, LVar3)
            Call(NpcJump0, NPC_KoopaBrosRed, LVar1, LVar2, LVar3, 10)
        CaseEq(NPC_KoopaBrosBlk)
            Call(SetNpcJumpscale, NPC_KoopaBrosBlk, Float(1.0))
            Call(GetNpcPos, NPC_KoopaBrosBlk, LVar1, LVar2, LVar3)
            Call(NpcJump0, NPC_KoopaBrosBlk, LVar1, LVar2, LVar3, 10)
        CaseEq(NPC_KoopaBrosYlw)
            Call(SetNpcJumpscale, NPC_KoopaBrosYlw, Float(1.0))
            Call(GetNpcPos, NPC_KoopaBrosYlw, LVar1, LVar2, LVar3)
            Call(NpcJump0, NPC_KoopaBrosYlw, LVar1, LVar2, LVar3, 10)
        CaseEq(NPC_KoopaBrosGrn)
            Call(SetNpcJumpscale, NPC_KoopaBrosGrn, Float(1.0))
            Call(GetNpcPos, NPC_KoopaBrosGrn, LVar1, LVar2, LVar3)
            Call(NpcJump0, NPC_KoopaBrosGrn, LVar1, LVar2, LVar3, 10)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_KoopaBros_SpinAround) = {
    Set(LVarA, LVar0)
    Call(MakeLerp, 0, 11 * 180, 50, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcRotation, LVarA, 0, LVar0, 0)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_KoopaBros_FlingAway) = {
    Thread
        Call(PlaySoundAtNpc, LVar0, SOUND_HIT_NORMAL, SOUND_SPACE_DEFAULT)
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(0.6))
    EndThread
    Switch(LVar0)
        CaseEq(NPC_KoopaBrosRed)
            Call(SetNpcAnimation, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_Shock)
            Call(SetNpcJumpscale, NPC_KoopaBrosRed, Float(0.7))
            Call(NpcJump0, NPC_KoopaBrosRed, -50, 200, 170, 40)
            Call(SetNpcFlagBits, NPC_KoopaBrosRed, NPC_FLAG_GRAVITY, false)
            Call(SetNpcPos, NPC_KoopaBrosRed, NPC_DISPOSE_LOCATION)
        CaseEq(NPC_KoopaBrosBlk)
            Call(SetNpcAnimation, NPC_KoopaBrosBlk, ANIM_KoopaBros_Black_Shock)
            Call(SetNpcJumpscale, NPC_KoopaBrosBlk, Float(0.7))
            Call(NpcJump0, NPC_KoopaBrosBlk, 0, 200, 127, 40)
            Call(SetNpcFlagBits, NPC_KoopaBrosRed, NPC_FLAG_GRAVITY, false)
            Call(SetNpcPos, NPC_KoopaBrosBlk, NPC_DISPOSE_LOCATION)
        CaseEq(NPC_KoopaBrosYlw)
            Call(SetNpcAnimation, NPC_KoopaBrosYlw, ANIM_KoopaBros_Yellow_Shock)
            Call(SetNpcJumpscale, NPC_KoopaBrosYlw, Float(0.7))
            Call(NpcJump0, NPC_KoopaBrosYlw, 100, 200, 200, 40)
            Call(SetNpcFlagBits, NPC_KoopaBrosYlw, NPC_FLAG_GRAVITY, false)
            Call(SetNpcPos, NPC_KoopaBrosYlw, NPC_DISPOSE_LOCATION)
        CaseEq(NPC_KoopaBrosGrn)
            Call(SetNpcAnimation, NPC_KoopaBrosGrn, ANIM_KoopaBros_Green_Shock)
            Call(SetNpcJumpscale, NPC_KoopaBrosGrn, Float(0.7))
            Call(NpcJump0, NPC_KoopaBrosGrn, 150, 200, 150, 40)
            Call(SetNpcFlagBits, NPC_KoopaBrosGrn, NPC_FLAG_GRAVITY, false)
            Call(SetNpcPos, NPC_KoopaBrosGrn, NPC_DISPOSE_LOCATION)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_Door) = {
    Call(DisablePlayerInput, true)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPlayerSpeed, Float(3.0 / DT))
    Call(PlayerMoveTo, -150, LVar2, 0)
    Call(SetCamType, CAM_DEFAULT, 6, false)
    Set(LVar6, Float(3.0 / DT))
    ExecWait(N(EVS_FocusCam_LookAtDoor))
    Set(MF_DoneIntroMessage, false)
    Thread
        Call(SetMusic, 0, SONG_FINAL_BOWSER_BATTLE, BGM_VARIATION_1, VOL_LEVEL_FULL)
        Wait(150)
        IfNe(MF_DoneIntroMessage, false)
            Goto(5)
        EndIf
        Call(FadeOutMusic, 0, 250)
        Wait(15)
        IfNe(MF_DoneIntroMessage, false)
            Goto(5)
        EndIf
        Call(SetMusic, 0, SONG_BOWSERS_CASTLE, 0, VOL_LEVEL_FULL)
        Wait(30)
        IfNe(MF_DoneIntroMessage, false)
            Goto(5)
        EndIf
        Call(SetTrackVolumes, TRACK_VOLS_KPA_3)
        Label(5)
    EndThread
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0053)
    Set(MF_DoneIntroMessage, true)
    Wait(2)
    Call(SetMusic, 0, SONG_KOOPA_BROS_THEME, BGM_VARIATION_2, VOL_LEVEL_FULL)
    Set(LVar3, 65)
    Set(LVar4, 0)
    Set(LVar5, 150)
    Set(LVar6, Float(90.0))
    ExecWait(N(EVS_FocusCam_InFrontOfDoor))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o166, COLLIDER_FLAGS_UPPER_MASK)
    Thread
        Call(SetNpcPos, NPC_KoopaBrosRed, 220, 180, 160)
        Call(SetNpcAnimation, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_Midair)
        Call(EnableNpcBlur, NPC_KoopaBrosRed, true)
        Call(SetNpcJumpscale, NPC_KoopaBrosRed, Float(1.0))
        Call(SetNpcFlagBits, NPC_KoopaBrosRed, NPC_FLAG_GRAVITY, true)
        Call(SetNpcFlagBits, NPC_KoopaBrosRed, NPC_FLAG_FLYING, false)
        Call(NpcMoveTo, NPC_KoopaBrosRed, 20, 160, 20)
        Call(PlaySoundAtNpc, NPC_KoopaBrosRed, SOUND_KOOPA_BROS_LAND, SOUND_SPACE_DEFAULT)
        PlayEffect(EFFECT_LANDING_DUST, 1, 20, 0, 160, 0)
        Call(EnableNpcBlur, NPC_KoopaBrosRed, false)
        Call(SetNpcAnimation, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_IdleCrouch)
        Call(SetNpcYaw, NPC_KoopaBrosRed, 270)
    EndThread
    Thread
        Wait(5)
        Call(SetNpcPos, NPC_KoopaBrosBlk, 248, 180, 185)
        Call(SetNpcAnimation, NPC_KoopaBrosBlk, ANIM_KoopaBros_Black_Midair)
        Call(EnableNpcBlur, NPC_KoopaBrosBlk, true)
        Call(SetNpcJumpscale, NPC_KoopaBrosBlk, Float(1.0))
        Call(SetNpcFlagBits, NPC_KoopaBrosBlk, NPC_FLAG_GRAVITY, true)
        Call(SetNpcFlagBits, NPC_KoopaBrosBlk, NPC_FLAG_FLYING, false)
        Call(NpcMoveTo, NPC_KoopaBrosBlk, 48, 185, 20)
        Call(PlaySoundAtNpc, NPC_KoopaBrosBlk, SOUND_KOOPA_BROS_LAND, SOUND_SPACE_DEFAULT)
        PlayEffect(EFFECT_LANDING_DUST, 1, 48, 0, 185, 0)
        Call(EnableNpcBlur, NPC_KoopaBrosBlk, false)
        Call(SetNpcAnimation, NPC_KoopaBrosBlk, ANIM_KoopaBros_Black_IdleCrouch)
        Call(SetNpcYaw, NPC_KoopaBrosBlk, 270)
    EndThread
    Thread
        Wait(10)
        Call(SetNpcPos, NPC_KoopaBrosYlw, 260, 180, 110)
        Call(SetNpcAnimation, NPC_KoopaBrosYlw, ANIM_KoopaBros_Yellow_Midair)
        Call(EnableNpcBlur, NPC_KoopaBrosYlw, true)
        Call(SetNpcJumpscale, NPC_KoopaBrosYlw, Float(1.0))
        Call(SetNpcFlagBits, NPC_KoopaBrosYlw, NPC_FLAG_GRAVITY, true)
        Call(SetNpcFlagBits, NPC_KoopaBrosYlw, NPC_FLAG_FLYING, false)
        Call(NpcMoveTo, NPC_KoopaBrosYlw, 60, 110, 20)
        Call(PlaySoundAtNpc, NPC_KoopaBrosYlw, SOUND_KOOPA_BROS_LAND, SOUND_SPACE_DEFAULT)
        PlayEffect(EFFECT_LANDING_DUST, 1, 60, 0, 110, 0)
        Call(EnableNpcBlur, NPC_KoopaBrosYlw, false)
        Call(SetNpcAnimation, NPC_KoopaBrosYlw, ANIM_KoopaBros_Yellow_IdleCrouch)
        Call(SetNpcYaw, NPC_KoopaBrosYlw, 270)
    EndThread
    Thread
        Wait(15)
        Call(SetNpcPos, NPC_KoopaBrosGrn, 288, 180, 155)
        Call(SetNpcAnimation, NPC_KoopaBrosGrn, ANIM_KoopaBros_Green_Midair)
        Call(EnableNpcBlur, NPC_KoopaBrosGrn, true)
        Call(SetNpcJumpscale, NPC_KoopaBrosGrn, Float(1.0))
        Call(SetNpcFlagBits, NPC_KoopaBrosGrn, NPC_FLAG_GRAVITY, true)
        Call(SetNpcFlagBits, NPC_KoopaBrosGrn, NPC_FLAG_FLYING, false)
        Call(NpcMoveTo, NPC_KoopaBrosGrn, 88, 155, 20)
        Call(PlaySoundAtNpc, NPC_KoopaBrosGrn, SOUND_KOOPA_BROS_LAND, SOUND_SPACE_DEFAULT)
        PlayEffect(EFFECT_LANDING_DUST, 1, 88, 0, 155, 0)
        Call(EnableNpcBlur, NPC_KoopaBrosGrn, false)
        Call(SetNpcAnimation, NPC_KoopaBrosGrn, ANIM_KoopaBros_Green_IdleCrouch)
        Call(SetNpcYaw, NPC_KoopaBrosGrn, 270)
    EndThread
    Wait(65)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o166, COLLIDER_FLAGS_UPPER_MASK)
    Thread
        Call(GetNpcPos, NPC_KoopaBrosRed, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Add(LVar1, 30)
        PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
        Call(PlaySoundAtNpc, NPC_KoopaBrosRed, SOUND_SMALL_LENS_FLARE, SOUND_SPACE_DEFAULT)
        Call(SetNpcAnimation, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_ThumbsUp)
    EndThread
    Thread
        Wait(5)
        Call(GetNpcPos, NPC_KoopaBrosBlk, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Add(LVar1, 30)
        PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
        Call(PlaySoundAtNpc, NPC_KoopaBrosBlk, SOUND_SMALL_LENS_FLARE, SOUND_SPACE_DEFAULT)
        Call(SetNpcAnimation, NPC_KoopaBrosBlk, ANIM_KoopaBros_Black_ThumbsUp)
    EndThread
    Thread
        Wait(10)
        Call(GetNpcPos, NPC_KoopaBrosYlw, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Add(LVar1, 30)
        PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
        Call(PlaySoundAtNpc, NPC_KoopaBrosYlw, SOUND_SMALL_LENS_FLARE, SOUND_SPACE_DEFAULT)
        Call(SetNpcAnimation, NPC_KoopaBrosYlw, ANIM_KoopaBros_Yellow_ThumbsUp)
    EndThread
    Thread
        Wait(15)
        Call(GetNpcPos, NPC_KoopaBrosGrn, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Add(LVar1, 30)
        PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
        Call(PlaySoundAtNpc, NPC_KoopaBrosGrn, SOUND_SMALL_LENS_FLARE, SOUND_SPACE_DEFAULT)
        Call(SetNpcAnimation, NPC_KoopaBrosGrn, ANIM_KoopaBros_Green_ThumbsUp)
    EndThread
    Wait(45)
    Call(SetNpcAnimation, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_ThumbsUp)
    Call(SetNpcAnimation, NPC_KoopaBrosBlk, ANIM_KoopaBros_Black_ThumbsUp)
    Call(SetNpcAnimation, NPC_KoopaBrosYlw, ANIM_KoopaBros_Yellow_ThumbsUp)
    Call(SetNpcAnimation, NPC_KoopaBrosGrn, ANIM_KoopaBros_Green_ThumbsUp)
    Thread
        Call(SetPlayerSpeed, Float(3.0 / DT))
        Call(PlayerMoveTo, -50, 150, 0)
    EndThread
    Call(SpeakToPlayer, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_ThumbsUp, ANIM_KoopaBros_Red_ThumbsUp, 0, MSG_CH8_0054)
    Set(LVar3, 0)
    Set(LVar4, 0)
    Set(LVar5, 150)
    Set(LVar6, Float(3.0 / DT))
    ExecWait(N(EVS_FocusCam_MidRoom))
    Call(SetNpcAnimation, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_Idle)
    Call(SetNpcAnimation, NPC_KoopaBrosBlk, ANIM_KoopaBros_Black_Idle)
    Call(SetNpcAnimation, NPC_KoopaBrosYlw, ANIM_KoopaBros_Yellow_Idle)
    Call(SetNpcAnimation, NPC_KoopaBrosGrn, ANIM_KoopaBros_Green_Idle)
    Call(SpeakToPlayer, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 0, MSG_CH8_0055)
    Call(ShowChoice, MSG_Choice_0013)
    IfEq(LVar0, 0)
        Call(ContinueSpeech, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 0, MSG_CH8_0056)
    Else
        Call(ContinueSpeech, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 0, MSG_CH8_0057)
    EndIf
    Set(LVar6, Float(3.0 / DT))
    ExecWait(N(EVS_FocusCam_LookAtDoor))
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0058)
    Set(LVar3, 0)
    Set(LVar4, 0)
    Set(LVar5, 150)
    Set(LVar6, Float(90.0))
    ExecWait(N(EVS_FocusCam_MidRoom))
    Call(SpeakToPlayer, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 0, MSG_CH8_0059)
    Call(SetMusic, 0, SONG_JR_TROOPA_THEME, BGM_VARIATION_1, VOL_LEVEL_FULL)
    Call(ShowMessageAtScreenPos, MSG_CH8_005A, 0, 150)
    Call(InterpPlayerYaw, 270, 0)
    Wait(10)
    Call(SetNpcPos, NPC_JrTroopa, -150, 0, 140)
    Call(SetNpcAnimation, NPC_JrTroopa, ANIM_JrTroopa_ChargeArmsUp)
    Call(SetNpcSpeed, NPC_JrTroopa, Float(8.0))
    Thread
        Call(SetPlayerAnimation, ANIM_Mario1_Flail)
        Loop(0)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(GetNpcPos, NPC_JrTroopa, LVar3, LVar4, LVar5)
            IfLe(LVar0, LVar3)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        Call(SetPlayerFlagBits, PS_FLAG_NO_STATIC_COLLISION | PS_FLAG_ROTATION_LOCKED | PS_FLAG_FACE_FORWARD, true)
        Call(MakeLerp, 0, 11 * 180, 50, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(InterpPlayerYaw, LVar0, 0)
            Call(N(SetPlayerSpriteFacingAngle))
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(SetPlayerFlagBits, PS_FLAG_NO_STATIC_COLLISION | PS_FLAG_ROTATION_LOCKED | PS_FLAG_FACE_FORWARD, false)
        Call(InterpPlayerYaw, 90, 0)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    EndThread
    Set(LVar0, NPC_KoopaBrosRed)
    ExecGetTID(N(EVS_KoopaBros_Hop), MV_KoopaBrosRed_HopScript)
    Set(LVar0, NPC_KoopaBrosBlk)
    ExecGetTID(N(EVS_KoopaBros_Hop), MV_KoopaBrosBlk_HopScript)
    Set(LVar0, NPC_KoopaBrosYlw)
    ExecGetTID(N(EVS_KoopaBros_Hop), MV_KoopaBrosYlw_HopScript)
    Set(LVar0, NPC_KoopaBrosGrn)
    ExecGetTID(N(EVS_KoopaBros_Hop), MV_KoopaBrosGrn_HopScript)
    Call(NpcMoveTo, NPC_JrTroopa, 22, 140, 0)
    Set(LVar0, NPC_KoopaBrosRed)
    Exec(N(EVS_KoopaBros_SpinAround))
    Call(NpcMoveTo, NPC_JrTroopa, 50, 140, 0)
    Set(LVar0, NPC_KoopaBrosBlk)
    Exec(N(EVS_KoopaBros_SpinAround))
    Call(NpcMoveTo, NPC_JrTroopa, 62, 140, 0)
    Set(LVar0, NPC_KoopaBrosYlw)
    Exec(N(EVS_KoopaBros_SpinAround))
    Call(NpcMoveTo, NPC_JrTroopa, 90, 140, 0)
    Set(LVar0, NPC_KoopaBrosGrn)
    Exec(N(EVS_KoopaBros_SpinAround))
    Call(NpcMoveTo, NPC_JrTroopa, 100, 140, 0)
    Call(NpcMoveTo, NPC_JrTroopa, 98, 140, 0)
    KillThread(MV_KoopaBrosGrn_HopScript)
    Set(LVar0, NPC_KoopaBrosGrn)
    Exec(N(EVS_KoopaBros_FlingAway))
    Call(NpcMoveTo, NPC_JrTroopa, 25, 140, 0)
    Call(NpcMoveTo, NPC_JrTroopa, 70, 140, 0)
    KillThread(MV_KoopaBrosYlw_HopScript)
    Set(LVar0, NPC_KoopaBrosYlw)
    Exec(N(EVS_KoopaBros_FlingAway))
    Call(NpcMoveTo, NPC_JrTroopa, 75, 140, 0)
    Call(NpcMoveTo, NPC_JrTroopa, 30, 140, 0)
    KillThread(MV_KoopaBrosRed_HopScript)
    Set(LVar0, NPC_KoopaBrosRed)
    Exec(N(EVS_KoopaBros_FlingAway))
    Call(NpcMoveTo, NPC_JrTroopa, 25, 140, 0)
    Call(NpcMoveTo, NPC_JrTroopa, 58, 140, 0)
    KillThread(MV_KoopaBrosBlk_HopScript)
    Set(LVar0, NPC_KoopaBrosBlk)
    Exec(N(EVS_KoopaBros_FlingAway))
    Call(NpcMoveTo, NPC_JrTroopa, 75, 140, 0)
    Call(InterpNpcYaw, NPC_JrTroopa, 270, 0)
    Wait(5)
    Call(GetNpcPos, NPC_JrTroopa, LVar0, LVar1, LVar2)
    Call(NpcMoveTo, NPC_JrTroopa, 100, 140, 0)
    Call(SetNpcAnimation, NPC_JrTroopa, ANIM_JrTroopa_Idle)
    Call(SetNpcYaw, NPC_JrTroopa, 270)
    Call(ShowMessageAtScreenPos, MSG_CH8_005B, 160, 40)
    Wait(10)
    Set(LVar3, 100)
    Set(LVar4, 0)
    Set(LVar5, 150)
    Set(LVar6, Float(3.0 / DT))
    ExecWait(N(EVS_FocusCam_JrTroopa))
    Call(SpeakToPlayer, NPC_JrTroopa, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle, 0, MSG_CH8_005C)
    Set(LVar3, 0)
    Set(LVar4, 0)
    Set(LVar5, 150)
    Set(LVar6, Float(3.0 / DT))
    ExecWait(N(EVS_FocusCam_AfterBattle))
    Call(SetNpcAnimation, NPC_JrTroopa, ANIM_JrTroopa_ChargeArmsUp)
    Thread
        Wait(5)
        Call(SetNpcSpeed, NPC_JrTroopa, Float(5.0))
        Call(NpcMoveTo, NPC_JrTroopa, -30, 140, 0)
    EndThread
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 60)
    Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(StartBossBattle, SONG_JR_TROOPA_BATTLE)
    Call(SpeakToPlayer, NPC_JrTroopa, ANIM_JrTroopa_Dizzy, ANIM_JrTroopa_Dizzy, 0, MSG_CH8_0061)
    Set(MV_Sync_AfterBattleCamMovement, 0)
    Thread
        Set(LVar3, 0)
        Set(LVar4, 0)
        Set(LVar5, 150)
        Set(LVar6, Float(3.0 / DT))
        ExecWait(N(EVS_FocusCam_AfterBattle))
        Call(ShowMessageAtScreenPos, MSG_CH8_0062, 160, 40)
        Set(MV_Sync_AfterBattleCamMovement, 1)
    EndThread
    Call(SetNpcAnimation, NPC_JrTroopa, ANIM_JrTroopa_ChargeArmsUp)
    Call(SetNpcSpeed, NPC_JrTroopa, Float(8.0))
    Call(NpcMoveTo, NPC_JrTroopa, -50, 140, 0)
    Call(InterpPlayerYaw, 270, 0)
    Call(NpcMoveTo, NPC_JrTroopa, -200, 140, 0)
    Call(SetNpcPos, NPC_JrTroopa, NPC_DISPOSE_LOCATION)
    Exec(N(EVS_SetupMusic))
    Loop(0)
        IfEq(MV_Sync_AfterBattleCamMovement, 1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Set(LVar6, Float(3.0 / DT))
    ExecWait(N(EVS_FocusCam_LookAtDoor))
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0063)
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Set(GB_KPA83_BowserDoorState, 1)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Door) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Set(LVar3, 100)
            Set(LVar4, 0)
            Set(LVar5, 150)
            Set(LVar6, Float(90.0))
            ExecWait(N(EVS_FocusCam_JrTroopa))
            Call(SetNpcAnimation, NPC_JrTroopa, ANIM_JrTroopa_Dizzy)
            Call(SetNpcPos, NPC_JrTroopa, 100, 0, 140)
            Call(SetNpcPos, NPC_SELF, 184, 20, 150)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Door) = {
    IfEq(GB_KPA83_BowserDoorState, 0)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Door)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Door)))
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_USE_INSPECT_ICON, true)
        Call(SetNpcPos, NPC_SELF, 184, 20, 150)
        Call(EnableNpcShadow, NPC_SELF, false)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_KoopaBros) = {
    Return
    End
};

EvtScript N(EVS_NpcInit_JrTroopa) = {
    Return
    End
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Enemies), BTL_KMR_3_FORMATION_07),
    {}
};
