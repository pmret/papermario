#include "kpa_14.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_BOWSERS_CASTLE, 0, VOL_LEVEL_FULL)
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Call(PlayAmbientSounds, AMBIENT_LAVA_1)
    Else
        Call(ClearAmbientSounds, 250)
    EndIf
    Call(UseDoorSounds, DOOR_SOUNDS_METAL)
    Thread
        Wait(30)
        Call(SetTrackVolumes, TRACK_VOLS_KPA_1)
    EndThread
    Return
    End
};
