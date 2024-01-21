#include "trd_03.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [trd_03_ENTRY_0]    { -647.0,    0.0,   80.0,   90.0 },
    [trd_03_ENTRY_1]    {  537.0,    0.0,   80.0,  270.0 },
    [trd_03_ENTRY_2]    { -647.0,  180.0, -100.0,   90.0 },
    [trd_03_ENTRY_3]    {  537.0,  180.0, -100.0,  270.0 },
    [trd_03_ENTRY_4]    { -645.0,   45.0, -100.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_trd_03 },
};

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_KOOPA_FORTRESS, 0, 8)
    Call(UseDoorSounds, DOOR_SOUNDS_METAL)
    Return
    End
};

EvtScript N(EVS_StartKoopaBrosTheme) = {
    Call(FadeInMusic, 1, SONG_KOOPA_BROS_INTERLUDE, 0, 3000, 0, 127)
    Call(FadeOutMusic, 0, 3000)
    Return
    End
};

EvtScript N(EVS_EndKoopaBrosTheme) = {
    Call(FadeInMusic, 0, SONG_KOOPA_FORTRESS, 0, 3000, 0, 127)
    Call(FadeOutMusic, 1, 3000)
    Return
    End
};
