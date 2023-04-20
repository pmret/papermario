#include "pra_40.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"

EvtScript N(EVS_ExitDoors_pra_31_1) = EVT_EXIT_DOUBLE_DOOR(pra_40_ENTRY_0, "pra_31", pra_31_ENTRY_1, COLLIDER_deilitt1, MODEL_o1055, MODEL_o1053);
EvtScript N(EVS_ExitDoors_pra_32_0) = EVT_EXIT_DOUBLE_DOOR(pra_40_ENTRY_1, "pra_32", pra_32_ENTRY_0, COLLIDER_deilitt2, MODEL_o880, MODEL_o878);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_31_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitt1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_32_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitt2, 1, 0)
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
        EVT_CASE_EQ(pra_40_ENTRY_0)
            EVT_SET(LVar2, MODEL_o1055)
            EVT_SET(LVar3, MODEL_o1053)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(pra_40_ENTRY_1)
            EVT_SET(LVar2, MODEL_o880)
            EVT_SET(LVar3, MODEL_o878)
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
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
