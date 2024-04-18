#include "dro_01.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseOrEq(dro_01_ENTRY_3)
        CaseOrEq(dro_01_ENTRY_4)
        EndCaseGroup
        CaseDefault
            Call(SetMusicTrack, 0, SONG_DRY_DRY_OUTPOST, 0, 8)
        EndCaseGroup
    EndSwitch
    Return
    End
};
