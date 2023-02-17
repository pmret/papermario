#include "kpa_62.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_BOWSERS_CASTLE, 0, 8)
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_CALL(PlayAmbientSounds, AMBIENT_LAVA_6)
    EVT_ELSE
        EVT_CALL(ClearAmbientSounds, 250)
    EVT_END_IF
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_METAL)
    EVT_THREAD
        EVT_WAIT(30)
        EVT_CALL(SetMusicTrackVolumes, TRACK_VOLS_KPA_OUTSIDE)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
