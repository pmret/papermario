#include "kkj_00.h"

EvtScript N(EVS_SetupMusic) = {
    IfEq(GB_StoryProgress, STORY_INTRO)
        Call(GetEntryID, LVar0)
        IfEq(LVar0, kkj_00_ENTRY_3)
            Call(SetMusic, 0, SONG_PEACHS_CASTLE_PARTY, BGM_VARIATION_1, VOL_LEVEL_7)
            Wait(3)
        EndIf
        Call(SetMusic, 0, SONG_PEACHS_CASTLE_PARTY, BGM_VARIATION_1, VOL_LEVEL_FULL)
    Else
        Thread
            Wait(90)
            Call(FadeOutMusic, 0, 3000)
        EndThread
    EndIf
    Return
    End
};
