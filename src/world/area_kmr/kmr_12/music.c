#include "kmr_12.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_PLEASANT_PATH, 0, VOL_LEVEL_FULL)
    Return
    End
};
