#include "arn_09.h"

EvtScript N(EVS_ExitDoor_arn_10_0) = EVT_EXIT_SPLIT_SINGLE_DOOR(arn_09_ENTRY_0, "arn_10", arn_10_ENTRY_0,
    COLLIDER_tte, MODEL_doa, MODEL_o37, DOOR_SWING_OUT);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_arn_10_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(arn_09_ENTRY_0)
            EVT_SET(LVar2, MODEL_doa)
            EVT_SET(LVar4, MODEL_o37)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSplitSingleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(arn_09_ENTRY_1)
            EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_WINDY_MILL)
    EVT_CALL(SetSpriteShading, SHADING_ARN_09)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_EXEC(N(EVS_LaunchPlayer))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
