#include "pra_13.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_CRYSTAL_PALACE, 0, VOL_LEVEL_FULL)
    Return
    End
};
