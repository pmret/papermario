#include "hos_02.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, hos_02_ENTRY_1)
        Call(SetMusicTrack, 0, SONG_STAR_WAY_OPENS, 3, 8)
    EndIf
    Return
    End
};
