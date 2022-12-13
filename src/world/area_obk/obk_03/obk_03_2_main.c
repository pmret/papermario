#include "obk_03.h"

EvtScript N(EVS_ExitDoor_obk_02_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, obk_03_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_tt2)
    EVT_SET(LVar2, MODEL_door_2_1)
    EVT_SET(LVar4, MODEL_door_2_2)
    EVT_SET(LVar3, DOOR_SWING_IN)
    EVT_EXEC(ExitSplitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("obk_02"), obk_02_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_obk_04_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, obk_03_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_tt1)
    EVT_SET(LVar2, MODEL_door_1)
    EVT_SET(LVar4, MODEL_o494)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC(ExitSplitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("obk_04"), obk_04_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(obk_03_ENTRY_0)
            EVT_SET(LVar2, MODEL_door_2_1)
            EVT_SET(LVar4, MODEL_door_2_2)
            EVT_SET(LVar3, DOOR_SWING_IN)
            EVT_EXEC_WAIT(EnterSplitSingleDoor)
        EVT_CASE_EQ(obk_03_ENTRY_1)
            EVT_SET(LVar2, MODEL_door_1)
            EVT_SET(LVar4, MODEL_o494)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSplitSingleDoor)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Fog) = {
    EVT_CALL(SetTexPanner, MODEL_m2, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_m4, TEX_PANNER_0)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LABEL(20)
        EVT_ADD(LVar0, 300)
        EVT_ADD(LVar1, 100)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, LVar0, LVar1)
        EVT_WAIT(1)
        EVT_GOTO(20)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOOS_MANSION)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupStairs))
    EVT_EXEC(N(EVS_SetupRockingChair))
    EVT_EXEC_WAIT(N(EVS_SetupShop))
    EVT_EXEC(N(EVS_TexPan_Fog))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_obk_04_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_obk_02_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tt2, 1, 0)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
