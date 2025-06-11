#include "mim_01.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_FOREVER_FOREST, 0, VOL_LEVEL_FULL)
    Call(PlayAmbientSounds, AMBIENT_SPOOKY)
    Return
    End
};
