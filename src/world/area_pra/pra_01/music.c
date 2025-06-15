#include "pra_01.h"

EvtScript N(EVS_SetupMusic) = {
    IfEq(GB_StoryProgress, STORY_CH7_BEGAN_PEACH_MISSION)
        Call(SetMusic, 0, SONG_STAR_SPIRIT_THEME, BGM_VARIATION_1, VOL_LEVEL_FULL)
    Else
        Call(SetMusic, 0, SONG_SHIVER_MOUNTAIN, 0, VOL_LEVEL_FULL)
    EndIf
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Return
    End
};
