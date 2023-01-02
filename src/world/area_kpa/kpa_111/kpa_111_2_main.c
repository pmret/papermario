#include "kpa_111.h"

EvtScript N(EVS_ExitDoors_kpa_130_1) = EVT_EXIT_DOUBLE_DOOR(kpa_111_ENTRY_0, "kpa_130", kpa_130_ENTRY_1, COLLIDER_deiliwtt, MODEL_o119, MODEL_o118);
EvtScript N(EVS_ExitDoors_kpa_112_0) = EVT_EXIT_WALK(40, kpa_111_ENTRY_1, "kpa_112", kpa_112_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_130_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deiliwtt, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_112_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kpa_111_ENTRY_0)
            EVT_SET(LVar0, kpa_111_ENTRY_0)
            EVT_SET(LVar2, MODEL_o119)
            EVT_SET(LVar3, MODEL_o118)
            EVT_EXEC(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kpa_111_ENTRY_1)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupStatues))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
