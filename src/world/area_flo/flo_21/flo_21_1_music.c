#include "flo_21.h"

EvtScript N(EVS_SetupMusic) = {
    IfEq(GB_StoryProgress, STORY_CH6_DEFEATED_HUFF_N_PUFF)
        Call(FadeOutMusic, 0, 500)
    Else
        Call(SetMusicTrack, 0, SONG_CLOUDY_CLIMB, 0, 8)
    EndIf
    Return
    End
};
