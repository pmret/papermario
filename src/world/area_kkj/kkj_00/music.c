#include "kkj_00.h"

EvtScript N(EVS_SetupMusic) = {
    IfEq(GB_StoryProgress, STORY_INTRO)
        Call(GetEntryID, LVar0)
        IfEq(LVar0, kkj_00_ENTRY_3)
            Call(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 7)
            Wait(3)
        EndIf
        Call(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 8)
    Else
        Thread
            Wait(90)
            Call(FadeOutMusic, 0, 3000)
        EndThread
    EndIf
    Return
    End
};
