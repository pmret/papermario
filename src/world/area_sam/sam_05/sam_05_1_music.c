#include "sam_05.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_SHIVER_SNOWFIELD, 0, 8)
    Return
    End
};
