#include "pra_13.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_CRYSTAL_PALACE, 0, VOL_LEVEL_8)
    Return
    End
};
