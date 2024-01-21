#include "flo_00.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(flo_00_ENTRY_8)
            IfNe(AF_FLO_RidingBeanstalk, FALSE)
                Call(SetMusicTrack, 0, SONG_MAGIC_BEANSTALK, 1, 8)
            Else
                Call(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
            EndIf
        CaseEq(flo_00_ENTRY_9)
            Call(SetMusicTrack, 0, SONG_SUNSHINE_RETURNS, 0, 8)
        CaseEq(flo_00_ENTRY_A)
            Call(SetMusicTrack, 0, SONG_STAR_SPIRIT_THEME, 1, 8)
            Thread
                Loop(0)
                    Wait(1)
                    IfGe(GB_StoryProgress, STORY_CH6_STAR_SPRIT_DEPARTED)
                        BreakLoop
                    EndIf
                EndLoop
                Call(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
            EndThread
        CaseEq(flo_00_ENTRY_B)
            Call(FadeInMusic, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 3000, 0, 127)
        CaseDefault
            Switch(GB_StoryProgress)
                CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
                    Call(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
                CaseDefault
                    Call(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
            EndSwitch
    EndSwitch
    Return
    End
};
