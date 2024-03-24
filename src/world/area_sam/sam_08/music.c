#include "sam_08.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_SHIVER_MOUNTAIN, 0, 8)
    Return
    End
};
