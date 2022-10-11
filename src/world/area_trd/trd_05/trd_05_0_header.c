#include "trd_05.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [trd_05_ENTRY_0]    { -310.0,    0.0,    0.0,   90.0 },
    [trd_05_ENTRY_1]    {    0.0,    0.0,  310.0,    0.0 },
    [trd_05_ENTRY_2]    {  290.0,    0.0,   30.0,  270.0 },
    [trd_05_ENTRY_3]    { -310.0,  240.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_trd_05 },
};

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_FORTRESS, 0, 8)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_METAL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StartKoopaBrosTheme) = {
    EVT_CALL(FadeInMusic, 1, SONG_KOOPA_BROS_INTERLUDE, 0, 3000, 0, 127)
    EVT_CALL(FadeOutMusic, 0, 3000)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EndKoopaBrosTheme) = {
    EVT_CALL(FadeInMusic, 0, SONG_KOOPA_FORTRESS, 0, 3000, 0, 127)
    EVT_CALL(FadeOutMusic, 1, 3000)
    EVT_RETURN
    EVT_END
};
