#include "kkj_19.h"

EvtScript N(EVS_SetupMusic) = {
    IfEq(GB_StoryProgress, STORY_INTRO)
        Call(SetMusic, 0, SONG_PEACHS_CASTLE_PARTY, BGM_VARIATION_1, VOL_LEVEL_7)
        Wait(3)
        Call(SetMusic, 0, SONG_PEACHS_CASTLE_PARTY, BGM_VARIATION_1, VOL_LEVEL_6)
        Return
    EndIf
    IfEq(GB_StoryProgress, STORY_CH4_BEGAN_PEACH_MISSION)
        Call(SetMusic, 0, SONG_PEACH_MISSION, 0, VOL_LEVEL_FULL)
        Return
    EndIf
    Return
    End
};
