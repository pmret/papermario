#include "pra_35.h"

#include "../common/GlassShimmer.inc.c"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"

s32 N(LeftDoorModelsL)[] = { MODEL_o772, MODEL_o844, -1 };
s32 N(LeftDoorModelsR)[] = { MODEL_o768, MODEL_o846, -1 };

s32 N(RightDoorModelsL)[] = { MODEL_o861, MODEL_o862, -1 };
s32 N(RightDoorModelsR)[] = { MODEL_o859, MODEL_o860, -1 };

EvtScript N(EVS_ExitWalk_pra_33_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, pra_35_ENTRY_0)
    Set(LVar1, COLLIDER_deilittsw)
    Set(LVar2, Ref(N(LeftDoorModelsL)))
    Set(LVar3, Ref(N(LeftDoorModelsR)))
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_33"), pra_33_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_pra_19_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, pra_35_ENTRY_1)
    Set(LVar1, COLLIDER_deilittsw)
    Set(LVar2, Ref(N(RightDoorModelsL)))
    Set(LVar3, Ref(N(RightDoorModelsR)))
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_19"), pra_19_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_pra_33_2) = EVT_EXIT_WALK(60, pra_35_ENTRY_2, "pra_33", pra_33_ENTRY_2);

EvtScript N(EVS_Unused) = {
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_pra_33_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_pra_19_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_pra_33_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilinw, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(pra_35_ENTRY_0)
            Set(LVar2, Ref(N(LeftDoorModelsL)))
            Set(LVar3, Ref(N(LeftDoorModelsR)))
            ExecWait(BaseEnterDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(pra_35_ENTRY_1)
            Set(LVar2, Ref(N(RightDoorModelsL)))
            Set(LVar3, Ref(N(RightDoorModelsR)))
            ExecWait(BaseEnterDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(pra_35_ENTRY_2)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};

BombTrigger N(D_802432A8_D904F8) = {
    .pos = { 13.0f, 0.0f, -80.0f },
    .radius = 0.0f
};

EvtScript N(D_802432B8_D90508) = {
    Call(EnableGroup, MODEL_g297, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittnw, COLLIDER_FLAGS_UPPER_MASK)
    Unbind
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
    Set(LVar0, 64)
    Set(LVar1, 65)
    Set(LVar2, 0)
    Exec(N(EVS_GlassShimmer))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_EnterMap))
    Wait(1)
    IfEq(GF_PRA33_BombedWall, FALSE)
        BindTrigger(Ref(N(D_802432B8_D90508)), TRIGGER_POINT_BOMB, Ref(N(D_802432A8_D904F8)), 1, 0)
    Else
        Call(EnableGroup, MODEL_g297, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittnw, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Set(LVar0, 0)
    Set(LVar1, GF_PRA_BrokeIllusion)
    Exec(N(EVS_SetupReflections))
    Exec(N(EVS_SetupMusic))
    Return
    End
};
