#include "pra_15.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_SHIVER_MOUNTAIN, 0, VOL_LEVEL_FULL)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Return
    End
};
