#include "kpa_16.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_BOWSERS_CASTLE, 0, VOL_LEVEL_FULL)
    Call(UseDoorSounds, DOOR_SOUNDS_METAL)
    IfEq(GF_KPA16_ShutOffLava, false)
        Call(PlayAmbientSounds, AMBIENT_LAVA_7)
    EndIf
    Thread
        Wait(30)
        Call(SetTrackVolumes, TRACK_VOLS_KPA_1)
    EndThread
    Return
    End
};
