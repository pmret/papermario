#include "isk_11.h"
#include "effects.h"

API_CALLABLE(N(SpawnLensFlare)) {
    Bytecode* args = script->ptrReadPos;
    f32 posX = evt_get_float_variable(script, *args++);
    f32 posY = evt_get_float_variable(script, *args++);
    f32 posZ = evt_get_float_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    fx_lens_flare(0, posX, posY, posZ, duration);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_DropHiddenStairs) = {
    EVT_CALL(MakeLerp, 0, -300, 30, EASING_LINEAR)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_SET(LVar2, LVar0)
        EVT_DIVF(LVar2, 10)
        EVT_CALL(TranslateModel, MODEL_o2155, 0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_o2156, 0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_o2198, 0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_o2199, 0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_o2200, 0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_o2201, 0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_o2202, 0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_o2203, 0, LVar2, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(PlaySoundAt, SOUND_57, SOUND_SPACE_MODE_0, 16, -562, 621)
    EVT_CALL(MakeLerp, LVar0, -550, 25, EASING_LINEAR)
    EVT_CALL(UpdateLerp)
    EVT_LABEL(20)
        EVT_CALL(UpdateLerp)
        EVT_SET(LVar2, LVar0)
        EVT_DIVF(LVar2, 10)
        EVT_CALL(TranslateModel, MODEL_o2198, 0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_o2199, 0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_o2200, 0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_o2201, 0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_o2202, 0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_o2203, 0, LVar2, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(20)
        EVT_END_IF
    EVT_CALL(PlaySoundAt, SOUND_57, SOUND_SPACE_MODE_0, 41, -587, 618)
    EVT_CALL(MakeLerp, LVar0, -800, 25, EASING_LINEAR)
    EVT_CALL(UpdateLerp)
    EVT_LABEL(30)
        EVT_CALL(UpdateLerp)
        EVT_SET(LVar2, LVar0)
        EVT_DIVF(LVar2, 10)
        EVT_CALL(TranslateModel, MODEL_o2200, 0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_o2201, 0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_o2202, 0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_o2203, 0, LVar2, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(30)
        EVT_END_IF
    EVT_CALL(PlaySoundAt, SOUND_57, SOUND_SPACE_MODE_0, 66, -612, 616)
    EVT_CALL(MakeLerp, LVar0, 0xFFFFFBE6, 25, EASING_LINEAR)
    EVT_CALL(UpdateLerp)
    EVT_LABEL(40)
        EVT_CALL(UpdateLerp)
        EVT_SET(LVar2, LVar0)
        EVT_DIVF(LVar2, 10)
        EVT_CALL(TranslateModel, MODEL_o2202, 0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_o2203, 0, LVar2, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(40)
        EVT_END_IF
    EVT_CALL(PlaySoundAt, SOUND_57, SOUND_SPACE_MODE_0, 95, -637, 614)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageSecretPassage) = {
    EVT_WAIT(1)
    EVT_LABEL(10)
    EVT_WAIT(1)
    EVT_IF_NE(GB_ISK11_ItemSocket1, 22)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_NE(GB_ISK11_ItemSocket3, 23)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_NE(GB_ISK11_ItemSocket5, 21)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2087, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2088, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2089, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2090, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2091, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2092, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2222, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2223, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2224, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2225, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2226, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2226, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2227, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o2092, SOUND_55, SOUND_SPACE_MODE_0)
        EVT_CALL(N(SpawnLensFlare), -16, -438, 510, 240)
        EVT_CALL(N(SpawnLensFlare), 16, -438, 510, 240)
        EVT_WAIT(5)
        EVT_CALL(N(SpawnLensFlare), -27, -438, 508, 240)
        EVT_CALL(N(SpawnLensFlare), -64, -438, 505, 240)
        EVT_CALL(N(SpawnLensFlare), 27, -438, 508, 240)
        EVT_CALL(N(SpawnLensFlare), 64, -438, 505, 240)
        EVT_WAIT(5)
        EVT_CALL(N(SpawnLensFlare), -74, -438, 504, 240)
        EVT_CALL(N(SpawnLensFlare), -104, -438, 499, 240)
        EVT_CALL(N(SpawnLensFlare), 74, -438, 504, 240)
        EVT_CALL(N(SpawnLensFlare), 104, -438, 499, 240)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(PlaySound, SOUND_80000003)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 330, EVT_FLOAT(0.5))
        EVT_CALL(StopSound, SOUND_80000003)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(12)
            EVT_PLAY_EFFECT(EFFECT_DUST, 0, 0, -390, 550, 30)
            EVT_WAIT(20)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_SET(MV_HiddenStairsRevealed, FALSE)
    EVT_SET(MV_PlayerPanicDone, FALSE)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_LABEL(20)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_60002)
        EVT_WAIT(8)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_60003)
        EVT_WAIT(8)
        EVT_IF_FALSE(MV_PlayerPanicDone)
            EVT_GOTO(20)
        EVT_END_IF
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetPlayerSpeed, 4)
        EVT_LABEL(30)
        EVT_CALL(PlayerMoveTo, 66, 555, 0)
        EVT_CALL(PlayerMoveTo, -66, 555, 0)
        EVT_IF_FALSE(MV_HiddenStairsRevealed)
            EVT_GOTO(30)
        EVT_END_IF
        EVT_CALL(PlayerMoveTo, 0, 555, 0)
        EVT_SET(MV_PlayerPanicDone, TRUE)
    EVT_END_THREAD
    EVT_WAIT(40)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, -520, 530)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 140)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(22.7), EVT_FLOAT(-22.7))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, -520, 530)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(EnableGroup, MODEL_15, TRUE)
    EVT_CALL(EnableGroup, MODEL_g377, FALSE)
    EVT_CALL(EnableModel, MODEL_o2205, FALSE)
    EVT_WAIT(60)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, -520, 530)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, -520, 530)
    EVT_WAIT(10)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(10.0), EVT_FLOAT(12.0))
    EVT_WAIT(90)
    EVT_EXEC(N(EVS_DropHiddenStairs))
    EVT_WAIT(60)
    EVT_SET(MV_HiddenStairsRevealed, TRUE)
    EVT_WAIT(100)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_SET(GB_StoryProgress, STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
    EVT_CALL(SetMusicTrack, 0, SONG_RUINS_BASEMENT, 0, 8)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2186, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
