#include "kpa_01.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_BOWSERS_CASTLE_CAVES, 0, VOL_LEVEL_FULL)
    Call(ClearAmbientSounds, 250)
    Call(UseDoorSounds, DOOR_SOUNDS_METAL)
    Return
    End
};
