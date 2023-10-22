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
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(MakeLerp, 100, 10, 150, EASING_LINEAR)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_MULF(LVar0, EVT_FLOAT(0.01))
        EVT_CALL(SetNpcScale, NPC_GoombaKing, LVar0, LVar0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_GoombaKing, EVT_FLOAT(0.3))
    EVT_CALL(NpcJump0, NPC_GoombaKing, -1600, 1000, -1600, 150)
    EVT_CALL(PlaySoundAt, SOUND_LARGE_LENS_FLARE, SOUND_SPACE_DEFAULT, -1600, 1000, -1600)
    EVT_CALL(N(MakeLensFlare), -1600, 1000, -1600, 40)
    EVT_CALL(SetNpcPos, NPC_GoombaKing, NPC_DISPOSE_LOCATION)
    EVT_CALL(RemoveNpc, NPC_GoombaKing)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCam_FortressExterior) = {
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, -7, 0)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -1208, 881)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, -524, -89)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 110)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 500)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCam_BesidePlayer) = {
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, -15, 25)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -1208, 881)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, -579, -89)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 110)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 200)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCam_Battlement) = {
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, -7, 2)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -1681, 511)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, -430, -92)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 200)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RandomQuaking) = {
    EVT_CALL(PlaySound, SOUND_KMR_TOWER_COLLAPSE_RUMBLE_LOOP)
    EVT_LABEL(0)
        EVT_CALL(RandInt, 10, LVar0)
        EVT_ADD(LVar0, 5)
        EVT_MULF(LVar0, EVT_FLOAT(0.1))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, LVar0)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FortressCollapse_MakeDust1) = {
    EVT_PLAY_EFFECT(EFFECT_DUST, 0, -273, 345, -44, 70)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FortressCollapse_MakeDust2) = {
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, -253, 8, 118, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, -253, 18, 138, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, -253, 18, 98, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, -253, 28, 118, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FortressCollapse_MakeDust3) = {
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, -346, 147, -21, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FortressCollapse_MakeDust4) = {
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, -336, 147, -21, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FortressCollapse_MakeDust5) = {
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, -249, 147, -64, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FortressCollapse_MakeDust6) = {
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, -239, 147, -64, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FortressCollapse_MakeDust7) = {
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, -158, -10, -175, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, -158, 0, -155, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, -158, 0, -195, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, -158, 10, -175, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FortressCollapse_MakeDust8) = {
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, 263, -10, -264, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, 263, 0, -244, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, 263, 0, -284, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, 263, 10, -264, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FortressCollapse_PlayFX) = {
    EVT_CALL(PlaySound, SOUND_KMR_TOWER_RUMBLE)
    EVT_EXEC(N(EVS_FortressCollapse_MakeDust1))
    EVT_WAIT(97)
    EVT_CALL(PlaySound, SOUND_DISTANT_THUD)
    EVT_EXEC(N(EVS_FortressCollapse_MakeDust2))
    EVT_WAIT(95)
    EVT_CALL(PlaySound, SOUND_KMR_TOWER_COLLAPSE_THUD)
    EVT_EXEC(N(EVS_FortressCollapse_MakeDust3))
    EVT_EXEC(N(EVS_FortressCollapse_MakeDust4))
    EVT_WAIT(34)
    EVT_CALL(PlaySound, SOUND_KMR_TOWER_COLLAPSE_THUD)
    EVT_EXEC(N(EVS_FortressCollapse_MakeDust5))
    EVT_EXEC(N(EVS_FortressCollapse_MakeDust6))
    EVT_WAIT(40)
    EVT_CALL(PlaySound, SOUND_KMR_TOWER_COLLAPSE_UNFOLD)
    EVT_WAIT(160)
    EVT_CALL(PlaySound, SOUND_BOING)
    EVT_WAIT(40)
    EVT_CALL(PlaySound, SOUND_DISTANT_THUD)
    EVT_EXEC(N(EVS_FortressCollapse_MakeDust7))
    EVT_EXEC(N(EVS_FortressCollapse_MakeDust8))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FortressCollapse_PlayerReactions) = {
    EVT_CALL(DisablePartnerAI, 0)
    EVT_WAIT(37)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_FlailArms)
    EVT_WAIT(60)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.8))
    EVT_CALL(PlayerJump1, LVar0, LVar1, LVar2, 10)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Run)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(6.0))
    EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(6.0))
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_PARTNER, -573, 162, 0)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, -547, 147, 0)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(EnablePartnerAI)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_SelfDestruct) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(15)
    EVT_CALL(SetCamType, CAM_DEFAULT, 1, FALSE)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 0, EVT_FLOAT(-12.5))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -389, -12)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, -469, 156)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -389, 120, -12)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 * DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcPos, NPC_GoombaKing, -380, 0, -42)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcJumpscale, NPC_GoombaKing, EVT_FLOAT(0.8))
    EVT_CALL(NpcFacePlayer, NPC_GoombaKing, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_GoombaKing, SOUND_LARGE_ACTOR_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump1, NPC_GoombaKing, -380, 120, -42, 25 * DT)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerPos, -497, 0, 130)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -534, 0, 127)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_CALL(SpeakToPlayer, NPC_GoombaKing, ANIM_GoombaKing_Idle, ANIM_GoombaKing_Idle, 0, MSG_CH0_00D8)
    EVT_SET(GB_StoryProgress, STORY_CH0_HIT_GATEHOUSE_SWITCH)
    EVT_CALL(EnableModel, MODEL_eye_mask, TRUE)
    EVT_WAIT(1)
    EVT_EXEC_GET_TID(N(EVS_RandomQuaking), LVarA)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.7))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, -100, 0)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(60 * DT)
    EVT_CALL(SpeakToPlayer, NPC_GoombaKing, ANIM_GoombaKing_Idle, ANIM_GoombaKing_Idle, 0, MSG_CH0_00D9)
    EVT_LOOP(100)
        EVT_CALL(GetNpcPos, NPC_GoombaKing, LVar0, LVar1, LVar2)
        EVT_SUB(LVar1, 1)
        EVT_CALL(SetNpcPos, NPC_GoombaKing, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_GoombaKing, -303, 286, -120)
    EVT_CALL(FadeOutMusic, 0, 1000)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_VacantStare)
    EVT_WAIT(30)
    EVT_KILL_THREAD(LVarA)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 100, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 15, EVT_FLOAT(4.0))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 83, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(1.5))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 15, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(1.5))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 170, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(3.0))
        EVT_WAIT(50)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(4.0))
        EVT_WAIT(20)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(0.5))
        EVT_WAIT(20)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(0.2))
        EVT_CALL(PlaySound, SOUND_KMR_TOWER_COLLAPSE_RUMBLE_LOOP | SOUND_ID_TRIGGER_CHANGE_SOUND)
    EVT_END_THREAD
    EVT_EXEC(N(EVS_PlayFortressAnimation))
    EVT_EXEC(N(EVS_FortressCollapse_PlayFX))
    EVT_EXEC(N(EVS_FortressCollapse_PlayerReactions))
    EVT_WAIT(380)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, -150, 0)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(20)
    EVT_EXEC(N(EVS_GoombaKingBlastoff))
    EVT_EXEC(N(EVS_PlayBridgeAnimation))
    EVT_WAIT(150)
    EVT_WAIT(50)
    EVT_CALL(EnableModel, MODEL_o416, FALSE)
    EVT_CALL(EnableModel, MODEL_o415, FALSE)
    EVT_CALL(EnableModel, MODEL_eye_mask, FALSE)
    EVT_CALL(DeleteAnimatedModel, 1)
    EVT_CALL(DeleteAnimatedModel, 0)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.8))
    EVT_LOOP(2)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_00DA)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GB_StoryProgress, STORY_CH0_OPENED_BRIDGE_TO_TOAD_TOWN)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BouncePlayerAndPartner) = {
    EVT_THREAD
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(2.0))
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(PlayerJump1, LVar0, LVar1, LVar2, LVar3)
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(2.0))
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump1, NPC_PARTNER, LVar0, LVar1, LVar2, LVar3)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_MeetGoombaKing_Impl) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_EXEC_WAIT(N(EVS_FocusCam_FortressExterior))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.3 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, EVT_FLOAT(0.5), 1)
    EVT_WAIT(170 * DT)
    EVT_CALL(SetNpcPos, NPC_BlueGoombaBro, -830, 0, -70)
    EVT_CALL(SetNpcPos, NPC_RedGoombaBro, -800, 0, -20)
    EVT_CALL(SetNpcAnimation, NPC_BlueGoombaBro, ANIM_GoombaBros_Blue_CryRun)
    EVT_CALL(SetNpcAnimation, NPC_RedGoombaBro, ANIM_GoombaBros_Red_CryRun)
    EVT_CALL(SetNpcSpeed, NPC_BlueGoombaBro, EVT_FLOAT(4.0 / DT))
    EVT_CALL(SetNpcSpeed, NPC_RedGoombaBro, EVT_FLOAT(4.0 / DT))
    EVT_WAIT(50 * DT)
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_BlueGoombaBro, -521, -100, 0)
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_RedGoombaBro, -504, -74, 0)
    EVT_CALL(SpeakToPlayer, NPC_RedGoombaBro, ANIM_GoombaBros_Red_CryWalk, ANIM_GoombaBros_Red_CryIdle, 5, MSG_CH0_00C3)
    EVT_CALL(SpeakToPlayer, NPC_BlueGoombaBro, ANIM_GoombaBros_Blue_CryWalk, ANIM_GoombaBros_Blue_CryIdle, 5, MSG_CH0_00C4)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tt, SOUND_METAL_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 90, 30, EASING_COS_IN_OUT)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o416, LVar0, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_o415, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_BlueGoombaBro, -353, -93, 0)
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_RedGoombaBro, -364, -77, 0)
    EVT_CALL(MakeLerp, 90, 0, 30, EASING_COS_IN_OUT)
    EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o416, LVar0, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_o415, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tt, SOUND_METAL_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySoundAt, SOUND_HEAVY_NPC_STEP_A, SOUND_SPACE_DEFAULT, -330, 0, -130)
    EVT_CALL(PlaySoundAt, SOUND_HEAVY_NPC_STEP_B, SOUND_SPACE_DEFAULT, -330, 0, -130)
    EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, -725, 117, -137, 100)
    EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, -617, 108, -137, 100)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.5))
    EVT_CALL(SetPlayerPos, -920, 0, -35)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PlayerMoveTo, -575, -60, 0)
    EVT_WAIT(30 * DT)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(PlayerFaceNpc, NPC_PARTNER, FALSE)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_00C5)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_WAIT(40 * DT)
    EVT_CALL(PlaySoundAt, SOUND_HEAVY_NPC_STEP_A, SOUND_SPACE_DEFAULT, -330, 0, -130)
    EVT_CALL(PlaySoundAt, SOUND_HEAVY_NPC_STEP_B, SOUND_SPACE_DEFAULT, -330, 0, -130)
    EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, -725, 117, -137, 100)
    EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, -617, 108, -137, 100)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.2))
    EVT_SET(LVar3, 2)
    EVT_EXEC(N(EVS_BouncePlayerAndPartner))
    EVT_WAIT(60 * DT)
    EVT_CALL(PlaySoundAt, SOUND_HEAVY_NPC_STEP_A, SOUND_SPACE_DEFAULT, -330, 0, -130)
    EVT_CALL(PlaySoundAt, SOUND_HEAVY_NPC_STEP_B, SOUND_SPACE_DEFAULT, -330, 0, -130)
    EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, -725, 117, -137, 100)
    EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, -617, 108, -137, 100)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.6))
    EVT_SET(LVar3, 4)
    EVT_EXEC(N(EVS_BouncePlayerAndPartner))
    EVT_WAIT(60 * DT)
    EVT_CALL(PlaySoundAt, SOUND_HEAVY_NPC_STEP_A, SOUND_SPACE_DEFAULT, -330, 0, -130)
    EVT_CALL(PlaySoundAt, SOUND_HEAVY_NPC_STEP_B, SOUND_SPACE_DEFAULT, -330, 0, -130)
    EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, -725, 117, -137, 100)
    EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, -617, 108, -137, 100)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_SET(LVar3, 6)
    EVT_EXEC(N(EVS_BouncePlayerAndPartner))
    EVT_WAIT(60 * DT)
    EVT_CALL(PlaySoundAt, SOUND_HEAVY_NPC_STEP_A, SOUND_SPACE_DEFAULT, -330, 0, -130)
    EVT_CALL(PlaySoundAt, SOUND_HEAVY_NPC_STEP_B, SOUND_SPACE_DEFAULT, -330, 0, -130)
    EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, -725, 117, -137, 100)
    EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, -617, 108, -137, 100)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.5))
    EVT_SET(LVar3, 8)
    EVT_EXEC(N(EVS_BouncePlayerAndPartner))
    EVT_WAIT(28 * DT)
    EVT_CALL(SetMusicTrack, 0, SONG_GOOMBA_KING_THEME, 0, 8)
    EVT_WAIT(32 * DT)
    EVT_CALL(SetNpcAnimation, NPC_BlueGoombaBro, ANIM_GoombaBros_Blue_Idle)
    EVT_CALL(SetNpcAnimation, NPC_RedGoombaBro, ANIM_GoombaBros_Red_Idle)
    EVT_CALL(SetNpcJumpscale, NPC_BlueGoombaBro, EVT_FLOAT(0.8))
    EVT_CALL(SetNpcJumpscale, NPC_RedGoombaBro, EVT_FLOAT(0.8))
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_BlueGoombaBro, -400, 0, -162)
        EVT_CALL(PlaySoundAtNpc, NPC_BlueGoombaBro, SOUND_ACTOR_HURT, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_BlueGoombaBro, -432, 130, -146, 30 * DT)
    EVT_END_THREAD
    EVT_CALL(SetNpcPos, NPC_RedGoombaBro, -400, 0, -41)
    EVT_CALL(PlaySoundAtNpc, NPC_RedGoombaBro, SOUND_ACTOR_HURT, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_RedGoombaBro, -412, 130, -35, 30 * DT)
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_GoombaKing, EVT_FLOAT(0.8))
        EVT_CALL(SetNpcPos, NPC_GoombaKing, -405, 0, -91)
        EVT_CALL(PlaySoundAtNpc, NPC_GoombaKing, SOUND_LARGE_ACTOR_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_GoombaKing, -419, 119, -91, 30 * DT)
        EVT_CALL(PlaySoundAt, SOUND_HEAVY_NPC_STEP_A, SOUND_SPACE_DEFAULT, -330, 0, -130)
        EVT_CALL(PlaySoundAt, SOUND_HEAVY_NPC_STEP_B, SOUND_SPACE_DEFAULT, -330, 0, -130)
        EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, -725, 117, -137, 100)
        EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, -617, 108, -137, 100)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_EXEC_WAIT(N(EVS_FocusCam_Battlement))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(55 * DT)
    EVT_CALL(SpeakToPlayer, NPC_GoombaKing, ANIM_GoombaKing_Idle, ANIM_GoombaKing_Idle, 0, MSG_CH0_00C6)
    EVT_CALL(SpeakToPlayer, NPC_RedGoombaBro, ANIM_GoombaBros_Red_Walk, ANIM_GoombaBros_Red_Idle, 0, MSG_CH0_00C7)
    EVT_CALL(SpeakToPlayer, NPC_BlueGoombaBro, ANIM_GoombaBros_Blue_Walk, ANIM_GoombaBros_Blue_Idle, 0, MSG_CH0_00C8)
    EVT_EXEC_WAIT(N(EVS_FocusCam_BesidePlayer))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_WAIT(5 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_00C9)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_EXEC_WAIT(N(EVS_FocusCam_Battlement))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(5 * DT)
    EVT_CALL(SpeakToPlayer, NPC_GoombaKing, ANIM_GoombaKing_Idle, ANIM_GoombaKing_Idle, 0, MSG_CH0_00CA)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcVar, NPC_GoombaKing, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_MeetGoombaKing) = {
    EVT_CALL(N(SetCameraVFov), 32)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_EXEC(N(EVS_Scene_MeetGoombaKing_Impl))
    EVT_RETURN
    EVT_END
};
