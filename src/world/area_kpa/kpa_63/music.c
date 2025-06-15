#include "kpa_63.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetLoadType, LVar0)
    IfEq(LVar0, 1)
        Call(SetMusic, 0, SONG_BOWSERS_CASTLE, 0, VOL_LEVEL_FULL)
        Thread
            Wait(30)
            Call(SetTrackVolumes, TRACK_VOLS_KPA_OUTSIDE)
        EndThread
        Call(ClearAmbientSounds, 250)
        Call(UseDoorSounds, DOOR_SOUNDS_METAL)
        Return
    EndIf
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kpa_63_ENTRY_0)
        Call(SetMusic, 0, SONG_BOWSERS_CASTLE, 0, VOL_LEVEL_FULL)
        Thread
            Wait(30)
            Call(SetTrackVolumes, TRACK_VOLS_KPA_OUTSIDE)
        EndThread
    EndIf
    Call(ClearAmbientSounds, 250)
    Call(UseDoorSounds, DOOR_SOUNDS_METAL)
    Return
    End
};
