
#include "kpa_40.h"

EvtScript N(EVS_ExitDoors_kpa_52_1) = EVT_EXIT_DOUBLE_DOOR(kpa_40_ENTRY_0, "kpa_52", kpa_52_ENTRY_1, COLLIDER_ttw, MODEL_o526, MODEL_o525);
EvtScript N(EVS_ExitWalk_kpa_40_3) = EVT_EXIT_WALK(60, kpa_40_ENTRY_1, "kpa_40", kpa_40_ENTRY_3);

EvtScript N(EVS_ExitWalk_kpa_41_3) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, kpa_40_ENTRY_2)
    EVT_EXEC(ExitWalk)
    EVT_SET(AB_KPA_MazeProgress, 1)
    EVT_CALL(GotoMap, EVT_PTR("kpa_41"), kpa_41_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_52_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_40_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie2, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_41_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kpa_40_ENTRY_0)
            EVT_SET(LVar0, kpa_40_ENTRY_0)
            EVT_SET(LVar2, MODEL_o526)
            EVT_SET(LVar3, MODEL_o525)
            EVT_EXEC(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};


