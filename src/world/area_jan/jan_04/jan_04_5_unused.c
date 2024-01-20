#include "jan_04.h"

EvtScript N(D_80243750_B47EC0) = {
    IfEq(MV_Unk_00, 0)
        Set(MV_Unk_01, 6)
    EndIf
    Add(MV_Unk_01, 2)
    Return
    End
};

EvtScript N(EVS_80243798) = {
    Label(0)
        Sub(MV_Unk_01, 1)
        Add(MV_Unk_00, MV_Unk_01)
        IfLt(MV_Unk_00, 0)
            Set(MV_Unk_01, 0)
            Set(MV_Unk_00, 0)
        EndIf
        IfGt(MV_Unk_00, 90)
            Set(MV_Unk_01, 0)
            Set(MV_Unk_00, 90)
        EndIf
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_SetupUnused) = {
    Return
    End
};
