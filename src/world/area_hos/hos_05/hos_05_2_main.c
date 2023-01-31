#include "hos_05.h"

EvtScript N(EVS_ExitWalk_hos_04_1) = EVT_EXIT_WALK(60, hos_05_ENTRY_0, "hos_04", hos_04_ENTRY_1);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_hos_04_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Starship_Depart)), TRIGGER_FLOOR_TOUCH, COLLIDER_o630, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_STAR_HAVEN)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, hos_05_ENTRY_3)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(IntroNPCs)))
    EVT_ELSE
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupStarshipAndWater))
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(hos_05_ENTRY_0)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.5))
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(hos_05_ENTRY_1)
            EVT_THREAD
                EVT_EXEC_WAIT(N(EVS_EnterStarship))
                EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_END_THREAD
        EVT_CASE_EQ(hos_05_ENTRY_3)
            EVT_EXEC_WAIT(N(EVS_Intro_Main))
    EVT_END_SWITCH
    EVT_EXEC(N(EVS_SetupNarrator))
    EVT_CALL(EnableGroup, MODEL_g277, FALSE)
    EVT_CALL(EnableGroup, MODEL_g279, FALSE)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_RANGE(hos_05_ENTRY_0, hos_05_ENTRY_1)
            EVT_EXEC(N(EVS_SetupLightBeam))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
