#include "pra_05.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_CRYSTAL_PALACE, 0, VOL_LEVEL_FULL)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Return
    End
};
