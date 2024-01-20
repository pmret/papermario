#include "kpa_32.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_BOWSERS_CASTLE, 0, 8)
    Call(UseDoorSounds, DOOR_SOUNDS_METAL)
    Thread
        Wait(30)
        Call(SetMusicTrackVolumes, TRACK_VOLS_KPA_2)
    EndThread
    Return
    End
};
