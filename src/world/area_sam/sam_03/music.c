#include "sam_03.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_SHIVER_SNOWFIELD, 0, VOL_LEVEL_8)
    Return
    End
};
