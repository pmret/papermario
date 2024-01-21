#include "hos_01.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, hos_01_ENTRY_0)
        Call(SetMusicTrack, 0, SONG_SHOOTING_STAR_SUMMIT, 0, 8)
    EndIf
    Return
    End
};
