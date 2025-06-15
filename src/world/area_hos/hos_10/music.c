#include "hos_10.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseOrEq(hos_10_ENTRY_1)
            Call(SetMusic, 0, SONG_INTRO_STORY, BGM_VARIATION_3, VOL_LEVEL_FULL)
        EndCaseGroup
        CaseOrEq(hos_10_ENTRY_2)
        EndCaseGroup
        CaseOrEq(hos_10_ENTRY_3)
        CaseOrEq(hos_10_ENTRY_4)
        EndCaseGroup
        CaseEq(hos_10_ENTRY_5)
            Thread
                Wait(10)
                Call(SetMusic, 0, SONG_MARIO_FALLS, 0, VOL_LEVEL_FULL)
            EndThread
    EndSwitch
    Return
    End
};
