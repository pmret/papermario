#include "common.h"

EvtScript N(EVS_GetIntoShell) = {
    EVT_CALL(GetNpcYaw, LVar4, LVar1)
    EVT_SET(LVar2, 30)
    EVT_IF_GT(LVar1, 151)
        EVT_IF_LE(LVar1, 331)
            EVT_SET(LVar2, -30)
        EVT_END_IF
    EVT_END_IF
    EVT_SET(LVar0, 0)
    EVT_LOOP(15)
        EVT_ADD(LVar0, LVar2)
        EVT_CALL(SetNpcRotation, LVar3, 0, 0, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
