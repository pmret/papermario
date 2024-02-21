#include "kkj_18.h"

EvtScript N(EVS_SetupMusic) = {
    IfEq(GB_StoryProgress, STORY_CH4_BEGAN_PEACH_MISSION)
        Call(SetMusicTrack, 0, SONG_PEACH_MISSION, 0, 8)
    EndIf
    Return
    End
};
