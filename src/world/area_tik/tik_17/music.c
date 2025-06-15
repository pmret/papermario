#include "tik_17.h"

API_CALLABLE(N(AdjustTrackVolumes)) {
    bgm_set_track_volumes(0, TRACK_VOLS_TIK_SHIVER);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_TOAD_TOWN_TUNNELS, 0, VOL_LEVEL_FULL)
    Thread
        Wait(30)
        Call(N(AdjustTrackVolumes))
    EndThread
    Return
    End
};
