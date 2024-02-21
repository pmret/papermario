#include "trd_02.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [trd_02_ENTRY_0]    { -257.0,    0.0,   80.0,   90.0 },
    [trd_02_ENTRY_1]    {  257.0,    0.0,   80.0,  270.0 },
    [trd_02_ENTRY_2]    { -257.0,  187.0,  -55.0,   90.0 },
    [trd_02_ENTRY_3]    {  257.0,  187.0,  -55.0,  270.0 },
    [trd_02_ENTRY_4]    {  235.0,   50.0,  -70.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_trd_02 },
};

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_KOOPA_FORTRESS, 0, 8)
    Call(UseDoorSounds, DOOR_SOUNDS_METAL)
    Return
    End
};
