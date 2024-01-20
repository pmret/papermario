#include "pra_03.h"

EvtScript N(EVS_ExitDoors_pra_02_1) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, pra_03_ENTRY_0)
    Set(LVar1, COLLIDER_deilittnnw)
    Set(LVar2, MODEL_o774)
    Set(LVar3, DOOR_SWING_IN)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_02"), pra_02_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_38_0) = EVT_EXIT_DOUBLE_DOOR(pra_03_ENTRY_1, "pra_38", pra_38_ENTRY_0, COLLIDER_deilittne, MODEL_o880, MODEL_o878);
EvtScript N(EVS_ExitDoors_pra_09_0) = EVT_EXIT_DOUBLE_DOOR(pra_03_ENTRY_2, "pra_09", pra_09_ENTRY_0, COLLIDER_deilittnne, MODEL_o989, MODEL_o988);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_pra_02_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnnw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_38_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_09_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnne, 1, 0)
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
        CaseEq(pra_03_ENTRY_0)
            Set(LVar2, MODEL_o774)
            Set(LVar3, DOOR_SWING_IN)
            ExecWait(EnterSingleDoor)
        CaseEq(pra_03_ENTRY_1)
            Set(LVar2, MODEL_o880)
            Set(LVar3, MODEL_o878)
            ExecWait(EnterDoubleDoor)
        CaseEq(pra_03_ENTRY_2)
            Set(LVar2, MODEL_o989)
            Set(LVar3, MODEL_o988)
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
    IfEq(GF_PRA04_BoardedFloor, TRUE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittn, COLLIDER_FLAGS_UPPER_MASK)
        Call(EnableModel, MODEL_g286, FALSE)
    Else
        Call(EnableModel, MODEL_o998, FALSE)
    EndIf
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
