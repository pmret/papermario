#include "kmr_10.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_PLEASANT_PATH, 0, 8)
    Return
    End
};
