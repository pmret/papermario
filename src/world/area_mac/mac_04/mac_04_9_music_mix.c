#include "mac_04.h"

#include "world/common/atomic/MonitorMusicProximityTrigger.inc.c"

MusicProximityTrigger N(MusicMixTrigger) = {
    .pos = { -480.0f, 220.0f },
    .innerDist = 100.0f,
    .outerDist = 120.0f,
    .unk = 9,
    .manualActivationFlag = MF_MusicMixTrigger,
};

EvtScript N(EVS_SetupMusicTriggers) = {
    EVT_CALL(SetMusicTrack, 0, SONG_TOAD_TOWN, 0, 8)
    EVT_CALL(EnableMusicProximityMix, 0)
    EVT_THREAD
        EVT_CALL(N(MonitorMusicProximityTrigger), EVT_PTR(N(MusicMixTrigger)))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
