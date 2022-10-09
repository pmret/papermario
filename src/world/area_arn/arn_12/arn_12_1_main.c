#include "arn_12.h"

extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

EvtScript N(EVS_ExitDoor_arn_10_1) = EVT_EXIT_SINGLE_DOOR(arn_12_ENTRY_0, "arn_10", arn_10_ENTRY_1,
    COLLIDER_ttw, MODEL_o44, DOOR_SWING_IN);

EvtScript N(EVS_ExitDoor_arn_13_0) = EVT_EXIT_SINGLE_DOOR(arn_12_ENTRY_1, "arn_13", arn_13_ENTRY_0,
    COLLIDER_tte, MODEL_o37, DOOR_SWING_OUT);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_arn_10_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_arn_13_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(arn_12_ENTRY_0)
            EVT_SET(LVar2, MODEL_o44)
            EVT_SET(LVar3, DOOR_SWING_IN)
            EVT_EXEC_WAIT(EnterSingleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(arn_12_ENTRY_1)
            EVT_SET(LVar2, MODEL_o37)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSingleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_WINDY_MILL)
    EVT_CALL(SetSpriteShading, SHADING_ARN_12)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
