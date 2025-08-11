#include "pra_29.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"

#include "../common/GlassShimmer.inc.c"

s32 N(NearLeftDoorModelsL)[] = { MODEL_o772, -1 };
s32 N(NearLeftDoorModelsR)[] = { MODEL_o768, -1 };
s32 N(FarLeftDoorModelsL)[]  = { MODEL_o859, -1 };
s32 N(FarLeftDoorModelsR)[]  = { MODEL_o861, -1 };
s32 N(BothLeftDoorModelsL)[] = { MODEL_o772, MODEL_o859, -1 };
s32 N(BothLeftDoorModelsR)[] = { MODEL_o768, MODEL_o861, -1 };

s32 N(NearRightDoorModelsL)[] = { MODEL_o995, -1 };
s32 N(NearRightDoorModelsR)[] = { MODEL_o997, -1 };
s32 N(FarRightDoorModelsL)[]  = { MODEL_o1096, -1 };
s32 N(FarRightDoorModelsR)[]  = { MODEL_o1094, -1 };
s32 N(BothRightDoorModelsL)[] = { MODEL_o995, MODEL_o1096, -1 };
s32 N(BothRightDoorModelsR)[] = { MODEL_o997, MODEL_o1094, -1 };

EvtScript N(EVS_ExitDoors_pra_20_2) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, pra_29_ENTRY_0)
    Set(LVar1, COLLIDER_deilittsw)
    IfEq(GF_PRA_BrokeIllusion, false)
        Set(LVar2, Ref(N(BothLeftDoorModelsL)))
        Set(LVar3, Ref(N(BothLeftDoorModelsR)))
    Else
        Set(LVar2, Ref(N(NearLeftDoorModelsL)))
        Set(LVar3, Ref(N(NearLeftDoorModelsR)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_20"), pra_20_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_34_0) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, pra_29_ENTRY_1)
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
    Call(GotoMap, Ref("pra_34"), pra_34_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_34_3) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, pra_29_ENTRY_2)
    Set(LVar1, COLLIDER_deilittne)
    IfEq(GF_PRA_BrokeIllusion, false)
        Set(LVar2, Ref(N(BothRightDoorModelsL)))
        Set(LVar3, Ref(N(BothRightDoorModelsR)))
    Else
        Set(LVar2, Ref(N(FarRightDoorModelsL)))
        Set(LVar3, Ref(N(FarRightDoorModelsR)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_34"), pra_34_ENTRY_3)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_20_3) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, pra_29_ENTRY_3)
    Set(LVar1, COLLIDER_deilittnw)
    IfEq(GF_PRA_BrokeIllusion, false)
        Set(LVar2, Ref(N(BothLeftDoorModelsL)))
        Set(LVar3, Ref(N(BothLeftDoorModelsR)))
    Else
        Set(LVar2, Ref(N(FarLeftDoorModelsL)))
        Set(LVar3, Ref(N(FarLeftDoorModelsR)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_20"), pra_20_ENTRY_3)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_pra_20_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_34_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_34_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_20_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(pra_29_ENTRY_0)
            IfEq(GF_PRA_BrokeIllusion, false)
                Set(LVar2, Ref(N(BothLeftDoorModelsL)))
                Set(LVar3, Ref(N(BothLeftDoorModelsR)))
            Else
                Set(LVar2, Ref(N(NearLeftDoorModelsL)))
                Set(LVar3, Ref(N(NearLeftDoorModelsR)))
            EndIf
        CaseEq(pra_29_ENTRY_1)
            IfEq(GF_PRA_BrokeIllusion, false)
                Set(LVar2, Ref(N(BothRightDoorModelsL)))
                Set(LVar3, Ref(N(BothRightDoorModelsR)))
            Else
                Set(LVar2, Ref(N(NearRightDoorModelsL)))
                Set(LVar3, Ref(N(NearRightDoorModelsR)))
            EndIf
        CaseEq(pra_29_ENTRY_2)
            IfEq(GF_PRA_BrokeIllusion, false)
                Set(LVar2, Ref(N(BothRightDoorModelsL)))
                Set(LVar3, Ref(N(BothRightDoorModelsR)))
            Else
                Set(LVar2, Ref(N(FarRightDoorModelsL)))
                Set(LVar3, Ref(N(FarRightDoorModelsR)))
            EndIf
        CaseEq(pra_29_ENTRY_3)
            IfEq(GF_PRA_BrokeIllusion, false)
                Set(LVar2, Ref(N(BothLeftDoorModelsL)))
                Set(LVar3, Ref(N(BothLeftDoorModelsR)))
            Else
                Set(LVar2, Ref(N(FarLeftDoorModelsL)))
                Set(LVar3, Ref(N(FarLeftDoorModelsR)))
            EndIf
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
    Call(SetCamEnabled, CAM_DEFAULT, true)
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_SetupBridge))
    Set(LVar0, MODEL_o945)
    Set(LVar1, MODEL_o945)
    Set(LVar2, TEX_PANNER_0)
    Exec(N(EVS_GlassShimmer))
    Set(LVar0, REFLECTION_WALL_ONLY)
    IfGe(GB_StoryProgress, STORY_CH7_EXTENDED_PALACE_BRIDGE)
        Set(LVar1, true)
    Else
        Set(LVar1, false)
    EndIf
    Exec(N(EVS_SetupReflections))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
