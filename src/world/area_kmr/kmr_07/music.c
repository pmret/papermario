#include "kmr_07.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_PLEASANT_PATH, 0, VOL_LEVEL_FULL)
    Return
    End
};
