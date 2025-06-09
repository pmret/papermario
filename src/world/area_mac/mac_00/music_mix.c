#include "mac_00.h"

#include "world/common/atomic/MonitorMusicProximityTrigger.inc.c"

MusicProximityTrigger N(MusicMixTrigger1) = {
    .pos = { 15.0f, -400.0f },
    .innerDist = 90.0f,
    .outerDist = 120.0f,
    .mix = 7,
    .manualActivationFlag = MF_MusicMixTrigger1,
};

MusicProximityTrigger N(MusicMixTrigger2) = {
    .pos = { 445.0f, -307.0f },
    .innerDist = 90.0f,
    .outerDist = 110.0f,
    .mix = 3,
    .manualActivationFlag = MF_MusicMixTrigger2,
};

EvtScript N(EVS_SetupMusicTriggers) = {
    Call(SetMusic, 0, SONG_TOAD_TOWN, 0, VOL_LEVEL_FULL)
    Call(EnableMusicProximityMix, 0)
    Thread
        Call(N(MonitorMusicProximityTrigger), Ref(N(MusicMixTrigger1)))
    EndThread
    IfGe(GB_StoryProgress, STORY_CH0_RETURNED_TO_TOAD_TOWN)
        Thread
            Call(N(MonitorMusicProximityTrigger), Ref(N(MusicMixTrigger2)))
        EndThread
    EndIf
    Return
    End
};
