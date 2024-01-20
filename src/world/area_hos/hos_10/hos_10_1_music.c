#include "hos_10.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseOrEq(hos_10_ENTRY_1)
            Call(SetMusicTrack, 0, SONG_INTRO_STORY, 3, 8)
        EndCaseGroup
        CaseOrEq(hos_10_ENTRY_2)
        EndCaseGroup
        CaseOrEq(hos_10_ENTRY_3)
        CaseOrEq(hos_10_ENTRY_4)
        EndCaseGroup
        CaseEq(hos_10_ENTRY_5)
            Thread
                Wait(10)
                Call(SetMusicTrack, 0, SONG_MARIO_FALLS, 0, 8)
            EndThread
    EndSwitch
    Return
    End
};
