#include "isk_11.h"
#include "effects.h"
#include "sprite/player.h"

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
    Call(MakeLerp, 0, -300, 30 * DT, EASING_LINEAR)
    Label(10)
        Call(UpdateLerp)
        Set(LVar2, LVar0)
        DivF(LVar2, 10)
        Call(TranslateModel, MODEL_o2155, 0, LVar2, 0)
        Call(TranslateModel, MODEL_o2156, 0, LVar2, 0)
        Call(TranslateModel, MODEL_o2198, 0, LVar2, 0)
        Call(TranslateModel, MODEL_o2199, 0, LVar2, 0)
        Call(TranslateModel, MODEL_o2200, 0, LVar2, 0)
        Call(TranslateModel, MODEL_o2201, 0, LVar2, 0)
        Call(TranslateModel, MODEL_o2202, 0, LVar2, 0)
        Call(TranslateModel, MODEL_o2203, 0, LVar2, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Call(PlaySoundAt, SOUND_ISK_STAIR_DROP_THUD, SOUND_SPACE_DEFAULT, 16, -562, 621)
    Call(MakeLerp, LVar0, -550, 25 * DT, EASING_LINEAR)
    Call(UpdateLerp)
    Label(20)
        Call(UpdateLerp)
        Set(LVar2, LVar0)
        DivF(LVar2, 10)
        Call(TranslateModel, MODEL_o2198, 0, LVar2, 0)
        Call(TranslateModel, MODEL_o2199, 0, LVar2, 0)
        Call(TranslateModel, MODEL_o2200, 0, LVar2, 0)
        Call(TranslateModel, MODEL_o2201, 0, LVar2, 0)
        Call(TranslateModel, MODEL_o2202, 0, LVar2, 0)
        Call(TranslateModel, MODEL_o2203, 0, LVar2, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(20)
        EndIf
    Call(PlaySoundAt, SOUND_ISK_STAIR_DROP_THUD, SOUND_SPACE_DEFAULT, 41, -587, 618)
    Call(MakeLerp, LVar0, -800, 25 * DT, EASING_LINEAR)
    Call(UpdateLerp)
    Label(30)
        Call(UpdateLerp)
        Set(LVar2, LVar0)
        DivF(LVar2, 10)
        Call(TranslateModel, MODEL_o2200, 0, LVar2, 0)
        Call(TranslateModel, MODEL_o2201, 0, LVar2, 0)
        Call(TranslateModel, MODEL_o2202, 0, LVar2, 0)
        Call(TranslateModel, MODEL_o2203, 0, LVar2, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(30)
        EndIf
    Call(PlaySoundAt, SOUND_ISK_STAIR_DROP_THUD, SOUND_SPACE_DEFAULT, 66, -612, 616)
    Call(MakeLerp, LVar0, 0xFFFFFBE6, 25 * DT, EASING_LINEAR)
    Call(UpdateLerp)
    Label(40)
        Call(UpdateLerp)
        Set(LVar2, LVar0)
        DivF(LVar2, 10)
        Call(TranslateModel, MODEL_o2202, 0, LVar2, 0)
        Call(TranslateModel, MODEL_o2203, 0, LVar2, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(40)
        EndIf
    Call(PlaySoundAt, SOUND_ISK_STAIR_DROP_THUD, SOUND_SPACE_DEFAULT, 95, -637, 614)
    Return
    End
};

EvtScript N(EVS_ManageSecretPassage) = {
    Wait(1)
    Label(10)
    Wait(1)
    IfNe(GB_ISK11_ItemSocket1, ITEM_PYRAMID_STONE)
        Goto(10)
    EndIf
    IfNe(GB_ISK11_ItemSocket3, ITEM_DIAMOND_STONE)
        Goto(10)
    EndIf
    IfNe(GB_ISK11_ItemSocket5, ITEM_LUNAR_STONE)
        Goto(10)
    EndIf
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2087, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2088, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2089, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2090, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2091, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2092, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2222, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2223, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2224, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2225, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2226, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2226, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2227, COLLIDER_FLAGS_UPPER_MASK)
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Wait(10 * DT)
    Thread
        Call(PlaySoundAtCollider, COLLIDER_o2092, SOUND_LARGE_LENS_FLARE, SOUND_SPACE_DEFAULT)
        Call(N(SpawnLensFlare), -16, -438, 510, 240)
        Call(N(SpawnLensFlare), 16, -438, 510, 240)
        Wait(5 * DT)
        Call(N(SpawnLensFlare), -27, -438, 508, 240)
        Call(N(SpawnLensFlare), -64, -438, 505, 240)
        Call(N(SpawnLensFlare), 27, -438, 508, 240)
        Call(N(SpawnLensFlare), 64, -438, 505, 240)
        Wait(5 * DT)
        Call(N(SpawnLensFlare), -74, -438, 504, 240)
        Call(N(SpawnLensFlare), -104, -438, 499, 240)
        Call(N(SpawnLensFlare), 74, -438, 504, 240)
        Call(N(SpawnLensFlare), 104, -438, 499, 240)
    EndThread
    Wait(30 * DT)
    Thread
        Call(PlaySound, SOUND_LOOP_ISK_LOWER_STAIRS)
        Call(ShakeCam, CAM_DEFAULT, 0, 330, Float(0.5))
        Call(StopSound, SOUND_LOOP_ISK_LOWER_STAIRS)
    EndThread
    Thread
        Loop(12)
            PlayEffect(EFFECT_DUST, 0, 0, -390, 550, 30)
            Wait(20 * DT)
        EndLoop
    EndThread
    Wait(10 * DT)
    Set(MV_HiddenStairsRevealed, false)
    Set(MV_PlayerPanicDone, false)
    Thread
        Wait(20 * DT)
        Label(20)
        Call(SetPlayerAnimation, ANIM_MarioW1_CarryRun)
        Wait(8 * DT)
        Call(SetPlayerAnimation, ANIM_MarioW1_CarryAboveRun)
        Wait(8 * DT)
        IfFalse(MV_PlayerPanicDone)
            Goto(20)
        EndIf
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    EndThread
    Thread
        Wait(20 * DT)
#if VERSION_PAL
        Call(SetPlayerSpeed, Float(4.0 / DT))
#else
        Call(SetPlayerSpeed, 4)
#endif
        Label(30)
        Call(PlayerMoveTo, 66, 555, 0)
        Call(PlayerMoveTo, -66, 555, 0)
        IfFalse(MV_HiddenStairsRevealed)
            Goto(30)
        EndIf
        Call(PlayerMoveTo, 0, 555, 0)
        Set(MV_PlayerPanicDone, true)
    EndThread
    Wait(40 * DT)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(UseSettingsFrom, CAM_DEFAULT, 0, -520, 530)
    Call(SetCamDistance, CAM_DEFAULT, 140)
    Call(SetCamPitch, CAM_DEFAULT, Float(22.7), Float(-22.7))
    Call(SetPanTarget, CAM_DEFAULT, 0, -520, 530)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(EnableGroup, MODEL_15, true)
    Call(EnableGroup, MODEL_g377, false)
    Call(EnableModel, MODEL_o2205, false)
    Wait(60)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(UseSettingsFrom, CAM_DEFAULT, 0, -520, 530)
    Call(SetPanTarget, CAM_DEFAULT, 0, -520, 530)
    Wait(10 * DT)
    Call(SetCamPitch, CAM_DEFAULT, Float(10.0), Float(12.0))
    Wait(90 * DT)
    Exec(N(EVS_DropHiddenStairs))
    Wait(60 * DT)
    Set(MV_HiddenStairsRevealed, true)
    Wait(100 * DT)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Wait(1)
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Set(GB_StoryProgress, STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
    Call(SetMusic, 0, SONG_RUINS_BASEMENT, 0, VOL_LEVEL_FULL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2186, COLLIDER_FLAGS_UPPER_MASK)
    Call(DisablePlayerPhysics, false)
    Call(DisablePlayerInput, false)
    Return
    End
};
