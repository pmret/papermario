#include "pra_01.h"

EvtScript N(EVS_SetupMusic) = {
    IfEq(GB_StoryProgress, STORY_CH7_BEGAN_PEACH_MISSION)
        Call(SetMusicTrack, 0, SONG_STAR_SPIRIT_THEME, 1, 8)
    Else
        Call(SetMusicTrack, 0, SONG_SHIVER_MOUNTAIN, 0, 8)
    EndIf
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Return
    End
};
