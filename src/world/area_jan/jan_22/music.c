#include "jan_22.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, jan_22_ENTRY_3)
        Call(SetMusic, 0, SONG_STAR_SPIRIT_THEME, BGM_VARIATION_1, VOL_LEVEL_FULL)
        Thread
            Loop(0)
                Wait(1)
                IfGe(GB_StoryProgress, STORY_CH5_STAR_SPRIT_DEPARTED)
                    BreakLoop
                EndIf
            EndLoop
            Call(SetMusic, 0, SONG_DEEP_JUNGLE, 0, VOL_LEVEL_FULL)
        EndThread
    Else
        Switch(GB_StoryProgress)
            CaseRange(STORY_CH5_RAPHAEL_MOVED_ROOT, STORY_CH5_RAPHAEL_WAITING_FOR_MARIO)
                IfNe(LVar0, jan_22_ENTRY_1)
                    Call(SetMusic, 0, SONG_RAPHAEL_RAVEN, 0, VOL_LEVEL_FULL)
                    Set(AF_JAN_03, FALSE)
                EndIf
                Thread
                    Loop(0)
                        Wait(1)
                        IfGe(GB_StoryProgress, STORY_CH5_ZIP_LINE_READY)
                            BreakLoop
                        EndIf
                    EndLoop
                    Call(SetMusic, 0, SONG_DEEP_JUNGLE, 0, VOL_LEVEL_FULL)
                    Set(AF_JAN_03, FALSE)
                EndThread
            CaseDefault
                Call(SetMusic, 0, SONG_DEEP_JUNGLE, 0, VOL_LEVEL_FULL)
        EndSwitch
    EndIf
    Call(PlayAmbientSounds, AMBIENT_JUNGLE)
    Return
    End
};
