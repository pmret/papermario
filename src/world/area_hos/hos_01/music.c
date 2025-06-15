#include "hos_01.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, hos_01_ENTRY_0)
        Call(SetMusic, 0, SONG_SHOOTING_STAR_SUMMIT, 0, VOL_LEVEL_FULL)
    EndIf
    Return
    End
};
