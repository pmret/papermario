#include "pra_09.h"
#include "effects.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"

EvtScript N(EVS_ExitDoors_pra_03_2) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, pra_09_ENTRY_0)
    Set(LVar1, COLLIDER_deilittsw)
    Set(LVar2, MODEL_o772)
    Set(LVar3, MODEL_o768)
    Set(LVar4, MODEL_o844)
    Set(LVar5, MODEL_o846)
    Exec(ExitSplitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_03"), pra_03_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_pra_11_0) = EVT_EXIT_WALK(60, pra_09_ENTRY_1, "pra_11", pra_11_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_pra_03_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    IfGe(GB_StoryProgress, STORY_CH7_DEFEATED_BOMBETTE_DUPLIGHOSTS)
        BindTrigger(Ref(N(EVS_ExitWalk_pra_11_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(pra_09_ENTRY_0)
            Set(LVar2, MODEL_o772)
            Set(LVar3, MODEL_o768)
            Set(LVar4, MODEL_o844)
            Set(LVar5, MODEL_o846)
            ExecWait(EnterSplitDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(pra_09_ENTRY_1)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};

BombTrigger N(BombPos_Wall) = {
    .pos = { 487.0f, 0.0f, 80.0f },
    .radius = 0.0f
};

EvtScript N(EVS_BlastWall) = {
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 0, 38, 30, 1, 10, 30)
    Call(EnableModel, MODEL_g260, FALSE)
    Call(EnableModel, MODEL_g265, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittse, COLLIDER_FLAGS_UPPER_MASK)
    Call(EnableModel, MODEL_o952, TRUE)
    Set(GF_PRA09_BombedWall, TRUE)
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
    IfEq(GF_PRA09_BombedWall, FALSE)
        BindTrigger(Ref(N(EVS_BlastWall)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Wall)), 1, 0)
        Call(EnableModel, MODEL_o952, FALSE)
    Else
        Call(EnableModel, MODEL_g260, FALSE)
        Call(EnableModel, MODEL_g265, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittse, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Exec(N(EVS_SetupMusic))
    Set(LVar0, 1)
    Set(LVar1, GF_PRA_BrokeIllusion)
    Exec(N(EVS_SetupReflections))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
