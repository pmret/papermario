#include "kpa_63.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetLoadType, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetMusicTrack, 0, SONG_BOWSERS_CASTLE, 0, 8)
        EVT_THREAD
            EVT_WAIT(30)
            EVT_CALL(SetMusicTrackVolumes, TRACK_VOLS_KPA_OUTSIDE)
        EVT_END_THREAD
        EVT_CALL(ClearAmbientSounds, 250)
        EVT_CALL(UseDoorSounds, DOOR_SOUNDS_METAL)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kpa_63_ENTRY_0)
        EVT_CALL(SetMusicTrack, 0, SONG_BOWSERS_CASTLE, 0, 8)
        EVT_THREAD
            EVT_WAIT(30)
            EVT_CALL(SetMusicTrackVolumes, TRACK_VOLS_KPA_OUTSIDE)
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_METAL)
    EVT_RETURN
    EVT_END
};
