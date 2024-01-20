#include "omo_01.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
    Return
    End
};
