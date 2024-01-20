#include "battle/battle.h"
#include "mapfs/omo_bt06_shape.h"

#define NAMESPACE A(omo_06)

EvtScript N(EVS_UpdateMovingPlatforms) = {
    Set(LVarA, LVar0) // modelID
    Set(LVar9, LVar1)
    Set(LVar8, LVar2)
    Label(0)
        Call(MakeLerp, 0, LVar9, LVar8, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, LVarA, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, LVar9, 0, LVar8, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, LVarA, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Goto(0)
    Return
    End
};

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Thread
        Set(LVar0, MODEL_ere1)
        Set(LVar1, -50)
        Set(LVar2, 120)
        Exec(N(EVS_UpdateMovingPlatforms))
        Wait(10)
        Set(LVar0, MODEL_ere2)
        Set(LVar1, -80)
        Set(LVar2, 150)
        Exec(N(EVS_UpdateMovingPlatforms))
    EndThread
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

s32 N(ForegroundModels)[] = {
    MODEL_kuruma,
    MODEL_hosi,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "omo_tex",
    .shape = "omo_bt06_shape",
    .hit = "omo_bt06_hit",
    .bg = "omo_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
