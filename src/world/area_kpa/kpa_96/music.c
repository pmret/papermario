#include "kpa_96.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_BOWSERS_CASTLE, 0, VOL_LEVEL_FULL)
    Call(UseDoorSounds, DOOR_SOUNDS_METAL)
    Thread
        Wait(30)
        Call(SetTrackVolumes, TRACK_VOLS_KPA_2)
    EndThread
    Return
    End
};
