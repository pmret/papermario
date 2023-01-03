#include "kpa_60.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_NE(GB_StoryProgress, STORY_CH8_STAR_SHIP_ACTIVATED)
        EVT_CALL(SetMusicTrack, 0, SONG_BOWSERS_CASTLE, 0, 8)
        EVT_THREAD
            EVT_WAIT(30)
        EVT_CALL(SetMusicTrackVolumes, TRACK_VOLS_KPA_OUTSIDE)
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_METAL)
    EVT_RETURN
    EVT_END
};
