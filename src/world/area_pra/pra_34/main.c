#include "pra_34.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"

#include "../common/GlassShimmer.inc.c"

s32 N(NearLeftDoorModelsL)[] = { MODEL_o1012, MODEL_o1013, -1 };
s32 N(NearLeftDoorModelsR)[] = { MODEL_o1014, MODEL_o1015, -1 };
s32 N(FarLeftDoorModelsL)[]  = { MODEL_o1010, MODEL_o1011, -1 };
s32 N(FarLeftDoorModelsR)[]  = { MODEL_o1008, MODEL_o1009, -1 };
s32 N(BothLeftDoorModelsL)[] = { MODEL_o1012, MODEL_o1013, MODEL_o1010, MODEL_o1011, -1 };
s32 N(BothLeftDoorModelsR)[] = { MODEL_o1014, MODEL_o1015, MODEL_o1008, MODEL_o1009, -1 };

s32 N(NearRightDoorModelsL)[] = { MODEL_o874, MODEL_o875, -1 };
s32 N(NearRightDoorModelsR)[] = { MODEL_o876, MODEL_o877, -1 };
s32 N(FarRightDoorModelsL)[]  = { MODEL_o880, MODEL_o881, -1 };
s32 N(FarRightDoorModelsR)[]  = { MODEL_o878, MODEL_o879, -1 };
s32 N(BothRightDoorModelsL)[] = { MODEL_o874, MODEL_o875, MODEL_o880, MODEL_o881, -1 };
s32 N(BothRightDoorModelsR)[] = { MODEL_o876, MODEL_o877, MODEL_o878, MODEL_o879, -1 };

EvtScript N(EVS_ExitDoors_pra_29_1) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, pra_34_ENTRY_0)
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
    Call(GotoMap, Ref("pra_29"), pra_29_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_31_0) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, pra_34_ENTRY_1)
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
    Call(GotoMap, Ref("pra_31"), pra_31_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_31_2) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, pra_34_ENTRY_2)
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
    Call(GotoMap, Ref("pra_31"), pra_31_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_29_2) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, pra_34_ENTRY_3)
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
    Call(GotoMap, Ref("pra_29"), pra_29_ENTRY_2)
    Wait(100)
    Return
    End
};

#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

s32 N(PalaceKeyList)[] = {
    ITEM_CRYSTAL_PALACE_KEY,
    ITEM_NONE
};

EvtScript N(EVS_UnlockPrompt_Doors) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    SuspendGroup(EVT_GROUP_FLAG_INTERACT)
    Call(ShowKeyChoicePopup)
    IfEq(LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        Call(CloseChoicePopup)
        ResumeGroup(EVT_GROUP_FLAG_INTERACT)
        Return
    EndIf
    IfEq(LVar0, -1)
        Call(CloseChoicePopup)
        ResumeGroup(EVT_GROUP_FLAG_INTERACT)
        Return
    EndIf
    Call(RemoveKeyItemAt, LVar1)
    Call(CloseChoicePopup)
    Set(GF_PRA34_UnlockedDoor, true)
    Call(N(GetEntityPosition), MV_FarPadlockEntityID, LVar0, LVar1, LVar2)
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    Call(N(GetEntityPosition), MV_NearPadlockEntityID, LVar0, LVar1, LVar2)
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    Set(LVar0, MV_FarPadlockEntityID)
    Call(N(RemovePadlock))
    Set(LVar0, MV_NearPadlockEntityID)
    Call(N(RemovePadlock))
    ResumeGroup(EVT_GROUP_FLAG_INTERACT)
    Unbind
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_pra_29_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_29_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    IfEq(GF_PRA34_UnlockedDoor, false)
        BindPadlock(Ref(N(EVS_UnlockPrompt_Doors)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), Ref(N(PalaceKeyList)), 0, 1)
        BindPadlock(Ref(N(EVS_UnlockPrompt_Doors)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(1), Ref(N(PalaceKeyList)), 0, 1)
    Else
        BindTrigger(Ref(N(EVS_ExitDoors_pra_31_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
        BindTrigger(Ref(N(EVS_ExitDoors_pra_31_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(pra_34_ENTRY_0)
            IfEq(GF_PRA_BrokeIllusion, false)
                Set(LVar2, Ref(N(BothLeftDoorModelsL)))
                Set(LVar3, Ref(N(BothLeftDoorModelsR)))
            Else
                Set(LVar2, Ref(N(NearLeftDoorModelsL)))
                Set(LVar3, Ref(N(NearLeftDoorModelsR)))
            EndIf
        CaseEq(pra_34_ENTRY_1)
            IfEq(GF_PRA_BrokeIllusion, false)
                Set(LVar2, Ref(N(BothRightDoorModelsL)))
                Set(LVar3, Ref(N(BothRightDoorModelsR)))
            Else
                Set(LVar2, Ref(N(NearRightDoorModelsL)))
                Set(LVar3, Ref(N(NearRightDoorModelsR)))
            EndIf
        CaseEq(pra_34_ENTRY_2)
            IfEq(GF_PRA_BrokeIllusion, false)
                Set(LVar2, Ref(N(BothRightDoorModelsL)))
                Set(LVar3, Ref(N(BothRightDoorModelsR)))
            Else
                Set(LVar2, Ref(N(FarRightDoorModelsL)))
                Set(LVar3, Ref(N(FarRightDoorModelsR)))
            EndIf
        CaseEq(pra_34_ENTRY_3)
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
