#include "kkj_19.h"

EvtScript N(EVS_SetupMusic) = {
    IfEq(GB_StoryProgress, STORY_INTRO)
        Call(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 7)
        Wait(3)
        Call(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 6)
        Return
    EndIf
    IfEq(GB_StoryProgress, STORY_CH4_BEGAN_PEACH_MISSION)
        Call(SetMusicTrack, 0, SONG_PEACH_MISSION, 0, 8)
        Return
    EndIf
    Return
    End
};
