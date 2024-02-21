#include "pra_40.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"

EvtScript N(EVS_ExitDoors_pra_31_1) = EVT_EXIT_DOUBLE_DOOR(pra_40_ENTRY_0, "pra_31", pra_31_ENTRY_1, COLLIDER_deilitt1, MODEL_o1055, MODEL_o1053);
EvtScript N(EVS_ExitDoors_pra_32_0) = EVT_EXIT_DOUBLE_DOOR(pra_40_ENTRY_1, "pra_32", pra_32_ENTRY_0, COLLIDER_deilitt2, MODEL_o880, MODEL_o878);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_pra_31_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitt1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_32_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitt2, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(pra_40_ENTRY_0)
            Set(LVar2, MODEL_o1055)
            Set(LVar3, MODEL_o1053)
            ExecWait(EnterDoubleDoor)
        CaseEq(pra_40_ENTRY_1)
            Set(LVar2, MODEL_o880)
            Set(LVar3, MODEL_o878)
            ExecWait(EnterDoubleDoor)
    EndSwitch
    Exec(N(EVS_BindExitTriggers))
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_CRYSTAL_PALACE)
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    Call(SetCamBGColor, CAM_DEFAULT, 24, 24, 40)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Call(SetCamEnabled, CAM_DEFAULT, TRUE)
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
