#include "flo_21.h"
#include "sprite/player.h"

#define STAR_SPIRIT_DATA_VAR MV_Unk_01
#include "world/common/todo/StarSpiritEffectFunc.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_RIGHT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_TrySpawningStarCard) = {
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH6_GREW_MAGIC_BEANSTALK)
            Set(LVar0, FALSE)
            IfEq(MV_BossDefeated, FALSE)
                Return
            EndIf
            Set(GB_StoryProgress, STORY_CH6_DEFEATED_HUFF_N_PUFF)
        CaseEq(STORY_CH6_DEFEATED_HUFF_N_PUFF)
            Set(LVar0, TRUE)
        CaseDefault
            Return
    EndSwitch
    IfEq(LVar0, FALSE)
        Call(DisablePlayerInput, TRUE)
        Call(UseSettingsFrom, CAM_DEFAULT, 650, 205, 0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.6))
        Call(SetPanTarget, CAM_DEFAULT, 650, 150, 0)
        EVT_SPIRIT_ADJUST_CAM(Float(-5.5))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(N(StarSpiritEffectFunc2), 5, 180, 650, 170, 0, 650, 205, 0, 150, 120)
        Thread
            Call(N(StarSpiritEffectFunc3))
        EndThread
        Thread
            Wait(1)
            Call(PlaySound, SOUND_LOOP_STAR_ORB_RISING)
            Call(N(StarSpiritEffectFunc1))
            Call(StopSound, SOUND_LOOP_STAR_ORB_RISING)
            Call(PlaySoundAt, SOUND_STAR_ORB_BURST, SOUND_SPACE_DEFAULT, 650, 205, 0)
        EndThread
        Thread
            Wait(45)
            Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
        EndThread
        Thread
            Wait(180)
            Wait(115)
            Call(PlaySoundAt, SOUND_STAR_CARD_APPEARS, SOUND_SPACE_DEFAULT, 650, 205, 0)
        EndThread
        Call(N(StarSpiritEffectFunc4), 1)
        Thread
            Wait(80)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        EndThread
        Add(LVar1, 100)
        Call(SetCamDistance, CAM_DEFAULT, LVar1)
        Call(SetPanTarget, CAM_DEFAULT, 650, 120, 0)
        Call(N(StarSpiritEffectFunc4), 2)
        Call(GetPlayerPos, LVar2, LVar3, LVar4)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
        Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
        Call(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
        Call(DisablePlayerInput, FALSE)
    Else
        Call(N(StarSpiritEffectFunc5), 5, 650, 150, 0, 120)
        Thread
            Call(N(StarSpiritEffectFunc6))
        EndThread
        Wait(1)
    EndIf
    Call(N(StarSpiritEffectFunc4), 3)
    Call(PlaySoundAtPlayer, SOUND_RESCUE_STAR_SPIRIT, SOUND_SPACE_DEFAULT)
    Call(DisablePlayerInput, TRUE)
    Set(GB_StoryProgress, STORY_CH6_STAR_SPIRIT_RESCUED)
    Call(GotoMapSpecial, Ref("kmr_23"), kmr_23_ENTRY_5, TRANSITION_GET_STAR_CARD)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_flo_19_1) = EVT_EXIT_WALK(60, flo_21_ENTRY_0, "flo_19", flo_19_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_flo_19_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_CLOUDY_CLIMB)
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    SetUP_CAMERA_DEFAULT()
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    Exec(N(EVS_Scene_HuffNPuffAmbush))
    Call(HidePlayerShadow, TRUE)
    Exec(N(EVS_SetupCloudPuffs))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o114, SURFACE_TYPE_CLOUD)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o115, SURFACE_TYPE_CLOUD)
    Call(GetEntryID, LVar0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    ExecWait(N(EVS_SetupMusic))
    IfGe(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        Call(N(SpawnSunEffect))
    EndIf
    Exec(N(EVS_TrySpawningStarCard))
    Return
    End
};
