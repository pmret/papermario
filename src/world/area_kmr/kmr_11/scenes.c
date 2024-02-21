#include "kmr_11.h"
#include "effects.h"
#include "sprite/player.h"

API_CALLABLE(N(MakeLensFlare)) {
    Bytecode* args = script->ptrReadPos;
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    fx_lens_flare(0, x, y, z, duration);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetCameraVFov)) {
    Bytecode* args = script->ptrReadPos;

    gCameras[CAM_DEFAULT].vfov = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_GoombaKingBlastoff) = {
    Wait(10)
    Thread
        Call(MakeLerp, 100, 10, 150, EASING_LINEAR)
        Label(0)
        Call(UpdateLerp)
        MulF(LVar0, Float(0.01))
        Call(SetNpcScale, NPC_GoombaKing, LVar0, LVar0, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    EndThread
    Call(SetNpcJumpscale, NPC_GoombaKing, Float(0.3))
    Call(NpcJump0, NPC_GoombaKing, -1600, 1000, -1600, 150)
    Call(PlaySoundAt, SOUND_LARGE_LENS_FLARE, SOUND_SPACE_DEFAULT, -1600, 1000, -1600)
    Call(N(MakeLensFlare), -1600, 1000, -1600, 40)
    Call(SetNpcPos, NPC_GoombaKing, NPC_DISPOSE_LOCATION)
    Call(RemoveNpc, NPC_GoombaKing)
    Return
    End
};

EvtScript N(EVS_FocusCam_FortressExterior) = {
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(SetCamType, CAM_DEFAULT, 4, FALSE)
    Call(SetCamPitch, CAM_DEFAULT, -7, 0)
    Call(SetCamPosA, CAM_DEFAULT, -1208, 881)
    Call(SetCamPosB, CAM_DEFAULT, -524, -89)
    Call(SetCamPosC, CAM_DEFAULT, 0, 110)
    Call(SetCamDistance, CAM_DEFAULT, 500)
    Return
    End
};

EvtScript N(EVS_FocusCam_BesidePlayer) = {
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(SetCamType, CAM_DEFAULT, 4, FALSE)
    Call(SetCamPitch, CAM_DEFAULT, -15, 25)
    Call(SetCamPosA, CAM_DEFAULT, -1208, 881)
    Call(SetCamPosB, CAM_DEFAULT, -579, -89)
    Call(SetCamPosC, CAM_DEFAULT, 0, 110)
    Call(SetCamDistance, CAM_DEFAULT, 200)
    Return
    End
};

EvtScript N(EVS_FocusCam_Battlement) = {
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(SetCamType, CAM_DEFAULT, 4, FALSE)
    Call(SetCamPitch, CAM_DEFAULT, -7, 2)
    Call(SetCamPosA, CAM_DEFAULT, -1681, 511)
    Call(SetCamPosB, CAM_DEFAULT, -430, -92)
    Call(SetCamPosC, CAM_DEFAULT, 0, 200)
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Return
    End
};

EvtScript N(EVS_RandomQuaking) = {
    Call(PlaySound, SOUND_KMR_TOWER_COLLAPSE_RUMBLE_LOOP)
    Label(0)
        Call(RandInt, 10, LVar0)
        Add(LVar0, 5)
        MulF(LVar0, Float(0.1))
        Call(ShakeCam, CAM_DEFAULT, 0, 20, LVar0)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_FortressCollapse_MakeDust1) = {
    PlayEffect(EFFECT_DUST, 0, -273, 345, -44, 70)
    Return
    End
};

EvtScript N(EVS_FortressCollapse_MakeDust2) = {
    PlayEffect(EFFECT_LANDING_DUST, 4, -253, 8, 118, 0)
    PlayEffect(EFFECT_LANDING_DUST, 4, -253, 18, 138, 0)
    PlayEffect(EFFECT_LANDING_DUST, 4, -253, 18, 98, 0)
    PlayEffect(EFFECT_LANDING_DUST, 4, -253, 28, 118, 0)
    Return
    End
};

EvtScript N(EVS_FortressCollapse_MakeDust3) = {
    PlayEffect(EFFECT_LANDING_DUST, 1, -346, 147, -21, 0)
    Return
    End
};

EvtScript N(EVS_FortressCollapse_MakeDust4) = {
    PlayEffect(EFFECT_LANDING_DUST, 1, -336, 147, -21, 0)
    Return
    End
};

EvtScript N(EVS_FortressCollapse_MakeDust5) = {
    PlayEffect(EFFECT_LANDING_DUST, 1, -249, 147, -64, 0)
    Return
    End
};

EvtScript N(EVS_FortressCollapse_MakeDust6) = {
    PlayEffect(EFFECT_LANDING_DUST, 1, -239, 147, -64, 0)
    Return
    End
};

EvtScript N(EVS_FortressCollapse_MakeDust7) = {
    PlayEffect(EFFECT_LANDING_DUST, 4, -158, -10, -175, 0)
    PlayEffect(EFFECT_LANDING_DUST, 4, -158, 0, -155, 0)
    PlayEffect(EFFECT_LANDING_DUST, 4, -158, 0, -195, 0)
    PlayEffect(EFFECT_LANDING_DUST, 4, -158, 10, -175, 0)
    Return
    End
};

EvtScript N(EVS_FortressCollapse_MakeDust8) = {
    PlayEffect(EFFECT_LANDING_DUST, 4, 263, -10, -264, 0)
    PlayEffect(EFFECT_LANDING_DUST, 4, 263, 0, -244, 0)
    PlayEffect(EFFECT_LANDING_DUST, 4, 263, 0, -284, 0)
    PlayEffect(EFFECT_LANDING_DUST, 4, 263, 10, -264, 0)
    Return
    End
};

EvtScript N(EVS_FortressCollapse_PlayFX) = {
    Call(PlaySound, SOUND_KMR_TOWER_RUMBLE)
    Exec(N(EVS_FortressCollapse_MakeDust1))
    Wait(97)
    Call(PlaySound, SOUND_DISTANT_THUD)
    Exec(N(EVS_FortressCollapse_MakeDust2))
    Wait(95)
    Call(PlaySound, SOUND_KMR_TOWER_COLLAPSE_THUD)
    Exec(N(EVS_FortressCollapse_MakeDust3))
    Exec(N(EVS_FortressCollapse_MakeDust4))
    Wait(34)
    Call(PlaySound, SOUND_KMR_TOWER_COLLAPSE_THUD)
    Exec(N(EVS_FortressCollapse_MakeDust5))
    Exec(N(EVS_FortressCollapse_MakeDust6))
    Wait(40)
    Call(PlaySound, SOUND_KMR_TOWER_COLLAPSE_UNFOLD)
    Wait(160)
    Call(PlaySound, SOUND_BOING)
    Wait(40)
    Call(PlaySound, SOUND_DISTANT_THUD)
    Exec(N(EVS_FortressCollapse_MakeDust7))
    Exec(N(EVS_FortressCollapse_MakeDust8))
    Return
    End
};

EvtScript N(EVS_FortressCollapse_PlayerReactions) = {
    Call(DisablePartnerAI, 0)
    Wait(37)
    Call(SetPlayerAnimation, ANIM_MarioW2_FlailArms)
    Wait(60)
    Call(SetPlayerAnimation, ANIM_Mario1_Flail)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPlayerJumpscale, Float(1.8))
    Call(PlayerJump1, LVar0, LVar1, LVar2, 10)
    Wait(30)
    Call(SetPlayerAnimation, ANIM_Mario1_Run)
    Call(SetPlayerSpeed, Float(6.0))
    Call(SetNpcSpeed, NPC_PARTNER, Float(6.0))
    Thread
        Call(NpcMoveTo, NPC_PARTNER, -573, 162, 0)
    EndThread
    Call(PlayerMoveTo, -547, 147, 0)
    Call(InterpPlayerYaw, 90, 0)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(EnablePartnerAI)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_Scene_SelfDestruct) = {
    Call(DisablePlayerInput, TRUE)
    Wait(15)
    Call(SetCamType, CAM_DEFAULT, 1, FALSE)
    Call(SetCamPitch, CAM_DEFAULT, 0, Float(-12.5))
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPosA, CAM_DEFAULT, -389, -12)
    Call(SetCamPosB, CAM_DEFAULT, -469, 156)
    Call(SetPanTarget, CAM_DEFAULT, -389, 120, -12)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 * DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetNpcPos, NPC_GoombaKing, -380, 0, -42)
    Wait(20 * DT)
    Call(SetNpcJumpscale, NPC_GoombaKing, Float(0.8))
    Call(NpcFacePlayer, NPC_GoombaKing, 0)
    Call(PlaySoundAtNpc, NPC_GoombaKing, SOUND_LARGE_ACTOR_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump1, NPC_GoombaKing, -380, 120, -42, 25 * DT)
    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
    Wait(10 * DT)
    Call(SetPlayerPos, -497, 0, 130)
    Call(InterpPlayerYaw, 270, 0)
    Call(SetNpcPos, NPC_PARTNER, -534, 0, 127)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    Call(SpeakToPlayer, NPC_GoombaKing, ANIM_GoombaKing_Idle, ANIM_GoombaKing_Idle, 0, MSG_CH0_00D8)
    Set(GB_StoryProgress, STORY_CH0_HIT_GATEHOUSE_SWITCH)
    Call(EnableModel, MODEL_eye_mask, TRUE)
    Wait(1)
    ExecGetTID(N(EVS_RandomQuaking), LVarA)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.7))
    Call(UseSettingsFrom, CAM_DEFAULT, 0, -100, 0)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(60 * DT)
    Call(SpeakToPlayer, NPC_GoombaKing, ANIM_GoombaKing_Idle, ANIM_GoombaKing_Idle, 0, MSG_CH0_00D9)
    Loop(100)
        Call(GetNpcPos, NPC_GoombaKing, LVar0, LVar1, LVar2)
        Sub(LVar1, 1)
        Call(SetNpcPos, NPC_GoombaKing, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(SetNpcPos, NPC_GoombaKing, -303, 286, -120)
    Call(FadeOutMusic, 0, 1000)
    Call(SetPlayerAnimation, ANIM_Mario1_VacantStare)
    Wait(30)
    KillThread(LVarA)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 100, Float(0.5))
        Call(ShakeCam, CAM_DEFAULT, 0, 15, Float(4.0))
        Call(ShakeCam, CAM_DEFAULT, 0, 83, Float(0.5))
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(1.5))
        Call(ShakeCam, CAM_DEFAULT, 0, 15, Float(0.5))
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(1.5))
        Call(ShakeCam, CAM_DEFAULT, 0, 170, Float(0.5))
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(3.0))
        Wait(50)
        Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(4.0))
        Wait(20)
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(0.5))
        Wait(20)
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(0.2))
        Call(PlaySound, SOUND_KMR_TOWER_COLLAPSE_RUMBLE_LOOP | SOUND_ID_TRIGGER_CHANGE_SOUND)
    EndThread
    Exec(N(EVS_PlayFortressAnimation))
    Exec(N(EVS_FortressCollapse_PlayFX))
    Exec(N(EVS_FortressCollapse_PlayerReactions))
    Wait(380)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, -150, 0)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(20)
    Exec(N(EVS_GoombaKingBlastoff))
    Exec(N(EVS_PlayBridgeAnimation))
    Wait(150)
    Wait(50)
    Call(EnableModel, MODEL_o416, FALSE)
    Call(EnableModel, MODEL_o415, FALSE)
    Call(EnableModel, MODEL_eye_mask, FALSE)
    Call(DeleteAnimatedModel, 1)
    Call(DeleteAnimatedModel, 0)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Exec(N(EVS_SetupMusic))
    Call(DisablePartnerAI, 0)
    Call(SetNpcJumpscale, NPC_PARTNER, Float(0.8))
    Loop(2)
        Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
        Wait(3)
    EndLoop
    Call(DisablePartnerAI, 0)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_00DA)
    Call(EnablePartnerAI)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt, COLLIDER_FLAGS_UPPER_MASK)
    Set(GB_StoryProgress, STORY_CH0_OPENED_BRIDGE_TO_TOAD_TOWN)
    Call(DisablePlayerInput, FALSE)
    Call(EnablePartnerAI)
    Unbind
    Return
    End
};

EvtScript N(EVS_BouncePlayerAndPartner) = {
    Thread
        Call(SetPlayerJumpscale, Float(2.0))
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(PlayerJump1, LVar0, LVar1, LVar2, LVar3)
    EndThread
    Call(SetNpcJumpscale, NPC_PARTNER, Float(2.0))
    Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(NpcJump1, NPC_PARTNER, LVar0, LVar1, LVar2, LVar3)
    Return
    End
};

EvtScript N(EVS_Scene_MeetGoombaKing_Impl) = {
    Call(DisablePlayerInput, TRUE)
    ExecWait(N(EVS_FocusCam_FortressExterior))
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.3 / DT))
    Call(PanToTarget, CAM_DEFAULT, Float(0.5), 1)
    Wait(170 * DT)
    Call(SetNpcPos, NPC_BlueGoombaBro, -830, 0, -70)
    Call(SetNpcPos, NPC_RedGoombaBro, -800, 0, -20)
    Call(SetNpcAnimation, NPC_BlueGoombaBro, ANIM_GoombaBros_Blue_CryRun)
    Call(SetNpcAnimation, NPC_RedGoombaBro, ANIM_GoombaBros_Red_CryRun)
    Call(SetNpcSpeed, NPC_BlueGoombaBro, Float(4.0 / DT))
    Call(SetNpcSpeed, NPC_RedGoombaBro, Float(4.0 / DT))
    Wait(50 * DT)
    Thread
        Call(NpcMoveTo, NPC_BlueGoombaBro, -521, -100, 0)
    EndThread
    Call(NpcMoveTo, NPC_RedGoombaBro, -504, -74, 0)
    Call(SpeakToPlayer, NPC_RedGoombaBro, ANIM_GoombaBros_Red_CryWalk, ANIM_GoombaBros_Red_CryIdle, 5, MSG_CH0_00C3)
    Call(SpeakToPlayer, NPC_BlueGoombaBro, ANIM_GoombaBros_Blue_CryWalk, ANIM_GoombaBros_Blue_CryIdle, 5, MSG_CH0_00C4)
    Call(PlaySoundAtCollider, COLLIDER_tt, SOUND_METAL_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 90, 30, EASING_COS_IN_OUT)
    Label(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o416, LVar0, 0, -1, 0)
        Call(RotateModel, MODEL_o415, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Thread
        Call(NpcMoveTo, NPC_BlueGoombaBro, -353, -93, 0)
    EndThread
    Call(NpcMoveTo, NPC_RedGoombaBro, -364, -77, 0)
    Call(MakeLerp, 90, 0, 30, EASING_COS_IN_OUT)
    Label(1)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o416, LVar0, 0, -1, 0)
        Call(RotateModel, MODEL_o415, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(1)
        EndIf
    Call(PlaySoundAtCollider, COLLIDER_tt, SOUND_METAL_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAt, SOUND_HEAVY_NPC_STEP_A, SOUND_SPACE_DEFAULT, -330, 0, -130)
    Call(PlaySoundAt, SOUND_HEAVY_NPC_STEP_B, SOUND_SPACE_DEFAULT, -330, 0, -130)
    PlayEffect(EFFECT_DROP_LEAVES, 0, -725, 117, -137, 100)
    PlayEffect(EFFECT_DROP_LEAVES, 0, -617, 108, -137, 100)
    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(0.5))
    Call(SetPlayerPos, -920, 0, -35)
    Call(SetPlayerSpeed, Float(3.0 / DT))
    Call(PlayerMoveTo, -575, -60, 0)
    Wait(30 * DT)
    Call(DisablePartnerAI, 0)
    Wait(10 * DT)
    Call(PlayerFaceNpc, NPC_PARTNER, FALSE)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_00C5)
    Call(InterpPlayerYaw, 90, 0)
    Wait(40 * DT)
    Call(PlaySoundAt, SOUND_HEAVY_NPC_STEP_A, SOUND_SPACE_DEFAULT, -330, 0, -130)
    Call(PlaySoundAt, SOUND_HEAVY_NPC_STEP_B, SOUND_SPACE_DEFAULT, -330, 0, -130)
    PlayEffect(EFFECT_DROP_LEAVES, 0, -725, 117, -137, 100)
    PlayEffect(EFFECT_DROP_LEAVES, 0, -617, 108, -137, 100)
    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(0.2))
    Set(LVar3, 2)
    Exec(N(EVS_BouncePlayerAndPartner))
    Wait(60 * DT)
    Call(PlaySoundAt, SOUND_HEAVY_NPC_STEP_A, SOUND_SPACE_DEFAULT, -330, 0, -130)
    Call(PlaySoundAt, SOUND_HEAVY_NPC_STEP_B, SOUND_SPACE_DEFAULT, -330, 0, -130)
    PlayEffect(EFFECT_DROP_LEAVES, 0, -725, 117, -137, 100)
    PlayEffect(EFFECT_DROP_LEAVES, 0, -617, 108, -137, 100)
    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(0.6))
    Set(LVar3, 4)
    Exec(N(EVS_BouncePlayerAndPartner))
    Wait(60 * DT)
    Call(PlaySoundAt, SOUND_HEAVY_NPC_STEP_A, SOUND_SPACE_DEFAULT, -330, 0, -130)
    Call(PlaySoundAt, SOUND_HEAVY_NPC_STEP_B, SOUND_SPACE_DEFAULT, -330, 0, -130)
    PlayEffect(EFFECT_DROP_LEAVES, 0, -725, 117, -137, 100)
    PlayEffect(EFFECT_DROP_LEAVES, 0, -617, 108, -137, 100)
    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
    Set(LVar3, 6)
    Exec(N(EVS_BouncePlayerAndPartner))
    Wait(60 * DT)
    Call(PlaySoundAt, SOUND_HEAVY_NPC_STEP_A, SOUND_SPACE_DEFAULT, -330, 0, -130)
    Call(PlaySoundAt, SOUND_HEAVY_NPC_STEP_B, SOUND_SPACE_DEFAULT, -330, 0, -130)
    PlayEffect(EFFECT_DROP_LEAVES, 0, -725, 117, -137, 100)
    PlayEffect(EFFECT_DROP_LEAVES, 0, -617, 108, -137, 100)
    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.5))
    Set(LVar3, 8)
    Exec(N(EVS_BouncePlayerAndPartner))
    Wait(28 * DT)
    Call(SetMusicTrack, 0, SONG_GOOMBA_KING_THEME, 0, 8)
    Wait(32 * DT)
    Call(SetNpcAnimation, NPC_BlueGoombaBro, ANIM_GoombaBros_Blue_Idle)
    Call(SetNpcAnimation, NPC_RedGoombaBro, ANIM_GoombaBros_Red_Idle)
    Call(SetNpcJumpscale, NPC_BlueGoombaBro, Float(0.8))
    Call(SetNpcJumpscale, NPC_RedGoombaBro, Float(0.8))
    Thread
        Call(SetNpcPos, NPC_BlueGoombaBro, -400, 0, -162)
        Call(PlaySoundAtNpc, NPC_BlueGoombaBro, SOUND_ACTOR_HURT, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_BlueGoombaBro, -432, 130, -146, 30 * DT)
    EndThread
    Call(SetNpcPos, NPC_RedGoombaBro, -400, 0, -41)
    Call(PlaySoundAtNpc, NPC_RedGoombaBro, SOUND_ACTOR_HURT, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_RedGoombaBro, -412, 130, -35, 30 * DT)
    Wait(10 * DT)
    Thread
        Call(SetNpcJumpscale, NPC_GoombaKing, Float(0.8))
        Call(SetNpcPos, NPC_GoombaKing, -405, 0, -91)
        Call(PlaySoundAtNpc, NPC_GoombaKing, SOUND_LARGE_ACTOR_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_GoombaKing, -419, 119, -91, 30 * DT)
        Call(PlaySoundAt, SOUND_HEAVY_NPC_STEP_A, SOUND_SPACE_DEFAULT, -330, 0, -130)
        Call(PlaySoundAt, SOUND_HEAVY_NPC_STEP_B, SOUND_SPACE_DEFAULT, -330, 0, -130)
        PlayEffect(EFFECT_DROP_LEAVES, 0, -725, 117, -137, 100)
        PlayEffect(EFFECT_DROP_LEAVES, 0, -617, 108, -137, 100)
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(1.0))
    EndThread
    ExecWait(N(EVS_FocusCam_Battlement))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(55 * DT)
    Call(SpeakToPlayer, NPC_GoombaKing, ANIM_GoombaKing_Idle, ANIM_GoombaKing_Idle, 0, MSG_CH0_00C6)
    Call(SpeakToPlayer, NPC_RedGoombaBro, ANIM_GoombaBros_Red_Walk, ANIM_GoombaBros_Red_Idle, 0, MSG_CH0_00C7)
    Call(SpeakToPlayer, NPC_BlueGoombaBro, ANIM_GoombaBros_Blue_Walk, ANIM_GoombaBros_Blue_Idle, 0, MSG_CH0_00C8)
    ExecWait(N(EVS_FocusCam_BesidePlayer))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(DisablePartnerAI, 0)
    Wait(5 * DT)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_00C9)
    Call(DisablePartnerAI, 0)
    ExecWait(N(EVS_FocusCam_Battlement))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(5 * DT)
    Call(SpeakToPlayer, NPC_GoombaKing, ANIM_GoombaKing_Idle, ANIM_GoombaKing_Idle, 0, MSG_CH0_00CA)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Wait(30 * DT)
    Call(SetNpcVar, NPC_GoombaKing, 0, 1)
    Return
    End
};

EvtScript N(EVS_Scene_MeetGoombaKing) = {
    Call(N(SetCameraVFov), 32)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Exec(N(EVS_Scene_MeetGoombaKing_Impl))
    Return
    End
};
