#include "jan_01.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_YOSHIS_VILLAGE, 0, VOL_LEVEL_FULL)
    Call(ClearAmbientSounds, 250)
    Return
    End
};
