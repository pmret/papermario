#include "pra_15.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_SHIVER_MOUNTAIN, 0, 8)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Return
    End
};
