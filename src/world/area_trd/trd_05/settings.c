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
    Call(SetMusic, 0, SONG_KOOPA_FORTRESS, 0, VOL_LEVEL_FULL)
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
