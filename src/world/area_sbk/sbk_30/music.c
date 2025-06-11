#include "sbk_30.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseOrEq(sbk_30_ENTRY_4)
        CaseOrEq(sbk_30_ENTRY_5)
        EndCaseGroup
        CaseDefault
            Call(SetMusic, 0, SONG_DRY_DRY_DESERT, 0, VOL_LEVEL_FULL)
        EndCaseGroup
    EndSwitch
    Return
    End
};
