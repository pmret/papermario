#include "pra_16.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"
#include "../common/GlassShimmer.inc.c"

// doors on right wall
s32 N(NearRightDoorModelsL)[] = { MODEL_o772, MODEL_o844, -1 };
s32 N(NearRightDoorModelsR)[] = { MODEL_o768, MODEL_o846, -1 };
s32 N(FarRightDoorModelsL)[]  = { MODEL_o859, MODEL_o860, -1 };
s32 N(FarRightDoorModelsR)[]  = { MODEL_o861, MODEL_o862, -1 };
s32 N(BothRightDoorModelsL)[] = { MODEL_o772, MODEL_o844, MODEL_o859, MODEL_o860, -1 };
s32 N(BothRightDoorModelsR)[] = { MODEL_o768, MODEL_o846, MODEL_o861, MODEL_o862, -1 };

// doors on left wall
s32 N(NearLeftDoorModelsL)[] = { MODEL_o874, MODEL_o875, -1 };
s32 N(NearLeftDoorModelsR)[] = { MODEL_o876, MODEL_o877, -1 };
s32 N(FarLeftDoorModelsL)[]  = { MODEL_o880, MODEL_o881, -1 };
s32 N(FarLeftDoorModelsR)[]  = { MODEL_o878, MODEL_o879, -1 };
s32 N(BothLeftDoorModelsL)[] = { MODEL_o874, MODEL_o875, MODEL_o880, MODEL_o881, -1 };
s32 N(BothLeftDoorModelsR)[] = { MODEL_o876, MODEL_o877, MODEL_o878, MODEL_o879, -1 };

EvtScript N(EVS_ExitDoors_pra_02_2) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Set(LVar0, pra_16_ENTRY_0)
    Set(LVar1, COLLIDER_deilittsw)
    IfEq(GF_PRA_BrokeIllusion, FALSE)
        Set(LVar2, Ref(N(BothRightDoorModelsL)))
        Set(LVar3, Ref(N(BothRightDoorModelsR)))
    Else
        Set(LVar2, Ref(N(NearRightDoorModelsL)))
        Set(LVar3, Ref(N(NearRightDoorModelsR)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_02"), pra_02_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_18_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, pra_16_ENTRY_1)
    Set(LVar1, COLLIDER_deilittse)
    IfEq(GF_PRA_BrokeIllusion, FALSE)
        Set(LVar2, Ref(N(BothLeftDoorModelsL)))
        Set(LVar3, Ref(N(BothLeftDoorModelsR)))
    Else
        Set(LVar2, Ref(N(NearLeftDoorModelsL)))
        Set(LVar3, Ref(N(NearLeftDoorModelsR)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_18"), pra_18_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_18_2) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, pra_16_ENTRY_2)
    Set(LVar1, COLLIDER_deilittne)
    IfEq(GF_PRA_BrokeIllusion, FALSE)
        Set(LVar2, Ref(N(BothLeftDoorModelsL)))
        Set(LVar3, Ref(N(BothLeftDoorModelsR)))
    Else
        Set(LVar2, Ref(N(FarLeftDoorModelsL)))
        Set(LVar3, Ref(N(FarLeftDoorModelsR)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_18"), pra_18_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_02_3) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Set(LVar0, pra_16_ENTRY_3)
    Set(LVar1, COLLIDER_deilittnw)
    IfEq(GF_PRA_BrokeIllusion, FALSE)
        Set(LVar2, Ref(N(BothRightDoorModelsL)))
        Set(LVar3, Ref(N(BothRightDoorModelsR)))
    Else
        Set(LVar2, Ref(N(FarRightDoorModelsL)))
        Set(LVar3, Ref(N(FarRightDoorModelsR)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_02"), pra_02_ENTRY_3)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_pra_02_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_18_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_18_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_02_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(pra_16_ENTRY_0)
            Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            IfEq(GF_PRA_BrokeIllusion, FALSE)
                Set(LVar2, Ref(N(BothRightDoorModelsL)))
                Set(LVar3, Ref(N(BothRightDoorModelsR)))
            Else
                Set(LVar2, Ref(N(NearRightDoorModelsL)))
                Set(LVar3, Ref(N(NearRightDoorModelsR)))
            EndIf
        CaseEq(pra_16_ENTRY_1)
            Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
            IfEq(GF_PRA_BrokeIllusion, FALSE)
                Set(LVar2, Ref(N(BothLeftDoorModelsL)))
                Set(LVar3, Ref(N(BothLeftDoorModelsR)))
            Else
                Set(LVar2, Ref(N(NearLeftDoorModelsL)))
                Set(LVar3, Ref(N(NearLeftDoorModelsR)))
            EndIf
        CaseEq(pra_16_ENTRY_2)
            Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
            IfEq(GF_PRA_BrokeIllusion, FALSE)
                Set(LVar2, Ref(N(BothLeftDoorModelsL)))
                Set(LVar3, Ref(N(BothLeftDoorModelsR)))
            Else
                Set(LVar2, Ref(N(FarLeftDoorModelsL)))
                Set(LVar3, Ref(N(FarLeftDoorModelsR)))
            EndIf
        CaseEq(pra_16_ENTRY_3)
            Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            IfEq(GF_PRA_BrokeIllusion, FALSE)
                Set(LVar2, Ref(N(BothRightDoorModelsL)))
                Set(LVar3, Ref(N(BothRightDoorModelsR)))
            Else
                Set(LVar2, Ref(N(FarRightDoorModelsL)))
                Set(LVar3, Ref(N(FarRightDoorModelsR)))
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
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Call(SetCamEnabled, CAM_DEFAULT, TRUE)
    Exec(N(EVS_SetupMusic))
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
