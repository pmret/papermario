#include "pra_20.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"
#include "../common/GlassShimmer.inc.c"

s32 N(NearSingleDoorModels)[] = { MODEL_o999, MODEL_o1000, -1 };
s32 N(FarSingleDoorModels)[]  = { MODEL_o997, MODEL_o998, -1 };

s32 N(NearRightDoorModelsL)[] = { MODEL_o874, MODEL_o875, -1 };
s32 N(NearRightDoorModelsR)[] = { MODEL_o876, MODEL_o877, -1 };

s32 N(BackRightDoorModelsL)[] = { MODEL_o880, MODEL_o881, -1 };
s32 N(BackRightDoorModelsR)[] = { MODEL_o878, MODEL_o879, -1 };

s32 N(BothRightDoorModelsL)[] = { MODEL_o874, MODEL_o875, MODEL_o880, MODEL_o881, -1 };
s32 N(BothRightDoorModelsR)[] = { MODEL_o876, MODEL_o877, MODEL_o878, MODEL_o879, -1 };

s32 N(ModelListNone)[] = { -1 };

EvtScript N(EVS_ExitWalk_pra_19_1) = EVT_EXIT_WALK(60, pra_20_ENTRY_0, "pra_19", pra_19_ENTRY_1);

EvtScript N(EVS_ExitDoor_pra_21_0) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, pra_20_ENTRY_1)
    Set(LVar1, COLLIDER_deilittssw)
    IfEq(GF_PRA_BrokeIllusion, false)
        Set(LVar2, Ref(N(NearSingleDoorModels)))
        Set(LVar3, Ref(N(FarSingleDoorModels)))
    Else
        Set(LVar2, Ref(N(NearSingleDoorModels)))
        Set(LVar3, Ref(N(ModelListNone)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_21"), pra_21_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_29_0) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, pra_20_ENTRY_2)
    Set(LVar1, COLLIDER_deilittse)
    IfEq(GF_PRA_BrokeIllusion, false)
        Set(LVar2, Ref(N(BothRightDoorModelsL)))
        Set(LVar3, Ref(N(BothRightDoorModelsR)))
    Else
        Set(LVar2, Ref(N(NearRightDoorModelsL)))
        Set(LVar3, Ref(N(NearRightDoorModelsR)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_29"), pra_29_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_29_3) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, pra_20_ENTRY_3)
    Set(LVar1, COLLIDER_deilittne)
    IfEq(GF_PRA_BrokeIllusion, false)
        Set(LVar2, Ref(N(BothRightDoorModelsL)))
        Set(LVar3, Ref(N(BothRightDoorModelsR)))
    Else
        Set(LVar2, Ref(N(BackRightDoorModelsL)))
        Set(LVar3, Ref(N(BackRightDoorModelsR)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_29"), pra_29_ENTRY_3)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoor_pra_22_0) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, pra_20_ENTRY_4)
    Set(LVar1, COLLIDER_deilittnnw)
    IfEq(GF_PRA_BrokeIllusion, false)
        Set(LVar2, Ref(N(NearSingleDoorModels)))
        Set(LVar3, Ref(N(FarSingleDoorModels)))
    Else
        Set(LVar2, Ref(N(ModelListNone)))
        Set(LVar3, Ref(N(FarSingleDoorModels)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_22"), pra_22_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_pra_19_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoor_pra_21_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittssw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_29_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_29_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoor_pra_22_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnnw, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(pra_20_ENTRY_0)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(pra_20_ENTRY_1)
            IfEq(GF_PRA_BrokeIllusion, false)
                Set(LVar2, Ref(N(NearSingleDoorModels)))
                Set(LVar3, Ref(N(FarSingleDoorModels)))
            Else
                Set(LVar2, Ref(N(NearSingleDoorModels)))
                Set(LVar3, Ref(N(ModelListNone)))
            EndIf
            ExecWait(BaseEnterDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(pra_20_ENTRY_2)
            IfEq(GF_PRA_BrokeIllusion, false)
                Set(LVar2, Ref(N(BothRightDoorModelsL)))
                Set(LVar3, Ref(N(BothRightDoorModelsR)))
            Else
                Set(LVar2, Ref(N(NearRightDoorModelsL)))
                Set(LVar3, Ref(N(NearRightDoorModelsR)))
            EndIf
            ExecWait(BaseEnterDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(pra_20_ENTRY_3)
            IfEq(GF_PRA_BrokeIllusion, false)
                Set(LVar2, Ref(N(BothRightDoorModelsL)))
                Set(LVar3, Ref(N(BothRightDoorModelsR)))
            Else
                Set(LVar2, Ref(N(BackRightDoorModelsL)))
                Set(LVar3, Ref(N(BackRightDoorModelsR)))
            EndIf
            ExecWait(BaseEnterDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(pra_20_ENTRY_4)
            IfEq(GF_PRA_BrokeIllusion, false)
                Set(LVar2, Ref(N(NearSingleDoorModels)))
                Set(LVar3, Ref(N(FarSingleDoorModels)))
            Else
                Set(LVar2, Ref(N(FarSingleDoorModels)))
                Set(LVar3, Ref(N(ModelListNone)))
            EndIf
            ExecWait(BaseEnterDoor)
            Exec(N(EVS_BindExitTriggers))
    EndSwitch
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
    Exec(N(EVS_SetupMusic))
    Call(EnableModel, MODEL_o981, false)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1019, COLLIDER_FLAGS_UPPER_MASK)
    Set(LVar0, MODEL_o945)
    Set(LVar1, MODEL_o947)
    Set(LVar2, TEX_PANNER_0)
    Exec(N(EVS_GlassShimmer))
    Set(LVar0, REFLECTION_FLOOR_WALL)
    Set(LVar1, GF_PRA_BrokeIllusion)
    Exec(N(EVS_SetupReflections))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
