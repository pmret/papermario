#include "jan_16.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(jan_16_ENTRY_0)
            Call(SetMusic, 0, SONG_RAPHAEL_RAVEN, 0, VOL_LEVEL_FULL)
            Set(AF_JAN_03, false)
        CaseEq(jan_16_ENTRY_3)
            Call(SetMusic, 0, SONG_RAPHAEL_RAVEN, BGM_VARIATION_1, VOL_LEVEL_FULL)
            Set(AF_JAN_03, true)
        CaseDefault
            IfEq(AF_JAN_03, false)
                Call(SetMusic, 0, SONG_RAPHAEL_RAVEN, 0, VOL_LEVEL_FULL)
            EndIf
    EndSwitch
    Call(PlayAmbientSounds, AMBIENT_JUNGLE)
    Return
    End
};
