#include "common.h"

// pan the main tile along U and V
// (in) LVar0 : modelID
// (in) LVar1 : tex panner ID
// (in) LVar2 : main du
// (in) LVar3 : main dv
EvtScript N(EVS_TexturePanMain) = {
    EVT_SET(LVarA, LVar1)
    EVT_SET(LVarB, LVar2)
    EVT_SET(LVarC, LVar3)
    EVT_CALL(SetTexPanner, LVar0, LVar1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LVarA, TEX_PANNER_MAIN, LVar0, LVar1)
        EVT_ADD(LVar0, LVarB)
        EVT_ADD(LVar1, LVarC)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

// pan the main and aux tiles along U
// (in) LVar0 : modelID
// (in) LVar1 : tex panner ID
// (in) LVar2 : main du
// (in) LVar3 : aux du
EvtScript N(EVS_TexturePanBothU) = {
    EVT_SET(LVarA, LVar1)
    EVT_SET(LVarB, LVar2)
    EVT_SET(LVarC, LVar3)
    EVT_CALL(SetTexPanner, LVar0, LVar1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LVarA, TEX_PANNER_MAIN, LVar0, 0)
        EVT_CALL(SetTexPanOffset, LVarA, TEX_PANNER_AUX,  LVar1, 0)
        EVT_ADD(LVar0, LVarB)
        EVT_ADD(LVar1, LVarC)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

// pan the main and aux tiles along V
// (in) LVar0 : modelID
// (in) LVar1 : tex panner ID
// (in) LVar2 : main dv
// (in) LVar3 : aux dv
EvtScript N(EVS_TexturePanBothV) = {
    EVT_SET(LVarA, LVar1)
    EVT_SET(LVarB, LVar2)
    EVT_SET(LVarC, LVar3)
    EVT_CALL(SetTexPanner, LVar0, LVar1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LVarA, TEX_PANNER_MAIN, 0, LVar0)
        EVT_CALL(SetTexPanOffset, LVarA, TEX_PANNER_AUX,  0, LVar1)
        EVT_ADD(LVar0, LVarB)
        EVT_ADD(LVar1, LVarC)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
