#include "battle/battle.h"
#include "mapfs/nok_bt01_shape.h"

#define NAMESPACE A(nok_01)

EvtScript N(EVS_AnimateFlower) = {
    Set(LVarA, LVar0)
    Label(0)
        Call(TranslateModel, LVarA, 0, 2, 0)
        Wait(5)
        Call(TranslateModel, LVarA, 0, 0, 0)
        Wait(5)
        Call(TranslateModel, LVarA, 0, 2, 0)
        Wait(5)
        Call(TranslateModel, LVarA, 0, 0, 0)
        Wait(5)
        Call(RandInt, 30, LVar0)
        Add(LVar0, 30)
        Wait(LVar0)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Set(LVar0, MODEL_h1)
    Exec(N(EVS_AnimateFlower))
    Set(LVar0, MODEL_h2)
    Exec(N(EVS_AnimateFlower))
    Set(LVar0, MODEL_h3)
    Exec(N(EVS_AnimateFlower))
    Set(LVar0, MODEL_h5)
    Exec(N(EVS_AnimateFlower))
    Set(LVar0, MODEL_h7)
    Exec(N(EVS_AnimateFlower))
    Set(LVar0, MODEL_h8)
    Exec(N(EVS_AnimateFlower))
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

s32 N(ForegroundModels)[] = {
    MODEL_ha3,
    MODEL_hap,
    MODEL_kusa3,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "nok_tex",
    .shape = "nok_bt01_shape",
    .hit = "nok_bt01_hit",
    .bg = "nok_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
