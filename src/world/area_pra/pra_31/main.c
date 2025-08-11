#include "pra_31.h"

s32 N(NearLeftDoorModelsL)[] = { MODEL_o772, -1 };
s32 N(NearLeftDoorModelsR)[] = { MODEL_o768, -1 };
s32 N(RightDoorModelsL)[]    = { MODEL_o955, -1 };
s32 N(RightDoorModelsR)[]    = { MODEL_o957, -1 };
s32 N(FarLeftDoorModelsL)[]  = { MODEL_o859, -1 };
s32 N(FarLeftDoorModelsR)[]  = { MODEL_o861, -1 };

EvtScript N(EVS_ExitDoors_pra_34_1) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, pra_31_ENTRY_0)
    Set(LVar1, COLLIDER_deilittsw)
    Set(LVar2, Ref(N(NearLeftDoorModelsL)))
    Set(LVar3, Ref(N(NearLeftDoorModelsR)))
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_34"), pra_34_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_40_0) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, pra_31_ENTRY_1)
    Set(LVar1, COLLIDER_deilitte)
    Set(LVar2, Ref(N(RightDoorModelsL)))
    Set(LVar3, Ref(N(RightDoorModelsR)))
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_40"), pra_40_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_34_2) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, pra_31_ENTRY_2)
    Set(LVar1, COLLIDER_deilittnw)
    Set(LVar2, Ref(N(FarLeftDoorModelsL)))
    Set(LVar3, Ref(N(FarLeftDoorModelsR)))
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_34"), pra_34_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_pra_34_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_40_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitte, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_34_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(pra_31_ENTRY_0)
            Set(LVar2, Ref(N(NearLeftDoorModelsL)))
            Set(LVar3, Ref(N(NearLeftDoorModelsR)))
        CaseEq(pra_31_ENTRY_1)
            Set(LVar2, Ref(N(RightDoorModelsL)))
            Set(LVar3, Ref(N(RightDoorModelsR)))
        CaseEq(pra_31_ENTRY_2)
            Set(LVar2, Ref(N(FarLeftDoorModelsL)))
            Set(LVar3, Ref(N(FarLeftDoorModelsR)))
    EndSwitch
    ExecWait(BaseEnterDoor)
    Exec(N(EVS_BindExitTriggers))
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_CRYSTAL_PALACE)
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    Call(SetCamBGColor, CAM_DEFAULT, 24, 24, 40)
    Call(SetCamLeadPlayer, CAM_DEFAULT, false)
    Call(SetCamEnabled, CAM_DEFAULT, true)
    Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_SetupPuzzle))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
