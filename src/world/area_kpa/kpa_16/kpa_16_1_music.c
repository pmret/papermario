#include "kpa_16.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_BOWSERS_CASTLE, 0, 8)
    Call(UseDoorSounds, DOOR_SOUNDS_METAL)
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Call(PlayAmbientSounds, AMBIENT_LAVA_7)
    EndIf
    Thread
        Wait(30)
        Call(SetMusicTrackVolumes, TRACK_VOLS_KPA_1)
    EndThread
    Return
    End
};
