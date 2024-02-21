#include "omo_04.h"

EvtScript N(EVS_SetupMusic) = {
    IfEq(GF_OMO04_SpawnedPeachChoice1, FALSE)
        Call(SetMusicTrack, 0, SONG_KAMMY_KOOPA_THEME, 0, 8)
    Else
        Call(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
    EndIf
    Return
    End
};
