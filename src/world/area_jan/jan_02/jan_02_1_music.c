#include "jan_02.h"

API_CALLABLE(N(AdjustTrackVolumes)) {
    bgm_set_track_volumes(0, TRACK_VOLS_0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING, STORY_CH5_SUSHIE_JOINED_PARTY)
            Call(SetMusicTrack, 0, SONG_YOSHIS_PANIC, 0, 8)
        CaseDefault
            Call(SetMusicTrack, 0, SONG_YOSHIS_VILLAGE, 0, 8)
            Thread
                Wait(3)
                Call(N(AdjustTrackVolumes))
            EndThread
    EndSwitch
    Call(ClearAmbientSounds, 250)
    Return
    End
};
