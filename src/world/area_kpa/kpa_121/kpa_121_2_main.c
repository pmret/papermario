#include "kpa_121.h"

EvtScript N(EVS_ExitDoors_kpa_83_1) = EVT_EXIT_DOUBLE_DOOR(kpa_121_ENTRY_0, "kpa_83", kpa_83_ENTRY_1, COLLIDER_deilitw, MODEL_o348, MODEL_o356);

EvtScript N(EVS_ExitDoor_osr_02_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
        EVT_SET(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
    EVT_END_IF
    EVT_SET(LVar0, kpa_121_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_deilitte)
    EVT_SET(LVar2, MODEL_o340)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("osr_02"), osr_02_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_83_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_osr_02_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitte, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kpa_121_ENTRY_0)
            EVT_SET(LVar0, 0)
            EVT_SET(LVar2, MODEL_o356)
            EVT_SET(LVar3, MODEL_o348)
            EVT_EXEC(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kpa_121_ENTRY_1)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar2, MODEL_o340)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSingleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
