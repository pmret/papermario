#include "sam_12.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_MERLAR_THEME, 0, VOL_LEVEL_FULL)
    Return
    End
};
