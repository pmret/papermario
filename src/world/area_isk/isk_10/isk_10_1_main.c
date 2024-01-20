#include "isk_10.h"

EvtScript N(EVS_ExitWalk_isk_08_1) = EVT_EXIT_WALK(40, isk_10_ENTRY_0, "isk_08", isk_08_ENTRY_1);
EvtScript N(EVS_ExitWalk_isk_14_0) = EVT_EXIT_WALK(40, isk_10_ENTRY_1, "isk_14", isk_14_ENTRY_0);
EvtScript N(EVS_ExitWalk_isk_18_0) = EVT_EXIT_WALK(40, isk_10_ENTRY_2, "isk_18", isk_18_ENTRY_0);
MAP_RODATA_PAD(1,unk);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_isk_08_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_isk_14_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_isk_18_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_DRY_DRY_RUINS)
    Call(SetSpriteShading, SHADING_ISK_10)
    SetUP_CAMERA_NO_LEAD()
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.8))
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupBombableWall))
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
