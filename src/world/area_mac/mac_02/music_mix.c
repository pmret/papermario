#include "mac_02.h"

#include "world/common/atomic/MonitorMusicProximityTrigger.inc.c"

MusicProximityTrigger N(MusicMixTrigger1) = {
    .pos = { -150.0f, -205.0f },
    .innerDist = 120.0f,
    .outerDist = 150.0f,
    .mix = 1,
    .manualActivationFlag = MF_MusicMixTrigger1,
};

MusicProximityTrigger N(MusicMixTrigger2) = {
    .pos = { -400.0f, 250.0f },
    .innerDist = 110.0f,
    .outerDist = 130.0f,
    .mix = 4,
    .manualActivationFlag = MF_MusicMixTrigger2,
};

EvtScript N(EVS_SetupMusicTriggers) = {
    Call(SetMusic, 0, SONG_TOAD_TOWN, 0, VOL_LEVEL_FULL)
    Call(EnableMusicProximityMix, 0)
    Thread
        Call(N(MonitorMusicProximityTrigger), Ref(N(MusicMixTrigger1)))
    EndThread
    Thread
        Call(N(MonitorMusicProximityTrigger), Ref(N(MusicMixTrigger2)))
    EndThread
    Return
    End
};
