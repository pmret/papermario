#include "jan_07.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_JADE_JUNGLE, 0, VOL_LEVEL_FULL)
    Call(ClearAmbientSounds, 250)
    Return
    End
};
