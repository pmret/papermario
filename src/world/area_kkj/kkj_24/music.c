#include "kkj_24.h"

EvtScript N(EVS_SetupMusic) = {
    IfGe(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
        Call(SetMusic, 0, SONG_BOWSER_THEME, 0, VOL_LEVEL_FULL)
    EndIf
    Return
    End
};
