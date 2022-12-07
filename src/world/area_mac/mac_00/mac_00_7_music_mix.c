#include "mac_00.h"

#include "world/common/atomic/MonitorMusicProximityTrigger.inc.c"

MusicProximityTrigger N(MusicMixTrigger1) = {
    .pos = { 15.0f, -400.0f },
    .innerDist = 90.0f,
    .outerDist = 120.0f,
    .unk = 7,
    .manualActivationFlag = MF_MusicMixTrigger1,
};

MusicProximityTrigger N(MusicMixTrigger2) = {
    .pos = { 445.0f, -307.0f },
    .innerDist = 90.0f,
    .outerDist = 110.0f,
    .unk = 3,
    .manualActivationFlag = MF_MusicMixTrigger2,
};

EvtScript N(EVS_SetupMusicTriggers) = {
    EVT_CALL(SetMusicTrack, 0, SONG_TOAD_TOWN, 0, 8)
    EVT_CALL(EnableMusicProximityMix, 0)
    EVT_THREAD
        EVT_CALL(N(MonitorMusicProximityTrigger), EVT_PTR(N(MusicMixTrigger1)))
    EVT_END_THREAD
    EVT_IF_GE(GB_StoryProgress, STORY_CH0_RETURNED_TO_TOAD_TOWN)
        EVT_THREAD
            EVT_CALL(N(MonitorMusicProximityTrigger), EVT_PTR(N(MusicMixTrigger2)))
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
