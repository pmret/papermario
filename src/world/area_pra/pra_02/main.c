#include "pra_02.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"
#include "../common/GlassShimmer.inc.c"

EvtScript N(EVS_UpdateShiftingWallPos) = {
    Call(TranslateGroup, MODEL_g293, 0, 250, 0)
    Call(TranslateGroup, MODEL_g291, 0, MV_WallPosOffset, 0)
    Return
    End
};

s32 N(NearLeftDoorModelsL)[] = { MODEL_o772, MODEL_o844, -1 };
s32 N(NearLeftDoorModelsR)[] = { MODEL_o768, MODEL_o846, -1 };
s32 N(FarLeftDoorModelsL)[] = { MODEL_o859, -1 };
s32 N(FarLeftDoorModelsR)[] = { MODEL_o861, -1 };
s32 N(BothLeftDoorModelsL)[] = { MODEL_o772, MODEL_o844, MODEL_o859, -1 };
s32 N(BothLeftDoorModelsR)[] = { MODEL_o768, MODEL_o846, MODEL_o861, -1 };

s32 N(FarBlueDoorModelsL)[] = { MODEL_o1162, -1 };
s32 N(FarBlueDoorModelsR)[] = { MODEL_o1160, -1 };
s32 N(FarRedDoorModelsL)[] = { MODEL_o952, -1 };
s32 N(FarRedDoorModelsR)[] = { MODEL_o950, -1 };

s32 N(NearBlueDoorModelsL)[] = { MODEL_o1156, -1 };
s32 N(NearBlueDoorModelsR)[] = { MODEL_o1158, -1 };
s32 N(NearRedDoorModelsL)[] = { MODEL_o946, -1 };
s32 N(NearRedDoorModelsR)[] = { MODEL_o948, -1 };

s32 N(BothBlueDoorModelsL)[] = { MODEL_o1156, MODEL_o1162, -1 };
s32 N(BothBlueDoorModelsR)[] = { MODEL_o1158, MODEL_o1160, -1 };
s32 N(BothRedDoorModelsL)[] = { MODEL_o946, MODEL_o952, -1 };
s32 N(BothRedDoorModelsR)[] = { MODEL_o948, MODEL_o950, -1 };

s32 N(NearCenterDoorModels)[] = { MODEL_o847, -1 };
s32 N(FarCenterDoorModels)[] = { MODEL_o774, -1 };
s32 N(EmptyModelList)[] = { -1 };

EvtScript N(EVS_ExitDoors_pra_01_1) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, pra_02_ENTRY_0)
    Set(LVar1, 24)
    IfEq(GF_PRA_BrokeIllusion, false)
        Set(LVar2, Ref(N(BothLeftDoorModelsL)))
        Set(LVar3, Ref(N(BothLeftDoorModelsR)))
    Else
        Set(LVar2, Ref(N(NearLeftDoorModelsL)))
        Set(LVar3, Ref(N(NearLeftDoorModelsR)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_01"), pra_01_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_03_0) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, pra_02_ENTRY_1)
    Set(LVar1, 56)
    IfEq(GF_PRA_BrokeIllusion, false)
        Set(LVar2, Ref(N(NearCenterDoorModels)))
        Set(LVar3, Ref(N(FarCenterDoorModels)))
    Else
        Set(LVar2, Ref(N(NearCenterDoorModels)))
        Set(LVar3, Ref(N(EmptyModelList)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_03"), pra_03_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_16_0) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Set(LVar0, pra_02_ENTRY_2)
    Set(LVar1, 36)
    IfEq(GF_PRA_BrokeIllusion, false)
        Set(LVar2, Ref(N(BothRedDoorModelsL)))
        Set(LVar3, Ref(N(BothRedDoorModelsR)))
    Else
        Set(LVar2, Ref(N(NearRedDoorModelsL)))
        Set(LVar3, Ref(N(NearRedDoorModelsR)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_16"), pra_16_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_13_0) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Set(LVar0, pra_02_ENTRY_2)
    Set(LVar1, 36)
    IfEq(GF_PRA_BrokeIllusion, false)
        Set(LVar2, Ref(N(BothBlueDoorModelsL)))
        Set(LVar3, Ref(N(BothBlueDoorModelsR)))
    Else
        Set(LVar2, Ref(N(NearBlueDoorModelsL)))
        Set(LVar3, Ref(N(NearBlueDoorModelsR)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_13"), pra_13_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_16_3) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Set(LVar0, pra_02_ENTRY_3)
    Set(LVar1, 32)
    IfEq(GF_PRA_BrokeIllusion, false)
        Set(LVar2, Ref(N(BothRedDoorModelsL)))
        Set(LVar3, Ref(N(BothRedDoorModelsR)))
    Else
        Set(LVar2, Ref(N(FarRedDoorModelsL)))
        Set(LVar3, Ref(N(FarRedDoorModelsR)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_16"), pra_16_ENTRY_3)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_13_3) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Set(LVar0, pra_02_ENTRY_3)
    Set(LVar1, 32)
    IfEq(GF_PRA_BrokeIllusion, false)
        Set(LVar2, Ref(N(BothBlueDoorModelsL)))
        Set(LVar3, Ref(N(BothBlueDoorModelsR)))
    Else
        Set(LVar2, Ref(N(FarBlueDoorModelsL)))
        Set(LVar3, Ref(N(FarBlueDoorModelsR)))
    EndIf
EndIf
Exec(BaseExitDoor)
Wait(17)
Call(GotoMap, Ref("pra_13"), pra_13_ENTRY_3)
Wait(100)
Return
End
};

EvtScript N(EVS_ExitDoors_pra_04_0) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, pra_02_ENTRY_4)
    Set(LVar1, 51)
    IfEq(GF_PRA_BrokeIllusion, false)
        Set(LVar2, Ref(N(NearCenterDoorModels)))
        Set(LVar3, Ref(N(FarCenterDoorModels)))
    Else
        Set(LVar2, Ref(N(EmptyModelList)))
        Set(LVar3, Ref(N(FarCenterDoorModels)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_04"), pra_04_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_01_2) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, pra_02_ENTRY_5)
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
    Call(GotoMap, Ref("pra_01"), pra_01_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_pra_01_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_03_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittssw, 1, 0)
    IfEq(GF_PRA02_DoorColorToggle, false)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittse2, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne2, COLLIDER_FLAGS_UPPER_MASK)
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittse, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    IfEq(GF_PRA02_UnlockedRedDoor, true)
        BindTrigger(Ref(N(EVS_ExitDoors_pra_16_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
        BindTrigger(Ref(N(EVS_ExitDoors_pra_16_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    EndIf
    IfEq(GF_PRA02_UnlockedBlueDoor, true)
        BindTrigger(Ref(N(EVS_ExitDoors_pra_13_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse2, 1, 0)
        BindTrigger(Ref(N(EVS_ExitDoors_pra_13_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne2, 1, 0)
    EndIf
    BindTrigger(Ref(N(EVS_ExitDoors_pra_04_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnnw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_01_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(pra_02_ENTRY_0)
            Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
            IfEq(GF_PRA02_Visited, false)
                Set(GF_PRA02_Visited, true)
                Set(GB_StoryProgress, STORY_CH7_ARRIVED_AT_CRYSTAL_PALACE)
            EndIf
            IfEq(GF_PRA_BrokeIllusion, false)
                Set(LVar2, Ref(N(BothLeftDoorModelsL)))
                Set(LVar3, Ref(N(BothLeftDoorModelsR)))
            Else
                Set(LVar2, Ref(N(NearLeftDoorModelsL)))
                Set(LVar3, Ref(N(NearLeftDoorModelsR)))
            EndIf
        CaseEq(pra_02_ENTRY_1)
            Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
            IfEq(GF_PRA_BrokeIllusion, false)
                Set(LVar2, Ref(N(NearCenterDoorModels)))
                Set(LVar3, Ref(N(FarCenterDoorModels)))
            Else
                Set(LVar2, Ref(N(NearCenterDoorModels)))
                Set(LVar3, Ref(N(EmptyModelList)))
            EndIf
        CaseEq(pra_02_ENTRY_2)
            Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            IfEq(GF_PRA02_DoorColorToggle, false)
                IfEq(GF_PRA_BrokeIllusion, false)
                    Set(LVar2, Ref(N(BothRedDoorModelsL)))
                    Set(LVar3, Ref(N(BothRedDoorModelsR)))
                Else
                    Set(LVar2, Ref(N(NearRedDoorModelsL)))
                    Set(LVar3, Ref(N(NearRedDoorModelsR)))
                EndIf
            Else
                IfEq(GF_PRA_BrokeIllusion, false)
                    Set(LVar2, Ref(N(BothBlueDoorModelsL)))
                    Set(LVar3, Ref(N(BothBlueDoorModelsR)))
                Else
                    Set(LVar2, Ref(N(NearBlueDoorModelsL)))
                    Set(LVar3, Ref(N(NearBlueDoorModelsR)))
                EndIf
            EndIf
        CaseEq(pra_02_ENTRY_3)
            Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            IfEq(GF_PRA02_DoorColorToggle, false)
                IfEq(GF_PRA_BrokeIllusion, false)
                    Set(LVar2, Ref(N(BothRedDoorModelsL)))
                    Set(LVar3, Ref(N(BothRedDoorModelsR)))
                Else
                    Set(LVar2, Ref(N(FarRedDoorModelsL)))
                    Set(LVar3, Ref(N(FarRedDoorModelsR)))
                EndIf
            Else
                IfEq(GF_PRA_BrokeIllusion, false)
                    Set(LVar2, Ref(N(BothBlueDoorModelsL)))
                    Set(LVar3, Ref(N(BothBlueDoorModelsR)))
                Else
                    Set(LVar2, Ref(N(FarBlueDoorModelsL)))
                    Set(LVar3, Ref(N(FarBlueDoorModelsR)))
                EndIf
            EndIf
        CaseEq(pra_02_ENTRY_4)
            Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
            IfEq(GF_PRA_BrokeIllusion, false)
                Set(LVar2, Ref(N(NearCenterDoorModels)))
                Set(LVar3, Ref(N(FarCenterDoorModels)))
            Else
                Set(LVar2, Ref(N(EmptyModelList)))
                Set(LVar3, Ref(N(FarCenterDoorModels)))
            EndIf
        CaseEq(pra_02_ENTRY_5)
            Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
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
    Call(SetCamLeadPlayer, CAM_DEFAULT, false)
    Call(SetCamEnabled, CAM_DEFAULT, true)
    ExecWait(N(EVS_MakeEntities))
    IfEq(GF_PRA02_DoorColorToggle, false)
        Set(MV_WallPosOffset, 0)
        Call(SetGroupVisibility, MODEL_g308, MODEL_GROUP_HIDDEN)
    Else
        Set(MV_WallPosOffset, -250)
        Call(SetGroupVisibility, MODEL_g307, MODEL_GROUP_HIDDEN)
    EndIf
    Exec(N(EVS_UpdateShiftingWallPos))
    BindTrigger(Ref(N(EVS_ManagePoundableSwitch)), TRIGGER_FLOOR_TOUCH, COLLIDER_o1342, 1, 0)
    BindTrigger(Ref(N(EVS_ManagePoundableSwitch)), TRIGGER_FLOOR_TOUCH, COLLIDER_o1344, 1, 0)
    Set(LVar0, MODEL_o549)
    Set(LVar1, MODEL_o549)
    Set(LVar2, TEX_PANNER_0)
    Exec(N(EVS_GlassShimmer))
    Set(LVar0, REFLECTION_WALL_ONLY)
    Set(LVar1, GF_PRA_BrokeIllusion)
    Exec(N(EVS_SetupReflections))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Return
    End
};
