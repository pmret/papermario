#include "trd_07.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [trd_07_ENTRY_0]    {  220.0,    0.0,    0.0,  270.0 },
    [trd_07_ENTRY_1]    { -200.0,    0.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_trd_07 },
};

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_FORTRESS, 0, 8)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_METAL)
    EVT_RETURN
    EVT_END
};
