#include "jan_16.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(jan_16_ENTRY_0)
            Call(SetMusicTrack, 0, SONG_RAPHAEL_RAVEN, 0, VOL_LEVEL_8)
            Set(AF_JAN_03, FALSE)
        CaseEq(jan_16_ENTRY_3)
            Call(SetMusicTrack, 0, SONG_RAPHAEL_RAVEN, 1, VOL_LEVEL_8)
            Set(AF_JAN_03, TRUE)
        CaseDefault
            IfEq(AF_JAN_03, FALSE)
                Call(SetMusicTrack, 0, SONG_RAPHAEL_RAVEN, 0, VOL_LEVEL_8)
            EndIf
    EndSwitch
    Call(PlayAmbientSounds, AMBIENT_JUNGLE)
    Return
    End
};
