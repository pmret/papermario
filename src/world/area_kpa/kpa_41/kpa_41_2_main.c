#include "kpa_41.h"

EvtScript N(EVS_ExitWalk_LowerLeft) = EVT_EXIT_WALK(60, kpa_41_ENTRY_0, "kpa_40", kpa_40_ENTRY_1);

EvtScript N(EVS_ExitWalk_LowerRight) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, kpa_41_ENTRY_1)
    EVT_EXEC(ExitWalk)
    EVT_SWITCH(AB_KPA_MazeProgress)
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(4)
            EVT_ADD(AB_KPA_MazeProgress, 1)
            EVT_CALL(GotoMap, EVT_PTR("kpa_41"), kpa_41_ENTRY_0)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(3)
        EVT_CASE_OR_EQ(5)
            EVT_CALL(GotoMap, EVT_PTR("kpa_40"), kpa_40_ENTRY_3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_UpperLeft) = EVT_EXIT_WALK(60, kpa_41_ENTRY_3, "kpa_40", kpa_40_ENTRY_2);

EvtScript N(EVS_ExitWalk_UpperRight) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, kpa_41_ENTRY_2)
    EVT_EXEC(ExitWalk)
    EVT_SWITCH(AB_KPA_MazeProgress)
        EVT_CASE_EQ(5)
            EVT_SET(AB_KPA_MazeProgress, 0)
            EVT_CALL(GotoMap, EVT_PTR("kpa_102"), kpa_102_ENTRY_0)
        EVT_CASE_EQ(3)
            EVT_ADD(AB_KPA_MazeProgress, 1)
            EVT_CALL(GotoMap, EVT_PTR("kpa_41"), kpa_41_ENTRY_3)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(4)
            EVT_CALL(GotoMap, EVT_PTR("kpa_40"), kpa_40_ENTRY_3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_LowerLeft)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_LowerRight)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_UpperLeft)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_UpperRight)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili4, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kpa_41_ENTRY_2)
            EVT_SET(AB_KPA_MazeProgress, 5)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_EXEC(N(EVS_EnterMap))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};

