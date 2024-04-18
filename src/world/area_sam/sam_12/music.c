#include "sam_12.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_MERLAR_THEME, 0, 8)
    Return
    End
};
