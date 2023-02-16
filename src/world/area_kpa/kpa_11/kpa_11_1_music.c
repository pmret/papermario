#include "kpa_11.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_BOWSERS_CASTLE, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_LAVA_1)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_METAL)
    EVT_THREAD
        EVT_WAIT(30)
        EVT_CALL(SetMusicTrackVolumes, TRACK_VOLS_KPA_1)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
