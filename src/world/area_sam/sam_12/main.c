#include "sam_12.h"

EvtScript N(EVS_ExitWalk_sam_10_2) = EVT_EXIT_WALK_NOK(60, sam_12_ENTRY_0, "sam_10", sam_10_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_sam_10_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHIVER_MOUNTAIN)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(MakeNpcs, false, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupMusic))
    IfLt(GB_StoryProgress, STORY_CH7_GOT_STAR_STONE)
        Exec(N(EVS_Scene_MeetMerlar))
    EndIf
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Return
    End
};
