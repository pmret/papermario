#include "kkj_01.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kkj_01_ENTRY_1)
        Call(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 7)
        Wait(3)
    EndIf
    Call(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 8)
    Return
    End
};
