#include "flo_00.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(flo_00_ENTRY_8)
            IfNe(AF_FLO_RidingBeanstalk, false)
                Call(SetMusic, 0, SONG_MAGIC_BEANSTALK, BGM_VARIATION_1, VOL_LEVEL_FULL)
            Else
                Call(SetMusic, 0, SONG_FLOWER_FIELDS_SUNNY, 0, VOL_LEVEL_FULL)
            EndIf
        CaseEq(flo_00_ENTRY_9)
            Call(SetMusic, 0, SONG_SUNSHINE_RETURNS, 0, VOL_LEVEL_FULL)
        CaseEq(flo_00_ENTRY_A)
            Call(SetMusic, 0, SONG_STAR_SPIRIT_THEME, BGM_VARIATION_1, VOL_LEVEL_FULL)
            Thread
                Loop(0)
                    Wait(1)
                    IfGe(GB_StoryProgress, STORY_CH6_STAR_SPRIT_DEPARTED)
                        BreakLoop
                    EndIf
                EndLoop
                Call(SetMusic, 0, SONG_FLOWER_FIELDS_SUNNY, 0, VOL_LEVEL_FULL)
            EndThread
        CaseEq(flo_00_ENTRY_B)
            Call(FadeInMusic, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 3000, 0, 127)
        CaseDefault
            Switch(GB_StoryProgress)
                CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
                    Call(SetMusic, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, VOL_LEVEL_FULL)
                CaseDefault
                    Call(SetMusic, 0, SONG_FLOWER_FIELDS_SUNNY, 0, VOL_LEVEL_FULL)
            EndSwitch
    EndSwitch
    Return
    End
};
