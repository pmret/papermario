#include "kpa_17.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_BOWSERS_CASTLE, 0, 8)
    Call(ClearAmbientSounds, 250)
    Call(UseDoorSounds, DOOR_SOUNDS_METAL)
    Thread
        Wait(30)
        Call(SetMusicTrackVolumes, TRACK_VOLS_KPA_1)
    EndThread
    Return
    End
};
