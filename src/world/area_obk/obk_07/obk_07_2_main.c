#include "obk_07.h"

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SET(LVar2, MODEL_door_1)
    EVT_SET(LVar4, MODEL_door1b)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC_WAIT(EnterSplitSingleDoor)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_obk_01_3) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, obk_07_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_tt1)
    EVT_SET(LVar2, MODEL_door_1)
    EVT_SET(LVar4, MODEL_door1b)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC(ExitSplitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("obk_01"), obk_01_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Fog) = {
    EVT_THREAD
        EVT_CALL(EnableTexPanning, MODEL_ma, TRUE)
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_LOOP(0)
            EVT_CALL(SetTexPanOffset, 2, 1, LVar0, LVar1)
            EVT_ADD(LVar0, 300)
            EVT_ADD(LVar1, 100)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_m2, 0)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 300)
        EVT_ADD(LVar1, 100)
        EVT_CALL(SetTexPanOffset, 0, 0, LVar0, LVar1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOOS_MANSION)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_TexPan_Fog))
    EVT_EXEC(N(EVS_SetupFireplace))
    EVT_EXEC(N(EVS_SetupPhonograph))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_obk_01_3)), TRIGGER_WALL_PRESS_A, COLLIDER_tt1, 1, 0)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
