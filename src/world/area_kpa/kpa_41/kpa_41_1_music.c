#include "kpa_41.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_BOWSERS_CASTLE, 0, 8)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_METAL)
    EVT_THREAD
        EVT_WAIT(30)
        EVT_CALL(SetMusicTrackVolumes, TRACK_VOLS_KPA_3)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
