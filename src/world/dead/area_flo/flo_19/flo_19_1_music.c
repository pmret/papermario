#include "flo_19.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseOrEq(flo_19_ENTRY_0)
        CaseOrEq(flo_19_ENTRY_1)
            Call(SetMusicTrack, 0, SONG_CLOUDY_CLIMB, 0, 8)
        EndCaseGroup
        CaseOrEq(flo_19_ENTRY_2)
        CaseOrEq(7)
        EndCaseGroup
        CaseEq(flo_19_ENTRY_3)
            IfNe(AF_FLO_RidingBeanstalk, FALSE)
            Else
                Call(FadeOutMusic, 1, 3000)
                Call(FadeInMusic, 0, SONG_CLOUDY_CLIMB, 0, 3000, 0, 127)
            EndIf
        EndCaseGroup
    EndSwitch
    Return
    End
};
