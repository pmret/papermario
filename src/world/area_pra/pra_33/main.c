#include "pra_33.h"
#include "effects.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"
#include "../common/GlassShimmer.inc.c"

s32 N(RightDoorModelsL)[] = { MODEL_o874, -1 };
s32 N(RightDoorModelsR)[] = { MODEL_o876, -1 };

s32 N(LeftDoorModelsL)[] = { MODEL_o859, -1 };
s32 N(LeftDoorModelsR)[] = { MODEL_o861, -1 };

EvtScript N(EVS_ExitDoors_pra_35_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, pra_33_ENTRY_0)
    Set(LVar1, COLLIDER_deilittse)
    Set(LVar2, Ref(N(RightDoorModelsL)))
    Set(LVar3, Ref(N(RightDoorModelsR)))
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_35"), pra_35_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_18_1) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, pra_33_ENTRY_1)
    Set(LVar1, COLLIDER_deilittnw)
    Set(LVar2, Ref(N(LeftDoorModelsL)))
    Set(LVar3, Ref(N(LeftDoorModelsR)))
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_18"), pra_18_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_pra_35_2) = EVT_EXIT_WALK(60, pra_33_ENTRY_2, "pra_35", pra_35_ENTRY_2);

EvtScript N(EVS_Unused) = {
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_pra_35_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_18_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_pra_35_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(pra_33_ENTRY_0)
            Set(LVar2, Ref(N(RightDoorModelsL)))
            Set(LVar3, Ref(N(RightDoorModelsR)))
            ExecWait(BaseEnterDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(pra_33_ENTRY_1)
            Set(LVar2, Ref(N(LeftDoorModelsL)))
            Set(LVar3, Ref(N(LeftDoorModelsR)))
            ExecWait(BaseEnterDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(pra_33_ENTRY_2)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};

BombTrigger N(BombPos_Wall) = {
    .pos = { 487.0f, 0.0f, -80.0f },
    .radius = 0.0f
};

EvtScript N(EVS_BlastWall) = {
    Set(GF_PRA33_BombedWall, TRUE)
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 0, 2, 34, 1, 10, 30)
    Call(EnableGroup, MODEL_g267, FALSE)
    Call(EnableGroup, MODEL_g270, TRUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
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
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    IfEq(GF_PRA33_BombedWall, FALSE)
        BindTrigger(Ref(N(EVS_BlastWall)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Wall)), 1, 0)
        Call(EnableGroup, MODEL_g270, FALSE)
    Else
        Call(EnableGroup, MODEL_g267, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Set(LVar0, MODEL_o945)
    Set(LVar1, MODEL_o987)
    Set(LVar2, TEX_PANNER_0)
    Exec(N(EVS_GlassShimmer))
    Set(LVar0, REFLECTION_WALL_ONLY)
    Set(LVar1, GF_PRA_BrokeIllusion)
    Exec(N(EVS_SetupReflections))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
