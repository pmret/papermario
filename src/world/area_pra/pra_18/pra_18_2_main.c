#include "pra_18.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"

#include "../common/GlassShimmer.inc.c"

s32 N(NearRightDoorModelsL)[] = { MODEL_o772, -1 };
s32 N(NearRightDoorModelsR)[] = { MODEL_o768, -1 };
s32 N(FarRightDoorModelsL)[]  = { MODEL_o859, -1 };
s32 N(FarRightDoorModelsR)[]  = { MODEL_o861, -1 };
s32 N(BothRightDoorModelsL)[] = { MODEL_o772, MODEL_o859, -1 };
s32 N(BothRightDoorModelsR)[] = { MODEL_o768, MODEL_o861, -1 };

s32 N(LeftDoorModelsL)[] = { MODEL_o995, MODEL_o996, -1 };
s32 N(LeftDoorModelsR)[] = { MODEL_o997, MODEL_o998, -1 };

EvtScript N(EVS_ExitDoors_pra_16_1) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, pra_18_ENTRY_0)
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
    Call(GotoMap, Ref("pra_16"), pra_16_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_33_1) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, pra_18_ENTRY_1)
    Set(LVar1, COLLIDER_deilittne)
    Set(LVar2, Ref(N(LeftDoorModelsL)))
    Set(LVar3, Ref(N(LeftDoorModelsR)))
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_33"), pra_33_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_16_2) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, pra_18_ENTRY_2)
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
    Call(GotoMap, Ref("pra_16"), pra_16_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_pra_16_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    IfGe(GB_StoryProgress, STORY_CH7_DEFEATED_CLUBBAS)
        BindTrigger(Ref(N(EVS_ExitDoors_pra_33_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    EndIf
    BindTrigger(Ref(N(EVS_ExitDoors_pra_16_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(pra_18_ENTRY_0)
            IfEq(GF_PRA_BrokeIllusion, FALSE)
                Set(LVar2, Ref(N(BothRightDoorModelsL)))
                Set(LVar3, Ref(N(BothRightDoorModelsR)))
            Else
                Set(LVar2, Ref(N(NearRightDoorModelsL)))
                Set(LVar3, Ref(N(NearRightDoorModelsR)))
            EndIf
        CaseEq(pra_18_ENTRY_1)
            Set(LVar2, Ref(N(LeftDoorModelsL)))
            Set(LVar3, Ref(N(LeftDoorModelsR)))
        CaseEq(pra_18_ENTRY_2)
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
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    Exec(N(EVS_SetupMusic))
    IfGe(GB_StoryProgress, STORY_CH7_DEFEATED_CLUBBAS)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1174, COLLIDER_FLAGS_UPPER_MASK)
        Call(SetGroupVisibility, MODEL_g298, MODEL_GROUP_HIDDEN)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1175, COLLIDER_FLAGS_UPPER_MASK)
        Call(SetGroupVisibility, MODEL_g296, MODEL_GROUP_HIDDEN)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1176, COLLIDER_FLAGS_UPPER_MASK)
        Call(SetGroupVisibility, MODEL_g297, MODEL_GROUP_HIDDEN)
    Else
        Switch(GB_PRA18_ClubbasDefeated)
            CaseEq(1)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1176, COLLIDER_FLAGS_UPPER_MASK)
                Call(SetGroupVisibility, MODEL_g297, MODEL_GROUP_HIDDEN)
            CaseEq(2)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1175, COLLIDER_FLAGS_UPPER_MASK)
                Call(SetGroupVisibility, MODEL_g296, MODEL_GROUP_HIDDEN)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1176, COLLIDER_FLAGS_UPPER_MASK)
                Call(SetGroupVisibility, MODEL_g297, MODEL_GROUP_HIDDEN)
        EndSwitch
    EndIf
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
