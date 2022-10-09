#include "iwa_10.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [iwa_10_ENTRY_0]    { -1250.0,   30.0,    0.0,   90.0 },
    [iwa_10_ENTRY_1]    { -445.0,  215.0, -500.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_iwa_10 },
};

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_MT_RUGGED, 0, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PushSong) = {
    EVT_CALL(StopSound, SOUND_80000009)
    EVT_CALL(PushSong, 130, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PopSong) = {
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_WAIT(15)
    EVT_CALL(PopSong)
    EVT_CALL(PlaySoundAtF, SOUND_80000009, 1, -560, 0, -233)
    EVT_RETURN
    EVT_END
};
