#include "omo_02.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_SHY_GUY_TOYBOX, 0, VOL_LEVEL_FULL)
    Return
    End
};
