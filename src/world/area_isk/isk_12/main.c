#include "isk_12.h"

EvtScript N(EVS_ExitWalk_isk_11_1) = EVT_EXIT_WALK(40, isk_12_ENTRY_0, "isk_11", isk_11_ENTRY_1);
EvtScript N(EVS_ExitWalk_isk_11_2) = EVT_EXIT_WALK(40, isk_12_ENTRY_1, "isk_11", isk_11_ENTRY_2);
EvtScript N(EVS_ExitWalk_isk_18_1) = EVT_EXIT_WALK(40, isk_12_ENTRY_2, "isk_18", isk_18_ENTRY_1);
EvtScript N(EVS_ExitWalk_isk_13_0) = EVT_EXIT_WALK(40, isk_12_ENTRY_3, "isk_13", isk_13_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_isk_11_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilinw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_isk_11_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_isk_18_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_isk_13_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_DRY_DRY_RUINS)
    Call(SetSpriteShading, SHADING_ISK_12)
    SetUP_CAMERA_NO_LEAD()
    IfLt(GB_StoryProgress, STORY_CH2_DRAINED_THIRD_SAND_ROOM)
        Call(SetZoneEnabled, ZONE_deiliw, FALSE)
    Else
        Call(SetZoneEnabled, ZONE_deiliw, FALSE)
        Call(SetZoneEnabled, ZONE_on, FALSE)
    EndIf
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupSand))
    Exec(N(EVS_SetupSwitches))
#if VERSION_PAL
    Call(SetMusicTrack, 0, SONG_DRY_DRY_RUINS, 0, 8)
#else
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
            Call(SetMusicTrack, 0, SONG_DRY_DRY_RUINS, 0, 8)
        CaseLt(STORY_CH2_DEFEATED_TUTANKOOPA)
            Call(SetMusicTrack, 0, SONG_RUINS_BASEMENT, 0, 8)
        CaseGe(STORY_CH2_DEFEATED_TUTANKOOPA)
            Call(SetMusicTrack, 0, SONG_DRY_DRY_RUINS, 0, 8)
    EndSwitch
#endif
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Return
    End
};
