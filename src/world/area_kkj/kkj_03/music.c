#include "kkj_03.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kkj_03_ENTRY_0)
            Call(SetMusic, 0, SONG_PEACHS_CASTLE_PARTY, BGM_VARIATION_1, VOL_LEVEL_5)
            Wait(3)
            Call(SetMusic, 0, SONG_PEACHS_CASTLE_PARTY, BGM_VARIATION_1, VOL_LEVEL_4)
        CaseDefault
            Call(SetMusic, 0, SONG_BOWSER_ATTACKS, 0, VOL_LEVEL_FULL)
        EndCaseGroup
    EndSwitch
    Return
    End
};
