#include "omo_15.h"
#include "sprite/player.h"

#define STAR_SPIRIT_DATA_VAR MV_Unk_01
#include "world/common/todo/StarSpiritEffectFunc.inc.c"

EvtScript N(EVS_TrySpawningStarCard) = {
    // determine if card should be spawned
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH4_OPENED_GENERAL_GUY_ROOM)
            Set(LVar0, false)
            Set(GB_StoryProgress, STORY_CH4_DEFEATED_GENERAL_GUY)
        CaseEq(STORY_CH4_DEFEATED_GENERAL_GUY)
            Set(LVar0, true)
        CaseDefault
            Return
    EndSwitch
    IfEq(LVar0, false)
        // card appearing scene
        Call(DisablePlayerInput, true)
        Call(UseSettingsFrom, CAM_DEFAULT, -100, 85, 0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.5))
        Call(SetPanTarget, CAM_DEFAULT, -100, 30, 0)
        EVT_SPIRIT_ADJUST_CAM(10000)
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Call(N(StarSpiritEffectFunc2), 3, 180, 215, 60, 0, -100, 85, 0, 30, 0)
        Thread
            Call(N(StarSpiritEffectFunc3))
        EndThread
        Thread
            Wait(1)
            Call(PlaySound, SOUND_LOOP_STAR_ORB_RISING)
            Call(N(StarSpiritEffectFunc1))
            Call(StopSound, SOUND_LOOP_STAR_ORB_RISING)
            Call(PlaySoundAt, SOUND_STAR_ORB_BURST, SOUND_SPACE_DEFAULT, -100, 85, 0)
        EndThread
        Thread
            Wait(45)
            Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
        EndThread
        Thread
            Wait(180)
            Wait(115)
            Call(PlaySoundAt, SOUND_STAR_CARD_APPEARS, SOUND_SPACE_DEFAULT, -100, 85, 0)
        EndThread
        Call(N(StarSpiritEffectFunc4), 1)
        Thread
            Wait(80)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        EndThread
        Add(LVar1, 100)
        Call(SetCamDistance, CAM_DEFAULT, LVar1)
        Call(SetPanTarget, CAM_DEFAULT, -100, 0, 0)
        Call(N(StarSpiritEffectFunc4), 2)
        Call(GetPlayerPos, LVar2, LVar3, LVar4)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
        Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
        Call(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(PanToTarget, CAM_DEFAULT, 0, false)
        Call(DisablePlayerInput, false)
    Else
        // just make the card spawn
        Call(N(StarSpiritEffectFunc5), 3, -100, 30, 0, 0)
        Thread
            Call(N(StarSpiritEffectFunc6))
        EndThread
        Wait(1)
    EndIf
    // wait for pickup
    Call(N(StarSpiritEffectFunc4), 3)
    Call(PlaySoundAtPlayer, SOUND_RESCUE_STAR_SPIRIT, SOUND_SPACE_DEFAULT)
    Call(DisablePlayerInput, true)
    Set(GB_StoryProgress, STORY_CH4_STAR_SPIRIT_RESCUED)
    Call(GotoMapSpecial, Ref("kmr_23"), kmr_23_ENTRY_3, TRANSITION_GET_STAR_CARD)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_omo_14_1) = EVT_EXIT_WALK(60, omo_15_ENTRY_0, "omo_14", omo_14_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_omo_14_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_SetupMusic))
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    IfEq(GB_StoryProgress, STORY_CH4_DEFEATED_GENERAL_GUY)
        Exec(N(EVS_TrySpawningStarCard))
    EndIf
    Return
    End
};
