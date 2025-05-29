#include "hos_02.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, hos_02_ENTRY_1)
        Call(SetMusic, 0, SONG_STAR_WAY_OPENS, BGM_VARIATION_3, VOL_LEVEL_FULL)
    EndIf
    Return
    End
};
