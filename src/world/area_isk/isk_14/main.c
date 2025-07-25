#include "isk_14.h"

EvtScript N(D_80241DB0_9944E0) = EVT_EXIT_WALK(40, isk_14_ENTRY_0, "isk_10", isk_10_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(D_80241DB0_9944E0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_DRY_DRY_RUINS)
    Call(SetSpriteShading, SHADING_ISK_14)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
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
