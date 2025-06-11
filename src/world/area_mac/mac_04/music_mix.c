#include "mac_04.h"

#include "world/common/atomic/MonitorMusicProximityTrigger.inc.c"

MusicProximityTrigger N(MusicMixTrigger) = {
    .pos = { -480.0f, 220.0f },
    .innerDist = 100.0f,
    .outerDist = 120.0f,
    .mix = 9,
    .manualActivationFlag = MF_MusicMixTrigger,
};

EvtScript N(EVS_SetupMusicTriggers) = {
    Call(SetMusic, 0, SONG_TOAD_TOWN, 0, VOL_LEVEL_FULL)
    Call(EnableMusicProximityMix, 0)
    Thread
        Call(N(MonitorMusicProximityTrigger), Ref(N(MusicMixTrigger)))
    EndThread
    Return
    End
};
