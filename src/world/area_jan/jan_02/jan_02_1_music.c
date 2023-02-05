#include "jan_02.h"

API_CALLABLE(N(AdjustTrackVolumes)) {
    bgm_set_track_volumes(0, TRACK_VOLS_0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetupMusic) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING, STORY_CH5_SUSHIE_JOINED_PARTY)
            EVT_CALL(SetMusicTrack, 0, SONG_YOSHIS_PANIC, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_YOSHIS_VILLAGE, 0, 8)
            EVT_THREAD
                EVT_WAIT(3)
                EVT_CALL(N(AdjustTrackVolumes))
            EVT_END_THREAD
    EVT_END_SWITCH
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_RETURN
    EVT_END
};
