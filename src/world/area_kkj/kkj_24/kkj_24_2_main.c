#include "kkj_24.h"

API_CALLABLE(N(func_80240000_B06570)) {
    enable_world_fog();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitDoors_kkj_23_1) = EVT_EXIT_DOUBLE_DOOR(kkj_24_ENTRY_0, "kkj_23", kkj_23_ENTRY_1, COLLIDER_tte, MODEL_o58, MODEL_o57);
EvtScript N(EVS_ExitDoors_kkj_25_0) = EVT_EXIT_DOUBLE_DOOR(kkj_24_ENTRY_1, "kkj_25", kkj_25_ENTRY_0, COLLIDER_tte2, MODEL_o78, MODEL_o77);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_23_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_25_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kkj_24_ENTRY_0)
            EVT_SET(LVar2, MODEL_o58)
            EVT_SET(LVar3, MODEL_o57)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(kkj_24_ENTRY_1)
            EVT_SET(LVar2, MODEL_o78)
            EVT_SET(LVar3, MODEL_o77)
            EVT_EXEC_WAIT(EnterDoubleDoor)
    EVT_END_SWITCH
    EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_KKJ_24)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(N(func_80240000_B06570))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
