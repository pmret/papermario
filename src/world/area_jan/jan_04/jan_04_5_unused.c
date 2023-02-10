#include "jan_04.h"

EvtScript N(D_80243750_B47EC0) = {
    EVT_IF_EQ(MV_Unk_00, 0)
        EVT_SET(MV_Unk_01, 6)
    EVT_END_IF
    EVT_ADD(MV_Unk_01, 2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80243798) = {
    EVT_LABEL(0)
        EVT_SUB(MV_Unk_01, 1)
        EVT_ADD(MV_Unk_00, MV_Unk_01)
        EVT_IF_LT(MV_Unk_00, 0)
            EVT_SET(MV_Unk_01, 0)
            EVT_SET(MV_Unk_00, 0)
        EVT_END_IF
        EVT_IF_GT(MV_Unk_00, 90)
            EVT_SET(MV_Unk_01, 0)
            EVT_SET(MV_Unk_00, 90)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupUnused) = {
    EVT_RETURN
    EVT_END
};
