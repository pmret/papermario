#include "sam_02.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Call(SetMusic, 0, SONG_SHIVER_CITY, 0, VOL_LEVEL_FULL)
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SetMusic, 0, SONG_PENGUIN_MYSTERY, 0, VOL_LEVEL_FULL)
        CaseGe(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SetMusic, 0, SONG_SHIVER_CITY, 0, VOL_LEVEL_FULL)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_PlayRestingSong) = {
    Call(SetMusic, 0, SONG_TAKING_REST, 0, VOL_LEVEL_FULL)
    Return
    End
};
