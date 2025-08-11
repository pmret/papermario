#include "isk_07.h"

EvtScript N(EVS_ExitWalk_isk_08_2) = EVT_EXIT_WALK(40, isk_07_ENTRY_0, "isk_08", isk_08_ENTRY_2);
EvtScript N(EVS_ExitWalk_isk_04_1) = EVT_EXIT_WALK(40, isk_07_ENTRY_1, "isk_04", isk_04_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_isk_08_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_isk_04_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_DRY_DRY_RUINS)
    Call(SetSpriteShading, SHADING_ISK_07)
    SetUP_CAMERA_ALT_NO_LEAD()
    IfEq(GF_ISK07_Defeated_Mummies, false)
        Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    EndIf
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupLock))
    Exec(N(EVS_SetupStairs))
    Exec(N(EVS_SetupSwitch))
    Exec(N(EVS_SetupSarcophagi))
#if VERSION_PAL
    Call(SetMusic, 0, SONG_DRY_DRY_RUINS, 0, VOL_LEVEL_FULL)
#else
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
            Call(SetMusic, 0, SONG_DRY_DRY_RUINS, 0, VOL_LEVEL_FULL)
        CaseLt(STORY_CH2_DEFEATED_TUTANKOOPA)
            Call(SetMusic, 0, SONG_RUINS_BASEMENT, 0, VOL_LEVEL_FULL)
        CaseGe(STORY_CH2_DEFEATED_TUTANKOOPA)
            Call(SetMusic, 0, SONG_DRY_DRY_RUINS, 0, VOL_LEVEL_FULL)
    EndSwitch
#endif
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Return
    End
};
