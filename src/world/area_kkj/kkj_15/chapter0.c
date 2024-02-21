#include "kkj_15.h"
#include "effects.h"

void sprite_shading_set_light_source(u32, s8, f32, f32, f32, u8, u8, u8, f32, s8);

API_CALLABLE(N(SetLightSourcePos)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    sprite_shading_set_light_source(0, LIGHT_SOURCE_ENABLED | LIGHT_SOURCE_LINEAR_FALLOFF,
        x, y, z, 255, 255, 255, 1.0f / 10000, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_PlaySounds_KoopaBrosShowOff) = {
    Loop(0)
        Call(PlaySoundAt, SOUND_LARGE_LENS_FLARE, SOUND_SPACE_DEFAULT, 100, 0, -40)
        Wait(30)
        Call(PlaySoundAt, SOUND_KOOPA_BROS_TOWER_SPIN_3, SOUND_SPACE_DEFAULT, 100, 0, -40)
        Wait(60)
        Call(PlaySoundAt, SOUND_KOOPA_LAUNCH_SHELL, SOUND_SPACE_DEFAULT, 100, 0, -40)
        Wait(30)
    EndLoop
    Return
    End
};

EvtScript N(EVS_FocusCam_WholeRoom) = {
    Call(UseSettingsFrom, CAM_DEFAULT, 30, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 30, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(400.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-11.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_FocusCam_BowserWide) = {
    Call(UseSettingsFrom, CAM_DEFAULT, -50, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -50, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-13.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_FocusCam_KoopaBros) = {
    Call(UseSettingsFrom, CAM_DEFAULT, 115, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 115, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(240.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-11.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Return
    End
};

EvtScript N(EVS_OpenDoor_Ch0) = {
    Call(PlaySoundAtCollider, COLLIDER_tte, SOUND_BASIC_DOOR_OPEN, 0)
    Call(MakeLerp, 0, 120, 14, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o2, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_CloseDoor_Ch0) = {
    Call(MakeLerp, 120, 0, 8, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o2, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_tte, SOUND_BASIC_DOOR_CLOSE, 0)
    Return
    End
};

EvtScript N(EVS_Scene_Chapter0_BowserAndKammy) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetMusicTrack, 0, SONG_BOWSER_THEME, 0, 8)
    Call(SetNpcPos, NPC_Bowser, -70, 0, -55)
    Call(InterpNpcYaw, NPC_Bowser, 90, 0)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    Call(UseSettingsFrom, CAM_DEFAULT, 237, 0, -74)
    Call(SetPanTarget, CAM_DEFAULT, 237, 0, -74)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(30 * DT)
    Exec(N(EVS_OpenDoor_Ch0))
    Wait(10 * DT)
    Call(SetNpcPos, NPC_Kammy, 270, 0, -78)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
    Call(SetNpcSpeed, NPC_Kammy, Float(3.0 / DT))
    Call(NpcMoveTo, NPC_Kammy, 180, -55, 0)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    ExecWait(N(EVS_CloseDoor_Ch0))
    Call(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_CH1_KoopaBros_0000)
    Thread
        Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
        Call(SetNpcSpeed, NPC_Kammy, Float(3.0 / DT))
        Call(NpcMoveTo, NPC_Kammy, 0, -55, 0)
        Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    EndThread
    Wait(20 * DT)
    ExecWait(N(EVS_FocusCam_BowserWide))
    Wait(20 * DT)
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_CH1_KoopaBros_0001)
    Call(SetPanTarget, CAM_DEFAULT, -20, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(225.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-13.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0 / DT))
    Wait(10 * DT)
    Call(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_CH1_KoopaBros_0002)
    Call(SetPanTarget, CAM_DEFAULT, -50, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-17.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Brandish)
    Wait(10 * DT)
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_BrandishTalk, ANIM_WorldBowser_BrandishIdle, 0, NPC_Kammy, MSG_Peach_CH1_KoopaBros_0003)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    Wait(15 * DT)
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_CH1_KoopaBros_0004)
    ExecWait(N(EVS_FocusCam_BowserWide))
    Call(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_CH1_KoopaBros_0005)
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_CH1_KoopaBros_0006)
    Call(FadeOutMusic, 0, 2000)
    Call(ShowMessageAtScreenPos, MSG_Peach_CH1_KoopaBros_0007, 300, 20)
    Wait(5 * DT)
    Call(PlaySoundAtNpc, NPC_Bowser, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_Bowser, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(PlaySoundAtNpc, NPC_Kammy, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_Kammy, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Wait(20 * DT)
    Thread
        Loop(2)
            Call(InterpNpcYaw, NPC_Kammy, 90, 7 * DT)
            Wait(5 * DT)
            Call(InterpNpcYaw, NPC_Kammy, 270, 7 * DT)
            Wait(5 * DT)
        EndLoop
        Call(InterpNpcYaw, NPC_Kammy, 90, 7 * DT)
    EndThread
    Wait(5 * DT)
    Thread
        Loop(2)
            Call(InterpNpcYaw, NPC_Bowser, 270, 7 * DT)
            Wait(5 * DT)
            Call(InterpNpcYaw, NPC_Bowser, 90, 7 * DT)
            Wait(5 * DT)
        EndLoop
    EndThread
    Wait(50 * DT)
    ExecWait(N(EVS_FocusCam_WholeRoom))
    Wait(20 * DT)
    Call(SetMusicTrack, 0, SONG_KOOPA_BROS_THEME, 0, 8)
    Call(ShowMessageAtScreenPos, MSG_Peach_CH1_KoopaBros_0008, 300, 20)
    Wait(20 * DT)
    Thread
        Call(SetNpcPos, NPC_KoopaBros_02, 300, 180, -60)
        Call(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Land)
        Call(EnableNpcBlur, NPC_KoopaBros_02, TRUE)
        Call(SetNpcJumpscale, NPC_KoopaBros_02, Float(0.5))
        Call(SetNpcFlagBits, NPC_KoopaBros_02, NPC_FLAG_GRAVITY, TRUE)
        Call(SetNpcFlagBits, NPC_KoopaBros_02, NPC_FLAG_FLYING, FALSE)
        Call(NpcMoveTo, NPC_KoopaBros_02, 100, -40, 18)
        Call(PlaySoundAtNpc, NPC_KoopaBros_02, SOUND_KOOPA_BROS_LAND, SOUND_PARAM_MUTE)
        PlayEffect(EFFECT_LANDING_DUST, 1, 100, 0, -40, 0)
        Call(EnableNpcBlur, NPC_KoopaBros_02, FALSE)
        Call(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Red_IdleCrouch)
    EndThread
    Thread
        Wait(5)
        Call(SetNpcPos, NPC_KoopaBros_01, 328, 180, -15)
        Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Black_Land)
        Call(EnableNpcBlur, NPC_KoopaBros_01, TRUE)
        Call(SetNpcJumpscale, NPC_KoopaBros_01, Float(0.5))
        Call(SetNpcFlagBits, NPC_KoopaBros_01, NPC_FLAG_GRAVITY, TRUE)
        Call(SetNpcFlagBits, NPC_KoopaBros_01, NPC_FLAG_FLYING, FALSE)
        Call(NpcMoveTo, NPC_KoopaBros_01, 128, -15, 18)
        Call(PlaySoundAtNpc, NPC_KoopaBros_01, SOUND_KOOPA_BROS_LAND, SOUND_PARAM_MUTE)
        PlayEffect(EFFECT_LANDING_DUST, 1, 128, 0, -15, 0)
        Call(EnableNpcBlur, NPC_KoopaBros_01, FALSE)
        Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Black_IdleCrouch)
    EndThread
    Thread
        Wait(10)
        Call(SetNpcPos, NPC_KoopaBros_03, 340, 180, -90)
        Call(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_Land)
        Call(EnableNpcBlur, NPC_KoopaBros_03, TRUE)
        Call(SetNpcJumpscale, NPC_KoopaBros_03, Float(0.5))
        Call(SetNpcFlagBits, NPC_KoopaBros_03, NPC_FLAG_GRAVITY, TRUE)
        Call(SetNpcFlagBits, NPC_KoopaBros_03, NPC_FLAG_FLYING, FALSE)
        Call(NpcMoveTo, NPC_KoopaBros_03, 140, -90, 18)
        Call(PlaySoundAtNpc, NPC_KoopaBros_03, SOUND_KOOPA_BROS_LAND, SOUND_PARAM_MUTE)
        PlayEffect(EFFECT_LANDING_DUST, 1, 140, 0, -90, 0)
        Call(EnableNpcBlur, NPC_KoopaBros_03, FALSE)
        Call(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_IdleCrouch)
    EndThread
    Thread
        Wait(15)
        Call(SetNpcPos, NPC_KoopaBros_04, 368, 180, -45)
        Call(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_Land)
        Call(EnableNpcBlur, NPC_KoopaBros_04, TRUE)
        Call(SetNpcJumpscale, NPC_KoopaBros_04, Float(0.5))
        Call(SetNpcFlagBits, NPC_KoopaBros_04, NPC_FLAG_GRAVITY, TRUE)
        Call(SetNpcFlagBits, NPC_KoopaBros_04, NPC_FLAG_FLYING, FALSE)
        Call(NpcMoveTo, NPC_KoopaBros_04, 168, -45, 18)
        Call(PlaySoundAtNpc, NPC_KoopaBros_04, SOUND_KOOPA_BROS_LAND, SOUND_PARAM_MUTE)
        PlayEffect(EFFECT_LANDING_DUST, 1, 168, 0, -45, 0)
        Call(EnableNpcBlur, NPC_KoopaBros_04, FALSE)
        Call(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_IdleCrouch)
    EndThread
    Wait(50)
    Call(UseSettingsFrom, CAM_DEFAULT, 128, 0, -15)
    Call(SetPanTarget, CAM_DEFAULT, 128, 0, -15)
    Call(SetCamDistance, CAM_DEFAULT, Float(240.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-11.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(15)
    Thread
        Call(PlaySoundAtNpc, NPC_KoopaBros_02, SOUND_SMALL_LENS_FLARE, SOUND_SPACE_DEFAULT)
        Call(GetNpcPos, NPC_KoopaBros_02, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Add(LVar1, 30)
        PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
        Call(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Red_ThumbsUp)
    EndThread
    Thread
        Wait(5)
        Call(PlaySoundAtNpc, NPC_KoopaBros_01, SOUND_SMALL_LENS_FLARE, SOUND_SPACE_DEFAULT)
        Call(GetNpcPos, NPC_KoopaBros_01, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Add(LVar1, 30)
        PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
        Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Black_ThumbsUp)
    EndThread
    Thread
        Wait(10)
        Call(PlaySoundAtNpc, NPC_KoopaBros_03, SOUND_SMALL_LENS_FLARE, SOUND_SPACE_DEFAULT)
        Call(GetNpcPos, NPC_KoopaBros_03, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Add(LVar1, 30)
        PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
        Call(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_ThumbsUp)
    EndThread
    Thread
        Wait(15)
        Call(PlaySoundAtNpc, NPC_KoopaBros_04, SOUND_SMALL_LENS_FLARE, SOUND_SPACE_DEFAULT)
        Call(GetNpcPos, NPC_KoopaBros_04, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Add(LVar1, 30)
        PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
        Call(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_ThumbsUp)
    EndThread
    Wait(45)
    Call(SpeakToNpc, NPC_KoopaBros_02, ANIM_KoopaBros_Red_ThumbsUp, ANIM_KoopaBros_Red_ThumbsUp, 0, NPC_Bowser, MSG_Peach_CH1_KoopaBros_0009)
    Wait(10)
    ExecWait(N(EVS_FocusCam_BowserWide))
    Wait(15 * DT)
    Call(InterpNpcYaw, NPC_Kammy, 270, 0)
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_CH1_KoopaBros_000A)
    Call(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Idle)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Black_Idle)
    Call(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_Idle)
    Call(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_Idle)
    ExecWait(N(EVS_FocusCam_KoopaBros))
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Walk)
    Call(NpcMoveTo, NPC_KoopaBros_02, 80, -40, 10)
    Call(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Idle)
    Call(SpeakToNpc, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 0, NPC_Bowser, MSG_Peach_CH1_KoopaBros_000B)
    ExecWait(N(EVS_FocusCam_WholeRoom))
    Call(SetNpcPos, NPC_KoopaBros_02, 80, 0, -40)
    Call(InterpNpcYaw, NPC_Kammy, 90, 5)
    Call(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_KoopaBros_01, MSG_Peach_CH1_KoopaBros_000C)
    Call(SpeakToNpc, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 0, NPC_Bowser, MSG_Peach_CH1_KoopaBros_000D)
    Call(InterpNpcYaw, NPC_KoopaBros_02, 90, 5)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 5, MSG_Peach_CH1_KoopaBros_000E)
    Call(UseSettingsFrom, CAM_DEFAULT, -50, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -50, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(200.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-18.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.2 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(40 * DT)
    ExecGetTID(N(EVS_PlaySounds_KoopaBrosShowOff), LVarB)
    Call(N(SetLightSourcePos), 100, 0, -40)
    Call(EnableSpriteShading, TRUE)
    PlayEffect(EFFECT_LIGHT_RAYS, 3, 100, 0, -40, 1, LVarA)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_KoopaBros_01, MSG_Peach_CH1_KoopaBros_000F)
    Wait(20 * DT)
    KillThread(LVarB)
    Call(DismissEffect, LVarA)
    Call(EnableSpriteShading, FALSE)
    Wait(30 * DT)
    ExecWait(N(EVS_FocusCam_KoopaBros))
    Wait(10 * DT)
    Call(SpeakToNpc, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 0, NPC_Bowser, MSG_Peach_CH1_KoopaBros_0010)
    ExecWait(N(EVS_FocusCam_WholeRoom))
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_KoopaBros_01, MSG_Peach_CH1_KoopaBros_0011)
    Call(SpeakToNpc, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 0, NPC_Bowser, MSG_Peach_CH1_KoopaBros_0012)
    Call(SetPanTarget, CAM_DEFAULT, -50, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-17.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Wait(10 * DT)
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_KoopaBros_01, MSG_Peach_CH1_KoopaBros_0013)
    ExecWait(N(EVS_FocusCam_KoopaBros))
    Wait(10 * DT)
    Call(FadeOutMusic, 0, 500)
    Call(PlaySoundAtNpc, NPC_KoopaBros_03, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_KoopaBros_03, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(PlaySoundAtNpc, NPC_KoopaBros_02, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_KoopaBros_02, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(PlaySoundAtNpc, NPC_KoopaBros_04, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_KoopaBros_04, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(PlaySoundAtNpc, NPC_KoopaBros_01, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_KoopaBros_01, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Wait(30 * DT)
    Call(SpeakToNpc, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 0, NPC_Bowser, MSG_Peach_CH1_KoopaBros_0014)
    Call(SetPanTarget, CAM_DEFAULT, 30, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, 400)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-11.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0 / DT))
    Thread
        Call(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Red_HurtStill)
        Call(NpcJump0, NPC_KoopaBros_02, 80, 0, -40, 10 * DT)
        Call(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Idle)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Black_HurtStill)
        Call(NpcJump0, NPC_KoopaBros_01, 128, 0, -15, 10 * DT)
        Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Black_Idle)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_HurtStill)
        Call(NpcJump0, NPC_KoopaBros_03, 140, 0, -90, 10 * DT)
        Call(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_Idle)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_HurtStill)
        Call(NpcJump0, NPC_KoopaBros_04, 168, 0, -45, 10 * DT)
        Call(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_Idle)
    EndThread
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 30, Float(1.0))
    EndThread
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_KoopaBros_02, MSG_Peach_CH1_KoopaBros_0015)
    Thread
        Call(PlaySoundAtNpc, NPC_KoopaBros_02, SOUND_RUN_AWAY_BUILDUP, SOUND_SPACE_DEFAULT)
        Call(InterpNpcYaw, NPC_KoopaBros_02, 90, 0)
        Call(EnableNpcBlur, NPC_KoopaBros_02, TRUE)
        Call(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Run)
        Wait(30 * DT)
        Call(PlaySoundAtNpc, NPC_KoopaBros_02, SOUND_RUN_AWAY, SOUND_SPACE_DEFAULT)
        Call(NpcMoveTo, NPC_KoopaBros_02, 200, -60, 10 * DT)
    EndThread
    Thread
        Call(InterpNpcYaw, NPC_KoopaBros_01, 90, 0)
        Call(EnableNpcBlur, NPC_KoopaBros_01, TRUE)
        Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Black_Run)
        Wait(30 * DT)
        Call(EnableNpcBlur, NPC_KoopaBros_01, TRUE)
        Call(NpcMoveTo, NPC_KoopaBros_01, 200, -60, 10 * DT)
    EndThread
    Thread
        Call(InterpNpcYaw, NPC_KoopaBros_03, 90, 0)
        Call(EnableNpcBlur, NPC_KoopaBros_03, TRUE)
        Call(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_Run)
        Wait(30 * DT)
        Call(EnableNpcBlur, NPC_KoopaBros_03, TRUE)
        Call(NpcMoveTo, NPC_KoopaBros_03, 200, -60, 10 * DT)
    EndThread
    Thread
        Call(InterpNpcYaw, NPC_KoopaBros_04, 90, 0)
        Call(EnableNpcBlur, NPC_KoopaBros_04, TRUE)
        Call(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_Run)
        Wait(30 * DT)
        Call(EnableNpcBlur, NPC_KoopaBros_04, TRUE)
        Call(NpcMoveTo, NPC_KoopaBros_04, 200, -60, 10 * DT)
    EndThread
    Wait(30 * DT)
    ExecWait(N(EVS_EndPeachChapter0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
