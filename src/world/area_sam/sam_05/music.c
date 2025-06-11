#include "sam_05.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_SHIVER_SNOWFIELD, 0, VOL_LEVEL_FULL)
    Return
    End
};
