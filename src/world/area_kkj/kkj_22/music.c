#include "kkj_22.h"

EvtScript N(EVS_SetupMusic) = {
    IfGe(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
        Call(SetMusicTrack, 0, SONG_BOWSER_THEME, 0, VOL_LEVEL_8)
    EndIf
    Return
    End
};
