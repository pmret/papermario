#include "jan_22.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, jan_22_ENTRY_3)
        Call(SetMusicTrack, 0, SONG_STAR_SPIRIT_THEME, 1, 8)
        Thread
            Loop(0)
                Wait(1)
                IfGe(GB_StoryProgress, STORY_CH5_STAR_SPRIT_DEPARTED)
                    BreakLoop
                EndIf
            EndLoop
            Call(SetMusicTrack, 0, SONG_DEEP_JUNGLE, 0, 8)
        EndThread
    Else
        Switch(GB_StoryProgress)
            CaseRange(STORY_CH5_RAPHAEL_MOVED_ROOT, STORY_CH5_RAPHAEL_WAITING_FOR_MARIO)
                IfNe(LVar0, jan_22_ENTRY_1)
                    Call(SetMusicTrack, 0, SONG_RAPHAEL_RAVEN, 0, 8)
                    Set(AF_JAN_03, FALSE)
                EndIf
                Thread
                    Loop(0)
                        Wait(1)
                        IfGe(GB_StoryProgress, STORY_CH5_ZIP_LINE_READY)
                            BreakLoop
                        EndIf
                    EndLoop
                    Call(SetMusicTrack, 0, SONG_DEEP_JUNGLE, 0, 8)
                    Set(AF_JAN_03, FALSE)
                EndThread
            CaseDefault
                Call(SetMusicTrack, 0, SONG_DEEP_JUNGLE, 0, 8)
        EndSwitch
    EndIf
    Call(PlayAmbientSounds, AMBIENT_JUNGLE)
    Return
    End
};
