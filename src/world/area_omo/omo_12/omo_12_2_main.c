#include "omo_12.h"

EvtScript N(EVS_ExitWalk_omo_11_0) = EVT_EXIT_WALK(60, omo_12_ENTRY_0, "omo_11", omo_11_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_omo_11_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_EXEC_WAIT(N(EVS_SetupLightSource))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH4_DEFEATED_LANTERN_GHOST)
            EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_EXEC(N(EVS_EnterScene))
            EVT_WAIT(1)
        EVT_CASE_LT(STORY_CH4_WATT_JOINED_PARTY)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
        EVT_CASE_GE(STORY_CH4_WATT_JOINED_PARTY)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
