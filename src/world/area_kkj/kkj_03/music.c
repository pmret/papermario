#include "kkj_03.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kkj_03_ENTRY_0)
            Call(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 5)
            Wait(3)
            Call(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 4)
        CaseDefault
            Call(SetMusicTrack, 0, SONG_BOWSER_ATTACKS, 0, 8)
        EndCaseGroup
    EndSwitch
    Return
    End
};
