#include "battle/battle.h"
#include "mapfs/flo_bt04_shape.h"

#define NAMESPACE A(flo_04)

#include "common/CosInterpMinMax.inc.c"

EvtScript N(EVS_AnimateCloud) = {
    Set(LVarA, LVar0)
    Set(LVarF, 0)
    Loop(0)
        Call(N(CosInterpMinMax), LVarF, LVar0, Float(0.968), Float(1.031), 15, 0, 0)
        Call(N(CosInterpMinMax), LVarF, LVar1, Float(1.031), Float(0.968), 15, 0, 0)
        Call(ScaleModel, LVarA, LVar1, LVar0, 1)
        Add(LVarF, 1)
        IfGe(LVarF, 30)
            Set(LVarF, 0)
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

#include "common/MakeSun.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Set(LVar0, MODEL_o412)
    Exec(N(EVS_AnimateCloud))
    Set(LVar0, MODEL_o413)
    Exec(N(EVS_AnimateCloud))
    Set(LVar0, MODEL_o414)
    Exec(N(EVS_AnimateCloud))
    Set(LVar0, MODEL_o415)
    Exec(N(EVS_AnimateCloud))
    Set(LVar0, MODEL_o419)
    Exec(N(EVS_AnimateCloud))
    Thread
        Set(LVar0, MODEL_o431)
        Exec(N(EVS_AnimateCloud))
        Set(LVar0, MODEL_o432)
        Exec(N(EVS_AnimateCloud))
        Wait(5)
        Set(LVar0, MODEL_b2_2)
        Exec(N(EVS_AnimateCloud))
        Set(LVar0, MODEL_b2_1)
        Exec(N(EVS_AnimateCloud))
        Wait(5)
        Set(LVar0, MODEL_b1_2)
        Exec(N(EVS_AnimateCloud))
        Set(LVar0, MODEL_b1_1)
        Exec(N(EVS_AnimateCloud))
        Set(LVar0, MODEL_b1_3)
        Exec(N(EVS_AnimateCloud))
        Wait(5)
        Set(LVar0, MODEL_o433)
        Exec(N(EVS_AnimateCloud))
        Set(LVar0, MODEL_o434)
        Exec(N(EVS_AnimateCloud))
    EndThread
    Call(CloneModel, MODEL_o427, CLONED_MODEL(0))
    Call(EnableModel, CLONED_MODEL(0), false)
    Call(TranslateModel, CLONED_MODEL(0), 0, 9, 0)
    Call(ParentColliderToModel, 0, CLONED_MODEL(0))
    ExecWait(N(MakeSun))
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

s32 N(ForegroundModels)[] = {
    -1,
    MODEL_o431,
    MODEL_o419,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "flo_tex",
    .shape = "flo_bt04_shape",
    .hit = "flo_bt04_hit",
    .bg = "sra_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
