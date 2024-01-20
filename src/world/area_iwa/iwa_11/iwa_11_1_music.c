#include "iwa_11.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_RIDING_THE_RAILS, 0, 8)
    Return
    End
};
