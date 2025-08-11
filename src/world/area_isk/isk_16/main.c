#include "isk_16.h"
#include "sprite/player.h"

#define STAR_SPIRIT_DATA_VAR MV_Unk_01
#include "world/common/todo/StarSpiritEffectFunc.inc.c"

EvtScript N(EVS_SpawnStarCard) = {
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
            Set(LVar0, 0)
            Set(GB_StoryProgress, STORY_CH2_DEFEATED_TUTANKOOPA)
        CaseEq(STORY_CH2_DEFEATED_TUTANKOOPA)
            Set(LVar0, 1)
        CaseDefault
            Return
    EndSwitch
    IfEq(LVar0, 0)
        Call(DisablePlayerInput, true)
        Call(UseSettingsFrom, CAM_DEFAULT, 408, -825, 414)
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.6))
        Call(SetPanTarget, CAM_DEFAULT, 408, -880, 414)
        EVT_SPIRIT_ADJUST_CAM(10000)
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Call(N(StarSpiritEffectFunc2), 1, 180, 408, -900, 414, 408, -825, 414, -880, -910)
        Thread
            Call(N(StarSpiritEffectFunc3))
        EndThread
        Thread
            Wait(1)
            Call(PlaySound, SOUND_LOOP_STAR_ORB_RISING)
            Call(N(StarSpiritEffectFunc1))
            Call(StopSound, SOUND_LOOP_STAR_ORB_RISING)
            Call(PlaySoundAt, SOUND_STAR_ORB_BURST, SOUND_SPACE_DEFAULT, 408, -825, 414)
        EndThread
        Thread
            Wait(45)
            Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
        EndThread
        Thread
            Wait(180)
            Wait(115)
            Call(PlaySoundAt, SOUND_STAR_CARD_APPEARS, SOUND_SPACE_DEFAULT, 408, -825, 414)
        EndThread
        Call(N(StarSpiritEffectFunc4), 1)
        Thread
            Wait(80)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        EndThread
        Add(LVar1, 100)
        Call(SetCamDistance, CAM_DEFAULT, LVar1)
        Call(SetPanTarget, CAM_DEFAULT, 408, -910, 414)
        Call(N(StarSpiritEffectFunc4), 2)
        Call(GetPlayerPos, LVar2, LVar3, LVar4)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
        Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
        Call(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(PanToTarget, CAM_DEFAULT, 0, false)
        Call(DisablePlayerInput, false)
    Else
        Call(N(StarSpiritEffectFunc5), 1, 408, -880, 414, -910)
        Thread
            Call(N(StarSpiritEffectFunc6))
        EndThread
        Wait(1)
    EndIf
    Call(N(StarSpiritEffectFunc4), 3)
    Call(PlaySoundAtPlayer, SOUND_RESCUE_STAR_SPIRIT, SOUND_SPACE_DEFAULT)
    Call(DisablePlayerInput, true)
    Set(GB_StoryProgress, STORY_CH2_STAR_SPIRIT_RESCUED)
    Call(GotoMapSpecial, Ref("kmr_23"), kmr_23_ENTRY_1, TRANSITION_GET_STAR_CARD)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_isk_19_1) = EVT_EXIT_WALK(40, isk_16_ENTRY_0, "isk_19", isk_19_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_isk_19_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_DRY_DRY_RUINS)
    Call(SetSpriteShading, SHADING_ISK_16)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, false, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_SetupFlames))
    IfEq(GB_StoryProgress, STORY_CH2_DEFEATED_TUTANKOOPA)
        Exec(N(EVS_SpawnStarCard))
    EndIf
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_DEFEATED_TUTANKOOPA)
            Call(SetMusic, 0, SONG_TUTANKOOPA_REVEALED, 0, VOL_LEVEL_FULL)
        CaseEq(STORY_CH2_DEFEATED_TUTANKOOPA)
            Call(FadeOutMusic, 0, 500)
        CaseGt(STORY_CH2_DEFEATED_TUTANKOOPA)
    EndSwitch
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_DEFEATED_TUTANKOOPA)
            Exec(N(EVS_Scene_TutankoopaAppears))
        CaseGe(STORY_CH2_DEFEATED_TUTANKOOPA)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};
