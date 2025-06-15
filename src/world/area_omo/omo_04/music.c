#include "omo_04.h"

EvtScript N(EVS_SetupMusic) = {
    IfEq(GF_OMO04_SpawnedPeachChoice1, FALSE)
        Call(SetMusic, 0, SONG_KAMMY_KOOPA_THEME, 0, VOL_LEVEL_FULL)
    Else
        Call(SetMusic, 0, SONG_SHY_GUY_TOYBOX, 0, VOL_LEVEL_FULL)
    EndIf
    Return
    End
};
