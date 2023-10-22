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
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAt, SOUND_LARGE_LENS_FLARE, SOUND_SPACE_DEFAULT, 100, 0, -40)
        EVT_WAIT(30)
        EVT_CALL(PlaySoundAt, SOUND_KOOPA_BROS_TOWER_SPIN_3, SOUND_SPACE_DEFAULT, 100, 0, -40)
        EVT_WAIT(60)
        EVT_CALL(PlaySoundAt, SOUND_KOOPA_LAUNCH_SHELL, SOUND_SPACE_DEFAULT, 100, 0, -40)
        EVT_WAIT(30)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCam_WholeRoom) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 30, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 30, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCam_BowserWide) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -50, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -50, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-13.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCam_KoopaBros) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 115, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 115, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(240.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenDoor_Ch0) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tte, SOUND_BASIC_DOOR_OPEN, 0)
    EVT_CALL(MakeLerp, 0, 120, 14, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o2, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CloseDoor_Ch0) = {
    EVT_CALL(MakeLerp, 120, 0, 8, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o2, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tte, SOUND_BASIC_DOOR_CLOSE, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_Chapter0_BowserAndKammy) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetMusicTrack, 0, SONG_BOWSER_THEME, 0, 8)
    EVT_CALL(SetNpcPos, NPC_Bowser, -70, 0, -55)
    EVT_CALL(InterpNpcYaw, NPC_Bowser, 90, 0)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 237, 0, -74)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 237, 0, -74)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(30 * DT)
    EVT_EXEC(N(EVS_OpenDoor_Ch0))
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcPos, NPC_Kammy, 270, 0, -78)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
    EVT_CALL(SetNpcSpeed, NPC_Kammy, EVT_FLOAT(3.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_Kammy, 180, -55, 0)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    EVT_EXEC_WAIT(N(EVS_CloseDoor_Ch0))
    EVT_CALL(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_CH1_KoopaBros_0000)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
        EVT_CALL(SetNpcSpeed, NPC_Kammy, EVT_FLOAT(3.0 / DT))
        EVT_CALL(NpcMoveTo, NPC_Kammy, 0, -55, 0)
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    EVT_END_THREAD
    EVT_WAIT(20 * DT)
    EVT_EXEC_WAIT(N(EVS_FocusCam_BowserWide))
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_CH1_KoopaBros_0001)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -20, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(225.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-13.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_CH1_KoopaBros_0002)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -50, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-17.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Brandish)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_BrandishTalk, ANIM_WorldBowser_BrandishIdle, 0, NPC_Kammy, MSG_Peach_CH1_KoopaBros_0003)
    EVT_CALL(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    EVT_WAIT(15 * DT)
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_CH1_KoopaBros_0004)
    EVT_EXEC_WAIT(N(EVS_FocusCam_BowserWide))
    EVT_CALL(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_CH1_KoopaBros_0005)
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_CH1_KoopaBros_0006)
    EVT_CALL(FadeOutMusic, 0, 2000)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_CH1_KoopaBros_0007, 300, 20)
    EVT_WAIT(5 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_Bowser, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_Bowser, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_Kammy, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_Kammy, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(20 * DT)
    EVT_THREAD
        EVT_LOOP(2)
            EVT_CALL(InterpNpcYaw, NPC_Kammy, 90, 7 * DT)
            EVT_WAIT(5 * DT)
            EVT_CALL(InterpNpcYaw, NPC_Kammy, 270, 7 * DT)
            EVT_WAIT(5 * DT)
        EVT_END_LOOP
        EVT_CALL(InterpNpcYaw, NPC_Kammy, 90, 7 * DT)
    EVT_END_THREAD
    EVT_WAIT(5 * DT)
    EVT_THREAD
        EVT_LOOP(2)
            EVT_CALL(InterpNpcYaw, NPC_Bowser, 270, 7 * DT)
            EVT_WAIT(5 * DT)
            EVT_CALL(InterpNpcYaw, NPC_Bowser, 90, 7 * DT)
            EVT_WAIT(5 * DT)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(50 * DT)
    EVT_EXEC_WAIT(N(EVS_FocusCam_WholeRoom))
    EVT_WAIT(20 * DT)
    EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_BROS_THEME, 0, 8)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Peach_CH1_KoopaBros_0008, 300, 20)
    EVT_WAIT(20 * DT)
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_KoopaBros_02, 300, 180, -60)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Land)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBros_02, TRUE)
        EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_02, EVT_FLOAT(0.5))
        EVT_CALL(SetNpcFlagBits, NPC_KoopaBros_02, NPC_FLAG_GRAVITY, TRUE)
        EVT_CALL(SetNpcFlagBits, NPC_KoopaBros_02, NPC_FLAG_FLYING, FALSE)
        EVT_CALL(NpcMoveTo, NPC_KoopaBros_02, 100, -40, 18)
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaBros_02, SOUND_KOOPA_BROS_LAND, SOUND_PARAM_MUTE)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 100, 0, -40, 0)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBros_02, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Red_IdleCrouch)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetNpcPos, NPC_KoopaBros_01, 328, 180, -15)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Black_Land)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBros_01, TRUE)
        EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_01, EVT_FLOAT(0.5))
        EVT_CALL(SetNpcFlagBits, NPC_KoopaBros_01, NPC_FLAG_GRAVITY, TRUE)
        EVT_CALL(SetNpcFlagBits, NPC_KoopaBros_01, NPC_FLAG_FLYING, FALSE)
        EVT_CALL(NpcMoveTo, NPC_KoopaBros_01, 128, -15, 18)
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaBros_01, SOUND_KOOPA_BROS_LAND, SOUND_PARAM_MUTE)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 128, 0, -15, 0)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBros_01, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Black_IdleCrouch)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetNpcPos, NPC_KoopaBros_03, 340, 180, -90)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_Land)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBros_03, TRUE)
        EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_03, EVT_FLOAT(0.5))
        EVT_CALL(SetNpcFlagBits, NPC_KoopaBros_03, NPC_FLAG_GRAVITY, TRUE)
        EVT_CALL(SetNpcFlagBits, NPC_KoopaBros_03, NPC_FLAG_FLYING, FALSE)
        EVT_CALL(NpcMoveTo, NPC_KoopaBros_03, 140, -90, 18)
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaBros_03, SOUND_KOOPA_BROS_LAND, SOUND_PARAM_MUTE)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 140, 0, -90, 0)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBros_03, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_IdleCrouch)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(SetNpcPos, NPC_KoopaBros_04, 368, 180, -45)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_Land)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBros_04, TRUE)
        EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_04, EVT_FLOAT(0.5))
        EVT_CALL(SetNpcFlagBits, NPC_KoopaBros_04, NPC_FLAG_GRAVITY, TRUE)
        EVT_CALL(SetNpcFlagBits, NPC_KoopaBros_04, NPC_FLAG_FLYING, FALSE)
        EVT_CALL(NpcMoveTo, NPC_KoopaBros_04, 168, -45, 18)
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaBros_04, SOUND_KOOPA_BROS_LAND, SOUND_PARAM_MUTE)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 168, 0, -45, 0)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBros_04, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_IdleCrouch)
    EVT_END_THREAD
    EVT_WAIT(50)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 128, 0, -15)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 128, 0, -15)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(240.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(15)
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaBros_02, SOUND_SMALL_LENS_FLARE, SOUND_SPACE_DEFAULT)
        EVT_CALL(GetNpcPos, NPC_KoopaBros_02, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_ADD(LVar1, 30)
        EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Red_ThumbsUp)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaBros_01, SOUND_SMALL_LENS_FLARE, SOUND_SPACE_DEFAULT)
        EVT_CALL(GetNpcPos, NPC_KoopaBros_01, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_ADD(LVar1, 30)
        EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Black_ThumbsUp)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaBros_03, SOUND_SMALL_LENS_FLARE, SOUND_SPACE_DEFAULT)
        EVT_CALL(GetNpcPos, NPC_KoopaBros_03, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_ADD(LVar1, 30)
        EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_ThumbsUp)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaBros_04, SOUND_SMALL_LENS_FLARE, SOUND_SPACE_DEFAULT)
        EVT_CALL(GetNpcPos, NPC_KoopaBros_04, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_ADD(LVar1, 30)
        EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_ThumbsUp)
    EVT_END_THREAD
    EVT_WAIT(45)
    EVT_CALL(SpeakToNpc, NPC_KoopaBros_02, ANIM_KoopaBros_Red_ThumbsUp, ANIM_KoopaBros_Red_ThumbsUp, 0, NPC_Bowser, MSG_Peach_CH1_KoopaBros_0009)
    EVT_WAIT(10)
    EVT_EXEC_WAIT(N(EVS_FocusCam_BowserWide))
    EVT_WAIT(15 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Kammy, 270, 0)
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_CH1_KoopaBros_000A)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Idle)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Black_Idle)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_Idle)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_Idle)
    EVT_EXEC_WAIT(N(EVS_FocusCam_KoopaBros))
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Walk)
    EVT_CALL(NpcMoveTo, NPC_KoopaBros_02, 80, -40, 10)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Idle)
    EVT_CALL(SpeakToNpc, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 0, NPC_Bowser, MSG_Peach_CH1_KoopaBros_000B)
    EVT_EXEC_WAIT(N(EVS_FocusCam_WholeRoom))
    EVT_CALL(SetNpcPos, NPC_KoopaBros_02, 80, 0, -40)
    EVT_CALL(InterpNpcYaw, NPC_Kammy, 90, 5)
    EVT_CALL(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_KoopaBros_01, MSG_Peach_CH1_KoopaBros_000C)
    EVT_CALL(SpeakToNpc, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 0, NPC_Bowser, MSG_Peach_CH1_KoopaBros_000D)
    EVT_CALL(InterpNpcYaw, NPC_KoopaBros_02, 90, 5)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 5, MSG_Peach_CH1_KoopaBros_000E)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -50, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -50, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(200.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-18.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.2 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(40 * DT)
    EVT_EXEC_GET_TID(N(EVS_PlaySounds_KoopaBrosShowOff), LVarB)
    EVT_CALL(N(SetLightSourcePos), 100, 0, -40)
    EVT_CALL(EnableSpriteShading, TRUE)
    EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 3, 100, 0, -40, 1, LVarA)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_KoopaBros_01, MSG_Peach_CH1_KoopaBros_000F)
    EVT_WAIT(20 * DT)
    EVT_KILL_THREAD(LVarB)
    EVT_CALL(DismissEffect, LVarA)
    EVT_CALL(EnableSpriteShading, FALSE)
    EVT_WAIT(30 * DT)
    EVT_EXEC_WAIT(N(EVS_FocusCam_KoopaBros))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToNpc, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 0, NPC_Bowser, MSG_Peach_CH1_KoopaBros_0010)
    EVT_EXEC_WAIT(N(EVS_FocusCam_WholeRoom))
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_KoopaBros_01, MSG_Peach_CH1_KoopaBros_0011)
    EVT_CALL(SpeakToNpc, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 0, NPC_Bowser, MSG_Peach_CH1_KoopaBros_0012)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -50, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-17.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_KoopaBros_01, MSG_Peach_CH1_KoopaBros_0013)
    EVT_EXEC_WAIT(N(EVS_FocusCam_KoopaBros))
    EVT_WAIT(10 * DT)
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_CALL(PlaySoundAtNpc, NPC_KoopaBros_03, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_KoopaBros_03, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_KoopaBros_02, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_KoopaBros_02, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_KoopaBros_04, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_KoopaBros_04, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_KoopaBros_01, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_KoopaBros_01, EMOTE_EXCLAMATION, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToNpc, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle, 0, NPC_Bowser, MSG_Peach_CH1_KoopaBros_0014)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 30, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Red_HurtStill)
        EVT_CALL(NpcJump0, NPC_KoopaBros_02, 80, 0, -40, 10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Black_HurtStill)
        EVT_CALL(NpcJump0, NPC_KoopaBros_01, 128, 0, -15, 10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Black_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_HurtStill)
        EVT_CALL(NpcJump0, NPC_KoopaBros_03, 140, 0, -90, 10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_HurtStill)
        EVT_CALL(NpcJump0, NPC_KoopaBros_04, 168, 0, -45, 10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_KoopaBros_02, MSG_Peach_CH1_KoopaBros_0015)
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaBros_02, SOUND_RUN_AWAY_BUILDUP, SOUND_SPACE_DEFAULT)
        EVT_CALL(InterpNpcYaw, NPC_KoopaBros_02, 90, 0)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBros_02, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Run)
        EVT_WAIT(30 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaBros_02, SOUND_RUN_AWAY, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcMoveTo, NPC_KoopaBros_02, 200, -60, 10 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(InterpNpcYaw, NPC_KoopaBros_01, 90, 0)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBros_01, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Black_Run)
        EVT_WAIT(30 * DT)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBros_01, TRUE)
        EVT_CALL(NpcMoveTo, NPC_KoopaBros_01, 200, -60, 10 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(InterpNpcYaw, NPC_KoopaBros_03, 90, 0)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBros_03, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_Run)
        EVT_WAIT(30 * DT)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBros_03, TRUE)
        EVT_CALL(NpcMoveTo, NPC_KoopaBros_03, 200, -60, 10 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(InterpNpcYaw, NPC_KoopaBros_04, 90, 0)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBros_04, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_Run)
        EVT_WAIT(30 * DT)
        EVT_CALL(EnableNpcBlur, NPC_KoopaBros_04, TRUE)
        EVT_CALL(NpcMoveTo, NPC_KoopaBros_04, 200, -60, 10 * DT)
    EVT_END_THREAD
    EVT_WAIT(30 * DT)
    EVT_EXEC_WAIT(N(EVS_EndPeachChapter0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
