#include "kpa_03.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_BOWSERS_CASTLE_CAVES, 0, 8)
    Call(UseDoorSounds, DOOR_SOUNDS_METAL)
    Return
    End
};
