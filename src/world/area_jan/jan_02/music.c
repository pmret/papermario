#include "jan_02.h"

API_CALLABLE(N(AdjustTrackVolumes)) {
    bgm_set_track_volumes(0, TRACK_VOLS_JAN_FULL);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING, STORY_CH5_SUSHIE_JOINED_PARTY)
            Call(SetMusic, 0, SONG_YOSHIS_PANIC, 0, VOL_LEVEL_FULL)
        CaseDefault
            Call(SetMusic, 0, SONG_YOSHIS_VILLAGE, 0, VOL_LEVEL_FULL)
            Thread
                Wait(3)
                Call(N(AdjustTrackVolumes))
            EndThread
    EndSwitch
    Call(ClearAmbientSounds, 250)
    Return
    End
};
