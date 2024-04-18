#include "kpa_63.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetLoadType, LVar0)
    IfEq(LVar0, 1)
        Call(SetMusicTrack, 0, SONG_BOWSERS_CASTLE, 0, 8)
        Thread
            Wait(30)
            Call(SetMusicTrackVolumes, TRACK_VOLS_KPA_OUTSIDE)
        EndThread
        Call(ClearAmbientSounds, 250)
        Call(UseDoorSounds, DOOR_SOUNDS_METAL)
        Return
    EndIf
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kpa_63_ENTRY_0)
        Call(SetMusicTrack, 0, SONG_BOWSERS_CASTLE, 0, 8)
        Thread
            Wait(30)
            Call(SetMusicTrackVolumes, TRACK_VOLS_KPA_OUTSIDE)
        EndThread
    EndIf
    Call(ClearAmbientSounds, 250)
    Call(UseDoorSounds, DOOR_SOUNDS_METAL)
    Return
    End
};
