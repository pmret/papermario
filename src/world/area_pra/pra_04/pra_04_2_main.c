#include "pra_04.h"

EvtScript N(EVS_ExitDoor_pra_02_4) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, pra_04_ENTRY_0)
    Set(LVar1, COLLIDER_deilittssw)
    Set(LVar2, MODEL_o847)
    Set(LVar3, DOOR_SWING_OUT)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_02"), pra_02_ENTRY_4)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_39_0) = EVT_EXIT_DOUBLE_DOOR(pra_04_ENTRY_1, "pra_39", pra_39_ENTRY_0, COLLIDER_deilittse, MODEL_o874, MODEL_o876);
EvtScript N(EVS_ExitDoors_pra_10_0) = EVT_EXIT_DOUBLE_DOOR(pra_04_ENTRY_2, "pra_10", pra_10_ENTRY_0, COLLIDER_deilittsse, MODEL_o986, MODEL_o987);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoor_pra_02_4)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittssw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_39_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_10_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsse, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(pra_04_ENTRY_0)
            Set(LVar2, MODEL_o847)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSingleDoor)
        CaseEq(pra_04_ENTRY_1)
            Set(LVar2, MODEL_o874)
            Set(LVar3, MODEL_o876)
            ExecWait(EnterDoubleDoor)
        CaseEq(pra_04_ENTRY_2)
            Set(LVar2, MODEL_o986)
            Set(LVar3, MODEL_o987)
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
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    IfEq(GF_PRA04_BoardedFloor, TRUE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitts, COLLIDER_FLAGS_UPPER_MASK)
        Call(EnableModel, MODEL_o994, FALSE)
    EndIf
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
