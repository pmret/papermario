#include "battle/battle.h"
#include "mapfs/flo_bt03_shape.h"

#define NAMESPACE A(flo_03)

EvtScript N(EVS_AnimateVines) = {
    Set(LVarA, LVar0)
    UseBuf(LVarA)
    Loop(0)
        BufRead1(LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
        Call(SetTexPanner, LVar0, TEX_PANNER_E)
        BufRead1(LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
        Call(SetTexPanner, LVar0, TEX_PANNER_F)
    EndLoop
    Set(LVar0, 0)
    Set(LVar1, 0)
    Label(0)
    Label(0)
        Add(LVar0, -140)
        IfLt(LVar0, 0)
            Add(LVar0, 0x10000)
        EndIf
        Call(SetTexPanOffset, TEX_PANNER_E, TEX_PANNER_MAIN, LVar0, 0)
        Add(LVar1, -200)
        IfLt(LVar1, 0)
            Add(LVar1, 0x10000)
        EndIf
        Call(SetTexPanOffset, TEX_PANNER_F, TEX_PANNER_MAIN, LVar1, 0)
        Wait(1)
        Goto(0)
    Return
    End
};

#include "common/MakeSun.inc.c"
#include "common/CosInterpMinMax.inc.c"

EvtScript N(EVS_AnimateSmokePuff) = {
    Call(EnableModel, LVarF, TRUE)
    Set(LVarE, 159)
    Loop(LVarE)
        AddF(LVar3, 0)
        AddF(LVar4, Float(0.0))
        SetF(LVar5, Float(0.01))
        AddF(LVar0, LVar3)
        AddF(LVar1, LVar4)
        AddF(LVar2, LVar5)
        MulF(LVar6, Float(1.01))
        AddF(LVar7, Float(0.01))
        SetF(LVar8, LVar6)
        Call(N(CosInterpMinMax), LVarE, LVarA, Float(0.0), Float(0.203), 15, 0, 0)
        AddF(LVar8, LVarA)
        SetF(LVar9, LVar7)
        Call(N(CosInterpMinMax), LVarE, LVarA, Float(0.0), Float(0.203), 20, 0, 90)
        AddF(LVar9, LVarA)
        SetF(LVarA, LVar0)
        MulF(LVarA, Float(10.0))
        Call(TranslateModel, LVarF, LVar0, LVar1, LVar2)
        Call(ScaleModel, LVarF, LVar8, LVar9, 1)
        Call(RotateModel, LVarF, LVarA, 0, 0, 1)
        Wait(1)
    EndLoop
    Call(EnableModel, LVarF, FALSE)
    Return
    End
};

s32 N(VineModels)[] = {
    MODEL_o419,
    MODEL_o420,
    MODEL_o422,
    STAGE_MODEL_LIST_END
};

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Set(LVar0, N(VineModels))
    Exec(N(EVS_AnimateVines))
    Call(SetTexPanner, MODEL_piko4, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_piko5, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_piko1, TEX_PANNER_3)
    Call(SetTexPanner, MODEL_piko2, TEX_PANNER_4)
    Call(SetTexPanner, MODEL_piko3, TEX_PANNER_5)
    Call(SetTexPanner, MODEL_piko6, TEX_PANNER_6)
    Call(SetTexPanner, MODEL_piko7, TEX_PANNER_7)
    Thread
        Set(LVarE, 1)
        Set(LVarF, 0)
        Loop(0)
            AddF(LVarF, LVarE)
            IfGe(LVarF, 1080)
                Set(LVarF, 0)
            EndIf
            Set(LVar0, LVarF)
            Div(LVar0, 9)
            Mod(LVar0, 2)
            Mul(LVar0, 0x4000)
            Set(LVar1, LVarF)
            Div(LVar1, 4)
            Mod(LVar1, 2)
            Mul(LVar1, 0x4000)
            Set(LVar2, LVarF)
            Div(LVar2, 5)
            Mod(LVar2, 2)
            Mul(LVar2, 0x4000)
            Set(LVar3, LVarF)
            Div(LVar3, 6)
            Mod(LVar3, 2)
            Mul(LVar3, 0x4000)
            Set(LVar4, LVarF)
            Div(LVar4, 2)
            Mod(LVar4, 2)
            Mul(LVar4, 0x4000)
            Set(LVar5, LVarF)
            Div(LVar5, 8)
            Mod(LVar5, 2)
            Mul(LVar5, 0x4000)
            Set(LVar6, LVarF)
            Div(LVar6, 8)
            Mod(LVar6, 2)
            Mul(LVar6, 0x8000)
            Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
            Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, LVar1, 0)
            Call(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, LVar2, 0)
            Call(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_MAIN, LVar3, 0)
            Call(SetTexPanOffset, TEX_PANNER_5, TEX_PANNER_MAIN, LVar4, 0)
            Call(SetTexPanOffset, TEX_PANNER_6, TEX_PANNER_MAIN, LVar5, 0)
            Call(SetTexPanOffset, TEX_PANNER_7, TEX_PANNER_MAIN, LVar6, 0)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Set(LVar0, 0)
        // create 16 smoke models
        Loop(16)
            Set(LVar1, LVar0)
            Add(LVar1, CLONED_MODEL(0))
            Add(LVar0, 1)
            Call(CloneModel, MODEL_o454, LVar1)
            Call(EnableModel, LVar1, FALSE)
        EndLoop
        // hide the original
        Call(EnableModel, MODEL_o454, FALSE)
        // animate them
        Set(LVarE, 0)
        Loop(0)
            SetF(LVar0, Float(106.0))
            SetF(LVar1, Float(94.0))
            SetF(LVar2, Float(-91.0))
            Call(RandInt, 100, LVar3)
            AddF(LVar3, -50)
            DivF(LVar3, Float(200.0))
            SetF(LVar4, Float(1.0))
            SetF(LVar5, 0)
            SetF(LVar6, Float(0.296))
            SetF(LVar7, Float(0.296))
            Set(LVarF, LVarE)
            Add(LVarF, CLONED_MODEL(0))
            Exec(N(EVS_AnimateSmokePuff))
            Add(LVarE, 1)
            IfGe(LVarE, 16)
                Set(LVarE, 0)
            EndIf
            Wait(10)
        EndLoop
    EndThread
    ExecWait(N(MakeSun))
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

s32 N(ForegroundVineModels)[] = {
    -1,
    MODEL_o411,
    MODEL_o415,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "flo_tex",
    .shape = "flo_bt03_shape",
    .hit = "flo_bt03_hit",
    .bg = "fla_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundVineModels),
};
