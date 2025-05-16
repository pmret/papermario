#include "iwa_04.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_MT_RUGGED, 0, VOL_LEVEL_8)
    Return
    End
};
