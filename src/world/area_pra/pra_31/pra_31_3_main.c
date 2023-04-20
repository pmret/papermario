#include "pra_31.h"

s32 N(NearLeftDoorModelsL)[] = { MODEL_o772, -1 };
s32 N(NearLeftDoorModelsR)[] = { MODEL_o768, -1 };
s32 N(RightDoorModelsL)[]    = { MODEL_o955, -1 };
s32 N(RightDoorModelsR)[]    = { MODEL_o957, -1 };
s32 N(FarLeftDoorModelsL)[]  = { MODEL_o859, -1 };
s32 N(FarLeftDoorModelsR)[]  = { MODEL_o861, -1 };

EvtScript N(EVS_ExitDoors_pra_34_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_31_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilittsw)
    EVT_SET(LVar2, EVT_PTR(N(NearLeftDoorModelsL)))
    EVT_SET(LVar3, EVT_PTR(N(NearLeftDoorModelsR)))
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_34"), pra_34_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_40_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_31_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_deilitte)
    EVT_SET(LVar2, EVT_PTR(N(RightDoorModelsL)))
    EVT_SET(LVar3, EVT_PTR(N(RightDoorModelsR)))
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_40"), pra_40_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_34_2) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_31_ENTRY_2)
    EVT_SET(LVar1, COLLIDER_deilittnw)
    EVT_SET(LVar2, EVT_PTR(N(FarLeftDoorModelsL)))
    EVT_SET(LVar3, EVT_PTR(N(FarLeftDoorModelsR)))
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_34"), pra_34_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_34_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_40_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitte, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_34_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(pra_31_ENTRY_0)
            EVT_SET(LVar2, EVT_PTR(N(NearLeftDoorModelsL)))
            EVT_SET(LVar3, EVT_PTR(N(NearLeftDoorModelsR)))
        EVT_CASE_EQ(pra_31_ENTRY_1)
            EVT_SET(LVar2, EVT_PTR(N(RightDoorModelsL)))
            EVT_SET(LVar3, EVT_PTR(N(RightDoorModelsR)))
        EVT_CASE_EQ(pra_31_ENTRY_2)
            EVT_SET(LVar2, EVT_PTR(N(FarLeftDoorModelsL)))
            EVT_SET(LVar3, EVT_PTR(N(FarLeftDoorModelsR)))
    EVT_END_SWITCH
    EVT_EXEC_WAIT(BaseEnterDoor)
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
    EVT_EXEC_WAIT(N(EVS_SetupPuzzle))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
