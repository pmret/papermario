#include "pra_04.h"

EvtScript N(EVS_ExitDoor_pra_02_4) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_04_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilittssw)
    EVT_SET(LVar2, MODEL_o847)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_02"), pra_02_ENTRY_4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_39_0) = EVT_EXIT_DOUBLE_DOOR(pra_04_ENTRY_1, "pra_39", pra_39_ENTRY_0, COLLIDER_deilittse, MODEL_o874, MODEL_o876);
EvtScript N(EVS_ExitDoors_pra_10_0) = EVT_EXIT_DOUBLE_DOOR(pra_04_ENTRY_2, "pra_10", pra_10_ENTRY_0, COLLIDER_deilittsse, MODEL_o986, MODEL_o987);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_pra_02_4)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittssw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_39_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_10_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsse, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(pra_04_ENTRY_0)
            EVT_SET(LVar2, MODEL_o847)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(pra_04_ENTRY_1)
            EVT_SET(LVar2, MODEL_o874)
            EVT_SET(LVar3, MODEL_o876)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(pra_04_ENTRY_2)
            EVT_SET(LVar2, MODEL_o986)
            EVT_SET(LVar3, MODEL_o987)
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
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_IF_EQ(GF_PRA04_BoardedFloor, TRUE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitts, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableModel, MODEL_o994, FALSE)
    EVT_END_IF
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
