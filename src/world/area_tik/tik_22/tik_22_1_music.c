#include "tik_22.h"

API_CALLABLE(N(AdjustTrackVolumes)) {
    bgm_set_track_volumes(0, TRACK_VOLS_2);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_TOAD_TOWN_TUNNELS, 0, 8)
    EVT_THREAD
        EVT_WAIT(30)
        EVT_CALL(N(AdjustTrackVolumes))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
