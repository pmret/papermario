#include "jan_16.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(jan_16_ENTRY_0)
            Call(SetMusicTrack, 0, SONG_RAPHAEL_RAVEN, 0, 8)
            Set(AF_JAN_03, FALSE)
        CaseEq(jan_16_ENTRY_3)
            Call(SetMusicTrack, 0, SONG_RAPHAEL_RAVEN, 1, 8)
            Set(AF_JAN_03, TRUE)
        CaseDefault
            IfEq(AF_JAN_03, FALSE)
                Call(SetMusicTrack, 0, SONG_RAPHAEL_RAVEN, 0, 8)
            EndIf
    EndSwitch
    Call(PlayAmbientSounds, AMBIENT_JUNGLE)
    Return
    End
};
