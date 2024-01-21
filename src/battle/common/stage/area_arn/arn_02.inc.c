#include "battle/battle.h"
#include "mapfs/arn_bt02_shape.h"

#define NAMESPACE A(arn_02)

EvtScript N(EVS_RotateWindmill) = {
    Set(LVarA, LVar0)
    Set(LVar0, 0)
    Label(0)
        Add(LVar0, 1)
        IfGt(LVar0, 359)
            Sub(LVar0, 360)
        EndIf
        Call(RotateModel, LVarA, LVar0, 0, 0, 1)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Set(LVar0, MODEL_o332)
    ExecWait(N(EVS_RotateWindmill))
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

s32 N(ForegroundModels)[] = {
    -1,
    MODEL_iwa4,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "arn_tex",
    .shape = "arn_bt02_shape",
    .hit = "arn_bt02_hit",
    .bg = "arn_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
