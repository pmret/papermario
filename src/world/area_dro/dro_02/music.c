#include "dro_02.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseOrEq(dro_02_ENTRY_2)
        CaseOrEq(dro_02_ENTRY_3)
        EndCaseGroup
        CaseDefault
            Call(SetMusicTrack, 0, SONG_DRY_DRY_OUTPOST, 0, 8)
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_PlayRestMusic) = {
    Call(SetMusicTrack, 0, SONG_TAKING_REST, 0, 8)
    Return
    End
};

EvtScript N(EVS_PlayMoustafaMusic) = {
    Call(SetMusicTrack, 0, SONG_MOUSTAFA_THEME, 0, 8)
    Return
    End
};
