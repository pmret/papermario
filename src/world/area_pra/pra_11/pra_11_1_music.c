#include "pra_11.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_CRYSTAL_PALACE, 0, 8)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Return
    End
};
