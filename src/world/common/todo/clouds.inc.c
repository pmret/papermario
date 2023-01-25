#include "common/UnkAngleFunc2.inc.c"

EvtScript N(clouds1) = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVar7, LVar2)
    EVT_MUL(LVar7, 10)
    EVT_LABEL(0)
        EVT_ADD(LVar7, 4)
        EVT_IF_GT(LVar7, 3599)
            EVT_SUB(LVar7, 3600)
        EVT_END_IF
        EVT_CALL(N(UnkAngleFunc2), LVar7, LVar0, LVar1, LVar2, LVar3)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        EVT_CALL(RotateModel, LVarA, LVar3, 0, 1, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(clouds2) = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar3)
    EVT_SET(LVarC, LVar4)
    EVT_SET(LVar7, LVar2)
    EVT_MUL(LVar7, 10)
    EVT_LABEL(0)
        EVT_ADD(LVar7, 4)
        EVT_IF_GT(LVar7, 3599)
            EVT_SUB(LVar7, 3600)
        EVT_END_IF
        EVT_CALL(N(UnkAngleFunc2), LVar7, LVar0, LVar1, LVar2, LVar3)
        EVT_ADDF(LVar1, LVarB)
        EVT_ADDF(LVar2, LVarC)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        EVT_CALL(RotateModel, LVarA, LVar3, 0, 1, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(clouds3) = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar3)
    EVT_SET(LVarC, LVar4)
    EVT_SET(LVarD, LVar5)
    EVT_SET(LVar7, LVar2)
    EVT_MUL(LVar7, 10)
    EVT_LABEL(0)
        EVT_ADD(LVar7, 4)
        EVT_IF_GT(LVar7, 3599)
            EVT_SUB(LVar7, 3600)
        EVT_END_IF
        EVT_CALL(N(UnkAngleFunc2), LVar7, LVar0, LVar1, LVar2, LVar3)
        EVT_ADDF(LVar0, LVarB)
        EVT_ADDF(LVar1, LVarC)
        EVT_ADDF(LVar2, LVarD)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        EVT_CALL(RotateModel, LVarA, LVar3, 0, 1, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};
