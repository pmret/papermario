#include "jan_01.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_YOSHIS_VILLAGE, 0, 8)
    Call(ClearAmbientSounds, 250)
    Return
    End
};
