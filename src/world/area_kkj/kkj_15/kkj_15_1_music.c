#include "kkj_15.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseOrEq(STORY_CH0_BEGAN_PEACH_MISSION)
        CaseOrEq(STORY_CH1_BEGAN_PEACH_MISSION)
        CaseOrEq(STORY_CH3_BEGAN_PEACH_MISSION)
        CaseOrEq(STORY_CH7_BEGAN_PEACH_MISSION)
            Call(SetMusicTrack, 0, SONG_PRISONER_PEACH_THEME, 0, 8)
        EndCaseGroup
        CaseOrEq(STORY_CH2_BEGAN_PEACH_MISSION)
        CaseOrEq(STORY_CH4_BEGAN_PEACH_MISSION)
        CaseOrEq(STORY_CH5_BEGAN_PEACH_MISSION)
        CaseOrEq(STORY_CH6_BEGAN_PEACH_MISSION)
            Call(SetMusicTrack, 0, SONG_PEACH_MISSION, 0, 8)
        EndCaseGroup
    EndSwitch
    Return
    End
};
