#include "common/UnkAngleFunc2.inc.c"

EvtScript N(clouds1) = {
    EVT_SET(LVarA, LocalVar(0))
    EVT_SET(LocalVar(7), LocalVar(2))
    EVT_MUL(LocalVar(7), 10)
    EVT_LABEL(0)
    EVT_ADD(LocalVar(7), 4)
    EVT_IF_GT(LocalVar(7), 3599)
        EVT_SUB(LocalVar(7), 3600)
    EVT_END_IF
    EVT_CALL(N(UnkAngleFunc2), LocalVar(7), LocalVar(0), LocalVar(1), LocalVar(2), LocalVar(3))
    EVT_CALL(TranslateModel, LVarA, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(RotateModel, LVarA, LocalVar(3), 0, 1, 0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(clouds2) = {
    EVT_SET(LVarA, LocalVar(0))
    EVT_SET(LVarB, LocalVar(3))
    EVT_SET(LVarC, LocalVar(4))
    EVT_SET(LocalVar(7), LocalVar(2))
    EVT_MUL(LocalVar(7), 10)
    EVT_LABEL(0)
    EVT_ADD(LocalVar(7), 4)
    EVT_IF_GT(LocalVar(7), 3599)
        EVT_SUB(LocalVar(7), 3600)
    EVT_END_IF
    EVT_CALL(N(UnkAngleFunc2), LocalVar(7), LocalVar(0), LocalVar(1), LocalVar(2), LocalVar(3))
    EVT_ADDF(LocalVar(1), LVarB)
    EVT_ADDF(LocalVar(2), LVarC)
    EVT_CALL(TranslateModel, LVarA, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(RotateModel, LVarA, LocalVar(3), 0, 1, 0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(clouds3) = {
    EVT_SET(LVarA, LocalVar(0))
    EVT_SET(LVarB, LocalVar(3))
    EVT_SET(LVarC, LocalVar(4))
    EVT_SET(LVarD, LocalVar(5))
    EVT_SET(LocalVar(7), LocalVar(2))
    EVT_MUL(LocalVar(7), 10)
    EVT_LABEL(0)
    EVT_ADD(LocalVar(7), 4)
    EVT_IF_GT(LocalVar(7), 3599)
        EVT_SUB(LocalVar(7), 3600)
    EVT_END_IF
    EVT_CALL(N(UnkAngleFunc2), LocalVar(7), LocalVar(0), LocalVar(1), LocalVar(2), LocalVar(3))
    EVT_ADDF(LocalVar(0), LVarB)
    EVT_ADDF(LocalVar(1), LVarC)
    EVT_ADDF(LocalVar(2), LVarD)
    EVT_CALL(TranslateModel, LVarA, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(RotateModel, LVarA, LocalVar(3), 0, 1, 0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};
