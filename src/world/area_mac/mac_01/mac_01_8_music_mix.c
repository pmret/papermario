#include "mac_01.h"

#include "world/common/atomic/MonitorMusicProximityTrigger.inc.c"

MusicProximityTrigger N(MusicMixTrigger1) = {
    .pos = { -190.0f, -210.0f },
    .innerDist = 100.0f,
    .outerDist = 120.0f,
    .unk = 2,
    .manualActivationFlag = MF_MusicMixTrigger1,
};

MusicProximityTrigger N(MusicMixTrigger2) = {
    .pos = { -150.0f, 330.0f },
    .innerDist = 110.0f,
    .outerDist = 130.0f,
    .unk = 8,
    .manualActivationFlag = MF_MusicMixTrigger2,
};

MusicProximityTrigger N(MusicMixTrigger3) = {
    .pos = { 266.0f, 370.0f },
    .innerDist = 200.0f,
    .outerDist = 220.0f,
    .unk = 5,
    .manualActivationFlag = MF_MusicMixTrigger3,
};


EvtScript N(EVS_SetupMusicMix) = {
    EVT_CALL(SetMusicTrack, 0, SONG_TOAD_TOWN, 0, 8)
    EVT_CALL(EnableMusicProximityMix, 0)
    EVT_IF_EQ(MF_SetupMusicMixes, FALSE)
        EVT_SET(MF_SetupMusicMixes, TRUE)
        EVT_THREAD
            EVT_CALL(N(MonitorMusicProximityTrigger), EVT_PTR(N(MusicMixTrigger1)))
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(N(MonitorMusicProximityTrigger), EVT_PTR(N(MusicMixTrigger2)))
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(N(MonitorMusicProximityTrigger), EVT_PTR(N(MusicMixTrigger3)))
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
