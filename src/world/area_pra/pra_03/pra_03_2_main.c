#include "pra_03.h"

EvtScript N(EVS_ExitDoors_pra_02_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_03_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilittnnw)
    EVT_SET(LVar2, MODEL_o774)
    EVT_SET(LVar3, DOOR_SWING_IN)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_02"), pra_02_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_38_0) = EVT_EXIT_DOUBLE_DOOR(pra_03_ENTRY_1, "pra_38", pra_38_ENTRY_0, COLLIDER_deilittne, MODEL_o880, MODEL_o878);
EvtScript N(EVS_ExitDoors_pra_09_0) = EVT_EXIT_DOUBLE_DOOR(pra_03_ENTRY_2, "pra_09", pra_09_ENTRY_0, COLLIDER_deilittnne, MODEL_o989, MODEL_o988);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_02_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnnw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_38_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_09_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnne, 1, 0)
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
        EVT_CASE_EQ(pra_03_ENTRY_0)
            EVT_SET(LVar2, MODEL_o774)
            EVT_SET(LVar3, DOOR_SWING_IN)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(pra_03_ENTRY_1)
            EVT_SET(LVar2, MODEL_o880)
            EVT_SET(LVar3, MODEL_o878)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(pra_03_ENTRY_2)
            EVT_SET(LVar2, MODEL_o989)
            EVT_SET(LVar3, MODEL_o988)
            EVT_EXEC_WAIT(EnterDoubleDoor)
    EVT_END_SWITCH
    EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_CRYSTAL_PALACE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 24, 24, 40)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_IF_EQ(GF_PRA04_BoardedFloor, TRUE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittn, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableModel, MODEL_g286, FALSE)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_o998, FALSE)
    EVT_END_IF
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
