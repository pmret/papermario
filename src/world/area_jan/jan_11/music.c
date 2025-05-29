#include "jan_11.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_JADE_JUNGLE, 0, VOL_LEVEL_6)
    Call(ClearAmbientSounds, 250)
    Return
    End
};
