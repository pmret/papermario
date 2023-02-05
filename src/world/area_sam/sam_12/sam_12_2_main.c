#include "sam_12.h"

EvtScript N(EVS_ExitWalk_sam_10_2) = EVT_EXIT_WALK_NOK(60, sam_12_ENTRY_0, "sam_10", sam_10_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sam_10_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_SHIVER_MOUNTAIN)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_GOT_STAR_STONE)
        EVT_EXEC(N(EVS_Scene_MeetMerlar))
    EVT_END_IF
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_RETURN
    EVT_END
};
