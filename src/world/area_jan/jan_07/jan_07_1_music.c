#include "jan_07.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_JADE_JUNGLE, 0, 8)
    Call(ClearAmbientSounds, 250)
    Return
    End
};
