#include "hos_03.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_STAR_HAVEN, 0, VOL_LEVEL_FULL)
    Return
    End
};

EvtScript N(EVS_PlayRestingSong) = {
    Call(SetMusic, 0, SONG_TAKING_REST, 0, VOL_LEVEL_FULL)
    Return
    End
};
